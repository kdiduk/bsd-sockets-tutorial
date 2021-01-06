# Inter-process communication using BSD Sockets and TCP

Tutorial on client-server programming using Berkeley sockets

## Introduction

On Unix/Linux and BSD operating systems socket API is part of Standard C Library.
It means that no any external dependencies are needed to use it in our C programs.
It only needs to include required header files which are available in the system by default.

## TCP vs UDP

In this tutorial we are going to consider only TCP.
There is a great article about socket programming using UDP by Glenn Fiedler [[2]](#2).

## Opening and closing sockets

To start working with a soket, regardless it it's sending or receiving data, we need to the following:
1) create a socket using `socket()` function
2) bind it to an address (and port) using `bind()` function

After the work with a socket is done, it has to be closed using `close()` function.

### Creating a socket: `socket()` function

The function to create a socket has the following prototype:

```
int socket(int domain, int type, int protocol);
```

#### `domain` parameter

The first parameter `domain` specifies the protocol family.

The POSIX standard [[1]](#1) defines only 3 possible values:
* `AF_UNIX` - UNIX internal protocols for local communications.
* `AF_INET` - Internet Protocol version 4 (IPv4) communications.
* `AF_INET6` - Internet Protocol version 6 (IPv6) communications.

On Linux systems there are many more other values defined.
In this article we are interested only in the last two values: `AF_INET` and `AF_INET6`.

Further we will see that we don't have to specify these values directly.
By using the function `getaddrinfo()` we can create IPv4/IPv6 protocol-independent sockets.

Instead of `AF_*` constants, some documentation and source code use corresponding `PF_*` constants (i.e. `PF_INET`, `PF_INET6`).
For example, man-pages on FreeBSD uses them.
The `PF` prefix stands for _"protocol family"_, while `AF` stands for _"address family"_.
Some people say that using `PF_*` constants in the `socket()` call is the right way.
However the POSIX standard defines only `AF_` constants and requires to use them.
In fact, the corresponding `AF_*` and `PF_*` constant have the same values.

#### `type` parameter

The second paramater, `type`, is the socket type.
There are different types of sockets.
The two most common ones are stream sockets and datagram sockets.

In this article we are going to consider only stream sockets.
For stream sockets the value of the parameter `type` should be specified as `SOCK_STREAM`.

#### `protocol` parameter

The third parameter, `protocol`, specifies the protocol for a given socket type.

### Binding a socket

Before listening for incoming connections, a socket should be bound to a local interface address using `bind()` function.

> It is possible to start listening on an unbound socket.
> In such case the socket is automatically bound to a random free port with the local address set to INADDR_ANY.

### Closing a socket

## Example: server listening for incoming connections

Let's create a small program that accepts incoming TCP connections.

## References

<a id="1">[1]</a>
[IEEE Std 1003.1-2017 (POSIX.1-2017)](https://pubs.opengroup.org/onlinepubs/9699919799/)

<a id="2">[2]</a>
[Glenn Fiedler, Sending and Receiving Packets](https://gafferongames.com/post/sending_and_receiving_packets/)

<a id="3">[3]</a>
[Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
