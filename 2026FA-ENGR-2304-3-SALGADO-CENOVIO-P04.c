#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	int Vs, R1, R2, R3;
	double Rt, I, V1, V2, V3;
	double userI, userV1, userV2, userV3;
	char choice;
	
	srand(time(NULL));
	
	do
	{
		/* Generate random values */
		Vs = (rand() % 9) + 1;
		R1 = (rand() % 19) + 1;
		R2 = (rand() % 19) + 1;
		R3 = (rand() % 19) + 1;
		
		/* Calculate answers */
		Rt = R1 + R2 + R3;
		
		I = Vs / Rt;
		
		V1 = I * R1;
		V2 = I * R2;
		V3 = I * R3;
		
		/* Display problem */
		printf("\n==============================\n");
		printf("     CIRCUIT PROBLEM\n");
		printf("==============================\n");
		
		printf("Vs = %d V\n", Vs);
		printf("R1 = %d ohms\n", R1);
		printf("R2 = %d ohms\n", R2);
		printf("R3 = %d ohms\n", R3);
		
		printf("\nEneter your answers:\n");
		
		printf("Current I = ");
		scanf("%1f", &userI);
		
		printf("Voltage V1 = ");
		scanf("%1f", &userV1);
		
		printf("Voltage V2 = ");
		scanf("%1f", &userV2);
		
		printf("Voltage V3 = ");
		scanf("%1f", &userV3);
		
		/* Check answers */
		if (fabs(userI - I) <= 0.001 &&
		    fabs(userV1 - V1) <= 0.001 &&
		    fabs(userV2 - V2) <= 0.001 &&
		    fabs(userV3 - V3) <= 0.001)
		{
			printf("\nSUCCESS! A11 answers are correct.\n");
		}
		else
		{
			printf("\nFAILURE! Some answers are incorrect.\n");
			
			printf("\nCorrect answers:\n");
			printf("I = %.3f A\n", I);
			printf("V1 = %.3f V\n", V1);
			printf("V2 = %.3f V\n", V2);
			printf("V3 = %.3f V\n", V3);
		}
		
		printf("\nEnter R to restart or E to exit: ");
		scanf(" %c", &choice);
		
	} while (choice != 'E' && choice != 'e');
	
	printf("\nProgram ended.\n");
	
	return 0;
}
   
		
		