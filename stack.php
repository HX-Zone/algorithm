<?php 
class Stack{
  private $stackArr = array();

  public function __construct($mem=NULL){
    if($mem!=NULL){
      $this->stackArr[] = $mem;
    }
  }

  public function push($mem){
    $this->stackArr[] = $mem;
  }

  public function top(){
    $length = $this->countArr();
    if($length==0){
      echo "The stack is empty!\n";
      return;
    }
    return $this->stackArr[$length-1];
  }

  public function pop(){
    $length = $this->countArr();
    if($length==0){
      echo "The stack is empty!\n";
      return;
    }
    $top = $this->stackArr[$length-1];
    unset($this->stackArr[$length-1]); 
  }

  public function countArr(){
    $length = 0;
    while(isset($this->stackArr[$length])){
      $length ++;
    }
    return $length;
  }

  public function printStack(){
    $length = $this->countArr();
    echo "stack:";
    for($i=$length-1;$i>=0;$i--){
      echo $this->stackArr[$i].",";
    }
    echo "\n";
  }

}

$stack = new Stack();

$stack->push(1);

$stack->printStack();

echo "top:".$stack->top()."\n";

$stack->push(2);

$stack->printStack();

echo "top:".$stack->top()."\n";

$stack->pop();

$stack->printStack();
?>
