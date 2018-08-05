#include <Python.h>

#include <stdio.h>
#include <time.h>

#include "SFMT-src-1.5.1/SFMT.h"

// 乱数のデータが格納される構造体
sfmt_t sfmt;

/**
 * 整数の乱数を num 個 print する関数
 * @param num print する乱数の数を指定する
 */
void print_rand_int(int num) {
    // Print header
    printf("# print %d random int\n", num);
    fflush(stdout);

    // Print rand
    for (int i = 0; i < num; i++) {
        printf("%10llu ", sfmt_genrand_uint64(&sfmt));
        if (i % 5 == 4) printf("\n");
    }
    printf("\n");
    fflush(stdout);
}

/**
 * [0, 1) の乱数を num 個 print する関数
 * @param num print する乱数の数を指定する
 */
void print_rand(int num) {
    // Print header
    printf("# print %d random numbers\n", num);
    fflush(stdout);

    // Print rands
    for (int i = 0; i < num; i++) {
        printf("%10.8f ", sfmt_genrand_real2(&sfmt));
        if (i % 5 == 4) printf("\n");
    }
    printf("\n");
    fflush(stdout);
}

/**
 * print_rand_int() を実行する Python メソッド
 */
static PyObject *
twister_print_rand_int(PyObject *self, PyObject *args) {
    int num = 10;
    if (!PyArg_ParseTuple(args, "|l", &num)) {
        return NULL;
    }
    print_rand_int(num);
    Py_RETURN_NONE;
}

/**
 * print_rand() を実行する Python メソッド
 */
static PyObject *
twister_print_rand(PyObject *self, PyObject *args) {
    int num = 10;
    if (!PyArg_ParseTuple(args, "|l", &num)) {
        return NULL;
    }
    print_rand(num);
    Py_RETURN_NONE;
}

/**
 * 乱数を1つ生成する Python メソッド
 */
static PyObject *
twister_random(PyObject *self, PyObject *args) {
    return PyFloat_FromDouble(sfmt_genrand_real2(&sfmt));
}

/**
 * 乱数を1つ生成する Python メソッド
 */
static PyObject *
twister_randint(PyObject *self, PyObject *args) {
    // [start, end) のパラメータをパースする
    long start, end;
    if (!PyArg_ParseTuple(args, "ll", &start, &end)) {
        return NULL;
    }

    // [0, 1) の乱数を、指定した範囲に正規化して、整数に変換する
    double r = sfmt_genrand_real2(&sfmt);
    return PyLong_FromLong((long)(r * (end - start) + start));
}

/**
 * 拡張モジュールのメソッドの定義
 */
static PyMethodDef TwisterMethods[] = {
        {"print_rand_int", twister_print_rand_int, METH_VARARGS, "Print random int num times."},
        {"print_rand",     twister_print_rand,     METH_VARARGS, "Print random x in [0, 1) num times."},
        {"random",         twister_random,         METH_VARARGS, "Generate a random number x in [0, 1)."},
        {"randint",        twister_randint,        METH_VARARGS, "Generate a random int in the range [start, end)."},
        {NULL, NULL},
};

/**
 * 拡張モジュールの定義
 */
static struct PyModuleDef twistermodule = {
        PyModuleDef_HEAD_INIT,
        "twister",
        "Generate random numbers by using Mersenne twister.",
        -1,
        TwisterMethods,
};

/**
 * モジュール読み込み時に行われる初期化処理
 * @return
 */
PyMODINIT_FUNC
PyInit_twister(void) {
    // 現在時刻をシードに与えて乱数を初期化する
    sfmt_init_gen_rand(&sfmt, (uint32_t) time(NULL));

    return PyModule_Create(&twistermodule);
}
