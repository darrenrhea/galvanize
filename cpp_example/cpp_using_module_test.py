import cpp_using_module


def test_echo():
    cpp_using_module.echo(1)
    y = cpp_using_module.echo(x=5)
    print(y)
    assert y is None
    print("Finished testing echo.")
