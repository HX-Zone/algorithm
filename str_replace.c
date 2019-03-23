/*题目：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 *假设只能在原来字符串上做替换，并且保证输入的字符串后面有足够多的空余内存。
 * 思路：如果从左往右，即由前往后替换空格的话，每次碰到空格都会将空格之后的字符移动一次，假设有n个空格，则n个字符最多会被一定n*n次，复杂度O(n²);如果由后往前进行替换，则复杂度为O(n)，每个字符都只会被移动一次，n个空格执行n次替换。
 *
 */

#include<stdio.h>

void str_replace(char* str){
  int len,spaceNum;
  char*p = str,*old;
  while(*p){
    printf("current:%c\n",*p);
    if(*p==' '){
      ++ spaceNum;
    }
    old = p;//旧的末端
    ++p;
  }
  printf("spaceNum:%d\n",spaceNum);
  p += spaceNum*2;
  *p = '\0';
  --p;//新的末端
  while(*old){
    printf("cu:%c\n",*old);
  if(*old!=' '){
    *p = *old;
    -- p;
  }else{
    *p = '0';
    --p;
    *p = '2';
    --p;
    *p = '%';
    --p;
  }
  -- old;
  }
}

void main(){
  char str[33] = "We are having fun in programing!";
  printf("%s\n",str);
  str_replace(str);
  int i=0;
  while(str[i]){
    ++i;
  }
  ++i;
  printf("新的长度：%d\n",i+1);
  printf("新的字符串：%s\n",str);
}

/*总结：假设一个字符串里有n个字符，则这个字符串实际长度n+1个字节。每次用%20去替换一个空格时，长度会+2；所以新的指针应在最后一个字符（本例中的'y'），加上空格数*2，再加上1个字符（'\0'）。
 *
 */
