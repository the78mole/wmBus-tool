wmBus-tool
==========


Instead of this software, better use [wmbusmeters](https://github.com/the78mole/wmbusmeters) and publish the wmbus data to some MQTT broker...


This repo is based on the wmbus source of the [ffcrg/ecpiww repo](https://github.com/ffcrg/ecpiww), splits it up to
a library and an application part and widens its usage.

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

 - Enhance autotools
   - Generate a shared library
   - Make use of ./configure for compile time options
     - AES key readout
 - Implement tests
 - Use semaphore to sync threads instead of timed polling
 - Add MQTT-Client
 - Add REST-Client
 - Seperate wMBus generic from HW dependent 
   - extract IMST
   - throw out AMBER
   - Make stubs for AMBER (find somebody to test it)

## Long term ToDos

 - Use a plugin infrastructure to provide drivers for different wMBus interfaces
   See [Eli Bendersky's post](https://eli.thegreenplace.net/2012/08/24/plugins-in-c) as a starting point.

# Building the software

The build is easily done by issuing

    libtoolize
    aclocal
    autoreconf --install
    ./configure
    make
    make check           # If you want to be sure
    make doc             # If you want to have docs (html and latex)
    sudo make install
