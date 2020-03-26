import socket
import csv
import re
from datetime import datetime

#config
server = "127.0.0.1"
port = 6969
threads = [] 

tcpServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
tcpServer.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
tcpServer.bind((server, port)) 

def handleConnect(ip,port):
	while True:
		response = conn.recv(2048)
		token = response.split(":")[1]
		if not response:
			exit(1)
	f = open("loggedTokens.csv", "w")
	logger = csv.writer(f,ip="",token="", time="")
	logger.writerow([ip, token, datetime.now()])




 
while True: 
	tcpServer.listen(4) 
	(conn, (ip,port)) = tcpServer.accept() 
	newthread = handleConnect(ip,port) 
	print("[+] - New Connection Starting Thread")
	newthread.start() 
	threads.append(newthread) 

