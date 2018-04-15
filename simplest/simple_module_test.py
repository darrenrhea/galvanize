import simple_module


def test_echo():
    # call by order of arguments:
    simple_module.echo(1)  # arguments are identified by order
    # call via keyword arguments:
    y = simple_module.echo(x=5)  # arguments are named
    print(y)
    assert y is None
    print("Finished testing echo.")


def test_add():
    # call by order of arguments:
    simple_module.add(2, 3)  # arguments are identified by order
    # call via keyword arguments:
    z = simple_module.add(x=5, y=7)  # arguments are named
    print(z)
    assert z == 12
    print("Finished testing add.")
