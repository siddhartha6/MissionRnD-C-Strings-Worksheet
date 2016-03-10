/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int pow(int afterdecimal);
void reverse_String(char *str, int len);
int integer_to_str(int intNumber, char *str, int afterdecimal);

int pow(int afterdecimal){

	int result = 1, index = 0;
	for (index = 0; index<afterdecimal; index++)         // to find power upto given afterdecimal value
		result *= 10;
	return result;
}

void reverse_String(char *str, int len){

	int index1 = 0, index2 = len - 1, temp = 0;
	while (index1<index2){                  //reverse of string
		temp = str[index1];
		str[index1] = str[index2];
		str[index2] = temp;
		index1++;
		index2--;
	}
}

int integer_to_str(int intNumber, char *str, int afterdecimal,int count)
{
	int index = 0,temp=intNumber;

	if (intNumber<0)
		intNumber *= -1;

	while (intNumber != 0){
		str[index++] = (intNumber % 10) + '0';   //converting integer digit to string
		intNumber = intNumber / 10;
	}
	while (index < afterdecimal)
		str[index++] = '0';

	if (temp<0 && count == 1)
		str[index++] = '-';           //negative number assignment

	reverse_String(str, index);
	str[index] = '\0';

	return index;
}

void number_to_str(float number, char *str, int afterdecimal){

	int intNumber = (int)number;                //converting float to int
	float point = number - (float)intNumber;    //storing after decimal point values

	int index = integer_to_str(intNumber, str, 0,1); //converting integer to string

	if (afterdecimal != 0)          
	{
		str[index] = '.';
		point = point * pow(afterdecimal);
		integer_to_str((int)point, str + index + 1, afterdecimal,2); //from next to dot location converting int to string
	}
}
