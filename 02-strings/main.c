#include <stdio.h>
#include <stdlib.h>

/*
 * 02 - Strings and character arrays
 *
 * Implement every function marked TODO, then run:
 *     make run L=02-strings
 *
 * Rule: do NOT use <string.h> (strlen, strcpy, ...) in your solutions.
 * You are writing those functions yourself. You may call your own
 * functions from later exercises.
 *
 * Key facts:
 *   - A C string is a char array that ends with '\0' (the null terminator).
 *     "hi" takes 3 bytes: 'h', 'i', '\0'.
 *   - The length of a string does not include the '\0'.
 *   - String literals ("hello") are read-only. Writing to one is undefined
 *     behavior. To modify a string, it must live in an array or heap memory:
 *         char s[] = "hello";   // modifiable copy on the stack
 *   - A function that writes into a caller's buffer must be told its size.
 */

// ============================================================
// Exercises
// ============================================================

// Exercise 1: Return the length of s, not counting the '\0'.
size_t my_strlen(const char *s) {
    // TODO
    (void)s;
    return 0;
}

// Exercise 2: Copy src into dst, where dst can hold dst_size bytes.
// Copy as much as fits and ALWAYS end dst with '\0' (unless dst_size is 0,
// in which case write nothing at all).
// Return the length of src, so the caller can detect truncation.
// Example: dst_size 4, src "hello" -> dst becomes "hel", returns 5.
size_t str_copy(char *dst, size_t dst_size, const char *src) {
    // TODO
    (void)dst;
    (void)dst_size;
    (void)src;
    return 0;
}

// Exercise 3: Compare a and b character by character.
// Return 0 if they are equal, a negative number if a comes first,
// a positive number if b comes first. "ab" comes before "abc".
int my_strcmp(const char *a, const char *b) {
    // TODO
    (void)a;
    (void)b;
    return 0;
}

// Exercise 4: Convert every lowercase letter in s to uppercase, in place.
// Leave every other character unchanged. Hint: chars are small integers,
// and 'a'..'z' and 'A'..'Z' are consecutive.
void to_upper(char *s) {
    // TODO
    (void)s;
}

// Exercise 5: Return how many times c appears in s.
size_t count_char(const char *s, char c) {
    // TODO
    (void)s;
    (void)c;
    return 0;
}

// Exercise 6: Reverse s in place: "abc" becomes "cba". The '\0' stays at the end.
void str_reverse(char *s) {
    // TODO
    (void)s;
}

// Exercise 7: Return a newly allocated copy of s. Return NULL if malloc fails.
// The caller frees it. Think about how many bytes you need.
char *str_dup(const char *s) {
    // TODO
    (void)s;
    return NULL;
}

// Exercise 8: Return a newly allocated string holding a followed by b.
// Example: "foo", "bar" -> "foobar". Return NULL if malloc fails.
char *str_concat(const char *a, const char *b) {
    // TODO
    (void)a;
    (void)b;
    return NULL;
}

// Exercise 9: Parse a decimal integer with an optional leading '-'.
// On success store it in *out and return 0.
// Return -1 (and leave *out unchanged) if s is empty, is just "-", or
// contains anything other than digits after the optional '-'.
// You can ignore overflow for now.
// Examples: "42" -> 42, "-17" -> -17, "12a" -> error, "" -> error.
int parse_int(const char *s, int *out) {
    // TODO
    (void)s;
    (void)out;
    return -1;
}

// Exercise 10: Parse a "key=value" line, like a tiny config/command protocol.
// Copy the part before '=' into key (key can hold key_size bytes) and parse
// the part after '=' as an integer into *value.
// Return 0 on success, -1 if:
//   - there is no '='
//   - the key is empty, or does not fit in key_size bytes (with its '\0')
//   - the value is not a valid integer (see parse_int)
// Examples: "temp=23" -> key "temp", value 23.  "temp=" -> error.
int parse_kv(const char *line, char *key, size_t key_size, int *value) {
    // TODO
    (void)line;
    (void)key;
    (void)key_size;
    (void)value;
    return -1;
}

// ============================================================
// Tests: no need to edit anything below (except the bonus at the end)
// ============================================================

#include <string.h>  // tests only: used to check your results

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

static void test_my_strlen(void) {
    CHECK(my_strlen("") == 0);
    CHECK(my_strlen("a") == 1);
    CHECK(my_strlen("hello") == 5);
}

static void test_str_copy(void) {
    char buf[8] = "";
    CHECK(str_copy(buf, sizeof buf, "hi") == 2);
    CHECK(strcmp(buf, "hi") == 0);

    char small[4] = "";
    CHECK(str_copy(small, sizeof small, "hello") == 5);
    CHECK(strcmp(small, "hel") == 0);  // truncated but still terminated

    char untouched = 'Z';
    CHECK(str_copy(&untouched, 0, "abc") == 3);
    CHECK(untouched == 'Z');  // dst_size 0: nothing written
}

