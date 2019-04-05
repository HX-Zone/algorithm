#include <iostream>
#include <queue>

void printFromTopToBottom(BinaryTreeNode* pTreeRoot){
  if(!pTreeRoot){
    return;
  }

  std::queue<BinaryTreeNode*> queTreeNode;

  queTreeNode.push_back(pTreeRoot);

  while(!queTreeNode.size()){//队列不为空
    BinaryTreeNode* pNode = queTreeNode.front();
    queTreeNode.pop();
    
    printf("%d,",pNode->m_nValue);
    
    if(pNode->m_pLeft!=NULL){
      queTreeNode.push(pNode->m_pLeft);
    }
    if(pNode->m_pRight!=NULL){
      queTreeNode.push(pNode->m_pRight);
    }
    
  }
}

