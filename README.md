# beebem OD

Port of beebem, a BBC Micro Model B emulator, for the JZ4770 (RG350/P/M, RG280V/M, GCW-ZERO, ...) and Lepus devices JZ4760(B) (LDKV/M, RS-97, ...) handhelds running OpenDingux mainline (current beta).

Based on RG350 port and RS-97 port, which in turn are based on the v0.6-1 of the GP2X port, the source of them can be found at:
 * [https://github.com/jeremyrayner/beebem-rg350](https://github.com/jeremyrayner/beebem-rg350)
 * [https://github.com/thefossilrecord/beebem-rs97](https://github.com/thefossilrecord/beebem-rs97)
 * [http://beebem-unix.bbcmicro.com/download.html](http://beebem-unix.bbcmicro.com/download.html)

Mainline OpenDingux can be obtained [here](http://od.abstraction.se/opendingux/latest/)

## Compile
Compile with:

`make -f Makefile_RG350`

For Lepus devices compile with:

`make TARGET=lepus -f Makefile_RG350`

If your toolchain is not located at default directories you can pass to make command:

`make TARGET=lepus TOOLCHAIN=/opt/your-opendingux-toolchain -f Makefile_RG350`

You'll need a toolchain to build from source.

[http://od.abstraction.se/opendingux/toolchain/](http://od.abstraction.se/opendingux/toolchain/)

## Create Distributable
After building the '`beebem`' binary, you then need to package for your OpenDingux device as an OPK file

Current make will create the OPK file for target device in the `dist` directory:
* `beebem_od.opk` for RG350 like devices.
* `beebem_lepus.opk` for Lepus devices..

## Installation
To install package onto the handheld...

* Depending on your device copy beebem_od.opk or beebem_lepus.opk to `/media/sdcard/APPS/` folder

* Running beebem at least once will create the ~/.beebem/roms if not already present on your device.
* Put ROMs with _exactly_ these names into ~/.beebem/roms

`'acorn_dnfs'` - Acorn DNFS 1.2 (chip ID# 201666)
`'os12'`       - Base operating system for BBC Model B (v1.2)
`'basic'`      - BBC Basic Programming Language (v2)

## Usage
* Put Disk Images, for example SSD files, e.g. into /media/sdcard/ROMS/BEEB/
