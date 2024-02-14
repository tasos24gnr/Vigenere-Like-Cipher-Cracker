#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define KEY_MAX_LENGTH 13
#define CIPHERTEXT_LENGTH 590

bool isEnglish(const char *text) {
    int printableCount = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= ' ' && text[i] <= '~') // Check if character is printable ASCII
            printableCount++;
    }
    double ratio = (double)printableCount / strlen(text);
    return ratio >= 0.9; // Threshold for determining if the text is English-like
}

void decrypt(const unsigned char *ciphertext, int ciphertextLength, const unsigned char *key, int keyLength) {
    unsigned char plaintext[CIPHERTEXT_LENGTH];
    for (int i = 0; i < ciphertextLength; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % keyLength]; // Perform XOR decryption
    }
    plaintext[ciphertextLength] = '\0'; // Null-terminate the plaintext
    if (isEnglish((char *)plaintext)) { // Check if the decrypted text is English-like
        printf("Decrypted plaintext: %s\n", plaintext);
        printf("Key: ");
        for (int i = 0; i < keyLength; i++) {
            printf("%02X ", key[i]); // Print the key as hexadecimal
        }
        printf("\n");
    }
}

void bruteForceDecrypt(const unsigned char *ciphertext, int ciphertextLength) {
    unsigned char key[KEY_MAX_LENGTH];
    for (int keyLength = 1; keyLength <= KEY_MAX_LENGTH; keyLength++) { // Try different key lengths
        for (int i = 0; i < 256; i++) { // Try all possible bytes as the key
            memset(key, i, keyLength); // Fill the key with the current byte
            decrypt(ciphertext, ciphertextLength, key, keyLength);
        }
    }
}

int main() {
    unsigned char ciphertext[CIPHERTEXT_LENGTH];
    FILE *file = fopen("ciphertext.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int i = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) { // Read ciphertext from file
        if (ch >= '0' && ch <= '9')
            ch -= '0';
        else if (ch >= 'A' && ch <= 'F')
            ch = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f')
            ch = ch - 'a' + 10;
        else
            continue; // Ignore non-hexadecimal characters
        ciphertext[i++] = ch;
    }
    fclose(file);
    bruteForceDecrypt(ciphertext, i);
    return 0;
}
