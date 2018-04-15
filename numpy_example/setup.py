from setuptools import setup, Extension
import numpy as np


numpy_example_module = Extension(
    'numpy_example',
    sources=["numpy_example.c"],
    include_dirs=[np.get_include(), "."],
    extra_link_args=[]
)


setup(
    name="numpy_using_package",
    version="0.0.1",
    description="Our first C extension to pass numpy arrays to C.",
    ext_modules=[numpy_example_module]
)
