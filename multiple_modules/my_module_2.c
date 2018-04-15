// Note: this only works for Python 3, not Python 2.7
#include <Python.h>  // MUST come before all other includes

static PyObject* subtract_wrapper(PyObject* self, PyObject* args,
                                  PyObject* keywds) {
  int x, y;
  static char* kwlist[] = {"x", "y", NULL};

  PyArg_ParseTupleAndKeywords(args, keywds, "ii", kwlist, &x, &y);
  int z = x - y;
  printf("Hello from subtract_wrapper: x = %d, y = %d, thus z = %d\n", x, y, z);

  return PyLong_FromLong(z);  // return the answer back to Python
}

// a bunch of 4-tuples whose entries are:
// 1: What the function is to be called in Python
// 2: the C function that implements it
// 3: some flags to say it can be called by kwargs or by args
// 4: The documentation string
static PyMethodDef list_of_methods[] = {
    {"subtract", (PyCFunction)subtract_wrapper, METH_VARARGS | METH_KEYWORDS,
     "Subtracts y from x."},
    {NULL, NULL, 0, NULL} /* this is a sentinel value to end the list */
};

static struct PyModuleDef mymodule_def = {
    PyModuleDef_HEAD_INIT, "dog",
    "Here is the documentation for the dog module", -1, list_of_methods};

PyMODINIT_FUNC PyInit_my_module_2(
    void)  // this MUST be named "PyInit_" ++ <name_of_module>
{
  return PyModule_Create(&mymodule_def);
}
