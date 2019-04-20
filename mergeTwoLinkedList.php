<?php
//节点类
class Node{
  public $data;//节点数据
  public $next;//下一节点

  public function __construct($data){
    
    $this->data = $data;
    $this->next = NULL;

  }
}

//单链表类
class singleLinkedList{
  private $header;//头节点

  function __construct($data){
    
    $this->header = new Node($data);

  }

  //在尾部插入新节点
  public function insert($data){
    $new = new Node($data);
    $cur = $this->header;
    while($cur->next!=NULL){
      $cur = $cur->next;
    }
    $cur->next = $new;
  }

  //打印链表
  public function display(){
    $cur = $this->header;
    while($cur->next!=NULL){
      echo $cur->next->data."\n";
      $cur = $cur->next;
    }
  }

  //输出头节点
  public function getHeader(){
    return $this->header;
  }

  public function setHeader($node){
    $this->header = $node;
  }

}

function merge($header1,$header2){
  if($header1==NULL && $header2==NULL){
    return NULL;
  }
  if($header1==NULL || $header1->next==NULL){
    return $header2;
  }
  if($header2==NULL || $header2->next==NULL){
    return $header1;
  }
  $cur1 = $header1;
  $cur2 = $header2;
  $mCur= $mHeader = new Node('mHeader');
  while($cur1->next!=NULL || $cur2->next!=NULL){
    if($cur1->next)
      echo "cur1->next->data:".$cur1->next->data."\n";
    if($cur2->next)
      echo "cur2->next->data:".$cur2->next->data."\n";
    if($cur1->next==NULL){
      $mCur->next->next = $cur2->next;
      break;
    }else if($cur2->next==NULL){
      $mCur->next->next = $cur1->next;
      break;
    }else if($cur1->next->data <= $cur2->next->data){
      $mCur->next = $cur1->next;
      $cur1 = $cur1->next;
    }else if($cur1->next->data > $cur2->next->data){
      $mCur->next = $cur2->next;
      $cur2 = $cur2->next;
    }
    echo "mCur->next->data:".$mCur->next->data."\n";
  } 
  return $mHeader;
}

$header1 = new singleLinkedList('header1');
$header1->insert(1);
$header1->insert(3);
$header1->insert(6);
$header1->insert(7);
$header1->insert(9);
$header1->insert(10);

$header2 = new singleLinkedList('header2');
$header2->insert(2);
$header2->insert(4);
$header2->insert(5);
$header2->insert(6);
$header2->insert(6);

//$singleLinkedList->display();

$mHeader = merge($header1->getHeader(),$header2->getHeader());
$mergedList = new singleLinkedList('');
$mergedList->setHeader($mHeader);
echo "合并后\n";
$mergedList->display();
?>
