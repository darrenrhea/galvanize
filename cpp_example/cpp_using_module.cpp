#define PY_SSIZE_T_CLEAN
#include <Python.h>  // MUST come before any other header!
#include <iostream>

static PyObject* echo_wrapper(PyObject* self, PyObject* args,
                              PyObject* keywds) {
  // just echos an integer back from C++.
  int x;
  int parse_success;
  static char* kwlist[] = {"x", NULL};  // that's a sentinel terminator
  parse_success = PyArg_ParseTupleAndKeywords(args, keywds, "i", kwlist, &x);
  if (!parse_success) {
    return NULL;  // by convention, this means an error has occured.
  }
  std::cout << "Hello from C++" << std::endl;
  Py_RETURN_NONE;  // the easiest way to return python None
}

static PyMethodDef list_of_methods[] = {
    {"echo", (PyCFunction)echo_wrapper, METH_KEYWORDS | METH_VARARGS,
     "Echos back an integer"},
    {NULL, NULL, 0, NULL} /* this is a sentinel value to end the list */
};

static struct PyModuleDef keywdargmodule = {
    PyModuleDef_HEAD_INIT, "cpp_implemented_module",
    "This is the documentation of the module cpp_implemented_module.", -1,
    list_of_methods};

PyMODINIT_FUNC PyInit_cpp_using_module(
    void)  // this MUST be named "PyInit_" ++ <name_of_module>
{
  return PyModule_Create(&keywdargmodule);
}
