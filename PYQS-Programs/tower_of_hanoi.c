#include <stdio.h>

// Function to move a ring from one peg to another
void moveRing(char from, char to) {
    printf("Move ring from %c to %c\n", from, to);
}

// Function to solve Tower of Hanoi for 3 rings
void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        moveRing(source, target);
    } else {
        towerOfHanoi(n - 1, source, target, auxiliary);
        moveRing(source, target);
        towerOfHanoi(n - 1, auxiliary, source, target);
    }
}

int main() {
    int rings = 3;
    printf("Tower of Hanoi solution for %d rings:\n", rings);
    towerOfHanoi(rings, 'A', 'B', 'C');
    return 0;
}
