 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #define MAX_PARAGRAPH_SIZE 1000
 #define MAX_WORD_SIZE 100
 #define MAX_WORDS 100
 typedef struct {
 char word[MAX_WORD_SIZE];
 int frequency;
 } WordFrequency;
 void normalizeWord(char *word) {
 for (int i = 0; word[i]; i++) {
 word[i] = tolower(word[i]);
 }
 }
 int findWordIndex(WordFrequency wordList[], int wordCount, const char *word) {
 for (int i = 0; i < wordCount; i++) {
 if (strcmp(wordList[i].word, word) == 0) {
 return i;
 }
 }
 return-1;
 }
 void countWordFrequencies(char *paragraph, WordFrequency wordList[], int *wordCount) {
 char *word;
 char temp[MAX_PARAGRAPH_SIZE];
 strcpy(temp, paragraph);
 word = strtok(temp, " \n\t\r");
 while (word != NULL) {
 normalizeWord(word);
 int index = findWordIndex(wordList, *wordCount, word);
 if (index !=-1) {
 wordList[index].frequency++;
 } else {
 strcpy(wordList[*wordCount].word, word);
 wordList[*wordCount].frequency = 1;
 (*wordCount)++;
 }
 word = strtok(NULL, " \n\t\r");
 }
 }
 void printWordFrequencies(const WordFrequency wordList[], int wordCount) {
 printf("Word Frequencies:\n");
 for (int i = 0; i < wordCount; i++) {
 printf("%s: %d\n", wordList[i].word, wordList[i].frequency);
 }
 }
 int main() {
char paragraph[MAX_PARAGRAPH_SIZE];
 WordFrequency wordList[MAX_WORDS];
 int wordCount = 0;
 printf("Enter a paragraph (end input with EOF or Ctrl+D):\n");
 while (fgets(paragraph, sizeof(paragraph), stdin)) {
 size_t len = strlen(paragraph);
 if (len > 0 && paragraph[len- 1] == '\n') {
 paragraph[len- 1] = '\0';
 countWordFrequencies(paragraph, wordList, &wordCount);
 printf("Enter more text (end input with EOF or Ctrl+D):\n");
 }
 printWordFrequencies(wordList, wordCount);
 return 0;
 }