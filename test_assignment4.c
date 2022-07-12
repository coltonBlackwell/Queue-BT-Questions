#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#include "lib/queue.h"
#include "lib/BTnode.h"
#include "assignment4.h"

/* Question 1 */


void test_q1_move() {
  queue_t* q = queue_create();
  enqueue(q, 'a');
  enqueue(q, 'B');

  queue_t* q2 = queue_create();
  enqueue(q2, 'X');

  queue_move(q2, q);


  bool okFlag = queue_is_empty(q);
  if (queue_is_empty(q2))
    okFlag = false;
  else if (dequeue(q2)!='X' || queue_is_empty(q2)) 
    okFlag = false;
  else if (dequeue(q2)!='a' || queue_is_empty(q2))
    okFlag = false;
  else if (dequeue(q2)!='B' || !queue_is_empty(q2))
    okFlag = false;

  queue_free(q);
  queue_free(q2);
  if (okFlag)
    printf("Q1-move ok\n");
  else
    printf("Q1-move ERROR\n");
}


void test_q1_size() {
  queue_t* q = queue_create();
  enqueue(q, 'a');
  enqueue(q, 'B');
  enqueue(q, 'c');

  int ans = queue_size(q);
  queue_free(q);
  if (ans==3)
    printf("Q1-size ok\n");
  else
    printf("Q1-size ERROR\n");
}


void test_q1_equal() {
  queue_t* q1 = queue_create();
  enqueue(q1, 'a');
  enqueue(q1, 'b');

  queue_t* q2 = queue_create();
  enqueue(q2, 'a');
  enqueue(q2, 'b');

  bool ans1 = queue_equal(q1,q2);
  bool okFlag = true;

  // check that q1 and q2 have not been modified
  if (dequeue(q1)!='a') okFlag = false;

  enqueue(q2, 'K');

  bool ans2 = queue_equal(q1,q2);

  if (dequeue(q1)!='b') okFlag = false;

  if (dequeue(q2)!='a') okFlag = false;

  if (dequeue(q2)!='b') okFlag = false;


  if (dequeue(q2)!='K') okFlag = false;

  queue_free(q1);
  queue_free(q2);

  if (ans1 && !ans2 && okFlag)
    printf("Q1-equal ok\n");
  else
    printf("Q1-equal ERROR\n");
}


/* Question 2 */

void test_q2() {
/***
// creates the following tree
//      +
//    /   \
//   *      +
//  / \    / \
// 3   -  5   /
//    / \    / \
//   9   7  11  -2
****/
  BTnode_t* root_plus = create_node(PLUS);
  BTnode_t* mult = create_node(MULT);
  BTnode_t* plus = create_node(PLUS);
  BTnode_t* minus = create_node(MINUS);
  BTnode_t* div = create_node(DIV);
  BTnode_t* neg_two = create_node(-2);
  BTnode_t* three = create_node(3);
  BTnode_t* five = create_node(5);
  BTnode_t* seven = create_node(7);
  BTnode_t* eleven = create_node(11);
  BTnode_t* nine = create_node(9);

  set_left_child(root_plus, mult);
  set_right_child(root_plus, plus);
  
  set_left_child(mult, three);
  set_right_child(mult, minus);

  set_left_child(plus, five);
  set_right_child(plus, div);

  set_left_child(minus, nine);
  set_right_child(minus, seven);

  set_left_child(div, eleven);
  set_right_child(div, neg_two);

  if (eval_arithmetic_expression(neg_two) == -2)
    printf("Q2-1 ok\n");
  else
    printf("Q2-1 ERROR\n");

  if (eval_arithmetic_expression(div) == -5.5)
    printf("Q2-2 ok\n");
  else
    printf("Q2-2 ERROR\n");
    
  if (eval_arithmetic_expression(plus) == -0.5)
    printf("Q2-3 ok\n");
  else
    printf("Q2-3 ERROR\n");
    
  if (eval_arithmetic_expression(mult) == 6)
    printf("Q2-4 ok\n");
  else
    printf("Q2-4 ERROR\n");

  if (eval_arithmetic_expression(root_plus) == 5.5)
    printf("Q2-5 ok\n");
  else
    printf("Q2-5 ERROR\n");

  BT_free(root_plus);
    

}

/* Question 3 */

bool is_even(int x) { return x%2==0;}

void test_q3_find() {
/***
// creates the following tree
//      3
//    /   \
//   5      4
//  /
// 2 
//
****/

  BTnode_t* three = create_node(3);
  BTnode_t* five = create_node(5);
  BTnode_t* four = create_node(4);
  BTnode_t* two = create_node(2);

  set_left_child(three, five);
  set_right_child(three, four);
  set_left_child(five, two);

  BTnode_t* ans = find(three, is_even);

  BT_free(three);

  if (ans && ans==two)
    printf("Q3-find ok\n");
  else
    printf("Q3-find ERROR\n");
}

void test_q3_mirror() {
/***
// creates the following tree
//      1
//    /   \
//   2      3
//  / \
// 4   5
//
****/
  BTnode_t* one = create_node(1);
  BTnode_t* two = create_node(2);
  BTnode_t* three = create_node(3);
  BTnode_t* four = create_node(4);
  BTnode_t* five = create_node(5);
  
  set_left_child(one, two);
  set_right_child(one, three);
  set_left_child(two, four);
  set_right_child(two, five);

  BTnode_t* ans = create_mirror_tree(one);

  bool okFlag = ans!=NULL && ans->value==1
          && ans->left && ans->left->value==3
          && ans->right && ans->right->value==2
          && ans->right->right && ans->right->right->value==4
          && ans->right->left && ans->right->left->value==5
          && ans->left->left==NULL
          && ans->left->right==NULL;

  BT_free(one);
  if (ans)
    BT_free(ans);

  if (!ans)
    printf("Q3-mirror ERROR : returned NULL\n");
  else if (okFlag)
    printf("Q3-mirror ok\n");
  else
    printf("Q3-mirror ERROR\n");
}



// when testing your code, it may be convenient 
// to comment out some of the test cases
// and focus only on the one you are working on right now.
// Also, you are encouraged to add more test casess
int main()  {

  test_q1_move();
  test_q1_size();
  test_q1_equal();

  test_q2();

  test_q3_find();
  test_q3_mirror();

  return 0;
}
