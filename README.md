# Inter-process communication using BSD Sockets and TCP

Tutorial on client-server programming using Berkeley sockets

## Introduction

On Unix/Linux and BSD operating systems socket API is part of Standard C Library.
It means that no any external dependencies are needed to use it in our C programs.
It only needs to include required header files which are available in the system by default.

## TCP vs UDP

In this tutorial we are going to consider only TCP.
There is a great article about socket programming using UDP by Glenn Fiedler [[1]](#1).

## Opening and closing sockets

To start working with a soket, regardless it it's sending or receiving data, we need to the following:
1) create a socket using `socket()` function
2) bind it to an address (and port) using `bind()` function

After the work with a socket is done, it has to be closed using `close()` function.

### Opening a socket

### Binding a socket

Before listening for incoming connections, a socket should be bound to a local interface address using `bind()` function.

> It is possible to start listening on an unbound socket.
> In such case the socket is automatically bound to a random free port with the local address set to INADDR_ANY.

### Closing a socket

## Example: server listening for incoming connections

Let's create a small program that accepts incoming TCP connections.

## References

<a id="1">[1]</a>
[Glenn Fiedler, Sending and Receiving Packets](https://gafferongames.com/post/sending_and_receiving_packets/)

