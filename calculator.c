#include <stdio.h>
#include <math.h>

//now is on github

void addition() {
	int a,b,result = 0;
	printf("===Addition==\n=");
	printf("First number: ");
	scanf("%d", &a);
	printf("Second number: ");
	scanf("%d", &b);
	result = a + b;
	printf("%d + %d = %d\n",a,b,result);
}
void subtraction() {
	int a,b,result = 0;
	printf("===Substraction===\n");
	printf("First number: ");
	scanf("%d", &a);
	printf("Second Number: ");
	scanf("%d", &b);
	result = a - b;
	printf("%d - %d = %d\n",a,b,result);
}
void multiplication() {
	int a,b,result = 0;
	printf("===Multiplication===\n");
	printf("First number: ");
	scanf("%d", &a);
	printf("Second number: ");
	scanf("%d", &b);
	result = a * b;
	printf("%d * %d = %d\n",a,b,result);
}
void division() {
	float a,b,result = 0;
	printf("===Division===\n");
	printf("First number: ");
	scanf("%f", &a);
	printf("Second number: ");
	scanf("%f", &b);
	if (b ==0) {
		printf("Cannot be divided by 0\nPlease try again\n");
	}
	else {
		result = a / b;
		printf("%.2f / %.2f = %.2f\n",a,b,result);

	}
}
void squareroot() {
	int a = 0;
	float result = 0;
	printf("===Square Root===\n");
	printf("Number: ");
	scanf("%d", &a);
	if (a <= 0) {
		printf("Invalid number\n");
	} else {
		result = sqrt(a);
		printf("Square root of %d = %.2f\n",a,result);
	}
}
void math_remainder() {
	int a,b,result = 0;
	printf("===Remainder===\n");
	printf("First number: ");
	scanf("%d", &a);
	printf("Second number: ");
	scanf("%d", &b);
	result = a % b;
	printf("%d %% %d, the remainder is %d\n",a,b,result);
}
void hypotenuse() {
	float a,b,result,a2,b2 = 0;
	printf("===Hypotenuse===\n");
	printf("First number: ");
	scanf("%f", &a);
	printf("Second number: ");
	scanf("%f", &b);
	a2 = a*a;
	b2 = b*b;
	result = sqrt(a2+b2);
	//using unicode escape sequence
	printf("\u221A(%.2f\u00B2 + %.2f\u00B2) = %.2f\n",a,b,result);
}

int main() {

	int operation, decision = 0;

	printf("===User calculator===\n");
	for (int i = 0; i != 100; i++) {

		printf("Select one operation: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5.Square Root\n6.Remainder\n7.Hypotenuse\nOperation: ");
			scanf("%d", &operation);
			switch (operation) {
				case 1:
					addition();
					break;
				case 2:
					subtraction();
					break;
				case 3:
					multiplication();
					break;
				case 4:
					division();
					break;
				case 5:
					squareroot();
					break;
				case 6:
					math_remainder();
					break;
				case 7:
					hypotenuse();
					break;

				}
		printf("To continue, press 1\nTo stop, press 2\n");
		scanf("%d", &decision);
		if (decision == 2) {
			i = 100;
			break;
		}
	}
	printf("Program Ended\n");

	return 0;
}
