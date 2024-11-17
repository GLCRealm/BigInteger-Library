#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <time.h>
#include "library.h"

struct node{
    int val;
    struct node * next;
};

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

struct node* createnode(int val){
    struct node*temp=(struct node*)malloc(sizeof(struct node));

    if(temp==NULL){
        printf("Memory allocation failed");
        return 0;
    }
    temp->val=val;
    temp->next = NULL;
    return temp;
}

void printlist(struct node* head){
    struct node* itr = (head);

    if(itr==NULL){
        printf("the list is empty\n");
        return;
    }

    while(itr!=NULL){
        printf("%d",itr->val);
        itr=itr->next;
    }
    printf("\n");
}

struct node* inputbigint() {
    struct node* temp = NULL;
    char ch;

    while (1) {
        ch = getchar();
        if (ch == '\n' || !isdigit(ch)) {
            break;
        }

        int digit = ch - '0';
        struct node* newnode = createnode(digit);

        if (temp == NULL) {
            temp = newnode;
        } else {
            newnode->next = temp;
            temp = newnode;
        }
    }

    return temp;
}

int toint(struct node *num){
    int res = 0;
    int count=1;
    while(num != NULL){
        res += (num->val)*count;
        count *=10;
        num=num->next;
    }
    return res;
}

struct node* copyBigInt(struct node* num) {
    if (num == NULL) return NULL;
    struct node* newNum = createnode(num->val);
    struct node* current = newNum;
    num = num->next;
    while (num != NULL) {
        current->next = createnode(num->val);
        current = current->next;
        num = num->next;
    }
    return newNum;
}

struct node* remove_initial_zeros(struct node* head) {
    while (head != NULL && head->val == 0) {
        struct node* temp = head;
        head = head->next;
        free(temp);  // free the removed node to avoid memory leak
    }
    return head;
}

