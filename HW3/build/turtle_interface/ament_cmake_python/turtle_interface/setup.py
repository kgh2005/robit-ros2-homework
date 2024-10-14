from setuptools import find_packages
from setuptools import setup

setup(
    name='turtle_interface',
    version='0.0.0',
    packages=find_packages(
        include=('turtle_interface', 'turtle_interface.*')),
)
