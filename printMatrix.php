<?php
function printMatrix($matrix,$minRow,$maxRow,$minCol,$maxCol){
  echo "\nminRow:".$minRow.";maxRow:".$maxRow.";minCol:".$minCol.";maxCol:".$maxCol."\n";
  if(($maxRow-$minRow<0) || ($maxCol-$minCol<0)){
    return;
  }
  $r = $minRow;
  for($c=$minCol;$c<=$maxCol;$c++){
    echo $matrix[$r][$c].",";
  }
  if(($r+1)<=$maxRow){//行数要2行以上才执行
    --$c;
    for($r=$r+1;$r<=$maxRow;$r++){
      echo $matrix[$r][$c].",";
    }
  } 
  --$r;
  if(($c-1)>=$minCol && ($r-1)>=$minRow){//列数要2列以上，行数要两行以上才执行
    for($c=$c-1;$c>=$minRow;$c--){
      echo $matrix[$r][$c].",";
    }
  }
  ++$c;
  if(($c+1)<=$maxCol && ($r-1)>=$minRow){
    for($r=$r-1;$r>=($minRow+1);$r--){
      echo $matrix[$r][$c].",";
    }
  }
  printMatrix($matrix,$minRow+1,$maxRow-1,$minCol+1,$maxCol-1);
}

//$matrix[0] = [1,2,3,4];
//$matrix[1] = [5,6,7,8];
//$matrix[2] = [9,10,11,12];
//$matrix[3] = [13,14,15,16];
$matrix[0] = [1,2,3];
$matrix[1] = [4,5,6];
$matrix[2] = [7,8,9];

//$matrix[0] = [1,2,3];
//main

$maxRow = count($matrix)-1;
$maxCol = count($matrix[0])-1;

printMatrix($matrix,0,$maxRow,0,$maxCol);
?>
