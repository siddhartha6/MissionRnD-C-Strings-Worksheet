/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_char_rev(char* input, int len);

void str_char_rev(char* input, int len)
{
	int index1=0, index2=0;
	char temp;

	index2 = len - 1;
	for (index1 = 0; index1<index2; index1++, index2--){
                                                   //reversing the string by swapping positions
		temp = input[index1];
		input[index1] = input[index2];
		input[index2] = temp;
	}
}
void str_words_in_rev(char *input, int len){

	int index1 = 0, index2 = 0;

	str_char_rev(input, len);              //reversing the string characters

	for (index1 = 0; index1 <= len; index1++){

		if (input[index1] == ' ' || input[index1] == '\0'){

			str_char_rev(input + index2, index1 - index2); //reversing the reversed characters
			index2 = index1 + 1;
		}
	}
	
}
