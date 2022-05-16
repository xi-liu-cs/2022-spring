# Intro to Hypertext Markup Language

facilitating the control the content of web pages

---

# Agenda

1. [Overview](#overview)
1. [Separation of Concerns](#separation)
1. [Bare Minimum Code](#minimum)
1. [Elements & Tags](#elements)
1. [Attributes](#attributes)
1. [Common Tags](#common)
1. [Try It Out](#try)
1. [Conclusions](#conclusions)

---

name: overview

# Overview

---

template: overview
name: overview-1

Hypertext Markup Language (HTML) is used to indicate the contents of a web page.

- What images, text, videos, audio, or animations should be placed on the page
- What is the _semantic_ meaning of each piece of content, i.e. what is it describing?

---

name: separation

# Separation of Concerns

---

template: separation
name: separation-1

The **separation of concerns** is a philosophy popular in technology that different tasks should be accomplished by different technologis. With regards the Web:

- The semantic content should be controlled by Hypertext Markup Language (HTML)
- The visual presentation of content should be controlled by Cascading Style Sheets (CSS)
- The interactive behavior of content should be controlled by Javascript (JS)

---

name: minimum

# Bare Minimum HTML Code

---

template: minimum
name: minimum-1

At the very least, an HTML document contains the following code:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <title>Insert the title of your page here</title>
    <link rel="stylesheet" type="text/css" href="css/some_stylesheet.css" />
  </head>
  <body>
    Insert the contents of your page here.
  </body>
</html>
```

---

template: minimum
name: minimum-2

## doctype

Let's start with the first line, the `doctype`.

```html
<!DOCTYPE html>
```

- This informs the web browser that this is an HTML version 5 document.
- Other versions of HTML have [other `doctype` strings](https://www.w3schools.com/tags/tag_doctype.asp).
- The browsers are programmed by their creators to understand these strings.

---

template: minimum
name: minimum-3

## html

Moving on, we see the `html` tags the beginning and the end.

```html
<html>
  ...
</html>
```

- All HTML code (except the `doctype`, which is technically not HTML) is surrounded by these beginning and ending `html` tags.
- Putting tags within other tags is called **nesting** tags - like [Matryoshka dolls](https://en.wikipedia.org/wiki/Matryoshka_doll#/media/File:Floral_matryoshka_set_2_smallest_doll_nested.JPG).
- The browser now knows that what is nested within the `html` tags will be HTML code.

---

template: minimum
name: minimum-4

## head and body

Within the `html` element, indented one level further in, we see two sets of tags: `head` and `body`.

```html
<head>
  ...
</head>

<body>
  ...
</body>
```

- The only two elements to be _nested_ directly within the `html` element are these two: `head` and `body`.
- All other HTML elements go further nested within one of these two.
- The `head` will contain _metadata_ about the page, and perhaps other invisible instructions to the web browser.
- The `body` willl contain the visible parts of the page - the things the end-user will see.

---

template: minimum
name: minimum-5

## meta charset

The `meta` tag resides within the `head`.

- Notice that this is the first tag we have encountered that does not have a corresponding closing tag, such as `</meta>`.

```html
<meta charset="utf-8" />
```

- This tag is metadata informing the web browser of the character set being used by the code on this page.
- Different character sets can support different languages.
- UTF-8 is a _Unicode_-based character set that supports all known written languages.
- If the character set is not specified correctly, non-English characters may not render correctly when the page is loaded by the browser.

---

template: minimum
name: minimum-6

## title

The `title` element is metadata indicating to the web browser the title of this document.

```html
<title>Insert the title of your page here</title>
```

- The `title` does not appear within the visible contents of the web page.
- The `title` does appear often in browser tabs and in search engines.

---

template: minimum
name: minimum-7

## link

The `link` element informs the web browser of the existence of another file it should load.

```html
<link rel="stylesheet" type="text/css" href="css/some_stylesheet.css" />
```

- In this case, the `link` informs the browser that it should load a Cascading Style Sheets (CSS) file.

---

template: minimum
name: minimum-8

## body contents

The contents of the `body` tag indicate the visible elements of the page.

- In this case, we simply specify some text to show on the page.
- Much of our remaining discussion will focus on other tags we can nested within the `body`.

```html
<body>
  Insert the contents of your page here.
</body>
```

---

name: elements

# Elements & Tags

---

template: elements
name: elements-1

## Elements

An HTML _element_ is a conceptual piece of content or metadata in the document. E.g.

- the title of the document
- an instruction to load a CSS document
- an image
- the main heading
- sub-headings
- a paragraph

---

template: elements
name: elements-2

## Tags

Tags are the code that is written to inform the browser that you wish to create an element.

- the `<title>...</title>` tags
- the `<link />` tag
- an `<img />` tag
- the `<h1>...</h1>` tags
- the `<h2>...</h2>` tags
- `<p>...</p>` tags

---

template: elements
name: elements-3

## Tag pairs

As a general rule, `tags` come in pairs - an opening and a closing `tag` together indicate the start and end of a conceptual `element`.

For example - an opening paragraph tag.

```html
<p></p>
```

And its corresponding closing - closing tags use the same _tag name_ as the opening tag, e.g. `p`, but place a slash `/` in front of it.

```html
</p>
```

---

template: elements
name: elements-4

## Self-closing tags

Some opening tags do not have a separate closing tag. These are _self-closing tags_.

For example - the `link` opening tag. There is no corresponding `</link>` closing tag.

- This is because there is no need to ever put any other tags nested _inside_ the `link` element.

```html
<link rel="stylesheet" type="text/css" href="css/some_stylesheet.css" />
```

---

template: elements
name: elements-4-1

## Self-closing tags (continued)

```html
<link rel="stylesheet" type="text/css" href="css/some_stylesheet.css" />
```

Notice that it has a slash `/` within the opening tag itself at the end - this indicates that it is self-closing.

- In HTML 5 (the latest version), this slash is not necessary, but optional.
- In XHTML (the previous popular version still in use), it is necessary.
- We will write our code in XHTML-compatible HTML 5... so **we will include the self-closing slash**.

---

template: elements
name: elements-5

## Tabs

Line breaks, multiple spaces, and tabs are ignored by the web browser.

- They are all interpreted as a single space character.

So the following code is a valid HTML document:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <title>Insert the title of your page here</title>
    <link rel="stylesheet" type="text/css" href="css/some_stylesheet.css" />
  </head>
  <body>
    Insert the contents of your page here.
  </body>
</html>
```

---

template: elements
name: elements-5b

## Tabs (continued)

This is also valid HTML code:

```html
<!-- prettier-ignore -->
<!doctype html>

<html
lang="en"><head                 ><meta          charset="utf-8" />
<title>Insert the title of your page here<
    /title>               <link rel="stylesheet"
            type="text/css"         href="css/some_stylesheet.css" /></head><body>Insert the contents of your page here.</body></html>
```

---

template: elements
name: elements-6

## Tags (continued again)

Don't do that! We want to be able to read and understand code easily.

- Use line breaks between elements.
- If one element is nested within another, indent the nested element within its parent element.

Do this:

```html
<article>
  <a href="somepage.html">
    <img src="images/donkey.jpg" />
  </a>
</article>
```

Not this:

```html
<!-- prettier-ignore -->
<article><a href="somepage.html"><img src="images/donkey.jpg" /></a></article>
```

---

template: elements
name: elements-7

## Tabs (continued again)

With elements that contain only text nested within them, it's okay to write that text on one line with the element's tags.

```html
<h1>Platypus Endangerment</h1>
```

But if that text is very long and requires scrolling, break it up onto multiple lines.

```html
<h1>
  Platypus Endangerment ipsum dolor sit amet, consectetur adipiscing elit. Nam
  posuere mauris sit amet nulla egestas blandit. Phasellus gravida dui eget nisi
  dictum
</h1>
```

---

name: attributes

# Attributes

---

template: attributes
name: attributes-1

## Concept

You may have noticed that some tags contain _attributes_. These are extra element settings.

- Attributes are only ever present on opening tags.
- Some are required, some are optional

For example - the `img` tag requires the `src` setting indicating which image file to load.

```html
<img src="images/donkey.jpg" />
```

---

template: attributes
name: attributes-2

## Specific values

Some elements require attributes with particular values in order to function properly.

- `selected` - used by some `input` elements... has only one meaningful value, 'selected'
- `checked` - used by some `input` elements... has only one meaningful value, 'checked'
- `type` - used by the `link`, `script`, and `input` elements... has various values with specific meanings.
- `rel` - used by the `link` element... usually has the value, `stylesheet`

---

template: attributes
name: attributes-3

## Arbitrary values

Other elements can have attributes with arbitrary values that the programmer makes up.

- `id`
- `class`
- `name`
- `value`
- `for`
- `title`
- `alt`
- `href` - any URI
- `src` - any URI
- `action` - any URI

---

name: common

# Common Elements

---

template: common
name: common-1

## Universal

Elements required to setup every HTML document:

- `html`
- `head`
- `body`

---

template: common
name: common-2

## Metadata in the head

Elements used for settings within the `head`:

- `title`
- `meta`
- `script`
- `link`
- `style`

---

template: common
name: common-3

## Body content

Elements used to indicate content within the `body`:

- `h1` - `h6`
- `a`
- `p`
- `br`
- `strong`
- `ul`
- `ol`
- `li`
- `img`
- `figure`
- `figcaption`
- `video`
- `audio`
- `source`

---

template: common
name: common-4

## Grouping

Elements used to group content within the `body`:

- `header`
- `footer`
- `main`
- `section`
- `article`
- `aside`
- `menu`
- `nav`
- `div`
- `span`

---

template: common
name: common-5

## Forms

Elements used in forms within the body:

- `form`
- `input`
- `textarea`
- `label`
- `select`
- `option`

---

template: common
name: common-6

## Learn more

Obviously you will want to see more information on using these in a practical sense.

- Check out the [w3schools.com HTML tutorials](https://www.w3schools.com/html/).

---

name: try

# Try It Out

--

## Concept

The best way to learn to make web pages is to try. There are many ways to write code for a web page and open it in a web browser to see what it looks like.

--

- by directly opening an HTML code file in your web browser

--

- by running web server software on your own computer

---

template: try

## Directly open an HTML code file in your web browser

This is the simplest way to test out a web page that you have been developing.

--

- Write the HTML and CSS code in a decent code editor. Save the HTML code into a file with the `.html` extension, the CSS code in a file with the `.css` extension, and any Javascript code in a file with the `.js` extension.

--

- Ensure that your HTML code [refers to the CSS file](#minimum-7) and any Javascript code files appropriately.

--

- Open your favorite web browser and use the `File`->`Open` menu option to open the HTML file you created.

---

template: try

## Run a web server on your own computer using Visual Studio Code's Live Server extension

Having a web server serve your web pages is a more "realistic" environment within which to test your pages, and it is easy to set up on your own machine.

--

- Install the [Live Server extension](https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer) by Ritwick Dey into Visual Studio Code

--

- Open any HTML file into the editor.

--

- Click the `Go Live` button in the status bar at the bottom of the editor to start a web server and open the HTML document in a web browser automatically.

--

- You can also right-click (or `Control`-click on Mac) on any file and select `Open with Live Server`.

---

template: try

## Run a web server on your own computer using Node.js' http-server module

Having a web server serve your web pages is a more "realistic" environment within which to test your pages, and it is easy to set up on your own machine.

--

- [download and install Node.js](https://nodejs.org/en/download/)

--

- from the command line, run the command `npm install --global http-server` to install a simple web server (note that Mac/Unix/Linux users may have to run `sudo npm install --global http-server` to install with superuser privileges)

--

- from the command line, start the web server from within the same directory where the web pages files reside: `http-server ./` - this should output a URL at which to view your web site.

--

- copy/paste the URL into a web browser to view the web pages.