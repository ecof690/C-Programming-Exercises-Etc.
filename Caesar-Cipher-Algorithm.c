//Caesar Cipher Algorithm.


#include <stdio.h>
#include <ctype.h>//To use "toupper" function.

//Function prototypes, 
int mainmenu();//Demonstrates menu to the user and take user choice, returns main function.
void receiver(char sen[]);//Takes sentence from user and returns main function.
void check(char checker[]);//Checks and fixes sentence.
void encryptor(char sen[], char result[], int key);//Encrypts sentence with given key.
void decoder(char sen[], char result[], int key);//Decodes sentence with given key.

int main() {

	int choice, key = 0;
	char main_sen[100], result[100];

	printf("////---  Welcome to Caesar Cipher !  ---\\\\\\\\ \n\n\n\n");

	choice = mainmenu();

	while (choice != 3) {
		switch (choice) {
		case 1:
			getchar();//To prevent fget bug on subsidiary functions.
			receiver(main_sen);
			check(main_sen);
			printf("Input your key number (between 1-25):");
			scanf_s("%d", &key);
			encryptor(main_sen, result, key);
			printf("Your encrypted message is = %s\n\n", result);
			break;
		case 2:
			getchar();//To prevent fget bug on subsidiary functions.
			receiver(main_sen);
			check(main_sen);
			printf("Input your key number (between 1-25):");
			scanf_s("%d", &key);
			decoder(main_sen, result, key);
			printf("Your decoded message is = %s\n\n", result);
			break;
		}//End of switch-case statement.

		if (choice != 1 && choice != 2 && choice != 3)
			printf("Your choice is wrong. Please input your choice using ONLY numbers.\n\n");

		choice = mainmenu();
	}//End of while-loop.

	printf("\n\nBye !\n");
	return 0;
}//End of main-function.

int mainmenu() {
	int choice;

	printf("Please select your choice from list (Input only choice number.):\n");
	printf("1. Encrypt your message.\n");
	printf("2. Decode your message.\n");
	printf("3. Exit program.\n");
	printf("Your choice =");
	scanf_s("%d", &choice);

	return choice;
}//End of mainmenu func.

void receiver(char sen[]) {

	printf("Input your message (Up to 100 character.):");
	fgets(sen, 100, stdin);

}//End of receiver func.

void check(char checker[]) {

	int i = 0;
	while (checker[i]) {
		checker[i] = toupper(checker[i]);
		i++;
	}

}//End of check func.

void encryptor(char sen[], char result[], int key) {
	int i = 0, j = 0, sum;

	while (sen[i]) {
		//65-> A and 90 -> Z from ASCII Table.
		if (sen[i] >= 65 && sen[i] <= 90) {//First if condition checks symbol, number etc. in sentence.
			if ((sen[i] + key) > 90) {
				sum = 64 + ((sen[i] + key) - 90);//64 to count first term which is A.
				result[j] = (char)sum;
				j++;
			}
			else {
				sum = sen[i] + key;
				result[j] = (char)sum;
				j++;
			}
		}
		else {
			result[j] = sen[i];
			j++;
		}

		i++;
	}

	result[j] = '\0';
}//End of encryptor func.

void decoder(char sen[], char result[], int key) {
	int i = 0, j = 0,sum;

	while (sen[i]) {
		//65-> A and 90 -> Z from ASCII Table.
		if (sen[i] >= 65 && sen[i] <= 90) {//First if condition checks symbol, number etc. in sentence.
			if ((sen[i] - key) < 65) {
				sum = 91 - (65-(sen[i] - key));//91 to count last term which is Z.
				result[j] = (char)sum;
				j++;
			}
			else {
				sum = sen[i] - key;
				result[j] = (char)sum;
				j++;
			}
		}
		else {
			result[j] = sen[i];
			j++;
		}

		i++;
	}

	result[j] = '\0';
}//End of decoder func.
