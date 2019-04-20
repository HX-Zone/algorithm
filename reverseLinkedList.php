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

}

function reverse($header){
  if($header==NULL || $header->next==NULL){
    echo "链表不能为空";
    return;  
  }
  $cur = $header->next;
  $prev = NULL;
  while($cur!=NULL){
    $next = $cur->next;
    $cur->next = $prev;
    $prev = $cur;
    $cur = $next;
  }
  $header->next = $prev;
}

$singleLinkedList = new singleLinkedList('header');
$singleLinkedList->insert('a');
$singleLinkedList->insert('b');
$singleLinkedList->insert('c');
$singleLinkedList->insert('d');
$singleLinkedList->insert('e');
$singleLinkedList->insert('f');

$singleLinkedList->display();

reverse($singleLinkedList->getHeader());

echo "逆转后\n";
$singleLinkedList->display();
?>
