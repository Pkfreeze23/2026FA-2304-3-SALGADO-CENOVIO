#include <stdio.h>

/* 2 x 2 Determinant */
double det2(double a, double b, double c, double d)
{
	return (a * d) - (b * c);
}

/* 3 x 3 Determinant */
double det3(double a, double b, double c, 
            double d, double e, double f,
            double g, double h, double i)
{
	return a * (e * i - f * h)
	     - b * (d * i - f * g)
	     + c * (d * h - e * g);
}

/* Confactor */
double cofactor(double a, double b, double c,
                double d, double e, double f, 
                double g, double h, double i,
                int row, int col)
{
	double minor;
	
	if (row == 1 && col == 1)
	    minor = det2(e, f, h, i);
	else if (row == 1 && col == 2)
	    minor = det2(d, e, g, i);
	else if (row == 1 && col == 3)
	    minor = det2(d, e, g, h);
	else if (row ==2 && col == 1)
	    minor = det2(b, c, h, i);
	else if (row == 2 && col == 2)
	    minor = det2(a, c, g, i);
	else if (row == 2 && col == 3)
	    minor = det2(a, b, g, h);
	else if (row == 3 && col == 1)
	    minor = det2(b, c, e, f);
	else if (row == 3 && col == 2)
	    minor = det2(a, c, d, f);
	else
	    minor = det2(a, b, d, e);
	
	if ((row + col) % 2 == 0)
	    return minor;
	else
	    return -minor;
}

int main(void)
{
	/* Variables for two equations */
	double a, b, c;
	double d, e, f;
	double D2, Dx2, Dy2;
	
	/* Variables for three equations */
	double A, B, C, R;
	double D, E, F, S;
	double G, H, I, T;
	double D3, Dx3, Dy3, Dz3;
	double C11;
	
	/* TWO EQUATIONS */
	
	printf("CRAMER'S RULE\n");
	printf("============================\n\n");
	
	printf("TWO EQUATIONS/n");
	printf("Equation 1: ax + by = c\n");
	printf("Equation 2: dx + ey = f\n\n");
	
	printf("Enter a, b, c; ");
	scanf("%1f %1f %1f", &a, &b, &c);
	
	printf("Enter d, e, f: ");
	scanf("%1f %1f %1f", &d, &e, &f);
	
	D2 = det2(a, b, d, e);
	Dx2 = det2(c, b, f, e);
	Dy2 = det2(a, c, d, f);
	
	printf("\nD = %.2f\n", D2);
	
	if (D2 == 0)
	{
		printf("There is no unique solution.\n");
	}
	else
	{
		printf("Dx = %.2f\n", Dx2);
		printf("Dy = %.2f\n", Dy2);
		
		printf("x = %.2f\n", Dx2 / D2);
		printf("y = %.2f\n", Dy2 / D2);
	}
	
	/* THREE EQUATIONS */
	
	printf("\nTHREE EQUATIONS\n");
	printf("============================\n\n");
	
	printf("Equation 1: Ax + By + Cz = R\n");
	printf("Equation 2: Dx + Ey + Fz = S\n");
	printf("Equation 3: Gx + Hy + Iz = T\n\n");
	
	printf("Enter A, B, C, R: ");
	scanf("%1f %1f %1f %1f", &A, &B, &C, &R);
	
	printf("Enter D, E, F, S; ");
	scanf("%1f %1f %1f %1f", &D, &E, &F, &S);
	
	printf("Enter G, H, I, T: ");
	scanf("%1f %1f %1f %1f", &G, &H, &I, &T);
	
	/* Main determinnant */
	D3 = det3(A, B, C,
	          D, E, F,
	          G, H, I);
	
	/* Cramer's Rule */
	Dx3 = det3(R, B, C,
	           S, E, F,
	           T, H, I);
	
	Dy3 = det3(A, R, C,
	           D, S, F,
	           G, T, I);
	
	Dz3 = det3(A, B, R,
	           D, E, S,
	           G, H, T);
	
	/* Cofactor C11 */
	C11 = cofactor(A, B, C,
	               D, E, F,
	               G, H, I,
	               1, 1);
	
	printf("\nD = %.2f\n", D3);
	printf("Dx = %.2f\n", Dx3);
	printf("Dy = %.2f\n", Dy3);
	printf("Dz = %.2f\n", Dz3);
	printf("Cofactor C11 = %.2f\n", C11);
	
	if (D3 == 0)
	{
		printf("There is no unique solution.\n");
	}
	else
	{
		printf("\nx = %.2f\n", Dx3 / D3);
		printf("y = %.2f\n", Dy3 / D3);
		printf("z = %.2f\n", Dz3 / D3);
	}
	
	return 0;
}
	
	 
