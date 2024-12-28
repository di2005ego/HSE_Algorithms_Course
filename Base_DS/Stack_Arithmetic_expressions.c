#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

bool digit(char element) {
	if (element != '+' && element != '-' && element != '*' && element != '/' && element != '(' && element != ')') {
		return true;
	}
	else {
		return false;
	}
}

bool operator(char element) {
	if (element == '+' || element == '-' || element == '*' || element == '/') {
		return true;
	}
	else {
		return false;
	}
}

unsigned priority(char element) {
	if (element == '+' || element == '-') {
		return 1;
	}
	if (element == '*' || element == '/') {
		return 2;
	}
	if (element != '+' && element != '-' && element != '*' && element != '/') {
		return 0;
	}
}

int main() {
	char expr[100];
	scanf("%s", expr);
	unsigned capacity = strlen(expr);
	expr[capacity] = '\0';
	printf("Expression:\n%s\n", expr);
	unsigned i = 0;
	unsigned j = 0;
	int top = -1;
	char rpn[200];
	char stack[100];
	for (i = 0; i < capacity; i++) {
		if (digit(expr[i])) {
			rpn[j] = expr[i];
			j++;
			if (!digit(expr[i + 1]))
			{
				rpn[j] = ' ';
				j++;
			}
		}
		if (operator(expr[i])) {
			while (top >= 0 && (priority(stack[top])) >= priority(expr[i])) {
				rpn[j] = stack[top];
				j++;
				top--;
			}
			top++;
			stack[top] = expr[i];
		}
		if (expr[i] == '(') {
			top++;
			stack[top] = '(';
		}
		if (expr[i] == ')') {
			while (top >= 0 && stack[top] != '(') {
				rpn[j] = stack[top];
				top--;
				j++;
			}
			top--;
		}
	}
	if (digit(rpn[j - 1])) {
		rpn[j] = ' ';
		j++;
	}
	while (top >= 0) {
		rpn[j] = stack[top];
		j++;
		top--;
	}
	rpn[j] = '\0';
	printf("Reverse Polish Notation:\n");
	for (int k = 0; k < j; k++) {
		if (operator(rpn[k])) {
			printf("%c ", rpn[k]);
		}
		else {
			printf("%c", rpn[k]);
		}
	}
	printf("\n");
	int len = strlen(rpn);
	long res[100];
	top = -1;
	for (int i = 0; i < len; i++) {
		if (digit(rpn[i])) {
			char extra[10];
			int index = 0;
			for (int ii = i; ii < len; ii++) {
				if (rpn[ii] == ' ') {
					extra[index] = '\0';
					break;
				}
				extra[index] = rpn[ii];
				index++;
				i++;
			}
			int copy = atoi(extra);
			top++;
			res[top] = copy;
		}
		if (operator(rpn[i])) {
			int operand_2 = res[top];
			top--;
			int operand_1 = res[top];
			top--;
			switch (rpn[i]) {
			case '+':
				top++;
				res[top] = operand_1 + operand_2;
				break;
			case '-':
				top++;
				res[top] = operand_1 - operand_2;
				break;
			case '*':
				top++;
				res[top] = operand_1 * operand_2;
				break;
			case '/':
				top++;
				res[top] = operand_1 / operand_2;
				break;
			}
		}
	}
	printf("Result:\n%ld", res[top]);
	return 0;
}