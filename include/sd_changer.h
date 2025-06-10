#pragma once

#include <stdint.h>
#include "driver/sdmmc_host.h"
#include "driver/gpio.h"
// GPIO Expander
#include "mcp23017.h"
#include "i2c_bus.h"


#define SD_SLOT_COUNT 8
#define SD_PORT_COUNT 2

#define SD_I2C_SCL GPIO_NUM_12
#define SD_I2C_SDA GPIO_NUM_13

#define SD_PORTA_INIT {     \
    .clk = GPIO_NUM_6,    \
    .cmd = GPIO_NUM_7,    \
    .d0 = GPIO_NUM_5,      \
    .d1 = GPIO_NUM_4,      \
    .d2 = GPIO_NUM_16,      \
    .d3 = GPIO_NUM_15,      \
    .cd = SDMMC_SLOT_NO_CD, \
    .wp = SDMMC_SLOT_NO_WP, \
    .width = 4,             \
    .flags = 0,             \
}

#define SD_PORTB_INIT {     \
    .clk = GPIO_NUM_42,    \
    .cmd = GPIO_NUM_41,    \
    .d0 = GPIO_NUM_2,      \
    .d1 = GPIO_NUM_1,      \
    .d2 = GPIO_NUM_39,      \
    .d3 = GPIO_NUM_40,      \
    .cd = SDMMC_SLOT_NO_CD, \
    .wp = SDMMC_SLOT_NO_WP, \
    .width = 4,             \
    .flags = 0,             \
}
#define SDCHNGR_DEFAULT() { \
    .selectedSlot = 0, \
    .detectedCards = 0, \
    .poweredSlots = 0, \
    .portConfigs = {SD_PORTA_INIT, SD_PORTB_INIT}, \
    .mcps = {NULL, NULL}, \
    .curentMcp = NULL, \
    .i2c = NULL, \
}

#ifdef __cplusplus
extern "C"
{
#endif

    /// @brief Struct containig GPIO pins definitions for SD changer port
    typedef struct sdchngr_port_config_s
    {
        /// @brief sdmmc pins
        gpio_num_t clk, cmd, d0, d1, d2, d3;
        /// @brief i2c pins
        gpio_num_t SDA, SCL;
    } sdchngr_port_config_t;

    /// @brief SD Changer handle variables struct
    typedef struct sdchngr_dev_s
    {
        uint8_t selectedSlot;
        uint8_t detectedCards;
        uint8_t poweredSlots;
        sdmmc_slot_config_t portConfigs[2];
        mcp23017_handle_t mcps[2];
        mcp23017_handle_t* curentMcp;
        i2c_bus_handle_t i2c;
    } sdchngr_dev_t;

    typedef sdchngr_dev_t* sdchngr_handle_t;

    /**
     * @brief Creates and initialize SD Changer handle
     * Initializes changer structure and i2c handles 
     * @return
     *      - SD Changer handle on success
     *      - null if error occured
     */
    sdchngr_handle_t sdchngr_create();

    /**
     * @brief Select SD card to be connected to the sdmmc host
     *
     * SD must be detected by handle to be selected
     * @param handle [IN] sdchanger config struct
     * @param slot [IN] SD card slot [0-7]
     * @param slot_config [OUT] sdmmc slot config
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_NOT_FOUND if SD card is not detected
     *      - ESP_ERR_INVALID_ARG if handle is null or if slot > SD_SLOT_COUNT
     */
    esp_err_t sdchngr_set_selected(sdchngr_handle_t handle, uint8_t slot, sdmmc_slot_config_t *slot_config);

    /**
     * @brief Turn SD card on/off
     * SD must be detected by handle to be powered
     *
     * @param handle [IN] configuration
     * @param slot [IN] SD card slot [0-7]
     * @param power [IN] 0-OFF 1-ON
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_NOT_FOUND if SD card is not detected
     *      - ESP_ERR_INVALID_ARG if handle is null or if slot > SD_SLOT_COUNT
     */
    esp_err_t sdchngr_set_power(sdchngr_handle_t handle, uint8_t slot, uint8_t power);

    /**
     * @brief Gets number of selected slot
     *
     * @param handle [IN] configuration
     * @param slot [OUT] number of selected slot
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_NOT_FOUND if SD card is not detected
     *      - ESP_ERR_INVALID_ARG if handle is null or if slot > SD_SLOT_COUNT
     */
    esp_err_t sdchngr_get_selected(sdchngr_handle_t handle, uint8_t* slot);

    /**
     * @brief Get bitmask of detected cards
     *
     * @param handle [IN] configuration
     * @param nDetected [OUT] number of detected cards
     * @param slots [OUT] bitmask of slots with detected cards
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_INVALID_ARG if input params are null
     */
    esp_err_t sdchngr_get_detected(sdchngr_handle_t handle, uint8_t *nDetected, uint8_t *slots);

    /**
     * @brief Get bitmask of powered cards
     *
     * @param handle [IN] configuration
     * @param nPowered [OUT] number of powered cards
     * @param slots [IN] bitmask of slots with powered cards
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_INVALID_ARG if input params are null
     */
    esp_err_t sdchngr_get_powered(sdchngr_handle_t handle, uint8_t *nPowered, uint8_t *slots);

    /**
     * @brief
     *
     * @param handle [IN] configuration
     * @param slot [IN] sd card slot
     * @param selected [OUT] selected state (0-OFF, 1-SELECTED)
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_INVALID_ARG if input params are null
     */
    esp_err_t sdchngr_is_selected(sdchngr_handle_t handle, uint8_t slot, uint8_t* selected);

    /**
     * @brief
     *
     * @param handle [IN] configuration
     * @param slot [IN] sd card slot
     * @param selected [OUT] power state (0-OFF, 1-ON)
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_INVALID_ARG if input params are null
     */
    esp_err_t sdchngr_is_powered(sdchngr_handle_t handle, uint8_t slot, uint8_t* powered);

    /**
     * @brief
     *
     * @param handle [IN] configuration
     * @param slot [IN] sd card slot
     * @param detected [OUT] detected state (0-OFF, 1-DETECTED)
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_INVALID_ARG if input params are null
     */
    esp_err_t sdchngr_is_detected(sdchngr_handle_t handle, uint8_t slot, uint8_t* detected);
    
    /**
     * @brief Function to get correct sdmmc slot config based on slot number
     * 
     * @param handle [IN] configuration
     * @param slot [IN] slot number
     * @param slot_config [OUT] sdmmc slot configuration for SD card slot
     * 
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_INVALID_ARG if handle or config is null  
     */
    esp_err_t sdchngr_set_port(sdchngr_handle_t handle, uint8_t slot, sdmmc_slot_config_t *slot_config);
    
    /**
     * @brief Function to set current mcp in handle based on slot number
     * 
     * @param handle [IN] configuration
     * @param slot [IN] slot number
     * 
     * @return
     *      - ESP_OK on success
     *      - ESP_ERR_INVALID_ARG if handle is null
     */
    esp_err_t sdchngr_set_mcp(sdchngr_handle_t handle, uint8_t slot);

#ifdef __cplusplus
}
#endif