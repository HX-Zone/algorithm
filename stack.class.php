<?php
class Stack {
  protected $limit;
  protected $stackArr = array();
  protected $size = 0;
  public function __construct($limit) {
    $this->limit = $limit;
  }

  public function size(){
    return $this->size;
  }

  public function push($item) {
    if($this->size < $this->limit) {
      $this->stackArr[$this->size] = $item;
      $this->size++;
    } else {
      echo "stack full \n";
    }
  }

  public function pop() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      $this->size--;
    }
  }

  public function top() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      return $this->stackArr[$this->size - 1];
    }
  }

  public function isEmpty() {
    return !$this->size > 0;
  }
}

// test
//define("NUM", 5);
//$st = new Stack(NUM);
//var_dump($st);
//$st->pop();
//echo $st->top() . "\n";
//for($i = 1; $i < NUM+3; $i++)
//  $st->push($i);
//for($i = 1; $i < NUM+3; $i++) {
//  echo $st->top() . "\n";
//  $st->pop();
//}

class Stack_hxz extends Stack{
  private $bak = NULL;

  public function __construct($limit) {
    $this->limit = $limit;
    $this->bak = new Stack($limit);
  }

  public function push($item) {
    if($this->size < $this->limit) {
      $this->stackArr[$this->size] = $item;
      $this->size++;
      if($this->bak->size){
        $this->bak->push($this->bak->top()>=$item?$item:$this->bak->top());
      }else{
        $this->bak->push($item);
      }
    } else {
      echo "stack full \n";
    }
  }

  public function pop() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      $this->size--;
      $this->bak->pop();
    }
  }

  public function min(){
    if($this->bak->size){
      return $this->bak->top();
    }else{
      echo "The stack is empty";
    }
  }

}

//$stack = new Stack_hxz(5);
//var_dump($stack);

define("NUM", 10);
$st = new Stack_hxz(NUM);
var_dump($st);
$st->pop();
echo $st->top() . "\n";
for($i = 8; $i < NUM+3; $i++) {
    $st->push($i);
      echo "cur min: " . $st->min() . "\n";
    
}
for($i = 1; $i < NUM+3; $i++) {
    $st->push($i);
      echo "cur min: " . $st->min() . "\n";
    
}
while(!$st->isEmpty()) {
    echo $st->top() . "\n";
      echo "cur min: " . $st->min() . "\n";
      $st->pop();
      
}

?>
