#include <iostream>
#include "AES.h"
#include <cassert>

using namespace std;






void Test128()
{
	AES cipher(128);
	unsigned char plain[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };
	unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
	unsigned char *out = new unsigned char[16];
	unsigned char right[] = { 0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30, 0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a };

	cipher.AES_Enc(plain, out, key);
	
	assert(!memcmp(right, out, 16 * sizeof(unsigned char)));
	cout << "Test 128 [OK]" << endl;
	delete[] out;
}


void Test192()
{
	AES cipher(192);
	unsigned char plain[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };
	unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x011,
		0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
	unsigned char *out = new unsigned char[16];
	unsigned char right[] = {0xdd, 0xa9, 0x7c, 0xa4, 0x86, 0x4c, 0xdf, 0xe0, 0x6e, 0xaf, 0x70, 0xa0, 0xec, 0x0d, 0x71, 0x91 };

	cipher.AES_Enc(plain, out, key);
	//print_mas(out, 16);
	assert(!memcmp(right, out, 16 * sizeof(unsigned char)));
	cout << "Test 192 [OK]" << endl;
	delete[] out;
}


void Test256()
{
	AES cipher(256);
	unsigned char plain[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };
	unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x011,
		0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f };
	unsigned char *out = new unsigned char[16];
	unsigned char right[] = { 0x8e, 0xa2, 0xb7, 0xca, 0x51, 0x67, 0x45, 0xbf, 0xea, 0xfc, 0x49, 0x90, 0x4b, 0x49, 0x60, 0x89 };

	cipher.AES_Enc(plain, out, key);
	assert(!memcmp(right, out, 16 * sizeof(unsigned char)));
	cout << "Test 256 [OK]" << endl;
	delete[] out;
}

int main()
{
	Test128();
	Test192();
	Test256();
	
	
	int c;
	cin >> c;
    return 0;
}

