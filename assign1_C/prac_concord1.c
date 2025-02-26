#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 20
#define MAX_SENTENCE_LENGTH 80
#define TOTAL_KEYWORDS 500
#define TOTAL_EXCEPTION_KEYWORDS 100

void populate_exception(char *Path);
void parse_reg(char *Path);
void add_words(char *,int line_num);

struct main_struct{
    char word[MAX_WORD_SIZE];
    char sentence[MAX_SENTENCE_LENGTH];
    int line_number;
    int this_sentence_count;

};
struct main_struct main1[TOTAL_KEYWORDS];

int EXCEPTION_SIZE = 0;
int MAIN_SIZE = 0;
// word = 20, 2 spaces, sentence = 80, 1 space, ( = 1,line_num = 1,if(*) = 1, ) = 1
// 5 is for (n*)\0 + 2 spaces between word and sentence, and 1 space between sentence and number

//char main1[TOTAL_KEYWORDS][108];
char exception_words[TOTAL_EXCEPTION_KEYWORDS][MAX_WORD_SIZE];

void main(int argc, char *argv[]){
    
    populate_exception(argv[1]);
    for(int i = 0; i<EXCEPTION_SIZE;i++){
        printf("%s%d ",exception_words[i],EXCEPTION_SIZE);
        }

    //printf("{%s}",argv[1]);
    //exit(0);
    parse_reg(argv[2]);

    for(int x = 0;x < MAIN_SIZE;x++){
        printf("%s         %s line num: %d\n",main1[x].word,main1[x].sentence,main1[x].line_number);    
    //printf("%s    %s (%d)",main1[x].word,main1[x].sentence,main1[x].line_number);
    }
      
    exit(0);

}

// works!
void populate_exception(char *Path){
    FILE *data_ep = fopen(Path,"r");
    char buffer[MAX_WORD_SIZE];
    int len = 0;
    if(data_ep == NULL){
        fprintf(stderr,"unable to open %s\n",Path);
        exit(1);
    }
    while(fgets(buffer,sizeof(char)*MAX_WORD_SIZE,data_ep)){
    // remove newline
        len = strlen(buffer) - 1;
        if(buffer[len] == '\n') buffer[len] = '\0';
        strncpy(exception_words[EXCEPTION_SIZE],buffer,MAX_WORD_SIZE);
        EXCEPTION_SIZE++;
           }
        fclose(data_ep);
}

// have add words exclude
void add_words(char *line, int line_num){
//word,sentence,line_num, check for word
    char *token;
    int len = strlen(line);
    char line2[80];
    strncpy(line2,line,80);
    token = strtok(line, " ");
 
    while(token != NULL){
        // if strcmp word[i] and line_num == line_number then don't add word and increment line_count
        // if word and line doesnt exist add these else increment count.
        strncpy(main1[MAIN_SIZE].word,token,MAX_WORD_SIZE);
        strncpy(main1[MAIN_SIZE].sentence,line2,MAX_SENTENCE_LENGTH);
        main1[MAIN_SIZE].line_number = line_num; 
        MAIN_SIZE += 1;
        token = strtok(NULL, " ");
    }
    line2[0] = '\0';
}
void parse_reg(char *Path){
    FILE* data_ep = fopen(Path, "r");
    char buffer[MAX_SENTENCE_LENGTH];
    int line_num =  1;
    char cur_line[MAX_SENTENCE_LENGTH];
    int len;

    if(data_ep == NULL){
        fprintf(stderr,"unable to open%s\n",Path);
        exit(1);
    }
    while(fgets(buffer,sizeof(char) * MAX_SENTENCE_LENGTH,data_ep)){
    //if(MAIN_SIZE > TOTAL_KEYWORDS) print_struct();
        len = strlen(buffer) - 1;
        buffer[len] = '\0';
        add_words(buffer,line_num);
        line_num++;
    }
    
    if(MAIN_SIZE == 0) exit(0);
    // print_struct();
}
