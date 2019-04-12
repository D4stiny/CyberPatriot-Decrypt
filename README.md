# CyberPatriot Decryptor

## Description

This is a small tool I made that is meant to accompany my research into the CyberPatriot Scoring Engine. Simply drag and drop an encrypted CyberPatriot file on to the program and it will spit out the decrypted version. If you haven't already, check out my research [here](https://d4stiny.github.io/Reversing-the-CyberPatriot-National-Competition/).

## Release

If you trust me enough to run a binary I compiled, there is one available in the [releases](https://github.com/D4stiny/CyberPatriot-Decrypt/releases) section.

## Pre-2016 Encrypted Files

For encrypted files before 2016, you may need to use a different key array. Here is a key array I used to decrypt 2014-2015 data:

```
byte key[] = { 0x20, 0xDB, 0xE7, 0x13, 0x07, 0x06, 0xB5, 0x16, 0x95, 0xF3, 0xA2, 0x5F, 0xC4, 0x9F, 0x23, 0xC6 };
```

## CyberPatriot XI (2018-2019) Encrypted Files

If you want to decrypt files from this years competition, you will need to use this key array:

```
byte key[] = { 0x48, 0x95, 0x3f, 0x18, 0x30, 0x42, 0x3a, 0x47, 0x51, 0x40, 0x05, 0x2c, 0x54, 0xae, 0x0c, 0x2e };
```

This means you will have to build my project yourself with the updated code.
