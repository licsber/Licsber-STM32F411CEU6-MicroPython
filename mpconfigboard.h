#define MICROPY_HW_BOARD_NAME       "LICSBER-F411CEU6"
#define MICROPY_HW_MCU_NAME         "STM32F411CE"
#define MICROPY_HW_FLASH_FS_LABEL   "Licsber411"

#define MICROPY_PY_THREAD           (1)
#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SERVO     (1)

// HSE is 12MHz, not 8MHz, cpu is 96MHz.
#define MICROPY_HW_CLK_PLLM (6)
#define MICROPY_HW_CLK_PLLN (96)
#define MICROPY_HW_CLK_PLLP (RCC_PLLP_DIV2)
#define MICROPY_HW_CLK_PLLQ (4)

#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (1)

// W25Q64, i have a 64Mbit SPI flash.
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (0)
#define MICROPY_HW_SPIFLASH_CS                   (pin_B12)
#define MICROPY_HW_SPIFLASH_SCK                  (pin_B13)
#define MICROPY_HW_SPIFLASH_MISO                 (pin_B14)
#define MICROPY_HW_SPIFLASH_MOSI                 (pin_B15)
#define MICROPY_HW_SPIFLASH_SIZE_BITS            (64 * 1024 * 1024)

#if !MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE

#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_BDEV_IOCTL(op, arg) ( \
    (op) == BDEV_IOCTL_NUM_BLOCKS ? (MICROPY_HW_SPIFLASH_SIZE_BITS / 8 / FLASH_BLOCK_SIZE) : \
    (op) == BDEV_IOCTL_INIT ? spi_bdev_ioctl(&spi_bdev, (op), (uint32_t)&spiflash_config) : \
    spi_bdev_ioctl(&spi_bdev, (op), (arg)) \
)
#define MICROPY_HW_BDEV_READBLOCKS(dest, bl, n) spi_bdev_readblocks(&spi_bdev, (dest), (bl), (n))
#define MICROPY_HW_BDEV_WRITEBLOCKS(src, bl, n) spi_bdev_writeblocks(&spi_bdev, (src), (bl), (n))
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev) // for extended block protocol

#endif

// UART config
#define MICROPY_HW_UART1_TX     (pin_A9)
#define MICROPY_HW_UART1_RX     (pin_A10)

#define MICROPY_HW_UART2_TX     (pin_A2)
#define MICROPY_HW_UART2_RX     (pin_A3)

#define MICROPY_HW_UART6_TX     (pin_A11)
#define MICROPY_HW_UART6_RX     (pin_A12)

// #define MICROPY_HW_UART_REPL        PYB_UART_6
// #define MICROPY_HW_UART_REPL_BAUD   115200

// I2C buses
#define MICROPY_HW_I2C1_SCL (pin_B6)
#define MICROPY_HW_I2C1_SDA (pin_B7)

#define MICROPY_HW_I2C2_SCL (pin_B10)
#define MICROPY_HW_I2C2_SDA (pin_B9)

#define MICROPY_HW_I2C3_SCL (pin_A8)
#define MICROPY_HW_I2C3_SDA (pin_B8)

// SPI buses
#define MICROPY_HW_SPI1_NSS  (pin_A4)
#define MICROPY_HW_SPI1_SCK  (pin_A5)
#define MICROPY_HW_SPI1_MISO (pin_A6)
#define MICROPY_HW_SPI1_MOSI (pin_A7)

// SPI2 used by flash.
#define MICROPY_HW_SPI2_NSS  (pin_B12)
#define MICROPY_HW_SPI2_SCK  (pin_B13)
#define MICROPY_HW_SPI2_MISO (pin_B14)
#define MICROPY_HW_SPI2_MOSI (pin_B15)

#define MICROPY_HW_SPI3_NSS  (pin_A15)
#define MICROPY_HW_SPI3_SCK  (pin_B3)
#define MICROPY_HW_SPI3_MISO (pin_B4)
#define MICROPY_HW_SPI3_MOSI (pin_B5)

#define MICROPY_HW_SPI4_NSS  (pin_B12)
#define MICROPY_HW_SPI4_SCK  (pin_B13)
#define MICROPY_HW_SPI4_MISO (pin_A11)
#define MICROPY_HW_SPI4_MOSI (pin_A1)

#define MICROPY_HW_SPI5_NSS  (pin_B1)
#define MICROPY_HW_SPI5_SCK  (pin_B0)
#define MICROPY_HW_SPI5_MISO (pin_A12)
#define MICROPY_HW_SPI5_MOSI (pin_B8)

// USRSW is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN        (pin_C13)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// LEDs
#define MICROPY_HW_LED1             (pin_A0) // R
#define MICROPY_HW_LED2             (pin_A1) // G
#define MICROPY_HW_LED3             (pin_A2) // B
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

// USB config
#define MICROPY_HW_USB_FS              (1)
