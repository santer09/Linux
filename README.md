# Linux CSUF (03/07/15)
Author - Erick Santos
working with Linux Shell (used UBUNTU)
File downloaders are programs used for downloading les from the Internet. In this assignment
you will implement two distinct types of multi-process downloaders (i.e. le downloaders that
comprise multiple processes):
1. a serial le downloader which downloads les one by one.
2. a parallel le downloader which dowloads multiple les in parallel.
You will then compare the performance of the two types of downloaders.
Both downloaders will use the Linux wget program in order to perform the actual downloading.
The usage of the wget is simple: wget <FILE URL>. For example, running from command line
the following command:
wget http://releases.ubuntu.com/11.10/ubuntu-11.10-desktop-i386.iso
will download the Ubuntu Linux iso image to the current directory.
