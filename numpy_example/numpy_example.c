// Note: this only works for Python 3, not Python 2.7

#define PY_SSIZE_T_CLEAN
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#define PY_ARRAY_UNIQUE_SYMBOL ccr_ARRAY_API
#include <Python.h>  // MUST come before all other includes
#include <numpy/arrayobject.h>
#include <stdint.h>

void print_uint8(int ndim, int64_t* shape, int64_t* strides, uint8_t* data) {
  printf("The data ptr is %p\n", data);
  if (ndim == 1) {
    for (int i0 = 0; i0 < shape[0]; i0++) {
      uint8_t val = *((uint8_t*)(data + i0 * strides[0]));
      printf("x[%d] = %d\n", i0, val);
    }
  }
  if (ndim == 2) {
    for (int i0 = 0; i0 < shape[0]; i0++) {
      for (int i1 = 0; i1 < shape[1]; i1++) {
        uint8_t val = *((uint8_t*)(data + i0 * strides[0] + i1 * strides[1]));
        printf("x[%d, %d] = %d\n", i0, i1, val);
      }
    }
  }
}

static PyObject* print_uint8_wrapper(PyObject* self, PyObject* args,
                                     PyObject* keywds) {
  // just echos a numpy array from C.
  PyArrayObject* x_the_py_array_obj;

  printf("Hello from print_numpy_wrapper\n");

  static char* argument_names[] = {"x",
                                   NULL};  // that NULL is a sentinel terminator

  PyArg_ParseTupleAndKeywords(args, keywds, "O", argument_names,
                              &x_the_py_array_obj);

  int ndim = PyArray_NDIM(x_the_py_array_obj);
  printf("ndim = %d\n", ndim);
  int64_t* shape = PyArray_DIMS(x_the_py_array_obj);

  Py_ssize_t* strides = PyArray_STRIDES(x_the_py_array_obj);
  printf("\nHere is the shape:\n");

  for (int which_dim = 0; which_dim < ndim; which_dim++) {
    printf("shape[%d] = %d\n", which_dim, shape[which_dim]);
  }
  printf("\n\nHere are the strides:\n");
  for (int which_dim = 0; which_dim < ndim; which_dim++) {
    printf("strides[%d] = %ld\n", which_dim, strides[which_dim]);
  }

  uint8_t* data = (uint8_t*)PyArray_DATA(x_the_py_array_obj);

  printf("\n\nHere is the data:\n");
  print_uint8(ndim, shape, strides, data);
  Py_RETURN_NONE;  // the easiest way to return Python None
}

// a bunch of 4-tuples that say
// 1: What the function is called in Python
// 2: the C function that implements it
// 3: some flags to say it can be called by kwargs or by args
// Documentation
static PyMethodDef list_of_methods[] = {
    {"print_uint8", (PyCFunction)print_uint8_wrapper,
     METH_VARARGS | METH_KEYWORDS, "Prints a numpy array but using C"},
    {NULL, NULL, 0, NULL} /* this is a sentinel value to end the list */
};

static struct PyModuleDef mymodule_def = {
    PyModuleDef_HEAD_INIT, "numpy_example",
    "Here is the documentation for numpy_example", -1, list_of_methods};

PyMODINIT_FUNC PyInit_numpy_example(
    void)  // this MUST be named "PyInit_" ++ <name_of_module>
{
  return PyModule_Create(&mymodule_def);
}
