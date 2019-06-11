# 2019 Operating Systems Project 2 Group 14 
## Programming design

In this project, we created and simulate an application of IoT in a master-slave model. There will be master device and slave device which could be accessed by the user through slave-side user program and master-side user program. In general, when the slave device set the IP address (set by the slave user program) , a Transmission Control Protocol (TCP) will be established and it will display the server receiving data from the distinct device. 
   
The master device then will listen to distinct port and then, the kernel will process the data using the kernel program. There will be 2 kinds of kernel program. The first one is to receive the data from master device and transmit it to slave-side user program. The another one is to receive data from slave-side user program and send it to master-side user program. In the end, the result will display the transmission time and the size.

## The Result

![62455131_2112094595761988_6432115161036750848_n](https://user-images.githubusercontent.com/31887135/59286839-0e5c5200-8ca3-11e9-80d2-c8b0f454bbce.png)(The outputs for memory-mapped I/O)
![64274920_430527401012861_5288177460997783552_n](https://user-images.githubusercontent.com/31887135/59286842-10beac00-8ca3-11e9-99ec-416f41daf429.png)(The outputs for file I/O)


## The comparison the performance between file I/O and memory-mapped I/O, and explain why.

File I/O should have a better performance over memory-mapped I/O because it uses two separate address spaces for memory and I/O device. However, from what we see in our results, they have similar results. File I/O is better than memory-mapped I/O in only some cases.

## Work list of team members

* 方喬 b06502060 機械二 
    *  Arrange the implementation of master device and write the code
* 綦家承 b06902078 資工二
    * Write the report.md
    * Fix major and minor mistake regarding overall performance
* 陳智豐 b06902088 資工二 
    * Arrange the implementation of socket and write the code
* 羅寶瑩 b06902091 資工二 
    * Arrange the implementation of user program and write the code
* 林貞 b06902099 資工二
    * Write the report.md
    * Supervise overall performance
* 李芍妍 t07902137 資工一 
    * Arrange the implementation of slave device and write the code

