#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//prompt user for inpute string type
int main(void) 
{
    string sentence = get_string("Text: ");

    //get count of letters, words, and sentences.
    int letters = 0;
    int words = 1;
    int sentences = 0;
    for (int i = 0, n = strlen(sentence); i < n; i++)
    {   
        //add to letters if the element is a letter
        if (isalpha(sentence[i]))
        {
            letters++;
        }
        
        //add to words if the element is a space 
        else if (isspace(sentence[i]))
        {
            words++;
        }
        
        //add to sentences if the element is an !, ? or .
        else if (sentence[i] == '!' || sentence[i] == '.' || sentence[i] == '?')
        {
            sentences++;
        }

    }

    //output grade x
    double l = (float)letters / (float)words * 100;
    double s = (float)sentences / (float)words * 100;
    double index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);
    
    //print before greade 1 if equation is less than 1
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    //print grade 16+ if the equetion is more then 16
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    //print grade and grade number
    else
    {
        printf("Grade %i\n", grade);
    }

}