int compare(struct node* num1, struct node* num2) {
    struct node* temp1 = num1;
    struct node* temp2 = num2;

    // Compare lengths of both numbers
    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    // If lengths are different, the longer number is greater
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    // If lengths are equal, compare digits
    temp1 = num1;
    temp2 = num2;
    while (temp1 != NULL) {
        if (temp1->val > temp2->val) return 1;
        if (temp1->val < temp2->val) return -1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 1; // Both numbers are equal
}

void freeBigInt(struct node* head) {
    struct node* current = head;
    struct node* nextNode;

    while (current != NULL) {
        nextNode = current->next;  // Store the next node
        free(current);            // Free the current node
        current = nextNode;       // Move to the next node
    }
}

int length(struct node * head){
    int c=0;
    while(head){
        head=head->next;
        c++;
    }
    return c;
}

int recieve_quotient(struct node * first, struct node * second){
    if(length(first)<length(second))
        return 0;
    if(length(first)>length(second))
        return 1;
    while(first){
        if(first->val>second->val)
            return 1;
        else if(first->val<second->val)
            return 0;
        first=first->next;
        second=second->next;
    }
    return 1;
}

int iszero(struct node * head){
    while(head &&head->val==0)
        head=head->next;

    if(head)    return 0;//sare zero nahi h
    return 1;
}

void appendnode(struct node * newNode,struct node** dividedhead) {
    if((*dividedhead)==NULL){
        (*dividedhead)=newNode;
        return ;
    }
    struct node* itr=(*dividedhead);
    while(itr->next){
        itr=itr->next;
    }
    itr->next=newNode;
}








struct node * addint(struct node* num1, struct node* num2) {
    struct node * result = NULL;
    struct node * temp;
    int carry =0;

    while(num1 != NULL || num2!=NULL|| carry!=0){
        int sum = carry;

        if(num1!=NULL){
            sum += num1->val;
            num1 = num1->next;
        }
        if(num2!=NULL){
            sum += num2->val;
            num2 = num2 ->next;
        }

        carry = sum/10;
        sum %= 10;

        struct node * newnode = createnode(sum);
        if(result ==NULL){
            result= newnode;
            temp = result;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    return result;
}

struct node* subint(struct node* num1, struct node* num2) {
    struct node* result = NULL;
    struct node* temp;
    int borrow = 0;

    while (num1 != NULL || num2 != NULL) {
        int diff = borrow;
        if (num1 != NULL) {
            diff += num1->val;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            diff -= num2->val;
            num2 = num2->next;
        }

        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        struct node* newnode = createnode(diff);
        if (result == NULL) {
            result = newnode;
            temp = result;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }

    return result;
}

struct node * multiply_int(struct node* num1, struct node *num2) {
    if (num1 == NULL || num2 == NULL) {
        return NULL;
    }

    int new_0 = 0 ;
    struct node * j = num1;
    struct node * i = num2;
    struct node * result=NULL, *temp=NULL, *result2=NULL,*temp2= NULL;


    while(i != NULL){
        int carry = 0;
        int carry2= 0;
        int a=0;

        while(j != NULL) {

            if (new_0 != 0) {
                if(a==0) {
                    for (int it = 0; it < new_0; it++) {
                        struct node *newnode2 = createnode(0);
                        if (result2 == NULL) {
                            result2 = newnode2;
                            temp2 = result2;
                        } else {
                            temp2->next = newnode2;
                            temp2 = temp2->next;
                        }
                    }
                    a=1;
                }

                int mult = carry2;
                mult += i->val * j->val;
                carry2 = mult / 10;
                mult %= 10;

                struct node *newnode2 = createnode(mult);

                if (result2 == NULL) {
                    result2 = newnode2;
                    temp2 = result2;
                } else {
                    temp2->next = newnode2;
                    temp2 = temp2->next;
                }
                j = j->next;

            }

            else {

                int mult = carry;
                mult += i->val * j->val;
                carry = mult / 10;
                mult %= 10;

                struct node *newnode = createnode(mult);

                if (result == NULL) {
                    result = newnode;
                    temp = result;
                } else {
                    temp->next = newnode;
                    temp = temp->next;
                }
                j = j->next;
            }

        }
        if(carry!=0){
            struct node *newnode = createnode(carry);
            temp->next = newnode;
            temp= temp->next;
            carry = 0;
        }
        if(carry2!=0){
            struct node *newnode = createnode(carry2);
            temp2->next = newnode;
            temp2= temp2->next;
            carry2 = 0;
        }

        j = num1;
        i = i->next;
        new_0 ++;
        result = addint(result,result2);
        result2 = NULL;
        temp2 = NULL;

    }
    return result;
}

struct node * square_int(struct node * num) {
    return multiply_int(num,num);
}

struct node * cube_int(struct node* num) {
    struct node*i = multiply_int(num,num);
    return multiply_int(i,num);
}

struct node* power_int(struct node* num1, struct node* num2) {
    int exp = toint(num2);
    if (exp > 99999) {
        printf("Result is too long\n");
        return NULL;
    }

    struct node* result = createnode(1);
    struct node* base = copyBigInt(num1);

    time_t start_time = time(NULL);
    const double max_time = 4.0;

    while (exp > 0) {
        if (difftime(time(NULL), start_time) > max_time) {
            printf("Result is too long\n");
            return createnode(0);
        }

        if (exp % 2 == 1) {
            struct node* temp = result;
            result = multiply_int(result, base);
            free(temp);
        }

        struct node* tempbase = base;
        base = multiply_int(base, base);
        free(tempbase);
        exp /= 2;
    }

    return result;
}

struct node* factorial(struct node* num) {
    struct node *a = num, * check = num, *result = copyBigInt(a);
    struct node *b =NULL, *checkb =NULL;

    if(toint(a)==0) return createnode(1);

    int flag_check =0;
    int double_check=0;

    time_t start_time = time(NULL);
    const double max_time = 10.0;

    while (flag_check == 0) {

        while (check != NULL) {
            if (check->val == 0) {
                check = check->next;
            } else {
                flag_check = 1;
                check = NULL;
            }
        }

        if(flag_check == 1){
            b = subint(a, createnode(1));
            checkb = b;

            while (checkb!=NULL&&double_check==0){

                if (difftime(time(NULL), start_time) > max_time) {
                    printf("Result is too long\n");
                    return NULL;
                }

                if(checkb->val == 0){
                    checkb = checkb->next;
                }else double_check=1;
            }
            if(checkb == NULL){
                break;
            }

            result = multiply_int(result, b);
            a = copyBigInt(b);
            check = a;
            flag_check = 0;
            double_check=0;
        } else break;
    }
    return result;

};

struct node* sqrt_int(struct node* num) {
    int n = toint(num);
    int root = 0;

    if (n < 0) {
        printf("Square root of negative number is not defined.\n");
        return NULL;
    }

    int odd = 1;
    int remainder = n;

    // Subtract odd numbers until we reach 0 or cannot subtract anymore
    while (remainder >= odd) {
        remainder -= odd;
        odd += 2;
        root++;
    }


    if (remainder != 0) {
        printf("Not a perfect square.\n");
        return NULL;
    }

    struct node* result = createnode(root);
    return result;
}

//struct node* divide_by_two(struct node* num) {
//    if (num == NULL) return NULL;
//
//    struct node *result = NULL;  // Resulting linked list
//    struct node *tail = NULL;    // Tail pointer for appending nodes
//    int carry = 0;               // Carry to manage odd numbers
//
//    while (num != NULL) {
//        int current = carry * 10 + num->val; // Combine carry with current digit
//        int quotient = current / 2;         // Compute quotient
//        carry = current % 2;                // Update carry
//
//        // Create a new node for the quotient digit
//        struct node* new_node = createnode(quotient);
//        if (result == NULL) {
//            result = new_node; // Initialize the result list
//        } else {
//            tail->next = new_node; // Append to the result list
//        }
//        tail = new_node; // Move the tail pointer
//
//        num = num->next; // Move to the next digit
//    }
//
//    // Remove leading zeros from the result (if any)
//    result = remove_initial_zeros(result);
//
//    return result;
//}

//struct node* sqrt_int(struct node* num) {
//    if (num == NULL || (num->val == 0 && num->next == NULL)) {
//        // If the number is 0 or NULL, return 0 as the square root.
//        return createnode(0);
//    }
//
//    struct node *low = createnode(0);         // Starting point of binary search
//    struct node *high = num;                 // Upper bound for binary search
//    struct node *mid = NULL;                 // Middle point in binary search
//    struct node *one = createnode(1);        // Constant value 1
//    struct node *two = createnode(2);        // Constant value 2
//    struct node *result = NULL;              // Store the result
//
//    while (compare(low, high) <= 0) {        // While low <= high
//        mid = addint(low, high);             // mid = (low + high) / 2
//        mid = divide_by_two(mid);            // Perform integer division by 2
//
//        struct node *square = multiply_int(mid, mid); // square = mid * mid
//
//        int cmp = compare(square, num);      // Compare square with num
//
//        if (cmp == 0) {                      // If square == num
//            result = mid;                    // Found the exact square root
//            break;
//        } else if (cmp < 0) {                // If square < num
//            result = mid;                    // Update result
//            low = addint(mid, one);          // low = mid + 1
//        } else {                             // If square > num
//            high = subint(mid, one);         // high = mid - 1
//        }
//
//        freeBigInt(square);             // Free the temporary square list
//    }
//
//    freeBigInt(low);
//    freeBigInt(high);
//    freeBigInt(one);
//    freeBigInt(two);
//
//    return result;
//}


int quotient_genreator(struct node * a,struct node * product) {

    if(product==NULL) return 0;
    //a * ans=product

    struct node * ansnode =(struct node * )malloc(sizeof(struct node));
    ansnode->next=NULL;
    int ans=0;

    for(int i=1;i<10;i++){

        ansnode->val=i;
        struct node * multipliedvalue=NULL;
        multipliedvalue= multiply_int(a,ansnode);
        multipliedvalue=reverse(multipliedvalue);
        multipliedvalue=remove_initial_zeros(multipliedvalue);

        //returns 1 if a-multipliedvalue is positive value
        if(recieve_quotient(product,multipliedvalue)==1) {
            ans = i;
            freeBigInt(multipliedvalue);
        }
        else
            break;
    }
    freeBigInt(ansnode);
    return ans;
}

struct node * divide(struct node * head1, struct node * head2 ) {
    if(compare(head1,head2)==0) return head1 = createnode(1);

    struct node* dividedhead=NULL;
    // Remove leading zeros
    head1 = remove_initial_zeros(head1);

    // Handle edge cases for division by zero or empty dividend
    if (head2 == NULL || remove_initial_zeros(head2) == NULL) {
        dividedhead = createnode(0);
        return dividedhead;
    }
    if (head1 == NULL) {
        dividedhead = createnode(0);
        return dividedhead;
    }

    struct node * remainderhead = NULL;
    int val = head1->val;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = NULL;
    remainderhead = newnode;
    head1 = head1->next;

    while (head1) {
        int quotient = quotient_genreator(head2, remove_initial_zeros(remainderhead));

        struct node * multipliedvalue = NULL;
        if ((dividedhead) == NULL && quotient == 0) {
            // EAT 5-STAR ... DO NOTHING
        } else {
            struct node * xyz = (struct node *)malloc(sizeof(struct node));
            xyz->val = quotient;
            xyz->next = NULL;

            appendnode(xyz, &dividedhead);
            struct node * head2temp = head2;
            multipliedvalue = multiply_int(head2temp, xyz);
            multipliedvalue = reverse(multipliedvalue);

            // Free the node xyz after use
            xyz=NULL;
        }

        struct node * temp = NULL;
        if (iszero(remainderhead) == 0) {
            remainderhead = remove_initial_zeros(remainderhead);
        }

        multipliedvalue = remove_initial_zeros(multipliedvalue);
        temp = subint(reverse(remainderhead), reverse(multipliedvalue));
        remainderhead = reverse(temp);

        struct node * iterator = remainderhead;
        while (iterator->next) {
            iterator = iterator->next;
        }

        int value = head1->val;
        head1 = head1->next;
        struct node * creatingnode = (struct node *)malloc(sizeof(struct node));
        creatingnode->val = value;
        creatingnode->next = NULL;
        iterator->next = creatingnode;

        if (iszero(remainderhead) == 0) {
            remainderhead = remove_initial_zeros(remainderhead);
        }

        // Free the multipliedvalue as it's no longer needed
        multipliedvalue=NULL;
    }

    int quotient = quotient_genreator(head2, remove_initial_zeros(remainderhead));

    struct node * multipliedvalue = NULL;
    if ((dividedhead) == NULL && quotient == 0) {
        // EAT 5-STAR ... DO NOTHING
    } else {
        struct node * abc = (struct node *)malloc(sizeof(struct node));
        abc->val = quotient;
        abc->next = NULL;

        appendnode(abc, &dividedhead);
        abc=NULL;
        // Free the node xyz after use

    }

    // Free the remainderhead as it is no longer needed
    remainderhead=NULL;
    return dividedhead;
}


int main() {
    int choice;
    int continue_choice;

    do {
        printf("\nWelcome to BIG-Integer Calculator\n\n");
        printf("Select the operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square\n");
        printf("7. Cube\n");
        printf("8. Square Root\n");
        printf("9. Factorial\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        struct node *a = NULL, *b = NULL, *result = NULL, *q=NULL;

        do {
            switch (choice) {
                case 1:
                    printf("Enter first big integer number:\n");
                    a = inputbigint();
                    printf("Enter second big integer number:\n");
                    b = inputbigint();
                    result = addint(a, b);
                    break;
                case 2:
                    printf("Enter first big integer number:\n");
                    a = inputbigint();
                    printf("Enter second big integer number:\n");
                    b = inputbigint();
                    result = subint(a, b);
                    break;
                case 3:
                    printf("Enter first big integer number:\n");
                    a = inputbigint();
                    printf("Enter second big integer number:\n");
                    b = inputbigint();
                    result = multiply_int(a, b);
                    break;
                case 4: // Division
                    printf("Enter dividend (big integer): ");
                    a = inputbigint();
                    a= reverse(a);
                    printf("Enter divisor (big integer): ");
                    b = inputbigint();
                    b= reverse(b);
                    result = reverse(divide(a,b));
                    break;
                case 5:
                    printf("Enter base big integer number:\n");
                    a = inputbigint();
                    printf("Enter exponent big integer number:\n");
                    b = inputbigint();
                    result = power_int(a, b);
                    break;
                case 6:
                    printf("Enter the big integer number to square:\n");
                    a = inputbigint();
                    result = square_int(a);
                    break;
                case 7:
                    printf("Enter the big integer number to cube:\n");
                    a = inputbigint();
                    result = cube_int(a);
                    break;
                case 8:
                    printf("Enter the big integer number to find square root:\n");
                    a = inputbigint();
                    result = sqrt_int(a);
                    break;
                case 9:
                    printf("Enter the big integer number to find factorial:\n");
                    a = inputbigint();
                    result = factorial(a);
                    break;
                case 10:
                    printf("Exiting...\n");
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
                    continue;
            }

            if (result != NULL) {
                result = reverse(result);
                result = remove_initial_zeros(result);
                printf("\nResult: ");
                printlist(result);
            } else{
                printf("result is null");
            }

            printf("\nDo you want to:\n");
            printf("1. Redo the operation\n");
            printf("2. Go back to main menu\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &continue_choice);
            getchar();

            if (continue_choice == 3) {
                printf("Exiting...\n");
                exit(0);
            } else if (continue_choice == 2) break;
        } while (continue_choice == 1);
    } while (1);
}
