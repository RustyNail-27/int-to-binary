#include <stdio.h>
#include <stdlib.h>

void binary(int input);
int setBit(int target, int input);
int getByte(int target, int input);
void printMenu();

int binaryNum[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int main()
{
	int input;
	int i = 1;
	char menuOption = 'x';
	
	while(menuOption != 'D' || menuOption != 'd')
	{
	printMenu();
	
	while(menuOption != 'A' && menuOption != 'a' 
	&& menuOption != 'B' && menuOption != 'b'
	&& menuOption != 'C' && menuOption != 'c'
	&& menuOption != 'D' && menuOption != 'd')
	{
		puts("\nEnter a menu option:");
		scanf("%c", &menuOption);
	}
	
	if(menuOption == 'A' || menuOption == 'a')
	{
		puts("Enter an integer: ");
		scanf("%d", &input);
	
		binary(input);
		
		menuOption = 'x';
	}
	else if(menuOption == 'B' || menuOption == 'b')
	{
		char comma;
		int target, num1, result;
		
		puts("Enter target bit, and integer value: ");
		scanf("%d%c%d", &target, &comma, &num1);
		
		result = setBit(target, num1);
		
		printf("The new value of the int is: %d\n", result);
		
		binary(result);
		
		menuOption = 'x';
	}
	else if(menuOption == 'C' || menuOption == 'c')
	{
		
		char comma2;
		int target2, num2, byteResult;
		
		puts("Enter target byte (1-4), and integer value: ");
		scanf("%d%c%d", &target2, &comma2, &num2);
		
		binary(num2);
		
		byteResult = getByte(target2, num2);
		
		printf("The value of the byte is: %d\n", byteResult);
		
		binary(byteResult);
		
		menuOption = 'x';
	}
	else
	{
		return 0;
	}
	}
	return 0;
}

void binary(int input)
{
	int i = 32;
	int quotient = input;
	
	while (quotient != 0)
	{
		binaryNum[i] = quotient % 2;
		quotient = quotient / 2;
		i--;
	}
	
	puts("Binary representation: ");
	
	i = 0;
	
	while(i <= 32)
	{
		printf("%d", binaryNum[i]);
		binaryNum[i] = 0;
		i++;
	}
	puts("\n");
}

int setBit(int target, int input)
{
	int i = 1;
	int mask = (i << (target-1));
	int output;
	
	output = input | mask;
	
	return output;	
}

int getByte(int target, int input)
{
	int mask, output;
	
	if(target == 1)
		mask = 0xFF;
	else if(target == 2)
		mask = 0xFF00;
	else if(target == 3)
		mask = 0xFF0000;
	else
		mask = 0xFF000000;
	
	output = input & mask;
	
	return output;
}

void printMenu()
{
	puts("\n");
	puts("** MENU OPTIONS **");
	puts("A) Display binary of passed integer");
	puts("B) Set the target bit of an input integer to 1 and return value");
	puts("C) Extract a byte from an input integer, with the value of that byte");
	puts("D) Exit");
}