static void test_my_strcmp(void) {
    CHECK(my_strcmp("abc", "abc") == 0);
    CHECK(my_strcmp("", "") == 0);
    CHECK(my_strcmp("abc", "abd") < 0);
    CHECK(my_strcmp("b", "a") > 0);
    CHECK(my_strcmp("ab", "abc") < 0);
    CHECK(my_strcmp("abc", "ab") > 0);
}

static void test_to_upper(void) {
    char s[] = "Hello, World 42!";
    to_upper(s);
    CHECK(strcmp(s, "HELLO, WORLD 42!") == 0);

    char empty[] = "";
    to_upper(empty);
    CHECK(empty[0] == '\0');
}

static void test_count_char(void) {
    CHECK(count_char("banana", 'a') == 3);
    CHECK(count_char("banana", 'z') == 0);
    CHECK(count_char("", 'a') == 0);
}

static void test_str_reverse(void) {
    char a[] = "abc";
    str_reverse(a);
    CHECK(strcmp(a, "cba") == 0);

    char b[] = "ab";
    str_reverse(b);
    CHECK(strcmp(b, "ba") == 0);

    char c[] = "x";
    str_reverse(c);
    CHECK(strcmp(c, "x") == 0);

    char d[] = "";
    str_reverse(d);
    CHECK(d[0] == '\0');
}

static void test_str_dup(void) {
    const char *src = "hello";
    char *d = str_dup(src);
    CHECK(d != NULL);
    if (d != NULL) {
        CHECK(d != src);  // must be new memory
        CHECK(strcmp(d, "hello") == 0);
    }
    free(d);

    char *e = str_dup("");
    CHECK(e != NULL);
    if (e != NULL) {
        CHECK(e[0] == '\0');
    }
    free(e);
}

static void test_str_concat(void) {
    char *s = str_concat("foo", "bar");
    CHECK(s != NULL);
    if (s != NULL) {
        CHECK(strcmp(s, "foobar") == 0);
    }
    free(s);

    char *t = str_concat("", "x");
    CHECK(t != NULL);
    if (t != NULL) {
        CHECK(strcmp(t, "x") == 0);
    }
    free(t);
}

static void test_parse_int(void) {
    int out = 0;
    CHECK(parse_int("42", &out) == 0 && out == 42);
    CHECK(parse_int("-17", &out) == 0 && out == -17);
    CHECK(parse_int("0", &out) == 0 && out == 0);

    out = 99;
    CHECK(parse_int("", &out) == -1);
    CHECK(parse_int("-", &out) == -1);
    CHECK(parse_int("12a", &out) == -1);
    CHECK(parse_int("abc", &out) == -1);
    CHECK(out == 99);  // unchanged after errors
}

static void test_parse_kv(void) {
    char key[16] = "";
    int value = 0;
    CHECK(parse_kv("temp=23", key, sizeof key, &value) == 0);
    CHECK(strcmp(key, "temp") == 0 && value == 23);

    CHECK(parse_kv("led=-1", key, sizeof key, &value) == 0);
    CHECK(strcmp(key, "led") == 0 && value == -1);

    CHECK(parse_kv("noequals", key, sizeof key, &value) == -1);
    CHECK(parse_kv("=5", key, sizeof key, &value) == -1);
    CHECK(parse_kv("temp=", key, sizeof key, &value) == -1);
    CHECK(parse_kv("temp=2x", key, sizeof key, &value) == -1);

    char tiny[4] = "";
    CHECK(parse_kv("abc=1", tiny, sizeof tiny, &value) == 0);  // "abc" + '\0' fits
    CHECK(parse_kv("abcd=1", tiny, sizeof tiny, &value) == -1);  // does not fit
}

static void run(const char *name, void (*test)(void)) {
    int failed_before = failed;
    test();
    printf("[%s] %s\n", failed == failed_before ? "PASS" : "FAIL", name);
}

int main(void) {
    run("Exercise 1   my_strlen", test_my_strlen);
    run("Exercise 2   str_copy", test_str_copy);
    run("Exercise 3   my_strcmp", test_my_strcmp);
    run("Exercise 4   to_upper", test_to_upper);
    run("Exercise 5   count_char", test_count_char);
    run("Exercise 6   str_reverse", test_str_reverse);
    run("Exercise 7   str_dup", test_str_dup);
    run("Exercise 8   str_concat", test_str_concat);
    run("Exercise 9   parse_int", test_parse_int);
    run("Exercise 10  parse_kv", test_parse_kv);

    printf("\n%d checks passed, %d failed\n", passed, failed);

    // Bonus: see AddressSanitizer catch classic string bugs.
    // Uncomment ONE block at a time, run, read the report, comment it back.
    //
    // Forgetting the '\0' byte (off-by-one):
    // char *p = malloc(5); for (int i = 0; i < 5; i++) p[i] = "hello"[i];
    // p[5] = '\0'; free(p);
    //
    // Writing to a string literal (may crash with a segfault):
    // char *lit = "hello"; lit[0] = 'J';

    return 0;
}
