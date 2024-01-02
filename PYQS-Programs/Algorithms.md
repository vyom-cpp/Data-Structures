# GTU PYQS ALGORITHMS
### Algorithm to insert in simple queue
```c
1. [Overflow?]
    if R>=N
    then  write('overflow')
        return
2. [Increment rear pointer]
    R<--R+1
3. [Insert element]
    Q[R]<--Y
4. [Is front pointer properly set?]
    if F=0
    then   F<--1
    return
// For all Queue operations here is the terminology (F & R are pointers to front and rear elements of a queue, Q is the queue and Y is the variable that set accordingly for insertion and deletion)
```
### Algorithm to delete from circular queue
```c
1. [Underflow?]
    if F=0
    then write('Underflow')
    return(0)
2. [Delete elemet]
    Y<--Q[F]
3. [Queue empty?]
    if F=R
    then F<--R<--0
    return(Y)
4. [Increment front pointer]
    if F=N
    then F<--1
    else F<--F+1
    return(Y)
```
### Algorithm for infix to postfix conversion
```c
1. [Initialize the stack]
    TOP<--1
    S[TOP]<--'#'
2. [Initialize output string and rank count]
    POLISH<--''
    RANK<--0
3. [Get first input symbol]
    NEXT<--NEXTCHAR(INFIX)
4. [Translate the infix expression]
    Repeat thru step 6 while NEXT != '#'
5. [Remove symbols with greater or equal precedence from stack]
    Repeat while f(NEXT) <= f(D[TOP])>
      TEMP<--POP(S,TOP)  // This copies stack contents into TEMP
      POLISH<--POLISH O TEMP
      RANK<--RANK+r(TEMP)
      if RANK<1
      then write('INVALID')
         EXIT
6. [Push current symbol onto stack and obtain next input symbol]
    Call PUSH(S,TOP,NEXT)
    NEXT<--NEXTCHAR(INFIX)
7. [Remove remaining elements from stack]
    Repeat while S[TOP] != '#'
       TEMP<--POP(S,TOP)
       POLISH--POLISH O TEMP
       RANK<--RANK+r(TEMP)
       if RANK<1
       then write('Invalid')
            EXIT
8. [Is the expression valid?]
    if RANK=1
    then write('Valid')
    else write('Invalid')
    EXIT
// INFIX = infix expression
// S = represents Stack
// NEXTCHAR = a string function
// RANK = contains value of each head of the reverse polish string
// NEXT = contains the symbol being examined
// TEMP = contains the unstacked element
// # = ensures that upon detection of '#' at the end of INFIX, the remaining elements of stack are put in POLISH
```
### Algorithm to insert in circular queue at first position
```c
1. [Queue Full?]
   if (F == (R + 1) mod N)
   then write('Queue Full')
        return(0)
2. [Empty Queue?]
   if (F == 0) and (R == 0)
   then F <-- R <-- 1
3. [Decrement Front Pointer]
   if (F == 1)
   then F <-- N
   else F <-- F - 1
4. [Insert Element]
   Q[F] <-- Y
5. return(Y)
```
### Algorithm to delete from simple queue
```c
1. [Underflow?]
    if F = 0
    then write('Underflow')
    return(0)   // 0 denotes an empty queue
2. [Delete element]
    Y<--Q[F]
3. [Queue empty?]
    if F = R
    then F<--R<--0
    else F<--F+1    // Increment front pointer
4. [Return element]
    Return(Y)
```
### Algorithm to merge two linked list
```c
1. [Check Empty Lists]
   if (Head1 == NULL)
      return Head2
   else if (Head2 == NULL)
      return Head1
2. [Initialize Merged List]
   MergedHead = MergedTail = NULL
3. [Initialize Pointers]
   Current1 = Head1
   Current2 = Head2
4. [Compare and Merge]
   while (Current1 != NULL and Current2 != NULL)
      if (Current1->data < Current2->data)
         Append Node(Current1->data) to MergedTail
         Move Current1 to the next node
      else
         Append Node(Current2->data) to MergedTail
         Move Current2 to the next node
5. [Handle Remaining Nodes]
   while (Current1 != NULL)
      Append Node(Current1->data) to MergedTail
      Move Current1 to the next node

   while (Current2 != NULL)
      Append Node(Current2->data) to MergedTail
      Move Current2 to the next node
6. return MergedHead
// Head1 and Head2 are the heads of the two sorted linked lists to be merged.
// MergedHead is the head of the merged sorted list.
// The Append Node operation adds a new node with the specified data to the end of the merged list.
```
### Algorithm to insert in a binary search tree
```c
void insert(node *root, node *New)
{
    if(New->data < root->data){
        if(root->left == NULL){
            root->left = New;
        }
        else{
            insert(root->left, New);
        }
    }
    if(New->data > root->data){
        if(root->right == NULL){
            root->right = New;
        }
        else{
            insert(root->right, New);
        }
    }
}
```
### Algorithm to count nodes in a circular queue
```c
1. [Check Empty Queue]
   if (Front == -1)
      return 0
2. [Initialize Count]
   Count = 0
3. [Count Nodes]
   Current = Front
   repeat
      Count = Count + 1
      Current = (Current + 1) mod N
   until Current is equal to Rear + 1
4. return Count
// Front is the front pointer of the circular queue.
// Rear is the rear pointer of the circular queue.
// N is the maximum size of the circular queue.
```
### Algorithm for quick sort
```c
pivot<--A[low]
i<--low
j<--high+1
while(i<=j)do{
    while(A[i]<=pivot)do
    i<--i+1
    while(A[j]>=pivot)do
    j<--j-1
    if(i<=j)then
    swap(A[i],A[j]) // Swaps A[i] and A[j]
}
swap(A[low], A[j]) // when i crosses j swap A[low] and A[j]
return j // rightmost index of the list
```
### Algorithm for bubble sort
```c
BUBBLE_SORT(K,N) // A vector K of N elements
1. [Initialize]
    LAST<--N // enitre list assumed unsorted at this point
2. [Loop on pass index]
    Repeat thru step 5 for PASS = 1, 2, 3, ..., N-1
3. [Initialize exchanges counter for this pass]
    EXCHS<--0
4. [Perform pairwise comparisons on unsorted elements]
    Repeat for i = 1, 2, 3, ..., LAST-1
      if K[i] > K[i+1]
      then K[i]<-->K[i+1]
        EXCHS<--EXCHS+1
5. [Were any exchanges made on this pass?]
    if EXCHS=0
    then Return // misson accomplished; return early
    else LAST<--LAST-1 // reduced size of unsorted list
6. [Finished]
    Return // maximum number of passes required
```
### Algorithm for selection sort
```c
SELECTION_SORT(K,N) // A vector K of N elements
1. [Loop on ppass index]
    Repeat thru step 4 for PASS = 1, 2, 3, ..., N - 1
2. [Initialize minimum index]
    MIN_INDEX<--PASS
3. [Make a pass and obtain element with smallest value]
    Repat for i = PASS+1, PASS+2, ..., N
      if K[i] < K[MIN_INDEX]
      then MIN_INDEX <-- 1
4. [Exhange elements]
    if MIN_INDEX != PASS
    then K[PASS]<-->K[MIN_INDEX]
5. [Finished]
    Return
```
### Algorithm for merge sort
```c
SIMPLE_MERGE(K, FIRST, SECOND, THIRD)
1. [Initialize]
    i<--FIRST
    j<--SECOND
    l<--0
2. [Compare corresponding elements and output the smallest]
    Repeat while i < SECOND and j <= THIRD
      if K[i] <= K[j]
      then l <-- l+1
           TEMP[l]<--K[i]
           i<--i+1
      else l <-- l+1
           TEMP[l] <-- K[j]
           j <-- j+1
3. [Copy the remaining unprocessed elements in output area]
    if i>= SECOND
    then repeat while j<=THIRD
        l<--l+1
        TEMP[l]<--K[j]
        j<--j+1
    else repeat while i<SECOND
        l<--l+1
        TEMP[l]<--K[i]
        i<--i+1
4. [Copy elements in temporary vector into original area]
    repeat for i = 1, 2, 3, .., l
        K[FIRST - 1 + i]<--TEMP[i]
5. [Finished]
    return
```
### Algorithm for linear search
```c
Input: Array A of size n, Search element X

1. Set position to -1 (initially not found).
2. For each element A[i] in the array A:
   a. If A[i] is equal to X:
      i. Set position to i.
      ii. Break from the loop (element found).
3. If position is -1:
   a. Display "Element not found".
4. Else:
   a. Display "Element found at position: position".
```
### Algorithm for binary search
```c
Input: Sorted array A of size n, Search element X

1. Set low to 0 (initial index of the array).
2. Set high to n - 1 (final index of the array).
3. While low is less than or equal to high:
   a. Set mid to the floor of (low + high) / 2.
   b. If A[mid] is equal to X:
      i. Return mid (element found).
   c. If A[mid] is less than X:
      i. Set low to mid + 1.
   d. If A[mid] is greater than X:
      i. Set high to mid - 1.
4. If low is greater than high:
   a. Return -1 (element not found).
```
### Algorithm to insert in doubly linked list
```c

```
### Algorithm to delete from doubly linked list
```c

```
### Algorithm to display elements of circular queue
```c

```
### Algorithm to find length of singly liked list
```c

```
### Algorithm to delete a node in a binary search tree
```c

```
### Algorithm to insert a node at a specific position in a singly linked list
```c

```
### Recursive function to compute factorial using stack
```c

```
### Algorithm for iterative pre-order traversal in a binary search tree
```c

```