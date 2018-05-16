wmBus-tool
==========

This repo is a fork of the ffcrg/ecpiww repo and widens the usage of the wmBus library.


[![GitHub issues](https://img.shields.io/github/issues/the78mole/wmBus-tool.svg?style=flat-square)](https://github.com/the78mole/wmBus-tool/issues)
[![GitHub license](https://img.shields.io/github/license/the78mole/wmBus-tool.svg?style=flat-square)](https://github.com/the78mole/wmBus-tool)


Hardware:
  - Any linux
  - at least one wM-Bus device
  - wireless M-Bus USB Stick (2 manufacturers are supported)
  	- IMST IM871A-USB Stick ( available at http://www.tekmodul.de/index.php?id=shop-wireless_m-bus_oms_module or http://webshop.imst.de/funkmodule/im871a-usb-wireless-mbus-usb-adapter-868-mhz.html)
  	- AMBER Wireless M-Bus USB Adapter (http://amber-wireless.de/406-1-AMB8465-M.html)

Features:
 - The application shows you all received wireless M-Bus packages. 
 - coming soon


# TODO

 - Use autotools
 - Generate a shared library
 - Add MQTT-Client
 - Add REST-Client

# Building the software

The build is easily done by issuing

    make