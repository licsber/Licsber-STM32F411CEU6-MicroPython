# Licsber - STM32F411CEU6 - MicroPython

## How to build

### ENV

```zsh
brew install gcc-arm-embedded
python3 -m pip install pyusb
```

### BUILD

```zsh
git clone --depth=1 https://github.com/micropython/micropython.git
cd micropython/
make -C mpy-cross/
cd ports/stm32/
git clone https://github.com/Licsber/Licsber-STM32F411CEU6-MicroPython.git boards/licsber/
make BOARD=licsber clean
make BOARD=licsber -j
make BOARD=licsber deploy
```

## How to use

### LED

R: PA0 G: PA1 B: PA2

```python
import time

R = pyb.LED(1)
G = pyb.LED(2)
B = pyb.LED(3)

G.toggle()
B.toggle()
time.sleep(1)
G.toggle()
B.toggle()

```

### Switch

Key: PC13

```python
sw = pyb.Switch()
sw.value()  # returns True or False
sw.callback(lambda: pyb.LED(3).toggle())

```

### I2C

I2C1: SCL(PB6) SDA(PB7)  
I2C2: SCL(PB10) SDA(PB9)  
I2C3: SCL(PA8) SDA(PB8)

```python
i2c = machine.I2C(1)
# i2c = I2C(scl='PB3', sda='PB5', freq=480000)
i2c.scan()

i2c.writeto(0x60, '<123>')
i2c.readfrom(0x60, 5)

i2c.readfrom_mem(0x60, 0x10, 7)
i2c.writeto_mem(0x60, 0x10, 'licsber')
```

### UART

UART1: TX(PA9) RX(PA10)  
UART2: TX(PA2) RX(PA3)  
UART6: TX(PA11) RX(PA12) # Not allowed, used by USB.

```python
u1 = pyb.UART(1, 115200)
u1.write('Hello\nLicsber!')
u1.readline()
u1.readline()

```

## About

Contributions Welcome!
Want Issues and PRs!
