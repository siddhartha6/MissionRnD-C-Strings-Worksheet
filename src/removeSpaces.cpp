/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
char removeSpaces(char *str) {

	if (str == NULL)
		return '\0';                  //invalid input

	int result = 0, index=0;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] != ' ')
		{
			str[result] = str[index];          //if no space shift characters
			result++;
		}                                      
		                                     //if space continue the index
	}
	str[result] = '\0';
	return *str;
}