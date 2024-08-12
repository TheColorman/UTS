# CSEC Week 1 Part 1

## Task 1: Submit a screenshot of the username and password from Wireshark  

![Task 1 solution](./task1.png)

## Task 2:  Take a screenshot of the object of the image ‘logo.gif’ in the HTTP object list  

![Task 2 solution](./task2.png)

## Task 3: Using Zenmap and/or NetCraft to scan www.uts.edu.au. Gather and compare the information collected.  

1. What is its Ip address?  
   Scanned 60.254.143.40, but domain has the following other addresses: 60.254.143.10 2001:8002:e22:ef00::6866:f451 2001:8002:e22:ef00::6866:f443  
2. Type the IP address in the browser to access the webpage, explain your observations.  
   Invalid URL, the website is probably behind a reverse proxy.  
3. Who is the IP owner?  
   NetCraft found the ip 2.19.176.152, which is owned by Akamai Technologies.  
4. What is the server’s operating system?  
   Ubiquiti Dream Machine Pro gateway (Linux 4.19)  
5. What type of web server is being used?  
   AkamaiGHost (Akamai's HTTP Acceleration/Mirror service) - This server seems to be a relay of some kind to the actual UTS server.  
6. What is its server-side scripting technology?  
   According to NetCraft, they use Drupal PHP  
7. Can you find the email for the domain admin of this website for a possible phishing attack?  
   `dnsadmin@uts.edu.au`  
8. What is the ‘Reverse DNS’ for the website?  
   `a60-254-143-40.deploy.static.akamaitechnologies.com` - For the nmap scanned IP.  
9. Who is the domain registrar?  
   audns.net.au  
10. What is nameserver organization?  
    whois.audns.net.au
11. What company is hosting the website?  
    uts.edu.au  
12. Where is the hosting company geologically located?  
    AU  
