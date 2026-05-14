#include "stm32f4xx_hal.h"
#include "ili9341.h"
#include "fonts.h"

/* ─── remap lib's expectations to your hardware ─── */
#undef  ILI9341_SPI_PORT
#define ILI9341_SPI_PORT      hspi2

#undef  ILI9341_DC_Pin
#undef  ILI9341_DC_GPIO_Port
#define ILI9341_DC_Pin        GPIO_PIN_2
#define ILI9341_DC_GPIO_Port  GPIOA

#undef  ILI9341_RES_Pin
#undef  ILI9341_RES_GPIO_Port
#define ILI9341_RES_Pin       GPIO_PIN_5
#define ILI9341_RES_GPIO_Port GPIOA

/* BLK (backlight) */
#define BLK_ON()  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET)

/* ─── handles ─── */
SPI_HandleTypeDef hspi2;

/* ─── prototypes ─── */
void GPIO_Init(void);
void SPI2_Init(void);

/* ══════════════════════════════════════════════
   MAIN
   ══════════════════════════════════════════════ */
int main()
{
    HAL_Init();

    GPIO_Init();
    SPI2_Init();

    BLK_ON();

    /* lib requires CS to be deasserted before init
       (your CS is hardwired low, so just call Unselect
       to satisfy the lib's internal state) */
    ILI9341_Unselect();
   for(int i = 0; i < 10; i++) {
	   for(int i=0; i<=1000000; i++){}
	          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	         // HAL_Delay(3);
	          for(int i=0; i<=1000000; i++){}
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
       // HAL_Delay(3);

    }

    ILI9341_Init();

    /* ── clear screen ── */
    ILI9341_FillScreen(ILI9341_BLACK);

    /* ── draw some text ── */
    ILI9341_WriteString(10, 10,  "Hello World",     Font_16x26, ILI9341_WHITE,  ILI9341_BLACK);
    ILI9341_WriteString(10, 50,  "STM32 ILI9341",   Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
    ILI9341_WriteString(10, 80,  "SPI2 driver",     Font_7x10,  ILI9341_CYAN,   ILI9341_BLACK);

    /* ── draw a filled rectangle ── */
    ILI9341_FillRectangle(10, 110, 200, 40, ILI9341_RED);

    /* ── label inside the rectangle ── */
    ILI9341_WriteString(20, 120, "Rectangle", Font_11x18, ILI9341_WHITE, ILI9341_RED);

   /* __HAL_RCC_GPIOA_CLK_ENABLE();

        GPIO_InitTypeDef gpio = {0};
        gpio.Pin   = GPIO_PIN_5;
        gpio.Mode  = GPIO_MODE_OUTPUT_PP;
        gpio.Pull  = GPIO_NOPULL;
        gpio.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOA, &gpio);*/

        while(1) {
           //HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

            //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
        }

}

/* ══════════════════════════════════════════════
   GPIO
   ══════════════════════════════════════════════ */
void GPIO_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_InitTypeDef gpio = {0};

    /* PC2=MISO, PC3=MOSI — SPI2 AF */
    gpio.Pin       = GPIO_PIN_2 | GPIO_PIN_3;
    gpio.Mode      = GPIO_MODE_AF_PP;
    gpio.Pull      = GPIO_NOPULL;
    gpio.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    gpio.Alternate = GPIO_AF5_SPI2;
    HAL_GPIO_Init(GPIOC, &gpio);

    /* PB10=SCK — SPI2 AF */
    gpio.Pin       = GPIO_PIN_10;
    gpio.Alternate = GPIO_AF5_SPI2;
    HAL_GPIO_Init(GPIOB, &gpio);

    /* PA2=DC, PA5=RES, PA6=BLK — output */
    gpio.Pin       = GPIO_PIN_2 | GPIO_PIN_5 | GPIO_PIN_6;
    gpio.Mode      = GPIO_MODE_OUTPUT_PP;
    gpio.Pull      = GPIO_NOPULL;
    gpio.Speed     = GPIO_SPEED_FREQ_LOW;
    gpio.Alternate = 0;
    HAL_GPIO_Init(GPIOA, &gpio);
}

/* ══════════════════════════════════════════════
   SPI2
   ══════════════════════════════════════════════ */
void SPI2_Init(void)
{
    __HAL_RCC_SPI2_CLK_ENABLE();

    hspi2.Instance               = SPI2;
    hspi2.Init.Mode              = SPI_MODE_MASTER;
    hspi2.Init.Direction         = SPI_DIRECTION_2LINES;
    hspi2.Init.DataSize          = SPI_DATASIZE_8BIT;
    hspi2.Init.CLKPolarity       = SPI_POLARITY_LOW;
    hspi2.Init.CLKPhase          = SPI_PHASE_1EDGE;
    hspi2.Init.NSS               = SPI_NSS_SOFT;
    hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4; /* faster than /8 */
    hspi2.Init.FirstBit          = SPI_FIRSTBIT_MSB;
    hspi2.Init.TIMode            = SPI_TIMODE_DISABLE;
    hspi2.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;

    HAL_SPI_Init(&hspi2);
}

/* ══════════════════════════════════════════════
   SYSTICK
   ══════════════════════════════════════════════ */
void SysTick_Handler(void)
{
    HAL_IncTick();
}
