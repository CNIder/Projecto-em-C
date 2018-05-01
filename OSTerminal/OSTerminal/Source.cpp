#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include < string.h>
#include <string.h>
#include <iostream>
#include <string.h>
#include <stdio.h> 
#include <time.h>
#include<conio.h>
#include <windows.h>
#include <graphics.h>
#include<conio.h>

#define LARGE_ENOUGH_VALUE 12l   // But not to large either...
/* Some list of combinations

0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White */
#define LEN 256


void login();
void boot();
void Os();
void calc();
void notepad();
void cmd();
void TR();
void bootAdvancedOptions();
void PI();//PC INFORMANTION
void FileExplorer();
void Log();
void MultiplicationTable(int nr);
void LogUser();
void adminCheck();
void adminChange();
void adminRevert();
void info();
int i;


struct registro
{

	char nomedocomputador[20];
	char username[20];
	char password[20];
	
	char verifyu[20];
	char verifyp[20];
	

};

struct registro vetor[1];

// *****************************Registo e Login**********************
void login(){
	
		fflush(stdin);
		printf("Nome do computador: ");
		gets_s(vetor[i].nomedocomputador);
		fflush(stdin);
		printf("username: ");
		gets_s(vetor[i].username);
		fflush(stdin);
		printf("password:");
		gets_s(vetor[i].password);
		fflush(stdin);
		FILE *fptr;

		fptr = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\programLogin.txt", "w");
		if (fptr == NULL)
		{
			printf("Error!");
			exit(1);
		}

		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		char s[64];
		strftime(s, sizeof(s), "%c", tm);

		fprintf(fptr, "Nome do computador: : %s\n",vetor[i].nomedocomputador);
		fprintf(fptr, "utilizador do computador: : %s\n", vetor[i].username);
		fprintf(fptr, "password do computador: : %s\n", vetor[i].password);
		fprintf(fptr, "Data De Criacao: : %s\n", s);
		fclose(fptr);

		FILE *fptr2;

		fptr2 = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\data.txt", "w");
		if (fptr2 == NULL)
		{
			printf("Error!");
			exit(1);
		}

		fprintf(fptr2, "%s\n", vetor[i].username);
		fprintf(fptr2, "%s\n", vetor[i].password);

		fclose(fptr2);

		// create a FILE typed pointer
		FILE *file_pointer;

		// open the file "name_of_file.txt" for writing
		file_pointer = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\priviligies\\admin_SD.text", "w");

		// Write to the file
		fprintf(file_pointer, "admin : yes");

		// Close the file
		fclose(file_pointer);

		Log();

}

void Log(){


	char nome[20];
	char password[20];
	for (i = 0; i < 1; i++){
		printf("\nusername: ");
		gets_s(nome);
		fflush(stdin);
		printf("password:");
		gets_s(password);
		fflush(stdin);



		if (strcmp(nome, vetor[i].username) == 0 && strcmp(password, vetor[i].password) == 0){
			system("@cls||clear");
			Os();
		}
		else{
			//invalid password. Report it
			printf("\nPassword entered is invalid");
			Log();
		}
	}
}
	
	

//********************************Operative system***************************

void Os(){

	char choise[20];

	fflush(stdin);
	        printf_s("#**********OS Terminal************\n");
			printf("-->");
			gets_s(choise);

			if (strcmp(choise, "Calc") == 0) {
				calc();
			}
			if (strcmp(choise, "Notepad") == 0)
			{
				notepad();
			}
			if (strcmp(choise, "comand") == 0)
			{
				cmd();
			}
			if (strcmp(choise, "--File op") == 0)
			{
				FileExplorer();
			}
			if (strcmp(choise, "--i") == 0)
			{
				TR();
			}
			if (strcmp(choise, "--date") == 0)
			{
				time_t t = time(NULL);
				struct tm *tm = localtime(&t);
				char s[64];
				strftime(s, sizeof(s), "%c", tm);
				printf("%s\n", s);
				Os();
			}
			if (strcmp(choise, "--gamePyramid") == 0)
			{
				int i, j;
				char input, alphabet = 'A';

				printf("Enter the uppercase character you want to print in last row: ");
				scanf("%c", &input);

				for (i = 1; i <= (input - 'A' + 1); ++i)
				{
					for (j = 1; j <= i; ++j)
					{
						printf("%c", alphabet);
					}
					++alphabet;

					printf("\n");
				}
				Os();
			}
			if (strcmp(choise, "--asci") == 0)
			{
			char c;
			printf("Enter a character: ");

			// Reads character input from the user
			scanf("%c", &c);

			// %d displays the integer value of a character
			// %c displays the actual character
			printf("ASCII value of %c = %d\n", c, c);
			Os();
			}

			if (strcmp(choise, "math--multiply") == 0)
			{
				 int n;
				printf("Enter an integer: ");
				scanf("%d", &n);
				MultiplicationTable(n);
			}
			if (strcmp(choise, "--set privilegies 0") == 0)
			{
				adminChange();
			}
			if (strcmp(choise, "--set privilegies 1") == 0)
			{
				adminRevert();
			}
			else{
				printf_s("Wrong conmand\n");
				Os();
			}
			
		}
		
