#ifndef LIBRARY_H
#define LIBRARY_H
//helper functions
struct node* reverse(struct node* head);
struct node* createnode(int val);
void printlist(struct node* head);
struct node* inputbigint();
int toint(struct node *num);
struct node* copyBigInt(struct node* num);
struct node* remove_initial_zeros(struct node* head);
int compare(struct node* num1, struct node* num2);
void freeBigInt(struct node* head);
int length(struct node * head);
int recieve_quotient(struct node * first, struct node * second);
int iszero(struct node * head);
void appendnode(struct node * newNode,struct node** dividedhead);
int quotient_genreator(struct node * a,struct node * product);

//main functions
struct node * addint(struct node* num1, struct node* num2);
struct node* subint(struct node* num1, struct node* num2);
struct node * multiply_int(struct node* num1, struct node *num2);
struct node * square_int(struct node * num);
struct node * cube_int(struct node* num);
struct node* power_int(struct node* num1, struct node* num2);
struct node* factorial(struct node* num);
struct node* sqrt_int(struct node* num);
struct node * divide(struct node * head1, struct node * head2 );

#endif