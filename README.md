# Text Encryption and Decryption Tool

This project provides a simple encryption and decryption tool implemented in C++. The tool allows users to encrypt and decrypt messages using a custom algorithm. The code provided performs encryption and decryption based on a matrix transposition technique.

## Features

- **Encryption**: Users can encrypt a message using the provided algorithm.
- **Decryption**: Users can decrypt an encrypted message using the corresponding key.

## How to Use

1. Clone the repository: `git clone https://github.com/your-username/encryption-decryption-tool.git`
2. Navigate to the project directory: `cd encryption-decryption-tool`
3. Compile the code: `g++ main.cpp -o encrypt-decrypt`
4. Run the program:
   - To encrypt a message:
     ```
     ./encrypt-decrypt 1
     ```
   - To decrypt a message:
     ```
     ./encrypt-decrypt 2
     ```
5. Follow the on-screen prompts to enter the necessary information for encryption or decryption.

**Note:** Make sure to provide the input files with the correct filenames as specified in the code (`encryp_input.txt` for encryption and `decryp_input.txt` for decryption). Similarly, the output files will be generated as `encryp_output.txt` and `decryp_output.txt` for encryption and decryption, respectively.

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

## Contributing

Contributions to the Encryption and Decryption Tool project are welcome. If you would like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature-name`.
3. Make your changes and commit them: `git commit -m 'Add your feature'`.
4. Push to the feature branch: `git push origin feature/your-feature-name`.
5. Submit a pull request outlining the changes you have made.

## License

The Encryption and Decryption Tool is licensed under the [MIT License](LICENSE.md). You are free to use, modify, and distribute this project for personal and commercial purposes.

## Acknowledgments

We would like to acknowledge the contributions made by the original author of the encryption and decryption algorithm implemented in this tool.
