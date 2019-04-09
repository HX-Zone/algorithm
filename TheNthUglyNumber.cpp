#include <iostream>

int Min(int number1, int number2, int number3){
  int min = (number1 < number2) ? number1 : number2;
  min = (min < number3) ? min : number3;
  
  return min;
}

int getTheNthUglyNumber(int N){
  if(N<=0)
    return 0;

  int arr[N];
  int T2=0,T3=0,T5=0;
  int M2,M3,M5;
  arr[0] = 1;
  for(int i=1;i<N;i++){
    M2 = arr[T2] * 2;
    M3 = arr[T3] * 3;
    M5 = arr[T5] * 5;
    int min = Min(M2, M3, M5);
    arr[i] = min;

    if(M2 == min)
      ++ T2;
    if(M3 == min)
      ++ T3;
    if(M5 == min)
      ++ T5;
  }

  return arr[N-1];
}

int main(){
  int r = getTheNthUglyNumber(200);
  std::cout << "r:" << r << std::endl;

  return 0;
}
