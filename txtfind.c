//
// Created by omerm on 31/12/2020.
//


#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
#define LINES 250


// This function need to check if str contain word

int substring (char *str1, char *str2)
{
    int i=0;

    while (*str1!='\0')
    {
        if (*str1 == *(str2+i))
        { //check if the char  is equals
            i++;
            if (strlen(str2)==i)
                return 1; //return true
        }
        else
            i=0;

        str1++;
    }
    return 0; // return false

}




// This functin check if the word similiar until num of change to str
int similar (char *s, char *t, int n)
{
    // check the size of wors, if it's bigger return false
    if (strlen(s)>strlen(t)+n)
        return 0;
     int j=-1;// num of mistake
    int i=0;
   

    int m =0;
    while (*(s+m)!='\0')
    {
        //check cahe equal
        if (*s == *(t+i))
        {
            i++;
            // if i is equal to size of word return true
            if (i==strlen(t))
                return 1;
        }

        else // if the char is not equals
        {
            j++; // num of mistake increase 1
            if (j==n)
            {
                j=0;
                i=0;
              
            }

        }
        // m++;
        s++; // pointers ++
    }

    return 0;
}

//*************************************

int getLine(char s[])
{
    int SizeLine = 0;
    char letter = getchar();

    while(letter=='\n')  //remove the spare whitelines in the begening of the file.
        letter = getchar();

    if(letter==EOF) //if the input is empty.
        return 0;

    while((letter != EOF) &&(letter != '\n') && (SizeLine < LINE))
    {
        s[SizeLine]=letter;
        SizeLine++;
        letter = getchar();
    }
    s[SizeLine]='\0'; // end of the srtring;

    return SizeLine;

}

//*********************************************************
//function to put a a word in w
int getWord(char w[])
{
  int SizeWord = 0;
	char letter = getchar();

	while((letter != EOF)&&(letter != ' ') &&(letter != '\t')&&(letter != '\n') && (SizeWord < WORD))
	{
		w[SizeWord]=letter;
		SizeWord++;
		letter = getchar();
	}



	w[SizeWord]='\0'; // end of the srtring;


	return SizeWord;

}

//*****************************************************


void print_lines(char * str)
{
    char line[LINE];
    int SizeLine = getLine(line);

    while(SizeLine != 0)
    {
        if(substring(line, str)==1)
            printf("%s\n", line);

        SizeLine = getLine(line); //line.next();
    }

}

//*****************************************************

void print_similar_words(char * str)
{
    char word[WORD];
//    int SizeWord = getWord(word);


    while(getWord(word) != 0)
    {

        if(similar(word, str,1)==1)
            printf("%s\n", word); //check it


//        SizeWord = getWord(word); //word.next();
    }


}

//******************************************************

int main ()
{

    //part A
    char word[WORD];
    char option;

    getWord(word); //take the first word in the first line



    scanf(" %c\n" , &option);




    //Part B

    if(option == 'a')
        print_lines(word);

    else if(option == 'b')
        print_similar_words(word);


}
