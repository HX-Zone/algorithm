/*题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 *思路：根据该题中数组的规律，可以通过排除法缩小该整数所在的范围，比如该整数比某一列首项小，则说明该整数不在该列
 */

#include<stdio.h>
#include<stdbool.h>

#define MAX_ROW 4
#define MAX_COL 4

void printArray(int arr[MAX_ROW][MAX_COL]){
  for(int i=0;i<MAX_ROW;i++){
    for(int j=0;j<MAX_COL;j++){
      printf("%6d",arr[i][j]);
    }
    printf("\n");
  }
}

bool findInArray(int arr[MAX_ROW][MAX_COL],int target,int* row,int* col){
 int i=0,column=MAX_COL-1;
 for(i=0;i<MAX_ROW;i++){
    for(int j=column;j>=0;j--){
      printf("current:%d\n",arr[i][j]);
      if(arr[i][j]==target){
        * row = i;
        * col = j;
        return true;
        break;
      }else if(arr[i][j]>target){
        column = j;
      }else{
        column = j;
        break;
      }
    }
  }
  return false;
}

void main(){
  int a[MAX_ROW][MAX_COL]={
    {1,2,8,9},
    {2,4,9,12},
    {3,7,10,13},
    {6,8,11,15}
  };
  int target,row,col;
  printArray(a);
  printf("Input the target:");
  scanf("%d",&target);
  bool result = findInArray(a,target,&row,&col);
  if(result){
    printf("The target is in (%d,%d)\n",row,col);
  }else{
    printf("The target was not found\n");
  }
}
