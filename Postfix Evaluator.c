//Postfix Evaluator
//Usage example   : 2 3 4 5 * - +
//Usage example-2 : 5 4 * 3 2 + -


#include <stdio.h>

#define MAX 100
#define isOperator(op) (op=='+'||op=='*'||op=='/'||op=='-')
int holder[MAX], top = 0;

int applyOperator(int num1, int num2, char oprt) {
	switch (oprt) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	}
}//End of applyOperator-func.


void push(int num) {
	holder[++top] = num;
}//End of push-func.


int pop() {
	int num;
	num = holder[top];
	top--;
	return num;
}//End of pop-func.


int main() {

	char input_data[MAX];
	int i = 0, temp, temp2, res;

	printf("Input data : ");
	fgets(input_data, MAX, stdin);

	/*
	While you are getting data from user, you should check whether is it compatible with your desired or not.
	In this code, because of demonstrate a basic algorithm, there is no check statements "isAlpha" etc.
	Also fgets will not stop when it encounters a NUL, be carefull when you use it to take data from user.
	*/


	while (input_data[i] != NULL) {
		if (isdigit(input_data[i])) {
			temp = (input_data[i] - '0');
			while (isdigit(input_data[++i])) {
				temp *= 10;
				temp += (input_data[i] - '0');
			}
			push(temp);
			//printf("push %d \n", temp); //This line for DEBUG purpose. To see what you've pushed your order.
		}
		else if (isOperator(input_data[i])) {
			temp = pop();
			temp2 = pop();
			res = applyOperator(temp2, temp, input_data[i]);
			push(res);
			//printf("%d --- %d\n", i, res); //This line for DEBUG purpose.
		}//End of if-statement.
		i++;
	}//End of while-loop.

	res = pop();
	printf("Evaluated : %d \n\n", res);

	return 0;
}//End of main-func.