void adminChange(){
	// create a FILE typed pointer
	FILE *file_pointer;

	// open the file "name_of_file.txt" for writing
	file_pointer = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\priviligies\\admin_SD.text", "w");

	// Write to the file
	fprintf(file_pointer, "admin : no");

	// Close the file
	fclose(file_pointer);
}

void adminRevert(){
	// create a FILE typed pointer
	FILE *file_pointer;

	// open the file "name_of_file.txt" for writing
	file_pointer = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\priviligies\\admin_SD.text", "w");

	// Write to the file
	fprintf(file_pointer, "admin : yes");

	// Close the file
	fclose(file_pointer);
}

void info(){

}
void MultiplicationTable(const int nr){
	int i;

	for (i = 1; i <= 10; ++i)
	{
		printf("%d * %d = %d \n", nr, i, nr*i);
		printf("*************\n");
	}

	Os();
}
void TR(){

	int opcao = 0;
	printf("Welcome\n");
	printf("TurnOFF ( 0 ) or Restart ( 2 ) Operative System?\n");
	scanf_s("%d", &opcao);
	switch (opcao){
	case 0:
	exit(0);
	case 2:
		 boot();
		break;
	default:
		printf_s("Wrong choise|| Repeat pls\n");
	}
}
	

void calc(){
	int escolha=0;
	int nr;
	int nr2;
	int soma = 0;
	int subtracao = 0;
	int dividir = 0;
	int multiplicacao = 0;
	printf("1..soma\n");
	printf("2..subtracao\n");
	printf("3..dividir\n");
	printf("4..multiplicacao\n");
	printf("5..Voltar Para o Sistem Operativo\n");
	scanf_s("%d", &escolha);
	switch (escolha){
	case 1:
		printf("primeiro numero\n");
		scanf_s("%d", &nr);
		printf("segundo numero\n");
		scanf_s("%d", &nr2);
		soma = nr + nr2;
		printf_s("total_%d\n", soma);
		printf_s("**********\n");
		calc();
		break;
	case 2:
		printf("primeiro numero\n");
		scanf_s("%d", &nr);
		printf("segundo numero\n");
		scanf_s("%d", &nr2);
		 subtracao = nr - nr2;
		 printf_s("total_%d", subtracao);
		 printf_s("**********\n");
		 calc();
	case 3:
		printf("primeiro numero\n");
		scanf_s("%d", &nr);
		printf("segundo numero\n");
		scanf_s("%d", &nr2);
		dividir = nr / nr2;
		printf_s("total_%d", dividir);
		printf_s("**********\n");
		calc();
	case 4:
		printf("primeiro numero\n");
		scanf_s("%d", &nr);
		printf("segundo numero\n");
		scanf_s("%d", &nr2);
		 multiplicacao = nr * nr2;
		 printf_s("total_%d", multiplicacao); 
		 printf_s("**********\n");
		 calc();
	case 5:
		Os();
	}

	
}

struct notepad
{
	char texto[20];

};

struct notepad vetor2[1];

