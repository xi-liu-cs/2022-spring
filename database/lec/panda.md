# Pandas

Database Design

---

# Agenda

1. [Overview](#overview)
1. [numpy](#numpy)
1. [Series](#series)
1. [Dataframe](#dataframe)
1. [Visualizations](#plotting)
1. [Conclusions](#conclusions)

---

name: overview

# Overview

--

## Concept

**pandas** is an extraordinarily powerful data munging and analysis module, and is a key part of the Python-based scientific computing toolkit.

---

template: overview

## Features

Some of pandas' most valuable features:

--

- ability to read and write data to and from common plain text data formats (e.g. CSV, JSON, fixed-width column text, etc), properietary formats like Excel's `.xlsx`, and online resources

--

- _fast and efficient_ data handling (based on `numpy` and vector math)

--

- built-in ability to _handle missing data_ (i.e. remove it or interpolate it)

--

- intuitive c*riteria-based filtering and grouping*, similar to that of common databases

--

- support for _time-series data_

--

- seamless _integration_ with the other popular Python-based scientific computing tools, including numpy and matplotlib

---

name: numpy

# Numpy

--

## Concept

pandas is built on top of [numpy](https://numpy.org/doc/stable/) - a Python module for optimized handling of _n_-dimensional arrays of data. A basic understanding of numpy is thus helpful in understanding pandas.

--

- arrays in `numpy` are referred to in documentation as **ndarrays**, for n-dimensional arrays.

--

- each array stores values of a single data type, called that array's **dtype** - usually an `int`, `float`, or an object type

--

- like Python lists, each value in an ndarray is indexed with an integer, starting from 0.

---

template: numpy

## Example Notebook

[Here is a Jupyter Notebook](../files/jupyter/intro_to_numpy.ipynb) that shows some of the core features of `numpy`.

--

- Open it from within JupyterLab or any other Jupyter Notebook viewer.

---

template: numpy

## Installing

`numpy` and `pandas`, like most popular modules, can be installed via `conda` or `pip` package managers, preferably into a virtual environment.

```
pip3 install numpy
pip3 install pandas
```

--

Importing into a Python script with the `np` and `pd` aliases is the convention:

```python
import numpy as np
import pandas as pd
```

---

template: numpy

## Creating

ndarrays can be created from scratch with a variety of `numpy` functions.

--

- `np.array( [23, 56, 2] )` - creates an ndarray from a Python list

--

- `np.random.random_sample( (3, 4) )` - creates an ndarray with the given _shape_ (number of rows and columns)

--

- `np.zeros( (3, 4), dtype = int )` - creates an ndarray in the given shape, filled with zeros

--

- `np.ones( (3, 4), dtype = int )` - creates an ndarray in the given shape, filled with zeros

--

- `np.arange( 10, 40, 5 )` - similar to the Python `range()` function - creates an ndarray with values in the given range; the third argument indicates the step.

--

- `np.linspace( 10, 40, 5 )` - creates an ndarray with values in the given range; the third argument specifies the number of values to generate

---

template: numpy

## Indexing and slicing

ndarrays in `numpy` can be indexed and sliced in the same manner as Python lists.

--

Take the following ndarray:

```python
x = np.array( [10, 12, 14, 16, 18 ] )
```

--

- `x[2]` - refers to `14`

--

- `x[-2]` - refers to `16`

--

- `x[2 : 4]` - refers to `array([14, 16])`

--

- `x[ : 2]` - refers to `array([10, 12])`

--

- `x[ 2 : ]` - refers to `array([14, 16, 18])`

---

template: numpy

## Simple math operations

It is straightforward to perform to the same math operation across all values in an ndarray.

--

- `np.array([1, 2, 3, 4]) + 2` - results in `array([3, 4, 5, 6])`

--

- `np.array([1, 2, 3, 4]) - 1` - results in `array([0, 1, 2, 3])`

--

- `np.array([1, 2, 3, 4]) * 2` - results in `array([2, 4, 6, 8])`

--

- `np.array([1, 2, 3, 4]) / 2` - results in `array([.5, 1., 1.5, 2])`

--

- `np.array([1, 2, 3, 4]) > 2` - results in `array([False, False, True, True])`

--

- `np.array([1, 2, 3, 4]) != 2` - results in `array([True, False, True, True])`

---

template: numpy

## Basic statistics

`numpy` includes functions to perform basic statistics on any ndarray, such as calculating the min, max, mean, median, and standard deviation.

--

For example, take the following ndarray:

```python
x = np.array([
    [ 2, 50, 100],
    [ 3, 60,  200],
    [ 4, 55, 150],
    [ 5, 40, 250]
])
```

--

- `x.mean()` - calculate the mean of all values in the flattened array

--

- `np.mean(x, axis=0)` - calculate the means 'vertically'

--

- `np.mean(x, axis=1)` - calculate the means 'horizontally'

--

- the other functions - to calculate the min, max, median, and standard deviation - have equivalent options.

---

template: numpy

## Filtering

You may apply certain conditions to extract a subset of values from an ndarray.

--

Take the following ndarray:

```python
a = np.array( [10, 12, 14, 16, 18 ] )
```

--

- `a[a < 15]` - results in `array([10, 12, 14])`

--

- `a[a > 15]` - results in `array([16, 18])`

--

- `a[ (a == 10) | (a > 16) ]` - results in `array([10, 18])`

--

- `a[ (a % 2 == 0) & (a > 16) ]` - results in `array([18])`

---

template: numpy

## Removing null values

The value, `np.nan` represents a null value. And the function, `np.isnan()` can be helpful in finding null values in an array.

--

For example, take the folowing data:

```python
x = np.array([np.nan, 1, 12, np.nan, 3, 41])
```

--

- `np.isnan(x)` - results in `array([True, False, False, True, False, False])`

--

- `x[ np.isnan(x) ]` - results in `array([nan, nan])`

--

- `x[ ~np.isnan(x) ]` - results in `array([1, 12, 3, 41])`

---

name: series

# Series

--

## Concept

A [Series](https://pandas.pydata.org/docs/reference/api/pandas.Series.html) in `pandas` is a one-dimensional series of values, often representing the values in either a single row or a single column of a tabular data structure.

--

- Series share much in common with one-dimensional `numpy` ndarrays.

--

- The difference, in practice, is that pandas Series are not restricted to integer indices, and can have string indices, for example.

--

- In this sense, Series can resemble Python dictionaries.

---

template: series

## Examples

See [this example Jupyter Notebook](../files/jupyter/pandas_series.ipynb) for examples exhibiting some of the core Series concepts.

---

name: dataframe

# Dataframe

--

## Concept

A DataFrame is the main data type that users of `pandas` interact with.

--

- DataFrames hold data in a row/column format similar to a spreadsheet

--

- Each column is represented as a pandas Series, and each row is also represented as a pandas Series.

--

- Each row has an index - a unique identifier of that row.

---

template: dataframe

## Examples

See [this example Jupyter Notebook](../files/jupyter/pandas_dataframe.ipynb) for examples exhibiting some of the core DataFrame concepts.

---

name: plotting

# Visualizations

--

## Concept

`pandas` contains wrappers around the popular `matplotlib` plotting module, and includes several functions for creating several common types of plots:

--

- `bar()` and `barh()` for vertical and horizontal bar plots, respectively

--

- `hist()` for histograms and `box()` for boxplots

--

- `kde()` or `density()` for density plots

--

- `area()` for area plots, `scatter()` for scatter plots

--

- `hexbin()` for hexagonal bin plots

--

- `pie()` for pie plots

---

template: plotting

## Examples

See [this example Jupyter Notebook](../files/jupyter/pandas_plotting.ipynb) for examples of data visualizations using `pandas` and `matplotlib`.

---

template: plotting

## matplotlib examples

While it is not necessary to have a deep understanding of `matplotlib` in order to use `pandas` plotting functions, it might be helpful. Here is [a sample Jupyter Notebook](../files/jupyter/plotting.ipynb) with some simple `matplotlib` examples that don't use `pandas`.