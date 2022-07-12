#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "assignment4.h"

/* Question 1 */

int queue_move(queue_t* destination, queue_t* source) {

  if (queue_is_empty(source)) {
    return 0;
  }
  else {
    int counter = 0;
    while (!queue_is_empty(source)) {
      enqueue(destination, dequeue(source));
      counter++;
    }
    return counter;
  }
}

int queue_size(queue_t* q){

  queue_t* tempq = queue_create();
  int size = queue_move(tempq, q);
  queue_move(q, tempq);

  free(tempq);
  return size;
}

bool queue_equal(queue_t* q1, queue_t* q2) {

  queue_t* tempQueue1 = queue_create();
  queue_t* tempQueue2 = queue_create();

  int size1 = queue_size(q1);
  int size2 = queue_size(q2);
  bool truthValue = true;

  char temp1;
  char temp2;

  if(size1 != size2){
    return false;
  } else {
       while(!queue_is_empty(q1) && !queue_is_empty(q2)){


    temp1 = dequeue(q1);

    temp2 = dequeue(q2);


    if(temp1 != temp2){
      truthValue = false ;
    }

      enqueue(tempQueue1, temp1);
      enqueue(tempQueue2, temp2);
    }
  

  queue_move(q1, tempQueue1);
  queue_move(q2, tempQueue2);
  queue_free(tempQueue1);
  queue_free(tempQueue2);
  }
  return truthValue;
}

/* Question 2 */

float eval_arithmetic_expression(BTnode_t* root) {
  

  if(!root){
    return 0;
  }

  if(!root->left && !root->right){
    return root->value;
  }

  float l_val = eval_arithmetic_expression(root->left);

  float r_val = eval_arithmetic_expression(root->right);

  if(root->value == '+'){
    return l_val+r_val;
  }

  if(root->value == '-'){
    return l_val-r_val;
  }

  if(root->value == '*'){
    return l_val*r_val;
  }
  
  return l_val/r_val;

}


/* Question 3 */

BTnode_t* find(BTnode_t* root, bool (*pred)(int)) {
  

  if(root == NULL){
    return NULL;
  }

  BTnode_t* leftDef = find(root->left, *pred);

  if(pred(root->value)){
    return root;
  }

  BTnode_t* rightDef = find(root->left, *pred);

}

BTnode_t* create_mirror_tree(BTnode_t* root) {
  

    if (root==NULL){
    return; 

  } else
  {

    BTnode_t* temp = create_node(root->value);

    temp->right = create_mirror_tree(root->left);
    temp->left = create_mirror_tree(root->right);
 
    return temp;
  }
}

