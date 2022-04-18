# Jupyter Notebooks

Database Design

---

# Agenda

1. [Overview](#overview)
1. [Setup](#setup)
1. [Cells](#cells)
1. [Code](#code)
1. [Conclusions](#conclusions)

---

name: overview

# Overview

--

## Concept

[Project Jupyter](https://jupyter.org/) is a web-based publishing system that can incorporate Python and many other language interpreters into a web pages.

--

It is extremely handy for sharing code and including documentation and notes for better reproducibility, collaboration, and education.

---

template: overview

## Key Features

Features of most interest to users:

--

- write documentation and notes in Markdown syntax

--

- write and execute code on the web

--

- supports a few popular data science languages, including Python and R

--

- import/export Jupyter Notebooks as `JSON`.

--

- bundled with the [Anaconda](https://www.anaconda.com/) data science toolkit

---

name: setup

# Setup

--

## Install

**JupyterLab** - an application that allows you to edit and write Jupyter Notebooks - may be installed on your own computer via the command line, using either of the popular Python package managers, `pip` or `conda`.

--

```bash
pip3 install jupyterlab
```

---

template: setup

## Run

Run from the command line:

```bash
jupyter-lab
```

--

- this will pop open an interface in your computer's default web browser

--

- click to create a new `Python 3` Notebook

---

template: setup

## Anaconda Navigator

JupyterLab can alternatively be launched from Anaconda Navigator, which contains a bundle of common data science tools.

![JupyterLab in Anaconda Navigator](../files/jupyter/anaconda_navigator.png)

---

template: setup

## Visual Studio Code

As an alternative to JupyterLab, Visual Studio Code includes Jupyter Notebook integration. Simply open up any file with the `.ipynb` extension, and you will be able to start working in the notebook.

--

- Here is [an example `.ipynb` file](../files/jupyter/welcome.ipynb) - pop it open in Visual Studio code and try for yourself.

---

template: setup

## GitHub

While GitHub does not include an execution environment for Jupyter Notebooks, it does allow visitors to view the notebooks.

--

- See [this example notebook](https://github.com/nyu-computer-science/database-design/blob/master/docs/files/jupyter/welcome.ipynb) hosted on GitHub.

---

name: cells

# Cells

--

## Concept

Notebooks are a collection of individual **cells** that can be edited and executed. There are two types of cells:

--

- **Markdown** - text written in standard Markdown syntax.

--

- **Code** - programming code written in whichever language the Notebook has been set up to support. This is the default cell type.

---

template: cells

## Activating cells

Any cell that has previously been placed in the notebook may be activated by double-clicking on it.

---

template: cells

## Switching between cell types

Cells are by default Code cells. Use shortcuts to switch the type of a cell:

--

- `Esc`-`m` - switch the active cell to Markdown type

--

- `Esc`-`y` - switch the active cell to Code type

---

template: cells

## Inserting new cells

There are two useful shortcuts for creating new cells:

--

- `Esc`-`a` - insert a new cell above the currently active cell.

--

- `Esc`-`b` - insert a new cell below the currently active cell.

---

template: cells

## Deleting cells

To delete the currently-active cell, use the `Esc`-`x` shortcut.

---

template: cells

## Executing cells

To interpret and execute the contents of a cell, press one either `Shift`-`Enter` to execute and move to the next cell below, or `Control`-`Enter` to execute but keep the current cell selected.

--

- **Markdown cells** will have their contents rendered as HTML web content.

--

- **Code cells** will have their contents executed and any output displayed.

---

name: code

# Code

--

## Concept

A few notes about writing code in Jupyter Notebooks...

---

template: code

## Output expressions as the last line of code in a cell

If the last statement in a cell is an expression of some kind, the value of that expression will be output in the notebookwithout the need for `print()`.

--

For example:

```python
# function definition that returns a value
def return_something():
    return 'This will be output without print!'

# calling it as the last line in the cell will output the return value
return_something()
```

--

Outputs the following: `'This will be output without print!'`

---

template: code

## Output expressions as the last line of code in a cell (continued)

The code:

```python
# a simple variable assignment
x = 10

# referencing it as the last line in the cell will output the value
x
```

--

Outputs the following: `10`

---

template: code

## Output expressions as the last line of code in a cell (continued again)

The code:

```python
# a boolean expression
(True and False) and (not True)
```

--

Outputs the following: `False`

--

While the code:

```python
# a literal
4
```

--

Outputs the following: `4`

---

template: code

## Output values in the middle of a cell using print()

Should you need to output values in the middle of a cell, you may use `print()`.

--

For example:

```python
for i in range(5):
    print(i)
print("Done")
```

--

Outputs the following:

```
0
1
2
3
4
Done
```

---

template: code

## Outputting more complex data

While `print()` works well for simple primitive values, it is really better used on the command line, not in a notebook.

--

- `print()` is not designed for an interactive programming environment and does not visually display well more complex data structures types like large lists, dictionaries, or other media types such as images or video.

--

- To do so in a notebook, import and use functions in the `IPython.display` module.

---

template: code

## Outputting more complex data (continued)

For example:

```python
from IPython.display import display, Image, Markdown

my_list = [ {"foo", "bar"}, {"baz": "bum"} , {"biddle": "diddle"} , {"dum": "fum"} , {"gram": "pram"} ]
display( my_list )
```

--

Outputs the following:

```
[{'bar', 'foo'},
 {'baz': 'bum'},
 {'biddle': 'diddle'},
 {'dum': 'fum'},
 {'gram': 'pram'}]
```

---

template: code

## Outputting more complex data (continued again)

For example:

```python
# some Markdown code, stored in a variable
my_markdown = '''
A simple Markdown list:
- first item
- second item, with some **bold text**
- third item, with a [link](https://knowledge.kitchen)
'''

# render the markdown
Markdown(my_markdown)

```

--

Outputs the following:

A simple Markdown list:

- first item
- second item, with ome **bold text**
- third item, with a [link](https://knowledge.kitchen)

---

template: code

## Autocomplete

While writing code, trigger an autocomplete suggestion box to appear at any time by typing the `Tab` key.

--

- the autocompletion may take a second or two to appear.

--

- if nothing appears after a few seconds, Jupyter probably has no autocompletions to suggest.

---

template: code

## Code documentation

To view the documentation of any function, place the cursor between the opening and closing parentheses of the function in your code, and press the shortcut, `Shift`-`Tab`.