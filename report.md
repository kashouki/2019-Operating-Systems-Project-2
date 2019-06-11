# 2019 Operating Systems Project 2 Group 14 
## Programming design

In this project, we created and simulate an application of IoT in a master-slave model. There will be master device and slave device which could be accessed by the user through slave-side user program and master-side user program. In general, when the slave device set the IP address (set by the slave user program) , a Transmission Control Protocol (TCP) will be established and it will display the server receiving data from the distinct device. 
   
The master device then will listen to distinct port and then, the kernel will process the data using the kernel program. There will be 2 kinds of kernel program. The first one is to receive the data from master device and transmit it to slave-side user program. The another one is to receive data from slave-side user program and send it to master-side user program. In the end, the result will display the transmission time and the size.

## The Result


## The comparison the performance between file I/O and memory-mapped I/O, and explain why.

## Work list of team members

* 方喬 b06502060 機械二 
    *  master device
* 綦家承 b06902078 資工二
    * report
* 陳智豐 b06902088 資工二 
    * socket
* 羅寶瑩 b06902091 資工二 
    * user program
* 林貞 b06902099 資工二
    * overall
* 李芍妍 t07902137 資工一 
    * slave device

