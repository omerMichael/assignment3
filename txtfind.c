#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
#define LINES 250

// if the word contain str1 the words from the user, and str2 if contaion str1
//it's work now
int substring( char * str1, char * str2){
    //This function returns a pointer to the first occurrence in haystack of any
    // of the entire sequence of characters specified in needle, or a null pointer if the sequence is not present in haystack.
    if(strstr(str1, str2) != NULL) {
        return 1;
    }
    return 0;

}

int similar (char *s, char *t, int n){
    if (substring(s,t))
        return 1;
    int i=0;
    while (*(s+i) != EOF && *(t+i) != EOF && *(s+i)!= ' ' && *(t+i) != ' ' ){
       //check if the first char in s equal to first char in t
       int p =n;
       int m=0;
        if (*(s+i)==*(t)) {
            for (int j = 0; *(s + j+i) != ' ' && *(t + j)-m != ' '; j++) {
            
            if (*(s+j+i)!=*(t+j-m)){
            p--;
            m++;
            }
            if (p==0)
                break;
            if (*(t+j+1)==' ' ||*(t+j+1)==EOF)
                return 1;
            }
        }// end if
        i++;
    }
    return 0;

}
int getLine(char s[])
{
	
	char letter = getchar();
    int SizeLine = 0;
		// while(letter=='\n')  //remove the spare whitelines in the begening of the file.
		// 	letter = getchar();

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

void print_lines(char * str)
{
    char line[LINE];
	// int SizeLine = getLine(line); // using function for getLine, now the line in char line
     int SizeLine =1;
	while(SizeLine > 0)
	{
        //get a line
        SizeLine = getLine(line); //line.next();
        //call to function that check if it's
		if(substring(line, str)==1)
        // print the line
			printf("%s\n", line);
        
		
	}
}
int getword(char w[])
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
void print_similar_words(char * str)
{
    char word[WORD];
    int sizeWord = 1;
    while (sizeWord>0){
        sizeWord = getword(word);
        if(similar(word,str,1)==1)
        printf("%s\n", word);

    }
    
}



int main ()
{

    //part A
    char word[WORD];
    char option;

    getword(word); //take the first word in the first line



    scanf(" %c\n" , &option);




    //Part B

    if(option == 'a')
        print_lines(word);

    else if(option == 'b')
        print_similar_words(word);


}

