| Supported Targets | ESP32-S3 |
| ----------------- | -------- |


## SD Changer code example

This code demonstrates a use of SD-Changer library on 8-slot ESP32S3 SD-Changer device. 
The device is expected to be connected via serial port to allow this example work.

The SD-Changer specific code looks as follows:

```c
esp_sdchngr_dev_t changer = SDCHNGR_DEFAULT();
ESP_ERROR_CHECK(esp_sdchngr_init(&changer));
ESP_ERROR_CHECK(esp_sdchngr_set_power(changer, SLOT, 1));
ESP_ERROR_CHECK(esp_sdchngr_set_selected(changer, SLOT, &slot_config));
...
// process your application
...
```

To run the example code:

1. set proper IDF environment - for instance, run the following scripts in your SD changer working directory:
```
<ESP-IDF-INSTALL-PATH>/install.sh
. <ESP-IDF-INSTALL-PATH>/export.sh>
```

2. navigate to the example directory, set ESP32S3 target and build the example code. Flash the binary into the device as the last step
```
cd example
idf.py set-target esp32s3
idf.py build
idf.py flash monitor
```

The console output should be similar to the following depending on SD card slots used:
```bash
I (293) main_task: Calling app_main()
I (293) example: Initializing SD card
I (293) example: Using SDMMC peripheral
I (293) sdchngr: Initializing SD changer

W (293) i2c.master: Please check pull-up resistances whether be connected properly. Otherwise unexpected behavior would happen. For more detailed information, please read docs
I (313) i2c_bus: i2c0 bus inited
I (313) i2c_bus: I2C Bus V2 Config Succeed, Version: 1.1.0
I (323) sdchngr: I2C speed 100000
I (323) sdchngr: Initialized

I (323) example: [SLOT 0]
W (333) example: [SLOT 0] Card not inserted!
I (333) example: [SLOT 1]
I (343) example: Mounting filesystem
I (343) gpio: GPIO[6]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (343) gpio: GPIO[7]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (353) gpio: GPIO[5]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (363) gpio: GPIO[4]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (373) gpio: GPIO[16]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (383) gpio: GPIO[15]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
I (623) gpio: GPIO[15]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (623) example: Filesystem mounted
Name: SL32G
Type: SDHC
Speed: 40.00 MHz (limit: 40.00 MHz)
Size: 30436MB
CSD: ver=2, sector_size=512, capacity=62333952 read_bl_len=9
SSR: bus_width=4
I (633) example: Opening file /sdcard/hello.txt
I (653) example: File written
I (663) example: Renaming file /sdcard/hello.txt to /sdcard/foo.txt
I (673) example: Reading file /sdcard/foo.txt
I (673) example: Read from file: 'Hello SL32G!'
I (673) example: Opening file /sdcard/nihao.txt
I (703) example: File written
I (703) example: Reading file /sdcard/nihao.txt
I (703) example: Read from file: 'Nihao SL32G!'
I (703) gpio: GPIO[6]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (713) gpio: GPIO[7]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (713) gpio: GPIO[5]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (723) gpio: GPIO[4]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (733) gpio: GPIO[16]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (743) gpio: GPIO[15]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (753) gpio: GPIO[0]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (763) gpio: GPIO[0]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (763) gpio: GPIO[0]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (773) gpio: GPIO[0]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (783) example: Card unmounted
I (783) example: [SLOT 2]
W (793) example: [SLOT 2] Card not inserted!
I (793) example: [SLOT 3]
W (793) example: [SLOT 3] Card not inserted!
I (803) example: [SLOT 4]
W (803) example: [SLOT 4] Card not inserted!
I (803) example: [SLOT 5]
W (813) example: [SLOT 5] Card not inserted!
I (813) example: [SLOT 6]
I (813) example: Mounting filesystem
I (813) gpio: GPIO[42]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (823) gpio: GPIO[41]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (833) gpio: GPIO[2]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (843) gpio: GPIO[1]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (853) gpio: GPIO[39]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (863) gpio: GPIO[40]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
I (1023) gpio: GPIO[40]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1033) example: Filesystem mounted
Name: SD32G
Type: SDHC
Speed: 40.00 MHz (limit: 40.00 MHz)
Size: 29664MB
CSD: ver=2, sector_size=512, capacity=60751872 read_bl_len=9
SSR: bus_width=4
I (1043) example: Opening file /sdcard/hello.txt
I (1063) example: File written
I (1073) example: Renaming file /sdcard/hello.txt to /sdcard/foo.txt
I (1073) example: Reading file /sdcard/foo.txt
I (1073) example: Read from file: 'Hello SD32G!'
I (1073) example: Opening file /sdcard/nihao.txt
I (1093) example: File written
I (1093) example: Reading file /sdcard/nihao.txt
I (1093) example: Read from file: 'Nihao SD32G!'
I (1093) gpio: GPIO[42]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1103) gpio: GPIO[41]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1103) gpio: GPIO[2]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1113) gpio: GPIO[1]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1123) gpio: GPIO[39]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1133) gpio: GPIO[40]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1143) gpio: GPIO[0]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1153) gpio: GPIO[0]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1153) gpio: GPIO[0]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1163) gpio: GPIO[0]| InputEn: 0| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (1173) example: Card unmounted
I (1173) example: [SLOT 7]
W (1183) example: [SLOT 7] Card not inserted!
I (1183) example: Detected count 2 mask 42
I (1183) example: Powered count 2 mask 00
I (1193) example: Last selected slot 6
I (1193) main_task: Returned from app_main()
```