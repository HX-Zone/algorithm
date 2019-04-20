<?php 
class Node{
  public $data = "";
  public $next = null;
  function __construct($data)
  {
    $this->data = $data;	
  }
}

//链表有几个元素
function countNode($head){
  $cur = $head;
  $num = 0;
  while(!is_null($cur->next)){
    $cur = $cur->next;
    ++$num;
  }
  return $num;
}

//尾部追加结点
function addNode($head,$data){
  $cur = $head;
  while(!is_null($cur->next)){
    $cur = $cur->next;
  }
  $node = new Node($data);
  $cur->next = $node;
}

//打印链表
function printNode($head){
  $cur = $head;
  while(!is_null($cur->next)){
    echo $cur->next->data."\n";
    $cur = $cur->next;
  }
}

function getNode($head,$k){
  if($head->next == NULL){
      echo "链表为空";
      return;
  }
  if($k<1){
    echo "k不能小于1";
    return;
  }
  $length = 0;
  $p1 = $p2 = $head;
  while($p1->next){
    ++ $length;
    $p1 = $p1->next;
    if($k>0){
      --$k;
    }else{
      $p2 = $p2->next;
    }
  }
  if($k>$length){
    echo "k超出链表长度";
    return;
  }
  return $p2->next;
}
$head = new Node(null);
addNode($head,'a');
addNode($head,'b');
addNode($head,'c');
addNode($head,'d');
addNode($head,'e');
addNode($head,'f');
printNode($head);
$k = 6;
$node = getNode($head,$k);
echo "第{$k}个结点的值是：".$node->data."\n";
?>
