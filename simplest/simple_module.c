// Note: this only works for Python 3, not Python 2.7
#include <Python.h>  // MUST come before all other includes
#include "stdio.h"

void echo(int x) { printf("Yo! Hello from C: x = %d\n", x); }

static PyObject* echo_wrapper(PyObject* self, PyObject* args,
                              PyObject* keywds) {
  // just echos an integer back from C.
  int x;
  static char* kwlist[] = {"x", NULL};  // that NULL is a sentinel terminator

  PyArg_ParseTupleAndKeywords(args, keywds, "i", kwlist, &x);

  echo(x);  // call the echo procedure, defined in its own separate file echo.c

  Py_RETURN_NONE;  // the easiest way to return Python None
}

static PyObject* add_wrapper(PyObject* self, PyObject* args, PyObject* keywds) {
  int x, y;
  static char* kwlist[] = {"x", "y", NULL};

  PyArg_ParseTupleAndKeywords(args, keywds, "ii", kwlist, &x, &y);
  int z = x + y;
  printf("Hello from C: x = %d, y = %d, thus z = %d\n", x, y, z);

  return PyLong_FromLong(z);  // return the answer back to Python
}

// a bunch of 4-tuples that say
// 1: What the function is called in Python
// 2: the C function that implements it
// 3: some flags to say it can be called by kwargs or by args
// Documentation
static PyMethodDef list_of_methods[] = {
    {"echo", (PyCFunction)echo_wrapper, METH_VARARGS | METH_KEYWORDS,
     "Echos back an integer"},
    {"add", (PyCFunction)add_wrapper, METH_VARARGS | METH_KEYWORDS,
     "Adds x and y."},
    {NULL, NULL, 0, NULL} /* this is a sentinel value to end the list */
};

static struct PyModuleDef mymodule_def = {
    PyModuleDef_HEAD_INIT, "mymodule", "Here is the documentation for mymodule",
    -1, list_of_methods};

PyMODINIT_FUNC PyInit_simple_module(
    void)  // this MUST be named "PyInit_" ++ <name_of_module>
{
  return PyModule_Create(&mymodule_def);
}
