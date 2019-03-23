<?php
ini_set('display_errors','on');
ini_set('error_reporting','E_ALL');
//1.堆化（最小堆）：对一个任意的数组，调整其元素满足arr[n]<=arr[2*n+1] && arr[n]<=arr[2*n+2]
//2.给堆排序：给定一个数组arr（最小堆），并且它的长度为L，要将数组的元素进行排序，实现为从左到右递增。先将数组第一个元素arr[0]（肯定是最小）与数组最后一个元素arr[L-1]交换，然后以最小堆的特征来调整arr[0]在长度为L-2的数组中的位置
//重复操作2直至L-2=1为止
function swap(&$arr, $index1, $index2)
{
    $temp = $arr[$index1];
    $arr[$index1] = $arr[$index2];
    $arr[$index2] = $temp;
}

function makeHeap(&$arr)
{
    $length = count($arr);
    if ($length == 0) {
        exit("数组不能为空");
    }
    for ($i = 0; $i < $length; $i++) {
        for ($k = $i; $k > 0; $k--) {
            while ($k > 0 && isset($arr[intval($k - 1) / 2]) && $arr[$k] < $arr[intval($k - 1) / 2]) {
                swap($arr, $k, intval(($k - 1) / 2));
                $k = intval(($k - 1) / 2);
            }
        }
    }
}

function sortInHeap(&$arr)
{
    $length = count($arr);
    for ($i = ($length - 1); $i > 0; $i--) {//当前数组长度
        $k = 0;
        $sign = true;
        swap($arr, $k, $i);
        while ($sign) {
            if ((2 * $k + 2) <= ($i - 1)) {
                if ($arr[$k] > $arr[2 * $k + 1] && $arr[$k] > $arr[2 * $k + 2]) {
                    if ($arr[2 * $k + 1] < $arr[2 * $k + 2]) {
                        swap($arr, $k, 2 * $k + 1);
                        $k = 2 * $k + 1;
                    } else {
                        swap($arr, $k, 2 * $k + 2);
                        $k = 2 * $k + 2;
                    }
                } else if ($arr[$k] > $arr[2 * $k + 1]) {
                    swap($arr, $k, 2 * $k + 1);
                    $k = 2 * $k + 1;
                } else if ($arr[$k] > $arr[2 * $k + 2]) {
                    swap($arr, $k, 2 * $k + 2);
                    $k = 2 * $k + 2;
                }

            } else if ((2 * $k + 1) <= ($i - 1) && $arr[$k] > $arr[2 * $k + 1]) {
                swap($arr, $k, 2 * $k + 1);
                $k = 2 * $k + 1;
            } else {
                $sign = false;
            }
        }
    }
    reverseArray($arr);
}

function reverseArray(&$arr)
{
  $length = count($arr);
  $mid = ($length-1)/2;
  for($j=0;$j<$mid;$j++){
    for($k=($length-1);$k>$mid;$k--){
      swap($arr,$j,$k);
    }
  }
}

$arr = array();
for ($i = 0; $i < 15; $i++) {
    $arr[] = rand(1, 100);
}

print_r($arr);
makeHeap($arr);
print_r($arr);
sortInHeap($arr);
print_r($arr);
