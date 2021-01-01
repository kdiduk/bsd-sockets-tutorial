# Inter-process communication using BSD Sockets and TCP

Tutorial on client-server programming using Berkeley sockets

## Introduction

On Unix/Linux and BSD operating systems socket API is part of Standard C Library.
It means that no any external dependencies are needed to use it in our C programs.
It only needs to include required header files which are available in the system by default.

## TCP vs UDP

In this tutorial we are going to consider only TCP.
There is a great article about socket programming using UDP by Glenn Fiedler [[1]](#1).

## Example: server listening for incoming connections

Let's create a small program that accepts incoming TCP connections.

## References

<a id="1">[1]</a>
[Glenn Fiedler, Sending and Receiving Packets](https://gafferongames.com/post/sending_and_receiving_packets/)

