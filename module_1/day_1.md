# Summary and Code for Day 1

On Day 1, I learned the basics of how to use the linux terminal. I learned
things like changing directory, how to use different paths, file related
commands, etc. Also I learned managing the ownership and permissions on files.

The pipe operator | is used to give the output of one command as input to the
other command. It is useful because multiple commands can be combined together
to do use things in the terminal.

There are also text propessing tools available such as awk, grep, sed.

Then I set up my github ssh key which I will use always to connect to github
from my Ubuntu VM.

# Exercises

## Exercise 1

umer@umer-VMware20-1:~~/Documents$ mkdir project
umer@umer-VMware20-1:~~/Documents$ cd project
umer@umer-VMware20-1:~~/Documents/project$ mkdir src
umer@umer-VMware20-1:~~/Documents/project$ cd src
umer@umer-VMware20-1:~~/Documents/project/src$ touch rtl
umer@umer-VMware20-1:~~/Documents/project/src$ touch tb
umer@umer-VMware20-1:~~/Documents/project/src$ touch include
umer@umer-VMware20-1:~~/Documents/project/src$ cd ..
umer@umer-VMware20-1:~~/Documents/project$ mkdir docs
umer@umer-VMware20-1:~~/Documents/project$ mkdir scripts
umer@umer-VMware20-1:~~/Documents/project$ mkdir build
umer@umer-VMware20-1:~~/Documents/project$ tree . ├── build ├── docs ├── scripts
└── src ├── include ├── rtl └── tb

5 directories, 3 files

## Exercise 2

umer@umer-VMware20-1:~/Documents/project/docs$ wget
https://docs.riscv.org/reference/isa/_attachments/riscv-unprivileged.pdf
--2026-05-07 15:19:43--
https://docs.riscv.org/reference/isa/_attachments/riscv-unprivileged.pdf
Resolving docs.riscv.org (docs.riscv.org)... 185.199.109.153 Connecting to
docs.riscv.org (docs.riscv.org)|185.199.109.153|:443... connected. HTTP request
sent, awaiting response... 200 OK Length: 4580174 (4.4M) [application/pdf]
Saving to: ‘riscv-unprivileged.pdf’

riscv-unprivileged.pdf
100%[===============================================================================================>]
4.37M 3.72MB/s in 1.2s

2026-05-07 15:19:45 (3.72 MB/s) - ‘riscv-unprivileged.pdf’ saved
[4580174/4580174]

## Exercise 3

umer@umer-VMware20-1:~~/Documents/project/docs$ seq 1 100 | sort > random.txt
umer@umer-VMware20-1:~~/Documents/project/docs$ sort random.txt | uniq -c | sort
-nr | head -20 > top10.txt

## Exercise 4

umer@umer-VMware20-1:~/Documents/project/docs$ ssh -T git@github.com Hi
umerfaisal1! You've successfully authenticated, but GitHub does not provide
shell access.
