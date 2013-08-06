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

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "LUAHandler.h"
#include "ESSHandler.h"

#define ARG_MODALITY argv[1]
#define ARG_INPUT argv[2]
#define ARG_OUTPUT argv[3]
#define ARG_TYPE argv[4]

FILE *FHandle;
FILE *OFHandle;

int main(int argc,const char* argv[])
{
	SetConsoleTitle("ElSword Lua Decrypter");
	printf("\t\t***************************************\n"
		   "\t\t***      ElSword LUA Decrypter      ***\n"
		   "\t\t**  Made by d3v1l401 (d3vsite.org)   **\n"
		   "\t\t*            Version 1.01             *\n"
		   "\t\t**           Made in Italy           **\n"
		   "\t\t***        22/05/2013  22.39        ***\n"
		   "\t\t***************************************\n\n");

	if (argc != 4)
	{
		printf("Instructions:\n\n"
			   "ESLuaD.exe [MODALITY] [INPUT] [OUTPUT] [FILETYPE]\n\n"
			   "LUA Example:\n\n"
			   "(Decrypting) ESLuaD.exe -d config.lua config_dec.lua LUA\n"
			   "(Encrypting) ESLuaD.exe -e config_dec.lua config.lua LUA\n\n"
			   "ESS Example:\n\n"
			   "(Decrypting) ESLuaD.exe -d general.ess generale.ess ESS\n"
			   "(Encrypting) ESLuaD.exe -e generale.ess generalizzando.ess ESS\n\n");
		_getch();
		return 0;
	}

	if (!strcmp(ARG_TYPE,"LUA"))
	{
		printf("[LOG] LUA File Type\n");
		if (!strcmp(ARG_MODALITY,"-d"))
		{
			printf("[LOG] Switched to decrypt mode.\n");
		
			if (!(FHandle = fopen(ARG_INPUT,"r")))
			{
				printf("[ERROR] Can't open the file %s.\n",ARG_INPUT);
				_getch();
				return 0;
			}
			if (!(OFHandle = fopen(ARG_OUTPUT,"w")))
			{
				printf("[ERROR] Can't write the file %s.\n",ARG_INPUT);
				_getch();
				return 0;
			}

			printf("[LOG] Decrypting...\n");
			LUAHandler::Decrypt(FHandle,OFHandle);
			printf("[SUCCESS] Done.\n");

		} else if (!strcmp(ARG_MODALITY,"-e")) 
		{
			printf("[LOG] Switched to encrypt mode.\n");

			if (!(FHandle = fopen(ARG_INPUT,"r")))
			{
				printf("[ERROR] Can't open the file %s.\n",ARG_INPUT);
				_getch();
				return 0;
			}
			if (!(OFHandle = fopen(ARG_OUTPUT,"w")))
			{
				printf("[ERROR] Can't write the file %s.\n",ARG_INPUT);
				_getch();
				return 0;
			}

			printf("[LOG] Encrypting...\n");
			LUAHandler::Encrypt(FHandle,OFHandle);
			printf("[SUCCESS] Done.\n");

		} else {
			printf("[ERROR] Unknown modality taken.\n");
			_getch();
			return 0;
		}
	} else if (!strcmp(ARG_TYPE,"ESS"))
	{
		printf("[LOG] ESS File Type\n");
		if (!strcmp(ARG_MODALITY,"-d"))
		{
			printf("[LOG] Switched to decrypt mode.\n");
		
			if (!(FHandle = fopen(ARG_INPUT,"r")))
			{
				printf("[ERROR] Can't open the file %s.\n",ARG_INPUT);
				_getch();
				return 0;
			}
			if (!(OFHandle = fopen(ARG_OUTPUT,"w")))
			{
				printf("[ERROR] Can't write the file %s.\n",ARG_INPUT);
				_getch();
				return 0;
			}

			printf("[LOG] Decrypting...\n");
			ESSHandler::Decrypt(FHandle,OFHandle);
			printf("[SUCCESS] Done.\n");

		} else if (!strcmp(ARG_MODALITY,"-e")) 
		{
			printf("[LOG] Switched to encrypt mode.\n");

			if (!(FHandle = fopen(ARG_INPUT,"r")))
			{
				printf("[ERROR] Can't open the file %s.\n",ARG_INPUT);
				_getch();
				return 0;
			}
			if (!(OFHandle = fopen(ARG_OUTPUT,"w")))
			{
				printf("[ERROR] Can't write the file %s.\n",ARG_INPUT);
				_getch();
				return 0;
			}

			printf("[LOG] Encrypting...\n");
			ESSHandler::Encrypt(FHandle,OFHandle);
			printf("[SUCCESS] Done.\n");

		} else {
			printf("[ERROR] Unknown modality taken.\n");
			_getch();
			return 0;
		}
	} else {
		printf("[ERROR] Unknown file type specified.\n");
	}

	_getch();
	return 0;
}