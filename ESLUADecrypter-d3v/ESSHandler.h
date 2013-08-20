#pragma once
#pragma warning( disable : 4996 )
#include <iostream>
#include <Windows.h>

static char ESSXORKey = 0x10;

static long ESSFSize = 0;

class ESSHandler
{
public:

	static void Decrypt(FILE* InFileHandle,FILE *OutFileHandle)
	{
		char Data[3145728]; // 3 Megabytes
		memset(Data, 0, sizeof(Data));

		fread(Data,sizeof(char),ESSFSize,InFileHandle);
		fclose(InFileHandle);

		for(int i = 0; i <= ESSFSize; i++)
		{
			Data[i] ^= ESSXORKey;
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