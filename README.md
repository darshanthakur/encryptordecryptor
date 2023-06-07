# Text Encryption and Decryption Tool

This project provides a simple encryption and decryption tool implemented in C++. The tool allows users to encrypt and decrypt messages using a custom algorithm. The code provided performs encryption and decryption based on a matrix transposition technique.

## Features

- **Encryption**: Users can encrypt a message using the provided algorithm.
- **Decryption**: Users can decrypt an encrypted message using the corresponding key.

## Algorithm Overview

The encryption and decryption algorithm used in this tool is based on a matrix transposition technique. The steps involved are as follows:

1. **Encryption:**

   - Read the input message.
   - Pad the message with spaces to form a square matrix.
   - Generate a random key of the same size as the number of rows in the matrix.
   - Sort the key and create a cipher matrix by rearranging the rows of the original matrix according to the sorted key.
   - Transpose the cipher matrix to obtain the final encrypted message.
   - Output the encrypted message and the key.

2. **Decryption:**

   - Read the input cipher and key.
   - Retrieve the original matrix by rearranging the rows of the cipher matrix according to the key.
   - Transpose the matrix to obtain the decrypted message.
   - Output the decrypted message.
