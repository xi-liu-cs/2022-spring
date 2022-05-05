# Blockchain

Database Design

---

# Agenda

1. [Overview](#overview)
1. [Bitcoin basics](#concepts)
1. [Smart Contracts](#smart-contracts)
1. [Conclusions](#conclusions)

---

name: overview

# Overview

--

## Concept

A **blockchain** is mechanism for storing data with a few properties that make it unusual.

--

- It is peer-to-peer. There is no need for a central server or a central organization to pass messages among computers on the network.

--

- It operates in a trustless environment, yet the data held within it is trustworthy.

--

- It depends upon some form of reward for those who help maintain it.

--

- The data held within it is immutable.

--

- All data is public and verifiable.

---

template: overview

## Creation myth

The true indentity of the inventor of blockchain is either unknown or disputed.

--

- On October 31st 2008, a user by the name of Satoshi Nakomoto, published [the Bitcoin white paper](https://bitcoin.org/bitcoin.pdf) on a cryptography-focused email list.

--

- A few likely suspects include [Hal Finney](https://en.wikipedia.org/wiki/Hal_Finney) (inventor of '[proof of work](https://en.wikipedia.org/wiki/Proof_of_work)'), [Wei Dai](https://en.wikipedia.org/wiki/Wei_Dai) (inventor of [b-money](https://en.bitcoin.it/wiki/B-money)), [Nick Szabo](https://en.wikipedia.org/wiki/Nick_Szabo) (inventor of [bit gold](https://unenumerated.blogspot.com/2005/12/bit-gold.html)), and [Craig Wright](https://en.wikipedia.org/wiki/Craig_Steven_Wright#Bitcoin) (fiery Australian polymath and businessman)

--

- Finney, Dai, and Szabo have all denied being Satoshi Nakomoto

--

- Wright claims that he is Satoshi Nakomoto and that he created Bitcoin with the help of [Dave Kleiman](https://en.wikipedia.org/wiki/Dave_Kleiman), although he has evaded requests to provide proof of this claim.

--
Kleinman's family are currently embroiled in a [farcical legal dispute with Wright](https://chainbulletin.com/timeline-craig-wrights-story/).

--

- Several notable crypto-celebrities, including [Vitalik Buterin](https://en.wikipedia.org/wiki/Vitalik_Buterin) (founder of Ethereum), [CZ](https://en.wikipedia.org/wiki/Changpeng_Zhao) (CEO of Binance), and Roger Ver (self-proclaimed 'Bitcoin Jesus') have called Wright a "fraud".

---

name: concepts

# Bitcoin basics

---

template: concepts

## Example code

Some of the basic cryptography concepts mentioned in this section, including hashes and digital signatures, are exhibited in Python code in [a companion Jupyter Notebook](../files/crypto/cryptography.ipynb)

---

template: concepts

## Hash

A cryptographic hashing function is a algorithm that can take data of an arbitrary length and produce a unique fixed-length 'digest' form of the data - the **hash** of the data.

--

- The same data, when run multiple times through the same hashing function, will always produce the same hash. These functions are **deterministic**.

--

- It is infeasible for any two different pieces of data, when run through the same hashing function, to produce the same hash. Hashes are thus **unique** to the data from which they are derived.

--

- It is infeasible to be able to discover the original data from its hash. Hashing functions are **one-way**.

--

- Hash functions are computationally simple and **fast**.

---

template: concepts

## Hash (continued)

![Hash SHA256](../files/crypto/hash.svg)

---

template: concepts

## Hash (continued)

Hashes have two important use cases:

--

- **Authenticity**: a sender can send both a message and the hash of the message to a recipient.

--
The recipient can then run the message through the hashing function, and compare the hash to the hash received from the sender. If the two match, then the message has not been tampered with by a 3rd party.

--

- **Proof of work**: it is not possible to predict what the hash of any given data will look like.

--
Thus, if trying to find data that produces a hash with specific attributes, a **brute force** approach must be taken, where a message is modified and hashed repeatedly until a hash with the desired attributes is encountered.

--
Proof of work systems require that a message sender have performed a particular amount of computational work by rejecting messages that do not contain a hash meeting specific requirements.

--
The first such system, created in 1997, was called [Hashcash](https://en.wikipedia.org/wiki/Hashcash), and was intended to make spam unprofitable by requiring emails to show proof of work.

---

template: concepts

## Nonce

A **nonce** is arbitrary data added to a message in order to change the hash of that message so as to hopefully meet the hash requirements of a proof of work system.

--

- the word, [nonce](https://www.merriam-webster.com/dictionary/nonce), originated in the 13th century, meaning "occurring, used, or made only once or for a special occasion".

--

- if the message plus the nonce do not produce a hash with the desired attributes, a different nonce must be used, thus expending work.

---

template: concepts

## Nonce (continued)

![Nonce](../files/crypto/nonce.svg)

---

template: concepts

## Mining

**Mining** is the process of trying out different nonces over and over again until one is found which, when added to the data in the message such that the requirements of the proof of work system are met.

--

- The difficulty of mining depends upon the difficulty of the requirements of the proof of work scheme.

--

- In cryptocurrencies that follow a proof of work system, miners that find a successful nonce are rewarded with newly-minted cryptocurrency coins.

--

- Thus, while minining requires continual use of computing power and energy resources, it offers a chance of a reward.

---

template: concepts

## Mining (continued)

![Mining](../files/crypto/mining.svg)

---

template: concepts

## Public key cryptography

[Public key cryptography](https://en.wikipedia.org/wiki/Public-key_cryptography#History) is a set of technologies for proving ownership of digital data. Two mathematically interrelated keys (text strings) are involved:

--

- a **private key**, which should be kept private.

--

- a **public key**, which can be shared publicly without concern.

--
It is derived from the private key by a one-way mathematical function.

---

template: concepts

## Public key cryptography (continued)

There are two main uses of public key cryptography:

--

- **Privacy** - any digital message can be encrypted with the intended recipient's public key.

--
Only the recipient, who holds the corresponding private key, will be able to decrypt the message.

--

- **Authentication** - a sender of a message can use their own private key to "sign" the message, producing a **digital signature** that can safely sent with the message.

--
The recipient can use the sender's public key to verify the authenticity of that signature, and thus the message.

---

template: concepts

## Privacy

![Public key encryption for privacy](../files/crypto/encrypt.svg)

---

template: concepts

## Authentication

![Public key encryption for authentication](../files/crypto/authenticity.svg)

---

template: concepts

## Addresses

In blockchains, each user has an **address** from which they can send or receive cryptocurrency transactions.

--

- This address is nothing but a shortened form of a public key, to which the user keeps secret the corresponding private key.

---

template: concepts

## Merkle tree

A **Merkle Tree**, or hash tree, is a hash of hashes, where the top-most hash can be considered a fixed-length digest of the data beneath it.

--

- The data in the leaf nodes is hashed, and those hashes are hashed, until all hashes convege at the top-most hash, the Merkle Root.

--

- It is possible to verify that a given piece of data in a leaf node is present in a given hash tree without re-hashing all data in the tree.

---

template: concepts

## Merkle tree (continued)

![Merkle Tree](../files/crypto/merkle_tree.svg)

---

template: concepts

## Block

At last, we come to the foundational concept of the blockchain - the block! Each block includes:

--

- the **hash of the previous block**, thus creating a **chain** where each block references the previous block.

--

- a **nonce** that, when combined with the other data in the block, successfully produces a hash that meets specific requirements in a proof of work scheme.

--

- a **Merkle Root** that is the top of a hash tree.

--

- a set of individual **transactions**, each digitally signed by the sender using their private key, which together make up the data in the leaf nodes of the hash tree.

---

template: concepts

## Block (continued)

![A block](../files/crypto/block.svg)

---

template: concepts

## Block (continued again)

![A block](../files/crypto/blockchain.svg)

---

template: concepts

## Block (continued once more)

Since each new block includes the hash of the previous block, any tampering with data in previous blocks (which would change their hashes) would invalidate subsequent blocks.

--

- Any computer running the full blockchain software validates all blocks and detects fraudulent blocks.

--

![Invalid blockchain](../files/crypto/blockchain_invalid.svg)

---

template: concepts

## Block (continued yet again)

Since the proof of work scheme requires that a block's hash meet certain specific requirements which are time-consuming to achieve, there is an intentional latency to the system.

--

- in the Bitcoin system, it takes on average about _10 minutes_ for one of the computers on the network to produce a viable block.

--

- the difficulty of the proof of work requirements is automatically _adjusted every 2 weeks_ to keep this pace, even as the number of computers on the network and the strength of their processing power is in continual flux.

--

- a typical computer on the network will solve the hashing problem once every _2 years, on average_.

---

template: concepts

## Transactions

Each transaction stored in a block includes details about the sender, the recipient, and the amount of funds to transfer.

--

- A finite number of transactions fit into the memory space of each block.

--

- Each transaction is **signed** by the sender, using their private key. This signature is included as part of the transaction data.

--
The authenticity of this signature can be validated by anyone, by simply using the sender's public key.

--

- All computers running the blockchain software can validate each transaction.

--

- The data for a transaction shows `inputs` - addresses from which funds will be taken, and `outputs` - addresses to which those funds will be sent.

--

- If the sum of `inputs` funds is more than the sum being sent to the `outputs`, then the sender can choose to return the excess balance to themselves, or provide it as _a tip for the miners_.

---

template: concepts

## Mining (continued)

Computers running the full version of the blockchain software (a.k.a. 'full nodes') compete with one-another to solve the hashing challenge of the proof of work system.

--

- Each full node picks a set of transactions from a shared list of pending transactions (the _mempool_) that all nodes pass around the network.

--
They tend to pick those transactions that offer them the highest tip, if any are available.

--

- The first computer to produce a hash that meets the proof of work requirements is able to publish their block by sending it around to the other full nodes on the network, and is rewarded with newly-minted cryptocurrency.

--

- The other full nodes will accept the new block once they validate that its hash meets the proof of work requirements.

---

name: smart-contracts

# Smart Contracts

--

## Concept

While Bitcoin included a limited scripting language that allowed some programmable logic to be placed inside of any transaction, [Ethereum](https://en.wikipedia.org/wiki/Ethereum) is the blockchain that took this concept to the next level.

--

- A "**smart contract**", a term coined by Nick Szabo, is a program.

--

- In Ethereum, smart contracts have addresses, just like use accounts, and can send or receive cryptocurrency to/from other accounts.

--

- Like everything on the blockchain, smart contracts are public and validated and executed by all full nodes on the network.

--
The entire network is considered a single **virtual machine** execution environment.

--

- Any account - be it a user account or a smart contract - can send cryptocurrency to a smart contract to trigger one of its functions to be executed.

--

- Functions in a smart contract typically transfer cryptocurrency or **tokens** to and from addresses on the blockchain.

---

template: smart-contracts

## Dapps

_Decentralized applications_, similar to the apps that most people are familiar with on the web, can be hosted on a blockchain, in combination with related decentralized platforms.

--

- From a user's perspective, dapps appear to operate just like regular apps.

--

- Decentralized file storage services, like [IPFS](https://ipfs.io/), allow the files that make up the app to be stored across the entire network rather than on a single server.

--

- Smart contracts allow the coin- or token-related functions to be hosted on a blockchain, rather than on a single server.

--

- Integration with cryptocurrency wallets allows users of dapps to digitally sign transfers of cryptocurrency or tokens to authenticate them.

--

- Check out [some examples](https://duckduckgo.com/?q=examples+of+dapps)

---

template: smart-contracts

## Tokens

Tokens are arbitrary representations of value.

--

- Tokens can be created (i.e. 'minted') by smart contracts and sent and received to or from any address on the blockchain.

--

- Ethereum's [ERC-20](https://ethereum.org/en/developers/docs/standards/tokens/erc-20/), [ERC-721](https://ethereum.org/en/developers/docs/standards/tokens/erc-721/), and other standards attempt to standardize which functions and behaviors should be included in smart contracts that issue _fungible_ and _non-fungible_ tokens.

--
This standardization allows for interoperability among smart contracts and even between different blockchains.

--

- The value of a token is determined by what you can do with that token or by what else you might be trade that token for.

--

- Some tokens _act like reputation points_ within social networks and gaming environments.

--
Other tokens act as _symbolic representations of ownership or possession_ of physical goods.

--
Still other tokens are _useless_ except for the fact that _you can trade them_ for other tokens or _fiat currency_.

---

template: smart-contracts

## DeFi

The world of [decentralized finance](https://www.nasdaq.com/articles/decentralized-finance-defi%3A-an-emerging-giant-2021-01-15) (DeFi) - finance on the blockchain - has become extremely popular within the last year.

--

- DeFi is growing to become a parallel financial system, with all kinds of financial instruments, old and new, on offer: borrowing, lending, crowdfunding, buying shares, taking long or short positions on the market, trading on "foreign currency" exchanges, providing _liquidity_, _farming_, and more.

--

- Cryptocurrency as "[programmable money](https://www.bissresearch.com/what-actually-is-programmable-money/)", allows people, funds, smart contracts and bots to perform any financial operation imaginable with little-to-no regulation.

--

- Warning: this environment is rife with speculators trying to make quick fortunes by inventing or betting on, and _shilling_ cryptocurrencies or tokens with little-to-no inherent value. Beware of [rug pulls](https://www.coingecko.com/en/glossary/rug-pulled).

--

- [#MOON!](https://www.reddit.com/r/SafeMoon/)

---

name: concerns

# Concerns

--

## Concept

Given the relative newness of blockchain, the incessant touting of its disruptive capabilities, and its explosive growth as a means of financial speculation and perhaps exploitation, many concerns about it have cropped up, including:

--

- Does blockchain have a use outside of cryptocurrency?

--
Listen to crypto explainer Andreas Antonopoulos consider "[Blockchain vs. Bullshit](https://www.youtube.com/watch?v=SMEOKDVXlUo)"".

--

- Isn't blockchain a giant waste of energy that is killing the environment?

--
View the [Cambridge Center for Alternative Finance's comparisons](https://cbeci.org/cbeci/comparisons) of Bitcoin's energy consumption to other common energy draws.

--

- Isn't blockchain designed to let criminals evade the government?

--
[Watch self-proclaimed Satoshi, Craig Wright, denounce decentralization](https://www.youtube.com/watch?v=0JvDauIX5lg) as "a lie" and the [Brookings Institute tout its crime-fighting properties](.edu/blog/future-development/2018/02/01/can-cryptocurrencies-and-blockchain-help-fight-corruption/).

--

- Can't the government just kill it once it becomes too big?

--
Nobody is really sure if this is possible.

--
Some nations, like China, are [trying to subvert it](https://www.bloomberg.com/news/articles/2020-06-01/china-is-making-cryptocurrency-to-challenge-bitcoin-and-dollar).