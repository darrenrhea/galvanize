from setuptools import setup, Extension

module1 = Extension(
    name='my_module_1',
    sources=["my_module_1.c", "echo.c"],
)

module2 = Extension(
    name='my_module_2',
    sources=["my_module_2.c"],
)

setup(
    name="bigpackage",
    version="0.0.1",
    description="A package with 2 modules",
    ext_modules=[module1, module2]
)
