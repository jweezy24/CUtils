#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

typedef struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
}paragraph;

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {

}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {

}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {

}

struct paragraph kth_paragraph(struct document Doc, int k) {

}

void parser(char* buffer, paragraph* para){
  char* word;
  int c,pos = 0;
  word = malloc(sizeof(char));
  int sentences = 0;
  int words = 0;
  while((c = getchar()) != '\n'){
    if(c != ' ' || c != '\t'){
      word = realloc(sizeof(char)+strlen(word),word);
      word[pos] = c;
      pos+=1;
      words+=1;
    }
  }
  printf("There are %d sentences", sentences);
  printf("There are %d words", words);
}

int main(){
  paragraph paras[MAX_PARAGRAPHS];
  char characters[MAX_CHARACTERS];
  int howMany = 0;
  scanf("%d", &howMany);
  for(int i =0; i < howMany; i++){
    parser(characters, paras);
  }
  return 0;
}
