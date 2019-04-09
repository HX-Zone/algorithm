#include <iostream>

int Min(int number1, int number2, int number3){
  int min = (number1 < number2) ? number1: number2;
  min = (min < number3) ? min: number3;
  return min;
}

int GetUglyNumber_Solution2(int index){
  if(index <= 0)
    return 0;
  int* pUglyNumbers = new int[index];//创建长度为index的int数组，并且首地址为pUglyNumbers
  pUglyNumbers[0] = 1;
  int nextUglyIndex = 1;
  
  int *pM2 = pUglyNumbers;
  int *pM3 = pUglyNumbers;
  int *pM5 = pUglyNumbers;

  while(nextUglyIndex < index){
      int min = Min(*pM2 * 2,*pM3 * 3,*pM5 * 5);
      pUglyNumbers[nextUglyIndex] = min;

      while(*pM2*2 <= pUglyNumbers[nextUglyIndex])
        ++ *pM2;
      while(*pM3*3 <= pUglyNumbers[nextUglyIndex])
        ++ *pM3;
      while(*pM5*5 <= pUglyNumbers[nextUglyIndex])
        ++ *pM5;
      
      ++ nextUglyIndex;
  }

  int ugly = pUglyNumbers[nextUglyIndex-1];
  return ugly;
} 

int main(){
  int result =  GetUglyNumber_Solution2(200);
  std::cout << "result:" << result << std::endl;
    
  return 0;
}
