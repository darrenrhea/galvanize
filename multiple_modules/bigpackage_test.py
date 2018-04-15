import my_module_1
import my_module_2


def test_echo():
    # call by order of arguments:
    my_module_1.echo(1)  # arguments are identified by order
    # call via keyword arguments:
    y = my_module_1.echo(x=5)  # arguments are named
    print(y)
    assert y is None
    print("Finished testing echo.")


def test_add():
    # call by order of arguments:
    my_module_1.add(2, 3)  # arguments are identified by order
    # call via keyword arguments:
    z = my_module_1.add(x=5, y=7)  # arguments are named
    print(z)
    assert z == 12
    print("Finished testing add.")


def test_subtract():
    # call by order of arguments:
    my_module_2.subtract(2, 3)  # arguments are identified by order
    # call via keyword arguments:
    z = my_module_2.subtract(x=5, y=7)  # arguments are named
    print(z)
    assert z == -2
    print("Finished testing subtract.")