void notepad(){



	int escolha = 0;
	printf("1.... abrir notepd\n");
	printf("2.... Menu Principal\n");
	scanf_s("%d", &escolha);
	switch (escolha){
	case 1:
		for (int i = 0; i < 1; i++){
			fflush(stdin);
			printf("digite algum texto: ");
			gets_s(vetor2[i].texto);
			fflush(stdin);
			printf("texto guardado:%s ", vetor2[i].texto);
			fflush(stdin);
			printf("2.... para retornar ao menu anterior\n");
			fflush(stdin);
			FILE * fp;

			char* str;
			int len = std::strlen(vetor2[i].texto);
			str = new char[len + 1];
			strcpy_s(str, len + 1, vetor2[i].texto);

			fp = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\note.txt", "w");
			fprintf(fp, "%s\n", str);


			fclose(fp);

			notepad();
			break;
			
		}
	case 2:
		Os();
		break;
	}
}
void cmd(){
	int specialNumber=0;


	printf("OSTerminal CMD\n");
	scanf_s("%d", &specialNumber);
	fflush(stdin);
	fflush(stdin);
	switch (specialNumber){
	case 1234:
		Os();
		break;
	case 12345:
		calc();
		break;
	case 123456:
		notepad();
		break;
	case 998812:
		bootAdvancedOptions();
		break;
	case 120789:
		PI();
		break;
	default:
		printf("Wrong Code or Unknow!\n");
		cmd();

	}

	

	
}
void bootAdvancedOptions(){

	int opcao = 0;
	int bootKey2 = 1234;
	printf("****ADVANCED BOOT OPTIONS***********************\n");
	printf("1....Return to Desktop\n");
	printf("2....View Boot Code\n");
	printf("3....Go to Desktop\n");
	scanf_s("%d", &opcao);
	switch (opcao){
	case 1:
		Os();
		break;
	case 2:
		printf("****BOOT INFORMANTION****\n");
		printf("Boot Key: %d\n", bootKey2);
		printf("Do Not DELETE THIS CODE!!\n");
		bootAdvancedOptions();
		break;
	case 3:
		Os();
		break;
	}
}
void PI(){
	
	printf("\nPCINFORMANTION");
	printf("\n*****************");
	FILE *fp;
	char str[MAXCHAR];
	char* filename = "C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\programLogin.txt";

	fp = fopen(filename, "r");
	if (fp == NULL){
		printf("Could not open file %s", filename);
	}
	while (fgets(str, MAXCHAR, fp) != NULL)
		printf("%s\n", str);
	fclose(fp);

	printf("\nBOOT CODE  ");

	FILE *fp2;
	char str2[MAXCHAR];
	char* filename2 = "C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\boot_KE.txt";

	fp2 = fopen(filename2, "r");
	if (fp2 == NULL){
		printf("Could not open file %s", filename2);
	}
	while (fgets(str2, MAXCHAR, fp2) != NULL)
		printf("%s\n\n//*", str2);
	fclose(fp2);
	
	Os();

}
void documents();
void FileExplorer(){

	int opcao = 0;
	printf("File Explorer\n");
	printf("1....Documents\n");
	printf("2....Go Back Desktop\n");
	scanf_s("%d", &opcao);
	switch (opcao){
	case 1:
		documents();
		break;
		FileExplorer();
	case 2:
		Os();

	}
}
struct documents
{

	char folder[20];


};

struct documents vetor8[1];
void documents(){
	int sim = 1;
	int nao = 0;
	int opcao = 0;
	printf("Documents:\n");
	printf("1....Create a new folder?/1 or 0\n");
	printf("2....View All Folders in memory\n");
	scanf_s("%d", &opcao);
	switch (opcao){
	case 1:
		for (int i = 0; i < 1; i++){
			if (opcao == sim){

				printf("\n\n\nNome do folder: ");
				fflush(stdin);
				gets_s(vetor8[i].folder);
				printf("Ficheiro criado !!\n");
				documents();
			}
			else{
				documents();
			}
		}
		break;

	case 2:
		printf("All Folders\n");
		for (int i = 0; i < 1; i++){
			printf_s("Folder:%s \n", vetor8[i].folder);
		}
		documents();
	}
}



// ********************************MAIN*************************************

