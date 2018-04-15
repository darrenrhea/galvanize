from setuptools import setup, Extension

simple_module = Extension(
    name='simple_module',
    sources=["simple_module.c"],
)

setup(
    name="mypackage",
    version="0.0.1",
    description="mypackage: our first C extension",
    ext_modules=[simple_module]
)
