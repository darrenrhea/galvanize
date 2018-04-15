from setuptools import setup, Extension

cpp_using_module = Extension(
    name='cpp_using_module',
    sources=["cpp_using_module.cpp"],
)

setup(
    name="cpp_using_package",
    version="0.0.1",
    description="Our first C++ extension",
    ext_modules=[cpp_using_module]
)