char bootKey[24];
int verifyBoot = 1234;
void boot(){
	int i = 0;

	adminCheck();
	FILE *fptr2;

	fptr2 = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\boot_KE.txt", "w");
	if (fptr2 == NULL)
	{
		printf("Error!");
		exit(1);
	}

	//generate code
	int i4, n;
	time_t t;

	n = 2;

	/* Intializes random number generator */
	srand((unsigned)time(&t));

	/* Print 5 random numbers from 0 to 49 */
	for (i4 = 0; i4 < n; i4++) {

		fprintf(fptr2, "%d", rand() % 40);
	}


	fclose(fptr2);



	FILE *sync;
	char line[1024] = { 0, }; // Initialize memory! You have to do this (as for your question)
	int n2 = 0;
	int n3 = 0;
	sync = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\boot.txt", "r");
	if (sync) {
		while (fgets(line, 1024, sync) != NULL) {
			// Just search for the latest line, do nothing in the loop
		}
		printf("_>_>_ %s\n", line); //<this is just a log... you can remove it
		if (strcmp(line,"100") == 0){
			int choise = 0;
			printf_s("Boot Complete!!\n");
			//get BootKey
			int end, loop;
			int user = 1;
			char str[512];
			FILE *fd = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\boot_KE.txt", "r");
			if (fd == NULL) {
				printf("Failed to open file\n");
			}


			for (end = loop = 0; loop < user; ++loop){
				if (0 == fgets(str, sizeof(str), fd)){//include '\n'
					end = 1;//can't input (EOF)
					break;
				}
			}


			printf("Boot key please || Verify the code on the guide menu!!\n");
			gets_s(bootKey);
			int code = 22;
			int code2 = 22;

			char c[1000];
			FILE *fptr;

			int ln = strlen(str);
			if ((ln > 0) && (str[ln - 1] == '\n'))
				str[ln - 1] = '\0';

			if (strcmp(bootKey, str) == 0)
			{
				printf("*****OS Terminal*************************\n");
				printf("1*******************for create an account\n");
				printf("2*********Begin Terminal Operative System(Specializes Only)\n");
				printf("3*********Login\n");
				printf("*****************************************\n");
				printf("-->");
				scanf_s("%d", &choise);
				switch (choise){
				default:
					printf("Wrong code try again\n");
					boot();
				case 1:
					login();
					break;
				case 2:
					printf("Digite o codigo especial");
					scanf_s("%d", &code);
					if (code == code2){
						Os();
					}
					else{
						printf_s("Developers Only!!");
					}
					boot();
					break;

				case 3:
					LogUser();
					break;
				}


				fflush(stdin);
				getchar();
			}
			else{
				printf_s("Wrong boot key || or missing boot key\n");
				fflush(stdin);
				boot();
			}
		}else{
			printf_s("boot error\n");
			getchar();
		}
		fclose(sync);
	
	
	}


}


void adminCheck(){

	FILE *fp;
	char str[MAXCHAR];
	char* filename = "C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\priviligies\\admin_SD.text";

	fp = fopen(filename, "r");
	if (fp == NULL){
		printf("Could not open file %s", filename);
	}
	while (fgets(str, MAXCHAR, fp) != NULL)
		printf("%s", str);
	fclose(fp);
	

		int ln = strlen(str);
		if ((ln > 0) && (str[ln - 1] == '\n'))
			str[ln - 1] = '\0';

		if (strcmp(str, "admin : yes") == 0)
		{
			system("@cls||clear");
			Os();
		}
		else if (strcmp(str, "admin : no") == 0){
			LogUser();
		}
	
}
void LogUser(){

	for (int i = 0; i < 1; i++){


		int end, loop;
		int user = 1;
		char str[512];
		FILE *fd = fopen("C:\\Users\\Utilizador\\Documents\\Visual Studio 2013\\Projects\\Projecto em C\\OSTerminal\\data.txt", "r");
		if (fd == NULL) {
			printf("Failed to open file\n");
		}


		for (end = loop = 0; loop < user; ++loop){
			if (0 == fgets(str, sizeof(str), fd)){//include '\n'
				end = 1;//can't input (EOF)
				break;
			}
		}


		int end2, loop2;
		int pass = 1;
		char str2[512];

		for (end2 = loop2 = 0; loop2 < pass; ++loop2){
			if (0 == fgets(str2, sizeof(str2), fd)){//include '\n'
				end2 = 1;//can't input (EOF)
				break;
			}
		}

		if (!end && !end2){

			fflush(stdin);
			printf("username:");
			gets_s(vetor[i].username);
			fflush(stdin);
			printf("password:");
			gets_s(vetor[i].password);

			int ln = strlen(str);
			if ((ln > 0) && (str[ln - 1] == '\n'))
				str[ln - 1] = '\0';

			int ln2 = strlen(str2);
			if ((ln2 > 0) && (str2[ln2 - 1] == '\n'))
				str2[ln2 - 1] = '\0';


			if (strcmp(vetor[i].username, str) == 0 && strcmp(vetor[i].password, str2) == 0)
			{
				system("@cls||clear");
				Os();
			}
			else{
				printf_s("wrong || invalid login , try again\n");
				LogUser();
			}
			fclose(fd);
		}

	}

}
int main(){
	
	boot();


	
}