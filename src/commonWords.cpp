/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31
char ** commonWords(char *str1, char *str2) {
	
	if (str1 == NULL || str2 == NULL)
		return NULL;                         //if any of the strings are empty

	int temp1[31][2], temp2[31][2];

	int index1 = 0, index2 = 0, str1_noWords = 0, str2_noWords = 0, len_word = 0;
	int m = 0, n = 0, r = 0, p = 0,count=0;

	temp1[0][0] = 0;
	temp2[0][0] = 0;

		char **words = (char **)malloc(SIZE * sizeof(char *));

		for (index1 = 0; index1 < SIZE; index1++)
			words[index1] = (char *)malloc(30 * sizeof(char *));
		
		//this for loop is to find and store each starting index and word length of str1
		for (index1 = 0; str1[index1] != '\0'; index1++)
		{
			if (str1[index1] == ' ')
			{                              //temp1[][0] stores word starting index
				str1_noWords++;
				len_word = 0;
				temp1[str1_noWords][0] = index1 + 1;
			}
			if (str1[index1] != ' '){                      //temp1[][1] stores length of word
				temp1[str1_noWords][1] = ++len_word;
			}
		}

		len_word = 0;

		//this for loop is to find and store each starting index and word length of str1
		for (index1 = 0; str2[index1] != '\0'; index1++)
		{
			if (str2[index1] == ' ')
			{                                //temp2[][0] stores word starting index
				str2_noWords++;
				len_word = 0;
				temp2[str2_noWords][0] = index1 + 1;
			}
			if (str2[index1] != ' ')                 //temp2[][1] stores length of word
				temp2[str2_noWords][1] = ++len_word;
		}

		for (index1 = 0; index1 <= str1_noWords; index1++)
		{
			for (index2 = 0; index2 <= str2_noWords; index2++)
			{
				m = temp1[index1][0];
				n = temp2[index2][0];

				if (str1[m] == str2[n])           //if starting index positions are equal proceed further
				{
					if (temp1[index1][1] == temp2[index2][1]) //checking if both the words length are equal or not 
					{
						for (p = 0; p < temp1[index1][1]; p++)
						{
							if (str1[m] == str2[n])            //comparing each word and storing character by character
							{
								words[r][p] = str1[m];
								m++;
								n++;
							}
							else
								break;
						}
						words[r][p] = '\0';
						if (p == (temp1[index1][1])){   
							++r;                          //incrementing the r value to store next common word
							count = 1;      //maintaining count to know whether their are common words or not
						}
					}
				}
			}
		}
		if (count == 0)
			return NULL;             //if their are no common words or spaces in any one of strings then returning NULL
		return words;
	
}
