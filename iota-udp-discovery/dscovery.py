from threading import Thread
import time
from socket import *

msg = 'Unicorn Smart AC'

# Create Socket and send data
cs = socket(AF_INET, SOCK_DGRAM)
cs.settimeout(2)
cs.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
cs.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)
cs.sendto(msg, ('255.255.255.255', 786))
#cs.sendto(msg, ('192.168.10.15', 786))

# Wait for reply
try:
    data, addr = cs.recvfrom(128)
    print "Got message '{}' from {}".format(data,addr)
except socket.timeout:
    pass
