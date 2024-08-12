# CSEC Week 3 Lab 2 assesment

## Task 1: Editing the HOSTS file

- Dig command before nameserver change  
  ![Task1.1](./image5.png)  
- Interfaces file after nameserver change  
  ![Task1.2](./image4.png)  
- Dig command after maneserver change  
  ![Task1.3](./image1.png)  

## Task 2: Attack by spoofing DNS response

- Dig command in the client  
  ![Task2.1](./image6.png)  
- Wireshark DNS packet capture  
  ![Task2.2](./image8.png)  
- Netwag configuration (forgot to include the TTL and spoof type in the screenshot)  
  ![Task2.3](./image3.png)  
- Dig command after netwag attack (Not successful cause the real DNS server responds first)  
  ![Task2.4](./image2.png)  
- Wireshark DNS packet capture during attack  
  ![Task2.5](./image9.png)  
- Wireshark attack packet info section  
  ![Task2.6](./image11.png)  

## Task 3: DNS Server Cache Poisoning

- Netwag configuration  
  ![Task3.1](./image10.png)  
- Dig command with poisoned response  
  ![Task3.2](./image7.png)  
