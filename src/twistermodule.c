#include <Python.h>

#include <stdio.h>
#include <time.h>
#include "mt19937ar/mt19937ar.h"

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
        printf("%10lu ", genrand_int32());
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
        printf("%10.8f ", genrand_real2());
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
    return PyFloat_FromDouble(genrand_real2());
}

/**
 * 拡張モジュールのメソッドの定義
 */
static PyMethodDef TwisterMethods[] = {
        {"print_rand_int", twister_print_rand_int, METH_VARARGS, "Print random int num times."},
        {"print_rand",     twister_print_rand,     METH_VARARGS, "Print random x in [0, 1) num times."},
        {"random",         twister_random,         METH_VARARGS, "Generate a random number x in [0, 1)."},
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
    init_genrand((unsigned long) time(NULL));

    return PyModule_Create(&twistermodule);
}
