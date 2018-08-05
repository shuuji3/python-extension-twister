#include <Python.h>

#include <time.h>
#include "twister.h"

// 整数の乱数を20個 print する関数
void print_rand_int(int num) {
    printf("# print %d random int\n", num);
    for (int i = 0; i < num; i++) {
        printf("%10lu ", genrand_int32());
        if (i % 5 == 4) printf("\n");
    }
}

// 0 <= r < 1 の乱数を20個 print する関数
void print_rand(int num) {
    printf("# print %d random number\n", num);
    for (int i = 0; i < num; i++) {
        printf("%10.8f ", genrand_real2());
        if (i % 5 == 4) printf("\n");
    }
}

static PyObject *
twister_print_rand_int(PyObject *self, PyObject *args) {
    int num = 1;
    if (!PyArg_ParseTuple(args, "|l", &num)) {
        return NULL;
    }
    print_rand_int(num);
    Py_RETURN_NONE;
}

static PyObject *
twister_print_rand(PyObject *self, PyObject *args) {
    int num = 1;
    if (!PyArg_ParseTuple(args, "|l", &num)) {
        return NULL;
    }
    print_rand(num);
    Py_RETURN_NONE;
}

static PyMethodDef TwisterMethods[] = {
        {"print_rand_int", twister_print_rand_int, METH_VARARGS, "Print random int num times."},
        {"print_rand",     twister_print_rand,     METH_VARARGS, "Print random r (0 <= r < 1) num times."},
        {NULL, NULL},
};

static struct PyModuleDef twistermodule = {
        PyModuleDef_HEAD_INIT,
        "twister",
        "Generate random numbers by using Mersenne twister.",
        -1,
        TwisterMethods,
};

PyMODINIT_FUNC
PyInit_twister(void) {
    // モジュール読み込み時に現在時刻で乱数を初期化する
    init_genrand((unsigned long) time(NULL));

    return PyModule_Create(&twistermodule);
}

int main(void) {
    print_rand(10);
    print_rand_int(20);
}