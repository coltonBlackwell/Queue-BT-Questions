#ifndef ASSIGNMENT4_H
#define ASSIGNMENT4_H

#include <stdbool.h>

#include "lib/queue.h"
#include "lib/BTnode.h"

/* Question 1 */


// moves all elements from source to destination in the FIFO order
// returns the number of elements moved
int queue_move(queue_t* destination, queue_t* source);

// gets a queue of chars and returns the number of elements in queue
// when the function returns, q should be in the same state
// as it was in the beginning
int queue_size(queue_t* q);


// checks if the two queues are equal
// when the function returns, q1 and q2 should be in the same state
// as they were in the beginning
bool queue_equal(queue_t* q1, queue_t* q2);

/* Question 2 */

enum {PLUS = '+', MINUS = '-', MULT = '*', DIV = '/'};

// evaluates an arithmetic expression in the given tree
// assumption: tree is not null and not empty
// assume all internal nodes are operations, as described in the enum
float eval_arithmetic_expression(BTnode_t* root); 


/* Question 3 */

// finds the first node satisfying pred according to in-order traversal
// if such node not found, returns NULL
BTnode_t* find(BTnode_t* root, bool (*pred)(int));

// creates a new tree that is the mirror image of the input
// the nodes in the new tree should all be new, and should not use the nodes of the input
// if root == NULL, the function returns NULL
BTnode_t* create_mirror_tree(BTnode_t* root);


#endif
