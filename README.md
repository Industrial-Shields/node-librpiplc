# node-librpiplc
### by Industrial Shields

**node-librpiplc** provides a NodeJS wrapper for the librpiplc C library, enabling JavaScript applications to interface with the GPIOs of Raspberry Pi based Industrial Shields PLCs:
* Analog reads and write
* Digital reads and writes
* Relay controlling


## Licensing
This library is dual-licensed under the EUPL-1.2 (for backwards compatibility) and the LGPL-3.0-or-later. The test programs are licensed under the GPL-3.0-or-later.


## Prerequisites

### One of our PLCs: https://www.industrialshields.com/


### Installing librpiplc

You must first install the [librpiplc](https://github.com/Industrial-Shields/librpiplc), as this library depends on it.



## Installing

1. Go to the directory where you want to install the NPM package.

2. Assuming you have a full NodeJS environment working, call `npm` to install the package:
```
npm install @industrial-shields/librpiplc@<tagname>
```
Where `<tagname>` is the version you wish to download. Before this unification, you had to choose between versions 1.X.X (for V3 PLCs) or 2.X.X (for V4 PLCs). As of 3.X.X this library is compatible with our PLCs regardless of it's version.
You can check the available versions in here: https://github.com/Industrial-Shields/node-librpiplc/tags



## API
To start using the library, you need to import it with the following statement:
```
const rpiplc = require("@industrial-shields/librpiplc")("VERSION_NAME", "MODEL_NAME");


// Or, in ESM modules:
import rpiplc from '../lib/addon.js';

const rpiplc = rpiplc("VERSION_NAME", "MODEL_NAME");
```

Finally, it is a good practice to initialize the pins you want to use as INPUTS or OUTPUTS. You can do so with the `rpiplc.pinMode(pin_name, mode)` function. For example, if you want to read from the **I0.2** input:
```
rpiplc.pinMode("I0.2", rpiplc.INPUT)
```

The functions to read and write are the following:
```
digitalRead(): rpiplc.digitalRead(PIN_NAME) # It returns either rpiplc.HIGH (enabled) or rpiplc.LOW (disabled)

digitalWrite(): rpiplc.digitalWrite(PIN_NAME, VALUE) # Where value is either rpiplc.HIGH (enabled) or rpiplc.LOW (disabled)
# It can be used to control both digital outputs and relays.

analogRead(): rpiplc.analogRead(PIN_NAME) # It returns a 12-bit number that goes from 0 to 4095 (0 to 10V)

analogWrite(): rpiplc.analogWrite(PIN_NAME, VALUE) # Where value is a 12-bit number that goes from 0 to 4095 (0 to 10V)

delay(): rpiplc.delay(MS) # Where MS is the number of milliseconds to block the execution before continuing
```



## References

1. [Available PLC versions](#available-versions)
1. [Available PLC models](#available-models)



### <a name="available-versions"></a>Available PLC versions
```
RPIPLC_V3 (deprecated)
RPIPLC_V4
RPIPLC_V6

UPSAFEPI_V6

GATEBERRY_V9

TOUCHBERRY_PI_V1
```


### <a name="available-models"></a>Available PLC models
```
RPIPLC_CPU
RPIPLC_19R
RPIPLC_21
RPIPLC_38AR
RPIPLC_38R
RPIPLC_42
RPIPLC_50RRA
RPIPLC_53ARR
RPIPLC_54ARA
RPIPLC_57AAR
RPIPLC_57R
RPIPLC_58

UPSAFEPI (for UPSafePis)

GATEBERRY (for GateBerries)

TOUCHBERRY_PI (for TouchBerry Pis)
```
