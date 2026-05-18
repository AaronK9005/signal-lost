#pragma once

#define LOADBAR_MAX_LEN 77

#define LB_DEFAULT_MAX 100
#define LB_DEFAULT_VAL 0
#define LB_DEFAULT_LEN 20

typedef struct loadbar_t {
    int max;
    int value;
    int len;
} loadbar_t;

loadbar_t lb_create(int max, int value, int len);

loadbar_t lb_default(int len);

void lb_print(const loadbar_t* lb);

void bar_print(const char* promt, const loadbar_t* lb, int val);
