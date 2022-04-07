# The Web

Database Design

---

# Agenda

1. [The Internet](#internet)
1. [The World Wide Web](#web)
1. [Clients and Servers](#client-server)
1. [Hypertext Transfer Protocol](#http)
1. [Front-End Technologies](#front-end)
1. [HTML in 4 slides](#html)
1. [CSS in 3 slides](#css)
1. [Back-End Technologies](#back-end)
1. [Databases](#databases)
1. [Conclusions](#conclusions)

---

name: internet

# The Internet

---

template: internet
name: internet-1

## Definition

The Internet is the global interconnected network of computers that communicate via a set of standardized protocols.

--

- It is sometimes referred to as a "network of networks."

![Network of networks](../files/the_web/network_of_networks.png)

---

template: internet

## Connective tissue

Copper wires and radio signals account for a smaller fraction of the total distance traveled by data on the Internet.

--

The vast expanses of the Internet's reach are today enabled primarily by fiber optic cables that run locally, regionally, and across ocean floors to connect continents - see a [map of submarine cables](https://www.submarinecablemap.com/).

![Submarine internet cable map](../files/the_web/submarine_internet_cable_map.png)

---

template: internet

## Origins

The Internet evolved over decades, funded primarily by the US Department of Defense

- 1960s - US Department of Defense networking projects explored fault-tolerant **networks resistent to nuclear attack**

--

- 1970s-80s - The ARPANET, a mostly regional network, attempted to **improve interoperability** among different computer systems

--

- 1980s-90s - This transitioned to the Internet, a **global network of interoperable computers**

---

template: internet

## Ownership

The "[backbone](https://en.wikipedia.org/wiki/Internet_backbone)" of networking equipment that fuels the Internet belongs to a patchwork of different interests:

--

- telecommunications companies and other private corporations

--

- federal, state, and local government

--

- academia

---

template: internet

## Cooperation

Given the patchwork of operators controlling different parts, cooperation is key.

--

- Organizations of approximately equal size that provide key parts of the Internet backbone usually abide by a "**free peering**" agreement, whereby they agree to relay each others' data across their own network hardware for free.

--

- Organizations of different sizes who need to cooperate often work out **payment agreements** to let traffic from one travel over the other's equipment

---

template: internet

## Control

The Internet, for better or worse, has been much touted as a disruptive force in society.

--

- A decade or two ago, many saw the Internet as a [democratizing force](https://blogs.harvard.edu/idblog/2008/05/14/the-democratic-power-shift-on-the-internet/) for oppressed peoples everywhere.

--

- Today, some point out a [more complicated situation](https://www.nytimes.com/2011/02/06/books/review/Siegel-t.html) where information and access to that information is controlled by corporate and government interests.

--

- The Internet, where anyone anywhere can _share_ information, _steal_ information, _surveil_ and _influence_ populations on the other side of the globe, is increasingly the site of a struggle for _information dominance_.

---

name: web

# The World Wide Web

--

## Definition

The World Wide Web is one use of the Internet to publish and browse hypertext documents.

---

template: web

## Hypertext

"Hypertext" means documents which reference and link to one-another.

--

- The hypertext concept was first popularized by Dr. Vannevar Bush in a 1945 article in The Atlantic titled, "[As We May Think](https://www.theatlantic.com/magazine/archive/1945/07/as-we-may-think/303881/)".

--

- Vannevar Bush was then the Director of the Office of Scientific Research and Development for the US military.

--

- After World War II, where he managed miliatry scientific research including the development of the atomic bomb, Bush turned his sights on the problem of information overload.

---

template: web

## Origin

The World Wide Web was invented in 1989-1990 by a British researcher at CERN named Tim Berners-Lee.

--

- Berners-Lee acknowledged that his invention was really a mashup of existing concepts, including hypertext, the Internet, and multi-font text.

--

- Inventing The Web required him to think at a higher level of abstraction and generalization to envision the value of this combination.

--

- He then invented Hypertext Markup Language (HTML) that is used to write web documents, and created the first web browser, the first web server, and invented the Hypertext Transfer Protocol (HTTP) that allows web browsers and web servers to communicate with a specific set of commands.

--

- He released his code free and open source, of course.

--

- Listen to him discuss [the current state of his invention](https://www.youtube.com/watch?v=g5AcmgFuOLU).

---

template: web

## Definition (revisited)

In the past, it was simple to define the World Wide Web.

--

- the use of a web browser to browse hypertext documents on the Internet

--

- use of the HTTP protocol by clients and servers to request and receive information

---

template: web

## Definition (revisited)

Today, the situation is a bit more blurry.

--

- Many apps besides web browsers now allow users to publish and read public and private hypertext documents over the Internet

--

- HTTP is now used to do much more than transferring hypertext documents - it is being used for all kinds of file transfers, messaging, virtual meetings, and more.

--

- other protocols, such as [WebSockets](https://en.wikipedia.org/wiki/WebSocket), can now be used to transfer hypertext documents

---

name: clients-servers

# Clients and servers

---

template: clients-servers

## Definitions

- a **client** is any machine on a network that is requesting data from a _server_.

--

- a **server** is any machine that is responding to a request for data from a _client_ machine.

--

- a single machine may sometimes act the role of a client in one interaction and the role of a server in another.

--

- the terms _client_ or _server_ can also be used to refer to the specific software on the client or server machine that is handling the communication in question.

---

template: clients-servers

## Requests

A client makes a request to a server.

![Client server request](../files/the_web/client_server_request.png)

---

template: clients-servers

## Responses

The server responds to the client.

![Client server response](../files/the_web/client_server_response.png)

---

template: clients-servers

## Centralized topology

A single server typically handles requests from many clients.

![Client server multiplicity](../files/the_web/client_server_multiplicity.png)

---

template: clients-servers

## Peer-to-peer

In peer-to-peer networks, such as [BitTorrent](https://en.wikipedia.org/wiki/BitTorrent) and [Bitcoin](https://bitcoin.org/bitcoin.pdf), any machines on the network may simultaneously act as a client in one exchange while playing the role of a server in another.

![Peer-to-peer networks](../files/the_web/client_server_peer_to_peer.png)

---

name: http

# Hypertext Transfer Protocol

--

## Standardized requests and responses

The [HTTP specification](https://www.w3.org/Protocols/rfc2616/rfc2616.html) indicates

- how Web clients can make requests to Web servers
- how Web servers can respond to those requests from Web clients

---

template: http

## Plain text

HTTP request and response commands are sent as plain text over the network, following a specific format.

--

- for added security, the **HTTPS** "secure" extension of HTTP encrypts the request and response communication while in transit

---

template: http
name: http-request-types

## Request types

The two most widely used [request types](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods) allowed by the HTTP specification

--

- **GET** - a web client requests that the web server respond by giving it a specific information resource, such as a web page

--

- **POST** - a web client supplies some data to the web server along with the request with the intention that the server save that data, or at least use it to change its behavior in some way

--

- other HTTP request types do exist, but are less widely used.

---

template: http

## Response codes

Web server responses include a [status code](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status), indicating the success or failure of the client's request.

- **200** to **299**: success
- **400** to **499**: client error
- **500** to **599**: server error
- and more...

---

template: http

## Example of a web client GET request

```http
GET /some_document.html HTTP/1.1
User-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)
Host: knowledge.kitchen
Accept-Language: en-us
Accept-Encoding: gzip, deflate
```

---

template: http

## Example of a web client POST request

```http
POST /some_document.html HTTP/1.1
User-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)
Host: knowledge.kitchen
Content-Type: application/x-www-form-urlencoded
Content-Length: 40
Accept-Language: en-us
Accept-Encoding: gzip, deflate

name=Foo+Barstein&topic=web+architecture
```

---

template: http

## Example of a successsful web server response

```http
HTTP/1.1 200 OK
Date: Mon, 27 Jul 2022 12:28:53 GMT
Server: Apache/2.2.14 (Win32)
Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT
Content-Length: 88
Content-Type: text/html
Connection: Closed

<html>
    <body>
        <h1>Hello, World!</h1>
        <p>How are you?</p>
    </body>
</html>
```

---

name: front-end

# Front-End Technologies

---

template: front-end

## Overview

Front-end technologies are those languages or programs which are interpreted and executed by the client, typically a web browser.

---

template: front-end

## Separation of concerns

Any **web browser** understands the three core front-end web technologies:

- **Hypertext Markup Language** (HTML) - controls the content present on the web page
- **Cascading Style Sheets** (CSS) - controls the visual style of the content on the web page
- **Javascript** (JS) - controls the iteractive behavior of the web page (how does the page change when a user clicks, types, moves them mouse, etc)

---

template: front-end

## HTML

Used to indicate the content and semantic _meaning_ of the content on a web page.

```html
<article>
  <h1>Jaberwocky</h1>
  <p id="p1">
    Twas brillig and the slithy toves did gyre and gimble in the wabe:
  </p>
  <a id="more" href="#">click to see more</a>
  <p id="p2">All mimsy were the borogoves, and the mome raths outgrabe.</p>
</article>
```

---

template: front-end

## CSS

Used to indicate the style and presentation of a web page.

```css
/* styles for the second paragraph */
#p2 {
  display: none; /* hide the second stanza by default */
}

/* styles for the link */
#more {
  color: red; /* make the text red */
  text-decoration: none; /* remove the default underline from the link */
}
```

---

template: front-end

## Javascript

Used to indicate interactive behaviors of a web page.

```javascript
// when the link is clicked...
$("#more").click(function () {
  $("#p2").show(); // make the second stanza appear
});
```

---

template: front-end

## It's up to a client's interpretation

A web browser client receives the HTML, CSS, and Javascript code from the server, and then interprets it.

![Client server responsibilities](../files/the_web/client_server_front_back_ends.png)

---

template: front-end

## Frameworks

Front-end frameworks attempt to simplify and streamline the process of creating front-end interfaces.

--

- **Bootstrap** - a framework ,originally by Twitter, with readymade CSS and Javascript code that handles many common interface design needs

--

- **Material UI** - a competitor to Bootstrap, by Google, specifically design to modularly fit into any project using React

--

- **React** - a framework, by Facebook, that attempts to abstract and streamline the process of generating the HTML, CSS, and Javascript code for a web or mobile app; allows for easy sharing among projects of modular "components" and behaviors

--

- **AngularJS** - a competitor to React, by Google

---

name: html

# HTML In 4 Slides

---

template: html
name: html-1

## Semantic markup

For any given web page, HTML code indicates the type of content to show as well as each piece of content's purpose, or semantic meaning.

- A level 1 heading: `<h1>Puppies For Sale</h1>`
- A paragraph: `<p>Buy now while supplies last!</p>`
- An image of a lonely puppy: `<img src="images/lonely_puppy.jpg" />`
- An article with a level 1 heading, an image of a sad puppy, and a paragraph with a link to another web page:

```html
<article>
  <h1>Puppies For Sale</h1>
  <img src="images/lonely_puppy.jpg" />
  <p>
    Buy now while supplies last!
    <a href="puppies.html">Learn more</a>
  </p>
</article>
```

[Try it](https://jsfiddle.net/barsteinfoo/erq4hzya/2/)

---

template: html
name: html-2

## Markup structure

Many web sites see the same basic content structures repeated across multiple pages, or repeated within a single page. [Try it!](https://jsfiddle.net/barsteinfoo/adgrp9zb/5/)

```html
<section>
  <!-- the first article -->
  <article>
    <h1>Puppies For Sale</h1>
    <img src="images/lonely_puppy.jpg" />
    <p>
      Buy now while supplies last!
      <a href="puppies.html">Learn more</a>
    </p>
  </article>
  <!-- the second article... notice its structural similarity to the first -->
  <article>
    <h1>Kittens For Sale</h1>
    <img src="images/sad_kitten.jpg" />
    <p>
      Get 'em while they're hot!
      <a href="kittens.html">Learn more</a>
    </p>
  </article>
</section>
```

---

template: html
name: html-4

## Forms

HTML allows web visitors to enter data into forms - there are a variety of different [user interface components specific to forms](https://www.w3schools.com/html/html_forms.asp). For example:

```html
<form action="/send" method="POST">
  <label for="fname">Your name:</label>
  <input type="text" name="fname" />
  <!-- a one-line text field for their email address -->
  <label for="femail">Your email:</label>
  <input type="email" name="femail" />
  <!-- a multi-line input for their comment -->
  <label for="fmessage">Your comment:</label>
  &lt;textarea name="fmessage" &gt;&lt;/textarea&gt;
  <!-- submit button with the words, 'Send to us!' on it -->
  <input type="submit" value="Send to us!" />
</form>
```

---

template: html
name: html-5

## Forms (continued)

Some important and required form tag attributes:

```html
<form action="/send" method="POST">...</form>
```

--

- `action="/send"` indicates that when the user submits the form, the web browser will send a request to the server's `/send` route. Presumably the server is set up properly to receive the form data at this route and do something useful with it.

--

- `method="POST"` indicates that the web browser will submit the data as an HTTP `POST` to the server, rather than an HTTP `GET` request, which is the browser's default, [remember](#http-request-types)?

---

template: html
name: html-5

## That's it.

What you just learned is how to code for content that will be displayed in the `body` of a web page - the part of an HTML document that represents the visible content.

- Learn [a bit more about HTML documents](https://nyu-computer-science.github.io/web-design/html/).

---

name: css

# CSS

--

name: css-1

## Adding style

For any given web page, CSS code indicates the style to use for the content indicated by the HTML.

- Give _all_ level 2 headings green text: `h2 { color: green; }`
- Give _all_ paragraphs a pink background: `p { background-color: pink; }`
- Set the dimensions of _all_ images: `img { width: 200px; height: 300px; }`
- Give _all_ articles a thick pink dotted border, a bold `serif` font, and lots of space around the contents inside them:

```css
article {
  border: 10px dotted pink;
  font-family: georgia;
  font-weight: bold;
  padding: 20px;
}
```

[Try it!](https://jsfiddle.net/barsteinfoo/adgrp9zb/6/)

---

template: css
name: css-2

## Selecting one or more elements

Let's say you had four paragraphs, and wanted to style only two of them the same. Mark them with a `class` attribute in the HTML. If you want to uniquely style only one, mark it with an `id` attribute:

```html
<p>Lorem ipsum dolor sit amet.</p>
<p class="my_favorite_paragraphs">Ipsum dolor sit amet lorem.</p>
<p id="a_really_special_paragraph">Dolor sit amet lorem ipsum.</p>
<p class="my_favorite_paragraphs">Ipsum dolor sit amet lorem.</p>
```

And select only the paragraphs that match these attributes in the CSS:

```css
p.my_favorite_paragraphs {
  box-shadow: 5px 5px 10px; /* a drop shadow */
}
p#a_really_special_paragraph {
  font-size: 24px; /* relatively big */
}
```

[Try it!](https://jsfiddle.net/barsteinfoo/adgrp9zb/8/)

---

template: css
name: css-3

## Positioning elements and creating layouts

That's almost it. But there is one very important part of CSS code that we will not address here is how you place elements onto the web page in the location where you want them to go.

There are a variety of ways... the latest greatest is to **CSS Flexbox** - see [a simple example](https://jsfiddle.net/barsteinfoo/adgrp9zb/13/) - flexbox is how layouts should be done with React.

- First learn [more about basic CSS](https://nyu-computer-science.github.io/web-design/css/).
- Then learn [more about layouts with CSS flexbox](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Flexible_Box_Layout/Basic_Concepts_of_Flexbox).

---

name: back-end

# Back-End Technologies

--

## Overview

Back-end technologies are those languages or programs used to control the behavior of the server and how it responds to various kinds of client requests.

---

template: back-end

## Servers control what the client receives

The server can be programmed to modify the HTML, CSS, and Javascript code that is sent to the client in response to the request.

![Client server responsibilities](../files/the_web/client_server_front_back_ends.png)

---

template: back-end

## Examples

For example, back-end programming on the server-side might allow a web server to...

- Send a Spanish version of a web page to a user whose browser's HTTP request said it prefers Spanish, and an English version of the same page to a browser with English as its language setting.

--

- Send a mobile version of a web page to a user whose browser's HTTP request said it is running on a mobile device, and a desktop version of the same page to a browser whose HTTP request says it's on a desktop computer.

--

- Send the client a web page that automatically includes today's news today and tomorrow's news tomorrow, rather than sending the client the same news articles every day.

--

- Allow a server to "remember" what products each user adds into their shopping cart; and serve all users the same shopping cart page, but with their own cart's products in it, not someone else's.

---

template: back-end

## Popular back-end programming languages

Just about any high-level programaming language of note can be used to control how a web server responds to requests.

- **Node.js (server-side Javascript)**
- **Ruby**
- **Python**
- **PHP**
- **C#**
- **ASP**

---

template: back-end

## Frameworks

The choice of frameworks to simplify the process of writing server-side code depends on which server-side programming language is being used.

- Node.js (server-side Javascript) usually use the **Express** framework
- Ruby projects usually use the **Rails** framework
- Python projects usually use the **Django** or **Flask** frameworks
- PHP projects often use **Laravel** or **Sympfony** frameworks
- C# projects usually use the **.NET** framework
- ASP projects usually use the **.NET** framework

---

template: back-end

## Example

This example, written in Python with `flask` and `pymongo` modules, would save data submitted by [an HTML form](#html-4) into a MongoDB database document.

```python
@app.route('/save', methods=['POST'])
def save_message():
    name = request.form['fname'] # retrieve the data the user entered into the fname field
    name = request.form['femail'] # retrieve the data the user entered into the femail field
    message = request.form['fmessage'] # retrieve the data the user entered into the fmessage field

    # create a new document with the data the user entered, plus the current date & time
    doc_to_insert = {
        "name": name,
        "email": email,
        "message": message,
        "created_at": datetime.datetime.utcnow() # the time right now, in UTC time
    }
    collection = app.db["exampleapp"] # select the collection where we want to save this document
    mongoid = collection.insert_one(doc_to_insert) # insert a new document, store the new document's _id value

    return render_template('show.html', mongoid=mongoid, doc=doc_to_insert) # render an HTML page with the new post displayed
```

---

name: databases

# Databases

---

template: databases

## Overview

As you undoubtedly know, a database is any technology used to store data

- fast storage and retrieval
- easy integration with back-end technologies and programming languages

---

template: databases

## Data flow

The server-side code usually communicates with the database to save new data sent from the client, or to retrieve existing data and use it to determine how to respond.

![Client-server-database](../files/the_web/client_server_databases.png)

---

template: databases

## Popular back-end databases for web sites and apps

Relational databases based on the SQL language have traditionally dominated since the 1970's.

- Oracle
- MS SQL
- PostgreSQL
- MySQL
- Amazon Aurora
- ... and more

---

template: databases

## Popular back-end databases for web sites and apps

However NoSQL databases are now surging, due to the changing expectations of web and mobile app developers and those using cloud-based infrastructure.

- MongoDB
- Redis
- Google Firebase
- Amazon DynamoDB
- ... and more

---

template: databases

## Serverless databases

A growing market is the "serverless database", where the server provides the initial front-end code to the client, but further data is sent/received by front-end Javascript directly to/from the database.

![Serverless databases](../files/the_web/client_server_databases_serverless.png)

---

template: databases

## Front-end data storage for web apps

There are some limited data storage capabilities of web browsers, where data used by a web site is stored locally on the client machine.

--

- **Cookies** - often used to store tracking codes that are secretly passed to the server in an HTTP header with every request

--

- **LocalStorage** - often used to store larger block of data, such as web pagee content that can be displayed even when browser is offline