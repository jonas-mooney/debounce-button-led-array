#include "max7219.h"
#include "main.h"

/* Send a 16-bit address/data pair over SPI */
void MAX7219_Write(uint8_t address, uint8_t data) {
    uint8_t packet[2] = {address, data};
    
    // Pull CS low to begin frame
    HAL_GPIO_WritePin(MAX7219_CS_GPIO_Port, MAX7219_CS_Pin, GPIO_PIN_RESET);
    
    // Transmit 2 bytes over SPI1
    HAL_SPI_Transmit(&hspi1, packet, 2, HAL_MAX_DELAY);
    
    // Pull CS hig to latch data into MAX7219
    HAL_GPIO_WritePin(MAX7219_CS_GPIO_Port, MAX7219_CS_Pin, GPIO_PIN_SET);
}