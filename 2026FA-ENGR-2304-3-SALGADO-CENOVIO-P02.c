#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void decimalToBinary(int n)
{
	int i, magnitude;
	
	if (n < -127 || n > 127) {
		printf("Number must be between -127 and 127.\n");
		return;
	}
	
	if (n < 0) {
		printf("1");
		magnitude = -n;
	} else {
		printf("0");
		magnitude = n;
	}
	
	for (i = 6; i >= 0; i--)
	    printf("%d", (magnitude >> i) & 1);
	
	printf("\n");
}

void binaryToDecimal(char *b)
{
	int i, value = 0, sign;
	
	sign = b[0] - '0';
	
	for (i = 1; b[i] != '\0'; i++) {
		if (b[i] != '0' && b[i] != '1') {
			printf("Invalid binary number.\n");
			return;
		}
		value = value * 2 + (b[i] - '0');
	}
	
	if (value > 127) {
		printf("Number is outside the allowed range.\n");
		return;
	}
	
	if (sign == 1)
	   value = -value;
	
	printf("Decimal = %d\n", value);
}

void hexToBinary(char *hex)
{
	int i, j;
	char *digits = hex + 2;
	
	for (i = 0; digits[i] != '\0'; i++) {
		if (digits[i] == '.') {
			printf('.');
			continue;
		}
		
		switch (toupper(digits[i])) {
			case '0': printf("0000"); break;
			case '1': printf("0001"); break;
			case '2': printf("0010"); break;
			case '3': printf("0011"); break;
			case '4': printf("0100"); break;
			case '5': printf("0101"); break;
			case '6': printf("0110"); break;
			case '7': printf("0111"); break;
			case '8': printf("1000"); break;
			case '9': printf("1001"); break;
			case 'A': printf("1010"); break;
			case 'B': printf("1011"); break;
			case 'C': printf("1100"); break;
			case 'D': printf("1101"); break;
			case 'E': printf("1110"); break;
			case 'F': printf("1111"); break;
			default:
			    printf("\nInvalid hexadecimal number.\n");
			    return;
		}
	}
	printf("\n");
}

void binaryToHex(char *bin)
{
	int i, count = 0;
	char group[5];
	
	for (i = 0; bin[i] != '\0'; i++) {
		if (bin[i] == '.') {
			printf(".");
			count= 0;
			continue;
		}
		
		if (bin[i] != '0' && bin[i] != '1') {
			printf("\nInvalid binary number.\n");
			return;
		}
		
		group[count++] = bin[i];
		
		if (count == 4) {
			group[4] = '\0';
			
			if (!strcmp(group, "0000")) printf("0");
			else if (!strcmp(group, "0001")) printf("1");
			else if (!strcmp(group, "0010")) printf("2");
			else if (!strcmp(group, "0011")) printf("3");
			else if (!strcmp(group, "0100")) printf("4");
			else if (!strcmp(group, "0101")) printf("5");
			else if (!strcmp(group, "0110")) printf("6");
			else if (!strcmp(group, "0111")) printf("7");
			else if (!strcmp(group, "1000")) printf("8");
			else if (!strcmp(group, "1001")) printf("9");
			else if (!strcmp(group, "1010")) printf("A");
			else if (!strcmp(group, "1011")) printf("B");
			else if (!strcmp(group, "1100")) printf("C");
			else if (!strcmp(group, "1101")) printf("D");
			else if (!strcmp(group, "1110")) printf("E");
			else if (!strcmp(group, "1111")) printf("F");
			
			count = 0;
		}
	}
	
	printf("\n");
}

int main()
{
	int choice, decimal;
	char input[100];
	
	while (1) {
		printf("\n===== NUMBER CONVERSION MENU =====\n");
		printf("1. Decimal to Binary\n");
		printf("2. Binary to Decimal\n");
		printf("3. Hex to Binary\n");
		printf("4. Binary to Hex\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		if (choice == 5)
		    break;
		
		switch (choice) {
			case 1:
			    printf("Enter decimal number (-127 to 127): ");
			    scanf("%d", &decimal);
			    printf("8-bit signed magnitude = ");
			    decimalToBinary(decimal);
			    break;
			
			case 2:
			    printf("Enter 8-bit signed magnitude binary: ");
			    scanf("%s", input);
			    binaryToDecimal(input);
			    break;
			
			case 3:
			    printf("Enter hexadecimal number beginning with 0x: ");
			    scanf("%s", input);
			    binaryToHex(input);
			    break;
			
			default:
			    printf("Invalid choice.\n");
		}
	}
	
	printf("Program ended.\n");
	return 0;
}