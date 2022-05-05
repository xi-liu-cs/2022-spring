# Exam 2 Review

Database Design

---

# Agenda

1. [Overview](#overview)
1. [MongoDB](#mongodb)
1. [Web Apps](#web-apps)
1. [Pandas](#pandas)
1. [Conclusions](#conclusions)

---

name: overview

# Overview

---

template: overview

## Format

The exam will be composed of two parts:

--

- A Google Form, similar to a Quiz

--

- A GitHub Classroom repository, similar to an assignment

---

template: overview

## Time

Start anytime and submit anytime within a 24 hour window.

---

template: overview

## Topics covered

The topics covered on the exam:

--

- Do you really need a slide about this?

---

template: overview

## Weighting

All topics will be weighted equally in grading.

---

name: mongodb

# MongoDB

--

template: mongodb

## Key points

Main topics:

--

- an example of a _NoSQL_ database

--

- easily imports `CSV` and `JSON` file formats

--

- _document-oriented_ - records stored as Javascript objects written with JSON

--

- Javascript objects support nesting of values

--

- normal forms need not apply

---

template: mongodb

## CRUD

CRUD is still cruddy

--

- **C**reate: `db.collection.insert(document)`

--

- **R**ead: `db.collection.find(criteria, projection)`

--

- **U**pdate: `db.collection.update(criteria, changes, one_or_many)`,

--

- **D**elete: `db.collection.remove(criteria)`.

---

template: mongodb

## Basic statistics

As with all database systems, MongoDB can easily do some basic statistical operations:

- Count: `db.collection.find(criteria).count()`

--

The _aggregation pipeline_ is used to calculate most other statistics...

---

template: mongodb

## Basic statistics (continued)

E.g., calculate average of all values in the `salary_range_to` field with no grouping:

```javascript
db.collection.aggregate([
  {
    $group: {
      _id: null,
      avg_val: { $avg: "$salary_range_to" },
    },
  },
]);
```

--

Same, but grouping by `agency`:

```javascript
db.collection.aggregate([
  {
    $group: {
      _id: "$agency",
      avg_val: { $avg: "$salary_range_to" },
    },
  },
]);
```

---

template: mongodb

## Aggregation pipeline

The aggregation pipeline allows for multi-stage transformations, where the output of each stage becomes the input for the following stage.

--
Stages may include operations such as:

- `$match` - to filter documents by criteria

- `$count` - to count the number documents at this stage

- `$project` - to calculate or select particular fields

- `$group` - to group documents by a common attribute

- `$sort` - sort the results by a given field(s)

---

name: web-apps

# Web Apps

--

## Key points

Main topics:

--

- the web is the use of the `HTTP` protocol that allows a web browser to browse _hypertext_ documents

--

- a client (e.g. web browser) makes requests (e.g. `HTTP` `GET` or `POST` requests), and a server (e.g. web server) issues responses to those requests (e.g. `HTTP` `200` `OK`).

--

- `HTTP` `POST` requests can contain a payload of body data, such as when the user submits a form. `GET` requests (the default type) cannot.

--

- `flask` and `pymongo` are useful Python modules when creating web apps.

---

template: web-apps

## HTML, CSS, Javascript

Web browsers can only "understand"/interpret 3 languages: `HTML`, `CSS`, `Javascript`.

--

- HTML is used to indicate the content and semantic meaning of the content of a given web page.

--

- CSS is used to indicate the styling of the content on a given web page.

--

- Javascript is used to indicate any interactive behaviors of a given web page (changes to make on user `click`, `mouseover`, `keyPressed`, etc).

--

All web servers must respond to incoming HTTP requests from a web browser with code in one or more of these types.

---

template: web-apps

## flask

`flask` is a Python web server module to help detect incoming requests and respond to them

--

- `flask` allows us to set up server-side _routes_ - functions that run automatically when a browser requests a certain web address.

--

- `flask` routes give us easy programmatic access to information in the incoming HTTP requests, such as any form data

--

- `flask` makes it easy to generate templates: static `HTML` documents with data injected into them dynamically.

---

template: web-apps

## pymongo

`pymongo` is a Python module that helps the server code communicate with a MongoDB databases.

--

- allows for all typical _CRUD_ operations to be handled on a MongoDB database using simple Python code.

--

- for example, when a web browser requests a web page, a `flask`-based server app can... fetch data from a database using `pymongo` and inject it into an HTML template that is placed into the HTTP response.

--

- another example, when a user fills in a form and clicks submit, the browser can make an HTTP POST request to a server, where a route in a `flask` app receives the form data, packages it up nicely into a document, and saves it into a MongoDB database.

---

name: pandas

# Pandas

--

## Key points

Main topics:

--

- powerful Python-based data analysis library

--

- stores data in `Series` and `DataFrame` data structures

--

- vector math!

--

- relies on `numpy`, wraps around `matplotlib`

--

- includes tools to help munge/cleanup the data.

--

- supports basic data analysis: statistical analysis including grouping.

---

template: pandas

## Jupyter Notebooks

A convenient web-based IDE widely-used in the scientific Python community for writing and sharing code.

--

- code cells and Markdown cells

--

- ability to run cells in the web browser

--

- supported by many platforms, including GitHub, Visual Studio Code, JupyterLab, etc.