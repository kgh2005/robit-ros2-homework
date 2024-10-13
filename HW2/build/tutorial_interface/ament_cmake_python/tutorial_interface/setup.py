from setuptools import find_packages
from setuptools import setup

setup(
    name='tutorial_interface',
    version='0.0.0',
    packages=find_packages(
        include=('tutorial_interface', 'tutorial_interface.*')),
)
