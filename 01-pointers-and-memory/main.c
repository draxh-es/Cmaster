#include <stdio.h>
#include <stdlib.h>

/*
 * 01 - Pointers, structs and malloc
 *
 * Implement every function marked TODO, then run:
 *     make run L=01-pointers-and-memory
 *
 * main() tests each exercise and prints PASS or FAIL.
 * The "(void)x;" lines only silence unused-parameter warnings.
 * Delete them as you implement each function.
 */

// ============================================================
// Exercises
// ============================================================

// Exercise 1: Multiply the value that x points to by 2.
void double_it(int *x) {
    // TODO
    *x *=2;
}

// Exercise 2: Store the smallest element of arr in *min and the largest in *max.
// You can assume n >= 1.
void min_max(const int *arr, size_t n, int *min, int *max) {
    // TODO
    *min = arr[0];
    *max = arr[0];
    for(size_t i = 0;i<n;i++){
        if(arr[i]<*min){
            *min = arr[i];
        }
        if(arr[i]>*max){
            *max = arr[i];
        }
    }

    
}

// Exercise 3: Return how many elements of arr are even.
size_t count_even(const int *arr, size_t n) {
    // TODO
    size_t c = 0;
    for(size_t i = 0;i<n;i++){
        if(arr[i]%2==0){
            c++;
        }
    }
    return c;
}

// Exercise 4: Reverse arr in place: {1, 2, 3} becomes {3, 2, 1}.
// Hint: swap elements from both ends toward the middle.
// Careful: n can be 0, and size_t cannot go below 0.
void reverse(int *arr, size_t n) {
    // TODO
    for(size_t i = 0;i<n/2;i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }

}

typedef struct {
    int x;
    int y;
} Point;

// Exercise 5: Move the point by (dx, dy). The caller's point must change.
void point_move(Point *p, int dx, int dy) {
    // TODO
    p->x += dx;
    p->y += dy;

}

// Exercise 6: Return a new Point halfway between a and b.
// Integer division is fine: midpoint of {0,0} and {3,3} is {1,1}.
Point point_midpoint(Point a, Point b) {
    // TODO
    Point result;
    result.x = (a.x+b.x)/2;
    result.y = (a.y+b.y)/2;


    return result;
}

typedef struct {
    char name[32];
    double gpa;
} Student;

// Exercise 7: Return the ADDRESS of the student with the highest gpa.
// Return NULL if n is 0.
const Student *best_student(const Student *students, size_t n) {
    // TODO
    const Student *best = students;
    if(n==0)
    return NULL;

    for(size_t i = 0;i<n;i++){

        if(students[i].gpa>best->gpa){
            best = &students[i];
        }
    }
    
    return best;
}

// Exercise 8: Allocate an array of n ints holding 0, 1, 2, ..., n-1 and return it.
// Return NULL if malloc fails. The caller is responsible for freeing it.
int *make_range(size_t n) {
    // TODO{
    int* arr = malloc(n*sizeof(int));
    if(arr==NULL)
    return NULL;
    for(size_t i = 0 ; i<n;i++){
        *(arr+i)=i;
    }
    
    return arr;
}

// Exercise 9: Return a newly allocated copy of arr (a different block of memory
// with the same values). Return NULL if malloc fails. The caller frees it.
int *copy_array(const int *arr, size_t n) {
    // TODO
    int * copy = malloc(sizeof(int)*n);
    if(copy==NULL){
        return NULL;
    }
    for(size_t i=0;i<n;i++){
        copy[i]=arr[i];
    }
    
    
    return copy;
}

// A dynamic array: it grows when it runs out of room.
typedef struct {
    int *data;        // heap memory holding the elements
    size_t size;      // how many elements are in use
    size_t capacity;  // how many elements fit before we must grow
} Vector;

