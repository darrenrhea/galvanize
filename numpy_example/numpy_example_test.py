import numpy as np
import numpy_example


def test_print_numpy():
    M = np.array(
        [
            [2,  3,   5,  7, 11, 13],  # noqa: E241
            [17, 19, 23, 29, 31, 37],
            [41, 43, 47, 53, 59, 61],
        ],
        dtype=np.uint8
    )
    print("\nPython thinks M is:\n", M, "\n")
    numpy_example.print_uint8(x=M)  # arguments are identified by order

    # show the importance of strides
    A = M[::2, 1::3]
    print("\nPython thinks A is:\n", A, "\n")
    numpy_example.print_uint8(x=A)  # arguments are identified by order


def test_print_tensor():
    M = np.array(
        [1, 2, 4, 8, 16, 32],
        dtype=np.uint8
    )

    print("\nPython thinks M is:\n", M, "\n")

    numpy_example.print_uint8(x=M)  # arguments are identified by order

    # show the importance of strides
    A = M[1::2]
    print("\nPython thinks A is:\n", A, "\n")
    numpy_example.print_uint8(x=A)  # arguments are identified by order
