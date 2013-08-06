					/*****************************************************
					**    Hello user,
					**    I released this as Open Source project,if you
					**    are gonna use part of this code,please give 
					**    credits,this is all what i ask for.
					**    I spent hours to find the encryption key,so 
					**    please respect my hard work.
					**
					**                        - d3v1l401 (d3vsite.org)
					*****************************************************/

#pragma once
#pragma warning( disable : 4996 )
#include <iostream>
#include <Windows.h>

static unsigned char XORKey[12] =
{
	0x02, 0xAA, 0xF8, 0xC6, 0xDC, 0xAB, 
	0x47, 0x26, 0xEF, 0xBB, 0x00, 0x98 
};

static long FSize = 0;

class LUAHandler
{
public:

	static void Decrypt(FILE* InFileHandle,FILE *OutFileHandle)
	{
		char Data[3145728]; // 3 Megabytes
		memset(Data, 0, sizeof(Data));
		short int KeyStepper = 0;

		fread(Data,sizeof(char),FSize,InFileHandle);
		fclose(InFileHandle);

		for(int i = 0; i <= FSize; i++)
		{
			Data[i] ^= XORKey[KeyStepper];
			if (KeyStepper == sizeof(XORKey))
				KeyStepper = 0;
			KeyStepper++;
		}

		fwrite(Data,sizeof(char),strlen(Data),OutFileHandle);
		fclose(OutFileHandle);
	}

	static void Encrypt(FILE* InFileHandle,FILE *OutFileHandle)
	{
		Decrypt(InFileHandle,OutFileHandle);
	}

	static void GetFileSize(FILE* InFileHandle)
	{
		fseek(InFileHandle, 0, SEEK_END);
		FSize = ftell(InFileHandle);
		fseek(InFileHandle, 0, SEEK_SET);
	}
};