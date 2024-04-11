int my_strlen(char* ptr,int separator,int index) {
  
  int i = index;
  int lenght = 0;
   
  while(ptr[i] != separator && ptr[i]) {
    lenght++;
    i++;
  }

  return lenght;

}

char** splitWordsBySeparator(char** words, int wordsSize, char separator, int* returnSize) {
 
  int len = 0;
  for(int i = 0; i < wordsSize; ++i) {
    int j = 0;
    while(words[i][j]) {
      if(words[i][j] != separator) {
        len++;
      int wordslenght = my_strlen(words[i],separator,j);
      j += wordslenght;
      } else {
        j++;
        }
    }
  }

  *returnSize = len;
  char** arr = (char**)malloc(sizeof(char*) * len);
  if(!arr) {
    return NULL;
    exit(1);
  }

  int k = 0;
  for(int i = 0; i < wordsSize; ++i) {
    int j = 0;
    while(words[i][j]) {
      if(words[i][j] != separator) {
        int word_length = my_strlen(words[i],separator,j);
        arr[k] = (char*)malloc(word_length + 1);
        
        if(!arr) {
          return NULL;
          exit(1);
        }

        for(int l = 0; l < word_length;++l) {
          arr[k][l] = words[i][j + l];
        }

        arr[k][word_length] = '\0';
        j += word_length;
        k++;
      } else {
          j++;
        }

    }
  }
  return arr;
}