from pwn import *

p = remote("hostname", port)

p.interactive()
