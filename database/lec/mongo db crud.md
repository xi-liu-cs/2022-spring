# MongoDB CRUD

Database Design

---

# Agenda

1. [Overview](#overview)
1. [Example Data Set](#data-set)
1. [Create](#create)
1. [Operators](#operators)
1. [Read](#read)
1. [Update](#update)
1. [Delete](#delete)
1. [Conclusions](#conclusions)

---

name: overview

# Overview

--

## Concept

MongoDB is a popular "document-oriented" database.

--

- MongoDB records are stored as Javascript Object Notation (JSON) documents.

--

- commands and queries issued to the command-line MongoDB **client** program are written in Javascript.

--

- MongoDB integrates easily with popular programming languages, such as Javascript, Python, and others.

---

template: overview

## Document-oriented database

MongoDB is not a relational database. It does not use the SQL query language. It attempts to fill a need for document-centric databases that can scale up or down rapidly, as needed.

--

- no more tables, rows, or columns

--

- data are stored as "documents" in "collections"

--

- a database server can house many "collections"

--

- documents can contain the equivalent of primary and foreign keys

---

template: overview

## No SQL

MongoDB is part of the "NoSQL" movement of databases that do not use SQL.

--

- MongoDB uses its own query language, based on Javascript

--

- many app or web programmers know Javascript, so this should make it more approachable

--

- [read more about the NoSQL trend](http://www.w3resource.com/mongodb/nosql.php) in database systems

---

template: overview

## Flexible data model

Schema-less, meaning there is no fixed set of fields in any document

--

- Documents can have whatever fields you decide to store in them

--

- Even documents within the same collection can differ in their fields

---

template: overview

## Cross-platform

MongoDB can run be "installed" and "setup" on all popular platforms, including Mac, Windows, Linux, and UNIX

--

- "Drivers" are available to be "installed" for most popular programming languages to allow them to communicate with MongoDB databases

---

template: overview

## Highly scalable

Built-in ability to be "sharded"

--

- a single database can be split across many servers, or even many thousands of servers

--

- this allows MongoDB to potentially run thousands of times faster than if a database were on a single computer with limited processing and memory power

---

template: overview

## Fast for large data sets

MongoDB is fast for large data sets

--

- includes sophisticated **indexes** to "pre-sort" results before queried

--

- supports many aggregate functions

---

template: overview

## Geospatial search

MongoDB has built-in ability to store geospatial coordinates

--

- this means it can perform searches for documents "near me"

--

- easily performs searches within a particular radius of any location

--

- in other words, it can order results by how far they are from any geospatial location

---

template: overview

## Industry-proven

MongoDB is used by:

--

- GitHub

--

- Etsy

--

- Google

--

- Ebay

--

- Expedia

--

- and [many more](https://www.mongodb.com/who-uses-mongodb)

--

Despite this MongoDB marketing, you can be sure that these organizations also use relational SQL databases aplenty.

---

template: overview

## CRUD with the mongo client

The `mongo` command line client uses a Javascript command shell interpreter to allow users to issue commands to any database to which they connect.

--

- as with databases of all kinds, most MongoDB commands engage in some form of CRUD

--

    - *C*reate
    - *R*ead
    - *U*pdate
    - *D*elete

--

We will show how to do common CRUD operations using the `mongo` client.

---

name: data-set

# Example Data Set

--

## Save the data file

This set of slides shows examples using a data set about books. To follow along, save the following JSON data into a file named [books.json](../files/mongodb/books.json).

```javascript
{"title": "Northanger Abbey", "author": "Austen, Jane", "year_written": 1814, "edition": "Penguin", "price":  18.2}
{"title": "War and Peace", "author": "Tolstoy, Leo", "year_written": 1865, "edition": "Penguin", "price":  12.7}
{"title": "Anna Karenina", "author": "Tolstoy, Leo", "year_written": 1875, "edition": "Penguin", "price":  13.5}
{"title": "Mrs. Dalloway", "author": "Woolf, Virginia", "year_written": 1925, "edition": "Harcourt Brace", "price":  25}
{"title": "The Hours", "author": "Cunnningham, Michael", "year_written": 1999, "edition": "Harcourt Brace", "price":  12.35}
{"title": "Huckleberry Finn", "author": "Twain, Mark", "year_written": 1865, "edition": "Penguin", "price":  5.76}
{"title": "Bleak House", "author": "Dickens, Charles", "year_written": 1870, "edition": "Random House", "price":  5.75}
{"title": "Tom Sawyer", "author": "Twain, Mark", "year_written": 1862, "edition": "Random House", "price":  7.75}
{"title": "A Room of One's Own", "author": "Woolf, Virginia", "year_written": 1922, "edition": "Penguin", "price":  29}
{"title": "Harry Potter", "author": "Rowling, J.K.", "year_written": 2000, "edition": "Harcourt Brace", "price":  19.95}
{"title": "One Hundred Years of Solitude", "author": "Marquez", "year_written": 1967, "edition": "Harper  Perennial", "price":  14.00}
{"title": "Hamlet, Prince of Denmark", "author": "Shakespeare", "year_written": 1603, "edition": "Signet  Classics", "price":  7.95}
{"title": "Lord of the Rings", "author": "Tolkien, J.R.", "year_written": 1937, "edition": "Penguin", "price":  27.45}
```

---

template: data-set

## Saving the data file to a web server

If you typically connect to the MongoDB database server from a web server, such as **i6** , it's easy to upload the data file to the web server using a Secure File Transfer (SFTP) application like [Cyberduck](https://cyberduck.io/).

![Cyberduck login](../files/mongodb/cyberduck.png)

---

template: data-set

## Import the data into MongoDB

To import the data file into a MongoDB database collection, go to the UNIX/Linux command line from where you typically connect to a MongoDB database, navigate to whichever folder you saved the data file into, and issue the following command:

```bash
mongoimport --db your_database_name --collection books --host database_host --username your_username --password your_password --type json --file books.json
```

--

- replace `database_host`, `your_database_name`, `your_username`, and `your_password` with the correct credentials.

--

- MongoDB can import both JSON and CSV plain text data formats, although JSON is much more closely related to MongoDB's internal data structure and can be considered its native format.

--

- note that the `mongoimport` command is not run from within the `mongo` client.

---

template: data-set

## Connect to the database with the mongo client

Once the data has been imported, you can log in to the database server using the `mongo` client:

`mongo your_database_name --host your_hostname -u your_username -p`

- replace `your_database_name` with your own NYU Net ID
- replace `your_hostname` with `class-mongodb.cims.nyu.edu`
- replace `your_username` with your own NYU Net ID
- you will be prompted to enter your MongoDB server password... do so... this is not the same as your i6 password

---

name: create

# Create

--

## Collections

There is no need to explicitly create a collection. Collections are created automatically as soon as the first document is saved into them.

---

template: create

## insert()

Documents can be created and stored into collections by importing from a JSON data file, as we have seen, or by using the `insert()` function.

```javascript
db.books.insert({
  title: "Pattern Recognition",
  author: "William Gibson",
  year_written: 2003,
  edition: "Penguin",
  price: 14.99,
});
```

- where `books` is a collection name that already exists or will be created automatically

---

name: read

# Read

--

## find()

The MongoDB `find()` function retrieves existing data from records in a given collection. It takes two arguments

- the **criteria** - that criteria that records must match to be included in the result set

  - this acts much like SQL's `WHERE` clause

- the **projection** - limits which fields from the records matching the criteria will be included in the records in the result set
  - this acts much like the list of fields to retrieve in SQL's `SELECT` query

---

template: read

## Retrieve all documents

```javascript
db.books.find();
```

- where `books` is the collection from which to retrieve documents.

---

template: read

## One criterion

```javascript
db.books.find({
  author: "Leo Tolstoy",
});
```

- retrieves all books where the `author` field has the value `Leo Tolstoy`

---

template: read

## One criterion with an operator

```javascript
db.books.find({
  price: {
    $gt: 25,
  },
});
```

- The `$gt` operator performs a "greater than" comparison.

---

template: read

## Two criteria

```javascript
db.books.find(
  {
    price: {
      $gte: 10,
      $lte: 20,
    },
    edition: "Penguin",
  },
  {
    _id: 0,
  }
);
```

Notes:

- **and** logic is implicit in the syntax of the price criteria
- the **projection** (the second argument) indicates to not include the `_id` field in the results.

---

template: read

## Two criteria

```javascript
db.books.find(
  {},
  {
    _id: 0,
    title: 1,
  }
);
```

Notes:

- This will return all book documents, since the **criteria** argument is a blank object.
- Only the `title` field will be included in the results for each document, since the **projection** argument indicates to do so.

---

template: read

## One criterion using the $or operator

```javascript
db.books.find({
  $or: [
    {
      price: {
        $gte: 20,
      },
    },
    {
      edition: "Penguin",
    },
  ],
});
```

Notes:

- **or** logic has to be explicitly indicated by the $or operator
- the syntax for the `$and` operator follows the same pattern

---

template: read

## Counting records

The `count()` function can be run on any query to count results.

```javascript
db.books
  .find({
    edition: "Penguin",
  })
  .count();
```

---

name: operators

# Operators

--

## Comparisons

A variety of operators allow criteria to be fine-tuned.

- `$eq` - equal to
- `$ne` - not equal to
- `$gt` - greater than
- `$gte` - greater than or equal to
- `$lt` - less than
- `$lte` - less than or equal to

---

template: operators

## Logic

Some other common operations have operators as well:

- `$and` - performs **and** logic
- `$or` - performs **or** logic
- `$in` - determines whether a value in a given field matches one of the values in an array
- `$nin` - determines whether a value in a given field does not match one of the values in an array

---

template: operators

## Implicit equality

The following retrieval will match books where the `edition` field has exactly the value, "Penguin".

```javascript
db.books.find({
  edition: "Penguin",
});
```

--

- The equality operator is implicit.

---

template: operators

## Implicit $eq

The same retrieval, in a more formal style, explicitly uses the `$eq` operator.

```javascript
db.books.find({
  edition: {
    $eq: "Penguin",
  },
});
```

--

- The equality `$eq` operator is explicit.

---

template: operators

## Implicit and

As we've seen, MongoDB's default operator is the **and** operator.

```javascript
db.books.find({
  price: {
    $gte: 10,
    $lte: 20,
  },
  edition: "Penguin",
});
```

--

- There is no need to explicitly mention **and**.

--

- This will find books that match the `price` **and** the `edition` criteria

--

- The `price` criterion will match books that are greater than $10 **and** less than $20

--

- The `edition` criterion will match books that have exactly "Penguin" as their edition value.

---

template: operators

## Explicit $and

The **and** logic in a query could be made more explicit. We can check a field in each documents against an array of criteria.

```javascript
db.books.find({
  $and: [
    {
      price: {
        $gte: 10,
      },
    },
    {
      price: {
        $lte: 20,
      },
    },
  ],
});
```

- This is quite a mouthful of `(`, `[`, `{`, `$`, `,`, `}`, `]`, and `)` characters.
- The implicit **and** seems nicer, when possible.

---

template: operators

## Explicit $or

**or** logic is written in much the same way as the explicit `$and`.

```javascript
db.books.find({
  $or: [
    {
      author: "Gibson, William",
    },
    {
      author: "Tolstoy, Leo",
    },
  ],
});
```

---

template: operators

## $in

If checking for a single field to have one of the values from a list of values, the `$in` operator can be less verbose than the explicit $or operator.

```javascript
db.books.find({
  author: {
    $in: ["Gibson, William", "Tolstoy, Leo"],
  },
});
```

---

template: operators

## $nin

Check that a document's field value is not one of an array of values.

```javascript
db.books.find({
  year_written: {
    $nin: [1865, 1925, 1927, 1802, 1814, 1999],
  },
});
```

---

name: update

# Update

--

## update()

To update existing documents, use the `update()` method.

```javascript
db.books.update(
  { year_written: { $lt: 2000 } },
  { $set: { price: 5.99 } },
  { multi: true }
);
```

- the first argument specifies the criteria indicating which documents to update
- the second argument represents the fields to be changed and their new values
- the third argument indicates to apply this to all rows that match the criteria

---

name: delete

# Delete

--

## remove()

To delete existing documents, use the `remove()` method.

```javascript
db.books.remove({
  author: "William Gibson",
  title: "Pattern Recognition",
});
```

- the argument sets the criteria that must be matched for any documents to be deleted