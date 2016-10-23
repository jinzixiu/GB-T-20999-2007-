#晋城市智慧交通 国标GB/T 20999-2007 标准的交通信号控制机上位机控制系统项目

### author:jinzixiu time:2014.9


### Project introduction:
National standard 20999-2007 GB/T traffic signal control machine PC control software.After cross compilation, Can be run over win7, wince, Linux operating system
Using the QT class library to write, the organization allows, open source.
Developers want to use the same development agreement

### How to use
Want to modify two times, the proposal,First you need to build the Qt development environment, version 4.7 or more.

file directory "anComtest" has  main files 

The "qtserialport" directory is the main file of serial communication, which is suitable for win7, wince, and Linux operating system.

"AnComtest-build-desktop" folder on the compiled PC Windows version of the program, if you need to use Linux, wince version, please build a cross compiler chain, self compiled!

"anComtest-build-desktop-release":"AnComtest-build-desktop-release" is the release version of the software, you can directly click on the use, but you have to make sure that your computer is connected to a serial port, or USB to the serial port device

To do a applicatin is very easy, so you can focus on the use of this project is: 
  1. serial automatic solution frame algorithm.
  2. qtserialport this cross platform serial port.
  
  