// Exercise 10: Make v an empty vector: data = NULL, size = 0, capacity = 0.
void vec_init(Vector *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

// Exercise 11: Append value to the end of v.
// If the vector is full (size == capacity), grow it first with realloc:
// capacity 0 becomes 4, otherwise double it.
// Return 0 on success, -1 if realloc fails (leave v unchanged in that case).
int vec_push(Vector *v, int value) {
    // TODO;
    int* c;
    if(v->capacity==0){
        
        c = malloc(sizeof(int)*4);
        if(c==NULL)
        return -1;
        v->data = c;
    v->capacity = 4;
    }else if(v->size==v->capacity){

        c=realloc(v->data,v->capacity*sizeof(int)*2);
        if(c==NULL)
        return -1;
        v->data = c;

    v->capacity*=2;

    }

    v->data[v->size] = value;

    v->size++;
    return 0;
}

// Exercise 12: Free v's memory and reset it to empty (same state as vec_init).
void vec_free(Vector *v) {
    free(v->data);
    v->data=NULL;
    v->size = 0;
    v->capacity = 0;
}

// ============================================================
// Tests: no need to edit anything below (except the bonus at the end)
// ============================================================

static int passed = 0;
static int failed = 0;

// You don't need to understand this macro yet; macros come in lesson 11.
#define CHECK(cond)                                                      \
    do {                                                                 \
        if (cond) {                                                      \
            passed++;                                                    \
        } else {                                                         \
            failed++;                                                    \
            printf("    expected: %s (line %d)\n", #cond, __LINE__);     \
        }                                                                \
    } while (0)

static int same(const int *a, const int *b, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

static void test_double_it(void) {
    int x = 5;
    double_it(&x);
    CHECK(x == 10);
    x = -3;
    double_it(&x);
    CHECK(x == -6);
}

static void test_min_max(void) {
    int a[] = {4, -2, 9, 0, 7};
    int mn = 0, mx = 0;
    min_max(a, 5, &mn, &mx);
    CHECK(mn == -2);
    CHECK(mx == 9);

    int one[] = {42};
    min_max(one, 1, &mn, &mx);
    CHECK(mn == 42 && mx == 42);
}

static void test_count_even(void) {
    int a[] = {1, 2, 3, 4, 6};
    CHECK(count_even(a, 5) == 3);
    CHECK(count_even(a, 1) == 0);
    CHECK(count_even(a, 0) == 0);
}

static void test_reverse(void) {
    int a[] = {1, 2, 3, 4, 5};
    int a_rev[] = {5, 4, 3, 2, 1};
    reverse(a, 5);
    CHECK(same(a, a_rev, 5));

    int b[] = {1, 2};
    int b_rev[] = {2, 1};
    reverse(b, 2);
    CHECK(same(b, b_rev, 2));

    int c[] = {7};
    reverse(c, 0);
    reverse(c, 1);
    CHECK(c[0] == 7);
}

static void test_point_move(void) {
    Point p = {1, 2};
    point_move(&p, 3, -5);
    CHECK(p.x == 4 && p.y == -3);
}

static void test_point_midpoint(void) {
    Point a = {0, 0};
    Point b = {4, 10};
    Point m = point_midpoint(a, b);
    CHECK(m.x == 2 && m.y == 5);
    CHECK(a.x == 0 && b.x == 4);  // originals must not change
}

static void test_best_student(void) {
    Student s[] = {
        {"Alice", 3.1},
        {"Bob", 3.9},
        {"Carol", 3.5},
    };
    CHECK(best_student(s, 3) == &s[1]);
    CHECK(best_student(s, 1) == &s[0]);
    CHECK(best_student(s, 0) == NULL);
}

static void test_make_range(void) {
    int expected[] = {0, 1, 2, 3, 4};
    int *r = make_range(5);
    CHECK(r != NULL);
    if (r != NULL) {
        CHECK(same(r, expected, 5));
    }
    free(r);
}

static void test_copy_array(void) {
    int src[] = {3, 1, 4, 1, 5};
    int *c = copy_array(src, 5);
    CHECK(c != NULL);
    if (c != NULL) {
        CHECK(c != src);  // must be new memory, not the same address
        CHECK(same(c, src, 5));
        c[0] = 99;
        CHECK(src[0] == 3);  // changing the copy must not touch the original
    }
    free(c);
}

static void test_vector(void) {
    int dummy = 0;
    Vector v = {&dummy, 99, 99};  // garbage on purpose; vec_init must reset it
    vec_init(&v);
    CHECK(v.data == NULL && v.size == 0 && v.capacity == 0);

    int all_pushed = 1;
    for (int i = 0; i < 10; i++) {
        if (vec_push(&v, i * i) != 0) {
            all_pushed = 0;
        }
    }
    CHECK(all_pushed);
    CHECK(v.size == 10);
    CHECK(v.capacity == 16);  // 0 -> 4 -> 8 -> 16
    if (v.size == 10 && v.data != NULL) {
        int expected[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
        CHECK(same(v.data, expected, 10));
    }

    vec_free(&v);
    CHECK(v.data == NULL && v.size == 0 && v.capacity == 0);
}

static void run(const char *name, void (*test)(void)) {
    int failed_before = failed;
    test();
    printf("[%s] %s\n", failed == failed_before ? "PASS" : "FAIL", name);
}

int main(void) {
    run("Exercise 1   double_it", test_double_it);
    run("Exercise 2   min_max", test_min_max);
    run("Exercise 3   count_even", test_count_even);
    run("Exercise 4   reverse", test_reverse);
    run("Exercise 5   point_move", test_point_move);
    run("Exercise 6   point_midpoint", test_point_midpoint);
    run("Exercise 7   best_student", test_best_student);
    run("Exercise 8   make_range", test_make_range);
    run("Exercise 9   copy_array", test_copy_array);
    run("Exercise 10-12  vector", test_vector);

    printf("\n%d checks passed, %d failed\n", passed, failed);

    // Bonus: see AddressSanitizer in action.
    // Uncomment ONE line at a time, run, and read the report. Then comment it back.
    // int *p = malloc(sizeof *p); free(p); *p = 1;   // use after free
    // int *q = malloc(sizeof *q); *q = 1;            // memory leak (never freed)
    // int arr[3]; int i = 3; arr[i] = 0;             // out of bounds write

    return 0;
}
