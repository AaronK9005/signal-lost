#include <stdio.h>

#include "../include/loadbar.h"

loadbar_t lb_create(int max, int value, int len) {
    int safe_max = (max > 0 ? max : LB_DEFAULT_MAX);
    int safe_val = (value <= safe_max ? (value >= 0 ? value: LB_DEFAULT_VAL) : safe_max);
    int safe_len = (len <= LOADBAR_MAX_LEN ? (len > 0 ? len : LB_DEFAULT_LEN) : LOADBAR_MAX_LEN);

    return (loadbar_t)
    {
        safe_max,
        safe_val,
        safe_len
    };
}

loadbar_t lb_default(int len) {
    return (loadbar_t) {
        100,
        0,
        (len <= LOADBAR_MAX_LEN ? (len > 0 ? len : LB_DEFAULT_LEN) : LOADBAR_MAX_LEN)
    };
}

void lb_print(const loadbar_t* lb) {
    if (!lb || lb->max <= 0) return;

    char buffer[LOADBAR_MAX_LEN + 3];

    buffer[0] = '[';
    buffer[lb->len + 1] = ']';

    int filled = (lb->value * lb->len) / lb->max;

    for (int i = 1; i <= lb->len; i++) {
        buffer[i] = (i <= filled) ? '#' : '-';
    }

    printf("%.*s", lb->len + 2, buffer);
}

void bar_print(const char* promt, const loadbar_t* lb, int val) {
    if (!lb) return;

    loadbar_t lb_temp = *lb;
    lb_temp.value = val;

    printf("%s ", promt);
    lb_print(&lb_temp);
    printf("\t%d/%d", val, lb->max);
    putchar('\n');
}