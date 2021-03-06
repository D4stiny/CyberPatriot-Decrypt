// CyberPatriot-Decrypt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>

#include "CryptoPP\aes.h"
#include "CryptoPP\filters.h"
#include "CryptoPP\zlib.h"
#include "CryptoPP\gcm.h"

static std::vector<char> ReadAllBytes(char const* filename)
{
	std::ifstream ifs(filename, std::ios::binary | std::ios::ate);
	std::ifstream::pos_type pos = ifs.tellg();

	std::vector<char> result(pos);

	ifs.seekg(0, std::ios::beg);
	ifs.read(&result[0], pos);

	return result;
}

int main(int argc, const char *argv[])
{
	if (argc < 2) {
		printf("Filename not passed!\n");
		std::cin.get();
		return 0;
	}

	std::vector<char> file_bytes = ReadAllBytes(argv[1]);
	char* file_buffer = file_bytes.data();

	byte iv[12];
	memcpy(iv, file_buffer, 12); // First 12 bytes of file is the IV.

	byte key[] = { 0xB, 0x50, 0x96, 0x92, 0xCA, 0xC8, 0xCA, 0xDE, 0xC8, 0xCE, 0xF6, 0x76, 0x95, 0xF5, 0x1E, 0x99 }; // This key is hardcoded into the scoring engine, see the blog post for details how to get this.

	std::string decryptedtext;

	CryptoPP::GCM<CryptoPP::AES>::Decryption gcmDecryption;
	gcmDecryption.SetKeyWithIV(key, sizeof(key), iv, 12);

	CryptoPP::ZlibDecompressor* inflator = new CryptoPP::ZlibDecompressor(new CryptoPP::StringSink(decryptedtext));
	CryptoPP::AuthenticatedDecryptionFilter df(gcmDecryption, inflator);
	df.Put((const byte*)(file_buffer + 12), file_bytes.size() - 12); // We want all the bytes AFTER the IV.

	printf("%s\n", decryptedtext.c_str());

	std::cin.get();
    return 0;
}

