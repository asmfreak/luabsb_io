# luabsb_io
Simple Lua module to interact with BlackSwift GPIO. Based on articles by BlackSwift developers: [on wiki](http://www.black-swift.ru/wiki/index.php?title=%D0%A0%D0%B0%D0%B1%D0%BE%D1%82%D0%B0_%D1%81_GPIO) and [on habrahabr](http://habrahabr.ru/company/blackswift/blog/247925/).
This module uses _fast_ "direct gpio register access" method. It means that this library is working with AR9331's registers directly. Use it with care.

##Installing
1. Download .ipk from [releases tab](https://github.com/ASMfreaK/luabsb_io/releases) or build it yourself (see section below)
2. Copy it to your BlackSwift
3. Run `opkg install luabsb_io_<version>.ipk`

##Building.
1. Download and install OpenWrt SDK from the second article
2. Clone this repo to `packages` directory of OpenWrt SDK.
3. In `make menuconfig` section `Languages->` in subsection `Lua->` select `luabsb_io`
4. Run `make` if you want to build whole distribution or `make package/luabsb_io/install` to build only luabsb_io with dependencies.
5. Locate .ipk in `bin/ar71xx/packages/base/`


##Usage
Any work with GPIO starts with `setup()` function.
You can change GPIO direction (input or output) by calling `direction` function.
Value of a GPIO can be read with `read(gpio, val)` and can be set with `set(gpio, val)` functions, where `gpio` and `val` are integers.

This code turn off BlackSwift's red led (to led must be driven low to light):
```
> bsb = require "bsb"
> bsb.setup()
> bsb.direction(27, bsb.OUTPUT)
> bsb.set(27,bsb.HIGH)
```
