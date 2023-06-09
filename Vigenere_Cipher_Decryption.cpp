//RUBEN VALENCIA - Vigenere Cipher Decryption
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string encrypt(string message, string key) {
    string encryptedMessage = ""; // to store the encrypted message
    int j = 0; // counter for the key

    // loop through the message
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == ' ') { // ignore spaces
            encryptedMessage += " ";
        } else {
            // add the value of the key to the ASCII value of the character
            int value = ((message[i] - 'A') + (key[j] - 'A')) % 26;
            encryptedMessage += char(value + 'A');
            j = (j + 1) % key.length(); // increment the key counter
        }
    }
    return encryptedMessage; // return the encrypted message
}

string decrypt(string message, string key) {
    string decryptedMessage = ""; // to store the decrypted message
    int j = 0; // counter for the key

    // loop through the message
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == ' ') { // ignore spaces
            decryptedMessage += " ";
        } else {
            // subtract the value of the key from the ASCII value of the character
            int value = ((message[i] - 'A') - (key[j] - 'A') + 26) % 26;
            decryptedMessage += char(value + 'A');
            j = (j + 1) % key.length(); // increment the key counter
        }
    }
    return decryptedMessage; // return the decrypted message
}

int main() {
    int choice;
    string message;
    string key;
cout << "This program encrypts or decrypts messages. ";
    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter key: ";
    getline(cin, key);

    transform(message.begin(), message.end(), message.begin(), ::toupper); // convert message to uppercase
    transform(key.begin(), key.end(), key.begin(), ::toupper); // convert key to uppercase

    cout << "Press 1 to encrypt, 2 to decrypt: ";
    cin >> choice;

    switch (choice) {
        case 1: // encrypt
            cout << "Encrypted message: " << encrypt(message, key) << endl;
            break;
        case 2: // decrypt
            cout << "Decrypted message: " << decrypt(message, key) << endl;
            break;
        default: // invalid choice
            cout << "Invalid choice." << endl;
            break;
    }

    return 0; // exit program
}