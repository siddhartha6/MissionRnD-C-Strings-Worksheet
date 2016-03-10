/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
char KthIndexFromEnd(char *str, int K) {
	if (str == NULL || K < 0 || str[0] == '\0')       //checking invalid inputs
		return '\0';
	int len = 0;
	for (len = 0; str[len] != 0; len++) {

		if (str[len + 1] != '\0')                  //finding length of string by skipping few iterations
			len = len + 1;
	}
	return str[len - K - 1];	//returning resultant character
}