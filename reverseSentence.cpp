#include <iostream>
#include <string.h>

void swap(char* str1,char* str2){
  if(str1 == NULL || str2 == NULL)
    return;
  char temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}


void reverseString(char* str, int start, int end){
  if(str == NULL || start < 0 || start > end)
    return;
  int left = start,right = end;
  while(left < right){
    swap(&str[left], &str[right]);
    ++ left;
    -- right;
  }
}

void reverseSentence(char* sen, int length){
  if(sen == NULL || length <= 0)
    return;
  int start = 0,end = length - 1;
  reverseString(sen, start, end);//整句反转
  int p = 0;
  while(sen[p] != '\0'){
    if(sen[p] != ' '){
      ++ p;
    }else{
      reverseString(sen, start, p-1);
      ++ p;
      start = p;
    }
  }
  reverseString(sen, start, p-1);

}

int main(){
  char str[20] = "world! Hello";
  int len = strlen(str);
  std::cout << "length:" << len << std::endl;
  //reverseString(str, 0, l-1);
  //std::cout << "str:" << str << std::endl;
  reverseSentence(str, len);
  std::cout << "str:" << str << std::endl;

  return 0;
}
