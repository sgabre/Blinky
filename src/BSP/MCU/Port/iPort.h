/*
  PDD layer implementation for peripheral type PORT
  (C) 2013 Freescale, Inc. All rights reserved.

  This file is static and it is generated from API-Factory
*/

#if !defined(iPORT_H_)
#define iPORT_H_

/* ----------------------------------------------------------------------------
   -- Test if supported MCU is active
   ---------------------------------------------------------------------------- */

#if !defined(MCU_ACTIVE)
  // No MCU is active
  #error PORT PDD library: No derivative is active. Place proper #include with PDD memory map before including PDD library.
#elif \
      !defined(MCU_MK10D10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK10D5) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK10D7) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK10F12) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK10DZ10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK11D5) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK11D5WS) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK12D5) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK20D10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK20D5) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK20D7) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK20F12) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK20DZ10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK21D5) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK21D5WS) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK21F12) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK21F12WS) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK22D5) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK22F12810) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK22F12) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK22F25612) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK22F51212) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK24F12) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK30D10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK30D7) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK30DZ10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK40D10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK40D7) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK40DZ10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK40X256VMD100) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK50D10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK50D7) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK50DZ10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK51D10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK51D7) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK51DZ10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK52D10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK52DZ10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK53D10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK53DZ10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK60D10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK60F12) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK60F15) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK60DZ10) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK60N512VMD100) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK61F12) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK61F15) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK61F12WS) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK61F15WS) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK63F12) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK63F12WS) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK64F12) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK65F18) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK65F18WS) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK66F18) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MK70F12) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK70F15) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK70F12WS) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MK70F15WS) /* PORTA, PORTB, PORTC, PORTD, PORTE, PORTF */ && \
      !defined(MCU_MKE02Z2) /* PORT */ && \
      !defined(MCU_MKE02Z4) /* PORT */ && \
      !defined(MCU_SKEAZN642) /* PORT */ && \
      !defined(MCU_MKE04Z1284) /* PORT */ && \
      !defined(MCU_MKE04Z4) /* PORT */ && \
      !defined(MCU_SKEAZN84) /* PORT */ && \
      !defined(MCU_MKE06Z4) /* PORT */ && \
      !defined(MCU_MKL02Z4) /* PORTA, PORTB */ && \
      !defined(MCU_MKL03Z4) /* PORTA, PORTB */ && \
      !defined(MCU_MKL04Z4) /* PORTA, PORTB */ && \
      !defined(MCU_MKL05Z4) /* PORTA, PORTB */ && \
      !defined(MCU_MKL14Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKL15Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKL16Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKL24Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKL25Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKL26Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKL34Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKL36Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKL46Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKV10Z7) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKV31F12810) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKV31F25612) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKV31F51212) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKW01Z4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKW21D5) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKW21D5WS) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKW22D5) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKW22D5WS) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKW24D5) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_MKW24D5WS) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_PCK20L4) /* PORTA, PORTB, PORTC, PORTD, PORTE */ && \
      !defined(MCU_SKEAZ1284) /* PORT */
  // Unsupported MCU is active
  #error PORT PDD library: Unsupported derivative is active.
#endif

#include "BSP/MCU/iTypes.h"

/* ----------------------------------------------------------------------------
   -- Method symbol definitions
   ---------------------------------------------------------------------------- */

/* Pin masks */
#define iPORT_PIN_0  0x1U                     /**< Pin 0 mask */
#define iPORT_PIN_1  0x2U                     /**< Pin 1 mask */
#define iPORT_PIN_2  0x4U                     /**< Pin 2 mask */
#define iPORT_PIN_3  0x8U                     /**< Pin 3 mask */
#define iPORT_PIN_4  0x10U                    /**< Pin 4 mask */
#define iPORT_PIN_5  0x20U                    /**< Pin 5 mask */
#define iPORT_PIN_6  0x40U                    /**< Pin 6 mask */
#define iPORT_PIN_7  0x80U                    /**< Pin 7 mask */
#define iPORT_PIN_8  0x100U                   /**< Pin 8 mask */
#define iPORT_PIN_9  0x200U                   /**< Pin 9 mask */
#define iPORT_PIN_10 0x400U                   /**< Pin 10 mask */
#define iPORT_PIN_11 0x800U                   /**< Pin 11 mask */
#define iPORT_PIN_12 0x1000U                  /**< Pin 12 mask */
#define iPORT_PIN_13 0x2000U                  /**< Pin 13 mask */
#define iPORT_PIN_14 0x4000U                  /**< Pin 14 mask */
#define iPORT_PIN_15 0x8000U                  /**< Pin 15 mask */
#define iPORT_PIN_16 0x10000U                 /**< Pin 16 mask */
#define iPORT_PIN_17 0x20000U                 /**< Pin 17 mask */
#define iPORT_PIN_18 0x40000U                 /**< Pin 18 mask */
#define iPORT_PIN_19 0x80000U                 /**< Pin 19 mask */
#define iPORT_PIN_20 0x100000U                /**< Pin 20 mask */
#define iPORT_PIN_21 0x200000U                /**< Pin 21 mask */
#define iPORT_PIN_22 0x400000U                /**< Pin 22 mask */
#define iPORT_PIN_23 0x800000U                /**< Pin 23 mask */
#define iPORT_PIN_24 0x1000000U               /**< Pin 24 mask */
#define iPORT_PIN_25 0x2000000U               /**< Pin 25 mask */
#define iPORT_PIN_26 0x4000000U               /**< Pin 26 mask */
#define iPORT_PIN_27 0x8000000U               /**< Pin 27 mask */
#define iPORT_PIN_28 0x10000000U              /**< Pin 28 mask */
#define iPORT_PIN_29 0x20000000U              /**< Pin 29 mask */
#define iPORT_PIN_30 0x40000000U              /**< Pin 30 mask */
#define iPORT_PIN_31 0x80000000U              /**< Pin 31 mask */

#if ((defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN84)))
/* List of pins offering high drive capability */
  #define iPORT_PTB5 0x2U                       /**< PTB5 mask */
  #define iPORT_PTC1 0x4U                       /**< PTC1 mask */
  #define iPORT_PTC5 0x8U                       /**< PTC5 mask */

#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) || (defined(MCU_SKEAZN642)) */
/* List of pins offering high drive capability */
  #define iPORT_PTB4 0x1U                       /**< PTB4 mask */
  #define iPORT_PTB5 0x2U                       /**< PTB5 mask */
  #define iPORT_PTD0 0x4U                       /**< PTD0 mask */
  #define iPORT_PTD1 0x8U                       /**< PTD1 mask */
  #define iPORT_PTE0 0x10U                      /**< PTE0 mask */
  #define iPORT_PTE1 0x20U                      /**< PTE1 mask */
  #define iPORT_PTH0 0x40U                      /**< PTH0 mask */
  #define iPORT_PTH1 0x80U                      /**< PTH1 mask */

#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) || (defined(MCU_SKEAZN642)) */
/* Filter selection */
#define iPORT_NO_FILTER 0U                    /**< No filter */
#define iPORT_BUSCLK    0U                    /**< BUSCLK */
#define iPORT_FLTDIV1   0x1U                  /**< FLTDIV1 */
#define iPORT_FLTDIV2   0x2U                  /**< FLTDIV2 */
#define iPORT_FLTDIV3   0x3U                  /**< FLTDIV3 */

#if ((defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN84)))
/* Modules offering input pin filtering capability */
  #define iPORT_PTA  0U                         /**< Selects filter for input from PTA */
  #define iPORT_PTB  0x2U                       /**< Selects filter for input from PTB */
  #define iPORT_PTC  0x4U                       /**< Selects filter for input from PTC */
  #define iPORT_RST  0x10U                      /**< Selects filter for input from RST */
  #define iPORT_KBI0 0x12U                      /**< Selects filter for input from KBI0 */
  #define iPORT_KBI1 0x14U                      /**< Selects filter for input from KBI1 */
  #define iPORT_NMI  0x16U                      /**< Selects filter for input from NMI */
  #define iPORT_IIC  0xAU                       /**< Selects filter for input from IIC */
  #define iPORT_FTM0 0xCU                       /**< Selects filter for input from FTM0 */
  #define iPORT_PWT  0xEU                       /**< Selects filter for input from PWT */

#elif ((defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_SKEAZN642)))
/* Modules offering input pin filtering capability */
  #define iPORT_PTA  0U                         /**< Selects filter for input from PTA */
  #define iPORT_PTB  0x2U                       /**< Selects filter for input from PTB */
  #define iPORT_PTC  0x4U                       /**< Selects filter for input from PTC */
  #define iPORT_PTD  0x6U                       /**< Selects filter for input from PTD */
  #define iPORT_PTE  0x8U                       /**< Selects filter for input from PTE */
  #define iPORT_PTF  0xAU                       /**< Selects filter for input from PTF */
  #define iPORT_PTG  0xCU                       /**< Selects filter for input from PTG */
  #define iPORT_PTH  0xEU                       /**< Selects filter for input from PTH */
  #define iPORT_RST  0x10U                      /**< Selects filter for input from RST */
  #define iPORT_KBI0 0x12U                      /**< Selects filter for input from KBI0 */
  #define iPORT_KBI1 0x14U                      /**< Selects filter for input from KBI1 */
  #define iPORT_NMI  0x16U                      /**< Selects filter for input from NMI */

#else /* (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) */
/* Modules offering input pin filtering capability */
  #define iPORT_PTA  0U                         /**< Selects filter for input from PTA */
  #define iPORT_PTB  0x2U                       /**< Selects filter for input from PTB */
  #define iPORT_PTC  0x4U                       /**< Selects filter for input from PTC */
  #define iPORT_PTD  0x6U                       /**< Selects filter for input from PTD */
  #define iPORT_PTE  0x8U                       /**< Selects filter for input from PTE */
  #define iPORT_PTF  0xAU                       /**< Selects filter for input from PTF */
  #define iPORT_PTG  0xCU                       /**< Selects filter for input from PTG */
  #define iPORT_PTH  0xEU                       /**< Selects filter for input from PTH */
  #define iPORT_RST  0x10U                      /**< Selects filter for input from RST */
  #define iPORT_KBI0 0x12U                      /**< Selects filter for input from KBI0 */
  #define iPORT_KBI1 0x14U                      /**< Selects filter for input from KBI1 */
  #define iPORT_NMI  0x16U                      /**< Selects filter for input from NMI */
  #define iPORT_PTI  0U                         /**< Selects filter for input from PTI */
  #define iPORT_IRQ  0x4U                       /**< Selects filter for input from IRQ */
  #define iPORT_FTM0 0x6U                       /**< Selects filter for input from FTM0 */
  #define iPORT_FTM1 0x8U                       /**< Selects filter for input from FTM1 */
  #define iPORT_PWT  0xAU                       /**< Selects filter for input from PWT */
  #define iPORT_I2C0 0xCU                       /**< Selects filter for input from I2C0 */
  #define iPORT_I2C1 0xEU                       /**< Selects filter for input from I2C1 */

#endif /* (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) */
/* Constants for pull type selection */
#define iPORT_PULL_DOWN 0U                    /**< Pull down */
#define iPORT_PULL_UP   0x1U                  /**< Pull up */

/* Constants for pull enabling/disabling */
#define iPORT_PULL_DISABLE 0U                 /**< Pull resistor disabled */
#define iPORT_PULL_ENABLE  0x2U               /**< Pull resistor enabled */

/* Constants for slew rate setting */
#define iPORT_SLEW_RATE_FAST 0U               /**< Fast slew rate */
#define iPORT_SLEW_RATE_SLOW 0x4U             /**< Slow slew rate */

/* Constants for slew rate setting */
#define iPORT_PASSIVE_FILTER_DISABLE 0U       /**< Passive filter disabled */
#define iPORT_PASSIVE_FILTER_ENABLE  0x10U    /**< Passive filter enabled */

/* Constants for open drain setting */
#define iPORT_OPEN_DRAIN_DISABLE 0U           /**< Open drain disabled */
#define iPORT_OPEN_DRAIN_ENABLE  0x20U        /**< Open drain enabled */

/* Constants for drive strength setting */
#define iPORT_DRIVE_STRENGTH_LOW  0U          /**< Low drive strength */
#define iPORT_DRIVE_STRENGTH_HIGH 0x40U       /**< High drive strength */

/* Constants for mux control setting */
#define iPORT_MUX_CONTROL_DISABLE 0U          /**< Mux control disabled */
#define iPORT_MUX_CONTROL_ALT1    0x100U      /**< Pin used with alternate 1 functionality */
#define iPORT_MUX_CONTROL_ALT2    0x200U      /**< Pin used with alternate 2 functionality */
#define iPORT_MUX_CONTROL_ALT3    0x300U      /**< Pin used with alternate 3 functionality */
#define iPORT_MUX_CONTROL_ALT4    0x400U      /**< Pin used with alternate 4 functionality */
#define iPORT_MUX_CONTROL_ALT5    0x500U      /**< Pin used with alternate 5 functionality */
#define iPORT_MUX_CONTROL_ALT6    0x600U      /**< Pin used with alternate 6 functionality */
#define iPORT_MUX_CONTROL_ALT7    0x700U      /**< Pin used with alternate 7 functionality */

/* Constants for pin lock setting */
#define iPORT_PIN_CONTROL_UNLOCK 0U           /**< Pin control unlocked */
#define iPORT_PIN_CONTROL_LOCK   0x8000U      /**< Pin control locked */

/* Constants for interrupt configuration setting */
#define iPORT_INTERRUPT_DMA_DISABLED      0U  /**< Interrupt and DMA disabled */
#define iPORT_DMA_ON_RISING               0x10000U /**< DMA enabled on rising edge */
#define iPORT_DMA_ON_FALLING              0x20000U /**< DMA enabled on falling edge */
#define iPORT_DMA_ON_RISING_FALLING       0x30000U /**< DMA enabled on rising and falling edges */
#define iPORT_INTERRUPT_ON_ZERO           0x80000U /**< Interrupt enabled on low level */
#define iPORT_INTERRUPT_ON_RISING         0x90000U /**< Interrupt enabled on rising edge */
#define iPORT_INTERRUPT_ON_FALLING        0xA0000U /**< Interrupt enabled on falling edge */
#define iPORT_INTERRUPT_ON_RISING_FALLING 0xB0000U /**< Interrupt enabled on rising and falling edges */
#define iPORT_INTERRUPT_ON_ONE            0xC0000U /**< Interrupt enabled on high level */

/* Constants for digital clock source setting */
#define iPORT_BUS_CLOCK 0U                    /**< Bus clock as filter clock source */
#define iPORT_LPO_CLOCK 0x1U                  /**< LPO clock as filter clock source */

/* Constants for Filter Division Set 1 */
#define iPORT_BUSCLK_DIV_2  0U                /**< BUSCLK/2 */
#define iPORT_BUSCLK_DIV_4  0x1000000U        /**< BUSCLK/4 */
#define iPORT_BUSCLK_DIV_8  0x2000000U        /**< BUSCLK/8 */
#define iPORT_BUSCLK_DIV_16 0x3000000U        /**< BUSCLK/16 */

/* Constants for Filter Division Set 2 */
#define iPORT_BUSCLK_DIV_32   0U              /**< BUSCLK/32 */
#define iPORT_BUSCLK_DIV_64   0x4000000U      /**< BUSCLK/64 */
#define iPORT_BUSCLK_DIV_128  0x8000000U      /**< BUSCLK/128 */
#define iPORT_BUSCLK_DIV_256  0xC000000U      /**< BUSCLK/256 */
#define iPORT_BUSCLK_DIV_512  0x10000000U     /**< BUSCLK/512 */
#define iPORT_BUSCLK_DIV_1024 0x14000000U     /**< BUSCLK/1024 */
#define iPORT_BUSCLK_DIV_2048 0x18000000U     /**< BUSCLK/2048 */
#define iPORT_BUSCLK_DIV_4096 0x1C000000U     /**< BUSCLK/4096 */

/* Constants for Filter Division Set 3 */
#define iPORT_LPOCLK         0U               /**< LPOCLK */
#define iPORT_LPOCLK_DIV_2   0x20000000U      /**< LPOCLK/2 */
#define iPORT_LPOCLK_DIV_4   0x40000000U      /**< LPOCLK/4 */
#define iPORT_LPOCLK_DIV_8   0x60000000U      /**< LPOCLK/8 */
#define iPORT_LPOCLK_DIV_16  0x80000000U      /**< LPOCLK/16 */
#define iPORT_LPOCLK_DIV_32  0xA0000000U      /**< LPOCLK/32 */
#define iPORT_LPOCLK_DIV_64  0xC0000000U      /**< LPOCLK/64 */
#define iPORT_LPOCLK_DIV_128 0xE0000000U      /**< LPOCLK/128 */


/* ----------------------------------------------------------------------------
   -- GetPinPullSelect
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets which pull resistor is selected.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of "Constants for pull type selection" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetPinPullSelect(<peripheral>_BASE_PTR,
 *      periphID);
 *      @endcode
 */
#define iPort_GetPinPullSelect(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_PS_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- SetPinPullSelect
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets pull type.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @param Type Pull type. This parameter is of "Constants for pull type
 *        selection" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPort_SetPinPullSelect(<peripheral>_BASE_PTR, periphID,
 *      iPORT_PULL_DOWN);
 *      @endcode
 */
#define iPort_SetPinPullSelect(PeripheralBase, PinIndex, Type) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_PCR_REG(PeripheralBase,(PinIndex))) & (( \
       (uint32_t)(~(uint32_t)PORT_PCR_PS_MASK)) & ( \
       (uint32_t)(~(uint32_t)PORT_PCR_ISF_MASK))))) | ( \
      (uint32_t)(Type))) \
  )

/* ----------------------------------------------------------------------------
   -- GetPinPullEnable
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets whether pull resistor is enabled.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of "Constants for pull enabling/disabling" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetPinPullEnable(<peripheral>_BASE_PTR,
 *      periphID);
 *      @endcode
 */
#define iPort_GetPinPullEnable(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_PE_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- SetPinPullEnable
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets pull type.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @param State Requested state of pull enable. This parameter is of "Constants
 *        for pull enabling/disabling" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPort_SetPinPullEnable(<peripheral>_BASE_PTR, periphID,
 *      iPORT_PULL_DISABLE);
 *      @endcode
 */
#define iPort_SetPinPullEnable(PeripheralBase, PinIndex, State) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_PCR_REG(PeripheralBase,(PinIndex))) & (( \
       (uint32_t)(~(uint32_t)PORT_PCR_PE_MASK)) & ( \
       (uint32_t)(~(uint32_t)PORT_PCR_ISF_MASK))))) | ( \
      (uint32_t)(State))) \
  )

/* ----------------------------------------------------------------------------
   -- GetPinSlewRate
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets how slew rate is set.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of "Constants for slew rate setting" type. The value
 *         is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetPinSlewRate(<peripheral>_BASE_PTR,
 *      periphID);
 *      @endcode
 */
#define iPort_GetPinSlewRate(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_SRE_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- SetPinSlewRate
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets slew rate.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @param State Requested state of slew rate. This parameter is of "Constants
 *        for slew rate setting" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPort_SetPinSlewRate(<peripheral>_BASE_PTR, periphID,
 *      iPORT_SLEW_RATE_FAST);
 *      @endcode
 */
#define iPort_SetPinSlewRate(PeripheralBase, PinIndex, State) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_PCR_REG(PeripheralBase,(PinIndex))) & (( \
       (uint32_t)(~(uint32_t)PORT_PCR_SRE_MASK)) & ( \
       (uint32_t)(~(uint32_t)PORT_PCR_ISF_MASK))))) | ( \
      (uint32_t)(State))) \
  )

/* ----------------------------------------------------------------------------
   -- GetPinPassiveFilter
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets whether passive filter is enabled.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of "Constants for slew rate setting" type. The value
 *         is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetPinPassiveFilter(<peripheral>_BASE_PTR,
 *      periphID);
 *      @endcode
 */
#define iPort_GetPinPassiveFilter(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_PFE_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- SetPinPassiveFilter
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets passive filter.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @param State Requested state of passive filter. This parameter is of
 *        "Constants for slew rate setting" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPort_SetPinPassiveFilter(<peripheral>_BASE_PTR, periphID,
 *      iPORT_PASSIVE_FILTER_DISABLE);
 *      @endcode
 */
#define iPort_SetPinPassiveFilter(PeripheralBase, PinIndex, State) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_PCR_REG(PeripheralBase,(PinIndex))) & (( \
       (uint32_t)(~(uint32_t)PORT_PCR_PFE_MASK)) & ( \
       (uint32_t)(~(uint32_t)PORT_PCR_ISF_MASK))))) | ( \
      (uint32_t)(State))) \
  )

/* ----------------------------------------------------------------------------
   -- GetPinOpenDrain
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets whether open drain is enabled.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of "Constants for open drain setting" type. The value
 *         is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetPinOpenDrain(<peripheral>_BASE_PTR,
 *      periphID);
 *      @endcode
 */
#define iPort_GetPinOpenDrain(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_ODE_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- SetPinOpenDrain
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets open drain.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @param State Requested state of open drain. This parameter is of "Constants
 *        for open drain setting" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPort_SetPinOpenDrain(<peripheral>_BASE_PTR, periphID,
 *      iPORT_OPEN_DRAIN_DISABLE);
 *      @endcode
 */
#define iPort_SetPinOpenDrain(PeripheralBase, PinIndex, State) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_PCR_REG(PeripheralBase,(PinIndex))) & (( \
       (uint32_t)(~(uint32_t)PORT_PCR_ODE_MASK)) & ( \
       (uint32_t)(~(uint32_t)PORT_PCR_ISF_MASK))))) | ( \
      (uint32_t)(State))) \
  )

/* ----------------------------------------------------------------------------
   -- GetPinDriverStrength
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets how drive strength is set.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of "Constants for drive strength setting" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetPinDriverStrength(<peripheral>_BASE_PTR,
 *      periphID);
 *      @endcode
 */
#define iPort_GetPinDriverStrength(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_DSE_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- SetPinDriveStrength
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets drive strength.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @param State Requested state of drive strength. This parameter is of
 *        "Constants for drive strength setting" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPort_SetPinDriveStrength(<peripheral>_BASE_PTR, periphID,
 *      iPORT_DRIVE_STRENGTH_LOW);
 *      @endcode
 */
#define iPort_SetPinDriveStrength(PeripheralBase, PinIndex, State) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_PCR_REG(PeripheralBase,(PinIndex))) & (( \
       (uint32_t)(~(uint32_t)PORT_PCR_DSE_MASK)) & ( \
       (uint32_t)(~(uint32_t)PORT_PCR_ISF_MASK))))) | ( \
      (uint32_t)(State))) \
  )

/* ----------------------------------------------------------------------------
   -- GetPinMuxControl
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets how mux control is set.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of "Constants for mux control setting" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetPinMuxControl(<peripheral>_BASE_PTR,
 *      periphID);
 *      @endcode
 */
#define iPort_GetPinMuxControl(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_MUX_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- SetPinMuxControl
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets mux control.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @param State Requested state of Mux control. This parameter is of "Constants
 *        for mux control setting" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPort_SetPinMuxControl(<peripheral>_BASE_PTR, periphID,
 *      iPORT_MUX_CONTROL_DISABLE);
 *      @endcode
 */
#define iPort_SetPinMuxControl(PeripheralBase, PinIndex, State) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_PCR_REG(PeripheralBase,(PinIndex))) & (( \
       (uint32_t)(~(uint32_t)PORT_PCR_MUX_MASK)) & ( \
       (uint32_t)(~(uint32_t)PORT_PCR_ISF_MASK))))) | ( \
      (uint32_t)(State))) \
  )

/* ----------------------------------------------------------------------------
   -- GetPinControlLock
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets how pin lock is set.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of "Constants for pin lock setting" type. The value
 *         is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetPinControlLock(<peripheral>_BASE_PTR,
 *      periphID);
 *      @endcode
 */
#define iPort_GetPinControlLock(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_LK_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- LockPinControl
   ---------------------------------------------------------------------------- */

/**
 * @brief Locks pin control such as settings of pull, slew rate, passive filter,
 * open drain, mux control and pin lock.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @param State Requested state of pin lock. This parameter is of "Constants for
 *        pin lock setting" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPORT_LockPinControl(<peripheral>_BASE_PTR, periphID,
 *      iPORT_PIN_CONTROL_UNLOCK);
 *      @endcode
 */
#define iPort_LockPinControl(PeripheralBase, PinIndex, State) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_PCR_REG(PeripheralBase,(PinIndex))) & (( \
       (uint32_t)(~(uint32_t)PORT_PCR_LK_MASK)) & ( \
       (uint32_t)(~(uint32_t)PORT_PCR_ISF_MASK))))) | ( \
      (uint32_t)(State))) \
  )

/* ----------------------------------------------------------------------------
   -- GetPinInterruptConfiguration
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets how interupt configuration is set.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of "Constants for interrupt configuration setting"
 *         type. The value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result =
 *      iPort_GetPinInterruptConfiguration(<peripheral>_BASE_PTR, periphID);
 *      @endcode
 */
#define iPort_GetPinInterruptConfiguration(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_IRQC_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- SetPinInterruptConfiguration
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets interrupt configuration.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @param State Requested state of interrupt configuration. This parameter is of
 *        "Constants for interrupt configuration setting" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPort_SetPinInterruptConfiguration(<peripheral>_BASE_PTR, periphID,
 *      iPORT_INTERRUPT_DMA_DISABLED);
 *      @endcode
 */
#define iPort_SetPinInterruptConfiguration(PeripheralBase, PinIndex, State) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_PCR_REG(PeripheralBase,(PinIndex))) & (( \
       (uint32_t)(~(uint32_t)PORT_PCR_IRQC_MASK)) & ( \
       (uint32_t)(~(uint32_t)PORT_PCR_ISF_MASK))))) | ( \
      (uint32_t)(State))) \
  )

/* ----------------------------------------------------------------------------
   -- GetPinInterruptFlag
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns interrupt flags.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetPinInterruptFlag(<peripheral>_BASE_PTR,
 *      periphID);
 *      @endcode
 */
#define iPort_GetPinInterruptFlag(PeripheralBase, PinIndex) ( \
    (uint32_t)(PORT_PCR_REG(PeripheralBase,(PinIndex)) & PORT_PCR_ISF_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- GetInterruptFlags
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns interrupt flags.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORTA_ISFR, PORTB_ISFR,
 *          PORTC_ISFR, PORTD_ISFR, PORTE_ISFR, PORTF_ISFR (depending on the
 *          peripheral).
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetInterruptFlags(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define iPort_GetInterruptFlags(PeripheralBase) ( \
    PORT_ISFR_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- ClearPinInterruptFlag
   ---------------------------------------------------------------------------- */

/**
 * @brief Clears interrupt flag.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PinIndex Pin index inside the port. This parameter is of index type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PCR[PinIndex].
 * @par Example:
 *      @code
 *      iPORT_ClearPinInterruptFlag(<peripheral>_BASE_PTR, periphID);
 *      @endcode
 */
#define iPort_ClearPinInterruptFlag(PeripheralBase, PinIndex) ( \
    PORT_PCR_REG(PeripheralBase,(PinIndex)) |= \
     PORT_PCR_ISF_MASK \
  )

/* ----------------------------------------------------------------------------
   -- ClearInterruptFlags
   ---------------------------------------------------------------------------- */

/**
 * @brief Clears interrupt flag bits defined by mask parameter.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Mask Mask of pins to clearing theirs interrupt flags. Use constants
 *        from group "Pin masks". This parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORTA_ISFR, PORTB_ISFR,
 *          PORTC_ISFR, PORTD_ISFR, PORTE_ISFR, PORTF_ISFR (depending on the
 *          peripheral).
 * @par Example:
 *      @code
 *      iPORT_ClearInterruptFlags(<peripheral>_BASE_PTR, iPORT_PIN_0);
 *      @endcode
 */
#define iPort_ClearInterruptFlags(PeripheralBase, Mask) ( \
    PORT_ISFR_REG(PeripheralBase) = \
     (uint32_t)(Mask) \
  )

/* ----------------------------------------------------------------------------
   -- SetGlobalPinControl
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets required pin control for required pins of whole port.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Mask Mask of pins in port where the bit 0 corresponds with the pin
 *        which has index 0 within the port and the bit 31 corresponds with the pin
 *        which has index 31 within the port. This parameter is a 32-bit value.
 * @param Value Settings of pull, slew rate, passive filter, open drain, mux
 *        control and pin lock . This parameter is a 16-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORTA_GPCLR,
 *          PORTA_GPCHR, PORTB_GPCLR, PORTB_GPCHR, PORTC_GPCLR, PORTC_GPCHR, PORTD_GPCLR,
 *          PORTD_GPCHR, PORTE_GPCLR, PORTE_GPCHR, PORTF_GPCLR, PORTF_GPCHR
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_SetGlobalPinControl(<peripheral>_BASE_PTR, 1, 1);
 *      @endcode
 */
#define iPort_SetGlobalPinControl(PeripheralBase, Mask, Value) ( \
    (PORT_GPCLR_REG(PeripheralBase) = \
     (uint32_t)(( \
      (uint32_t)((uint32_t)((uint32_t)(Mask) & 0xFFFFU) << PORT_GPCLR_GPWE_SHIFT)) | ( \
      (uint32_t)(Value)))), \
    (PORT_GPCHR_REG(PeripheralBase) = \
     (uint32_t)(( \
      (uint32_t)((uint32_t)(Mask) & (uint32_t)(~(uint32_t)0xFFFFU))) | ( \
      (uint32_t)(Value)))) \
  )

/* ----------------------------------------------------------------------------
   -- SetGlobalPinControlLow
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets required pin control for required pins from low part of port.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Mask Mask of pins in port where the bit 0 corresponds with the pin
 *        which has index 0 within the port and the bit 15 corresponds with the pin
 *        which has index 15 within the port. This parameter is a 16-bit value.
 * @param Value Settings of pull, slew rate, passive filter, open drain, mux
 *        control and pin lock . This parameter is a 16-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORTA_GPCLR,
 *          PORTB_GPCLR, PORTC_GPCLR, PORTD_GPCLR, PORTE_GPCLR, PORTF_GPCLR (depending on
 *          the peripheral).
 * @par Example:
 *      @code
 *      iPort_SetGlobalPinControlLow(<peripheral>_BASE_PTR, 1, 1);
 *      @endcode
 */
#define iPort_SetGlobalPinControlLow(PeripheralBase, Mask, Value) ( \
    PORT_GPCLR_REG(PeripheralBase) = \
     (uint32_t)((uint32_t)((uint32_t)(Mask) << PORT_GPCLR_GPWE_SHIFT) | (uint32_t)(Value)) \
  )

/* ----------------------------------------------------------------------------
   -- SetGlobalPinControlHigh
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets required pin control for required pins from high part of port.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Mask Mask of pins in port where the bit 0 corresponds with the pin
 *        which has index 16 within the port and the bit 15 corresponds with the pin
 *        which has index 31 within the port. This parameter is a 16-bit value.
 * @param Value Settings of pull, slew rate, passive filter, open drain, mux
 *        control and pin lock . This parameter is a 16-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORTA_GPCHR,
 *          PORTB_GPCHR, PORTC_GPCHR, PORTD_GPCHR, PORTE_GPCHR, PORTF_GPCHR (depending on
 *          the peripheral).
 * @par Example:
 *      @code
 *      iPort_SetGlobalPinControlHigh(<peripheral>_BASE_PTR, 1, 1);
 *      @endcode
 */
#define iPort_SetGlobalPinControlHigh(PeripheralBase, Mask, Value) ( \
    PORT_GPCHR_REG(PeripheralBase) = \
     (uint32_t)((uint32_t)((uint32_t)(Mask) << PORT_GPCHR_GPWE_SHIFT) | (uint32_t)(Value)) \
  )

/* ----------------------------------------------------------------------------
   -- GetEnableDigitalFilterStatusMask
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns enable status of digital filter for whole port.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORTA_DFER, PORTB_DFER,
 *          PORTC_DFER, PORTD_DFER, PORTE_DFER, PORTF_DFER (depending on the
 *          peripheral).
 * @par Example:
 *      @code
 *      uint32_t result =
 *      iPort_GetEnableDigitalFilterStatusMask(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define iPort_GetEnableDigitalFilterStatusMask(PeripheralBase) ( \
    PORT_DFER_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- EnableDigitalFilters
   ---------------------------------------------------------------------------- */

/**
 * @brief Enables digital filters.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Mask Mask of pins. Use constants from group "Pin masks". This
 *        parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORTA_DFER, PORTB_DFER,
 *          PORTC_DFER, PORTD_DFER, PORTE_DFER, PORTF_DFER (depending on the
 *          peripheral).
 * @par Example:
 *      @code
 *      iPort_EnableDigitalFilters(<peripheral>_BASE_PTR, iPORT_PIN_0);
 *      @endcode
 */
#define iPort_EnableDigitalFilters(PeripheralBase, Mask) ( \
    PORT_DFER_REG(PeripheralBase) |= \
     (uint32_t)(Mask) \
  )

/* ----------------------------------------------------------------------------
   -- DisableDigitalFilters
   ---------------------------------------------------------------------------- */

/**
 * @brief Disables digital filters.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Mask Mask of pins. Use constants from group "Pin masks". This
 *        parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORTA_DFER, PORTB_DFER,
 *          PORTC_DFER, PORTD_DFER, PORTE_DFER, PORTF_DFER (depending on the
 *          peripheral).
 * @par Example:
 *      @code
 *      iPORT_DisableDigitalFilters(<peripheral>_BASE_PTR, iPORT_PIN_0);
 *      @endcode
 */
#define iPort_DisableDigitalFilters(PeripheralBase, Mask) ( \
    PORT_DFER_REG(PeripheralBase) &= \
     (uint32_t)(~(uint32_t)(Mask)) \
  )

/* ----------------------------------------------------------------------------
   -- GetFilterClockSource
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets how filter clock source is set.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of "Constants for digital clock source setting" type.
 *         The value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PORTA_DFCR, PORTB_DFCR,
 *          PORTC_DFCR, PORTD_DFCR, PORTE_DFCR, PORTF_DFCR (depending on the
 *          peripheral).
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetFilterClockSource(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define iPort_GetFilterClockSource(PeripheralBase) ( \
    (uint32_t)(PORT_DFCR_REG(PeripheralBase) & PORT_DFCR_CS_MASK) \
  )

/* ----------------------------------------------------------------------------
   -- SetFilterClockSource
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets filter clock source.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param State Requested state of filter clock source. This parameter is of
 *        "Constants for digital clock source setting" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORTA_DFCR, PORTB_DFCR,
 *          PORTC_DFCR, PORTD_DFCR, PORTE_DFCR, PORTF_DFCR (depending on the
 *          peripheral).
 * @par Example:
 *      @code
 *      iPort_SetFilterClockSource(<peripheral>_BASE_PTR,
 *      iPORT_BUS_CLOCK);
 *      @endcode
 */
#define iPort_SetFilterClockSource(PeripheralBase, State) ( \
    PORT_DFCR_REG(PeripheralBase) = \
     (uint32_t)(( \
      (uint32_t)(PORT_DFCR_REG(PeripheralBase) & (uint32_t)(~(uint32_t)PORT_DFCR_CS_MASK))) | ( \
      (uint32_t)(State))) \
  )

/* ----------------------------------------------------------------------------
   -- GetFilterLength
   ---------------------------------------------------------------------------- */

/**
 * @brief Returns filter length in clock cycles.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORTA_DFWR, PORTB_DFWR,
 *          PORTC_DFWR, PORTD_DFWR, PORTE_DFWR, PORTF_DFWR (depending on the
 *          peripheral).
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetFilterLength(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define iPort_GetFilterLength(PeripheralBase) ( \
    PORT_DFWR_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- SetFilterLength
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets filter length in clock cycles.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Parameter specifying new value. This parameter is a 5-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORTA_DFWR, PORTB_DFWR,
 *          PORTC_DFWR, PORTD_DFWR, PORTE_DFWR, PORTF_DFWR (depending on the
 *          peripheral).
 * @par Example:
 *      @code
 *      iPort_SetFilterLength(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
#define iPort_SetFilterLength(PeripheralBase, Value) ( \
    PORT_DFWR_REG(PeripheralBase) = \
     (uint32_t)(Value) \
  )

/* ----------------------------------------------------------------------------
   -- GetFilterDivisionSet1
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)))
/**
 * @brief Gets configuration of the Filter Division Set 1.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of "Constants for Filter Division Set 1" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetFilterDivisionSet1(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_GetFilterDivisionSet1(PeripheralBase) ( \
      (uint32_t)(PORT_IOFLT0_REG(PeripheralBase) & PORT_IOFLT0_FLTDIV1_MASK) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */
/**
 * @brief Gets configuration of the Filter Division Set 1.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of "Constants for Filter Division Set 1" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetFilterDivisionSet1(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_GetFilterDivisionSet1(PeripheralBase) ( \
      (uint32_t)(PORT_IOFLT_REG(PeripheralBase) & PORT_IOFLT_FLTDIV1_MASK) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */

/* ----------------------------------------------------------------------------
   -- SetFilterDivisionSet1
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)))
/**
 * @brief Configures Filter Division Set 1.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param FilterDivision Filter division 1. This parameter is of "Constants for
 *        Filter Division Set 1" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_SetFilterDivisionSet1(<peripheral>_BASE_PTR,
 *      iPORT_BUSCLK_DIV_2);
 *      @endcode
 */
  #define iPort_SetFilterDivisionSet1(PeripheralBase, FilterDivision) ( \
      PORT_IOFLT0_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(( \
         PORT_IOFLT0_REG(PeripheralBase)) & ( \
         (uint32_t)(~(uint32_t)PORT_IOFLT0_FLTDIV1_MASK)))) | ( \
        (uint32_t)(FilterDivision))) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */
/**
 * @brief Configures Filter Division Set 1.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param FilterDivision Filter division 1. This parameter is of "Constants for
 *        Filter Division Set 1" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_SetFilterDivisionSet1(<peripheral>_BASE_PTR,
 *      iPORT_BUSCLK_DIV_2);
 *      @endcode
 */
  #define iPort_SetFilterDivisionSet1(PeripheralBase, FilterDivision) ( \
      PORT_IOFLT_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(( \
         PORT_IOFLT_REG(PeripheralBase)) & ( \
         (uint32_t)(~(uint32_t)PORT_IOFLT_FLTDIV1_MASK)))) | ( \
        (uint32_t)(FilterDivision))) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */

/* ----------------------------------------------------------------------------
   -- GetFilterDivisionSet2
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)))
/**
 * @brief Gets configuration of the Filter Division Set 2.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of "Constants for Filter Division Set 2" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetFilterDivisionSet2(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_GetFilterDivisionSet2(PeripheralBase) ( \
      (uint32_t)(PORT_IOFLT0_REG(PeripheralBase) & PORT_IOFLT0_FLTDIV2_MASK) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */
/**
 * @brief Gets configuration of the Filter Division Set 2.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of "Constants for Filter Division Set 2" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetFilterDivisionSet2(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_GetFilterDivisionSet2(PeripheralBase) ( \
      (uint32_t)(PORT_IOFLT_REG(PeripheralBase) & PORT_IOFLT_FLTDIV2_MASK) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */

/* ----------------------------------------------------------------------------
   -- SetFilterDivisionSet2
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)))
/**
 * @brief Configures Filter Division Set 2.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param FilterDivision Filter division 2. This parameter is of "Constants for
 *        Filter Division Set 2" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_SetFilterDivisionSet2(<peripheral>_BASE_PTR,
 *      iPORT_BUSCLK_DIV_32);
 *      @endcode
 */
  #define iPort_SetFilterDivisionSet2(PeripheralBase, FilterDivision) ( \
      PORT_IOFLT0_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(( \
         PORT_IOFLT0_REG(PeripheralBase)) & ( \
         (uint32_t)(~(uint32_t)PORT_IOFLT0_FLTDIV2_MASK)))) | ( \
        (uint32_t)(FilterDivision))) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */
/**
 * @brief Configures Filter Division Set 2.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param FilterDivision Filter division 2. This parameter is of "Constants for
 *        Filter Division Set 2" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_SetFilterDivisionSet2(<peripheral>_BASE_PTR,
 *      iPORT_BUSCLK_DIV_32);
 *      @endcode
 */
  #define iPort_SetFilterDivisionSet2(PeripheralBase, FilterDivision) ( \
      PORT_IOFLT_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(( \
         PORT_IOFLT_REG(PeripheralBase)) & ( \
         (uint32_t)(~(uint32_t)PORT_IOFLT_FLTDIV2_MASK)))) | ( \
        (uint32_t)(FilterDivision))) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */

/* ----------------------------------------------------------------------------
   -- GetFilterDivisionSet3
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)))
/**
 * @brief Gets configuration of the Filter Division Set 3.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of "Constants for Filter Division Set 3" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetFilterDivisionSet3(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_GetFilterDivisionSet3(PeripheralBase) ( \
      (uint32_t)(PORT_IOFLT0_REG(PeripheralBase) & PORT_IOFLT0_FLTDIV3_MASK) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */
/**
 * @brief Gets configuration of the Filter Division Set 3.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a value of "Constants for Filter Division Set 3" type. The
 *         value is cast to "uint32_t".
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result = iPort_GetFilterDivisionSet3(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_GetFilterDivisionSet3(PeripheralBase) ( \
      (uint32_t)(PORT_IOFLT_REG(PeripheralBase) & PORT_IOFLT_FLTDIV3_MASK) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */

/* ----------------------------------------------------------------------------
   -- SetFilterDivisionSet3
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)))
/**
 * @brief Configures Filter Division Set 3.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param FilterDivision Filter division 3. This parameter is of "Constants for
 *        Filter Division Set 3" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_SetFilterDivisionSet3(<peripheral>_BASE_PTR, iPORT_LPOCLK);
 *      @endcode
 */
  #define iPort_SetFilterDivisionSet3(PeripheralBase, FilterDivision) ( \
      PORT_IOFLT0_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(( \
         PORT_IOFLT0_REG(PeripheralBase)) & ( \
         (uint32_t)(~(uint32_t)PORT_IOFLT0_FLTDIV3_MASK)))) | ( \
        (uint32_t)(FilterDivision))) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */
/**
 * @brief Configures Filter Division Set 3.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param FilterDivision Filter division 3. This parameter is of "Constants for
 *        Filter Division Set 3" type.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT, PORT_IOFLT0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_SetFilterDivisionSet3(<peripheral>_BASE_PTR, iPORT_LPOCLK);
 *      @endcode
 */
  #define iPort_SetFilterDivisionSet3(PeripheralBase, FilterDivision) ( \
      PORT_IOFLT_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(( \
         PORT_IOFLT_REG(PeripheralBase)) & ( \
         (uint32_t)(~(uint32_t)PORT_IOFLT_FLTDIV3_MASK)))) | ( \
        (uint32_t)(FilterDivision))) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */

/* ----------------------------------------------------------------------------
   -- GetFilter
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets filter configuration for module input pins.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Module Module. Use constants from group "Modules offering input pin
 *        filtering capability". This parameter is 5 bits wide.
 * @return Use constants from group "Filter selection" for processing return
 *         value. The value is cast to "uint8_t".
 * @remarks The macro accesses the following registers: PORT_IOFLT.
 * @par Example:
 *      @code
 *      uint8_t result = iPort_GetFilter(<peripheral>_BASE_PTR,
 *      iPORT_PTA);
 *      @endcode
 */
#define iPort_GetFilter(PeripheralBase, Module) ( \
    (uint8_t)((uint8_t)(PORT_IOFLT_REG(PeripheralBase) >> (uint8_t)(Module)) & (uint8_t)0x3U) \
  )

/* ----------------------------------------------------------------------------
   -- SetFilter
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets filter for module input pins.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Module Module to be configured. Use constants from group "Modules
 *        offering input pin filtering capability". This parameter is 5 bits wide.
 * @param Filter Selected filter. Use constants from group "Filter selection".
 *        This parameter is 2 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT.
 * @par Example:
 *      @code
 *      iPort_SetFilter(<peripheral>_BASE_PTR, iPORT_PTA,
 *      iPORT_NO_FILTER);
 *      @endcode
 */
#define iPort_SetFilter(PeripheralBase, Module, Filter) ( \
    PORT_IOFLT_REG(PeripheralBase) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_IOFLT_REG(PeripheralBase)) & ( \
       (uint32_t)(~(uint32_t)((uint32_t)0x3U << (uint8_t)(Module)))))) | ( \
      (uint32_t)((uint32_t)(Filter) << (uint8_t)(Module)))) \
  )

/* ----------------------------------------------------------------------------
   -- WritePortFilterReg
   ---------------------------------------------------------------------------- */

/**
 * @brief Writes port filter register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Value to be written into IOFLT0 register. This parameter is a
 *        32-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT.
 * @par Example:
 *      @code
 *      iPort_WritePortFilterReg(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
#define iPort_WritePortFilterReg(PeripheralBase, Value) ( \
    PORT_IOFLT_REG(PeripheralBase) = \
     (uint32_t)(Value) \
  )

/* ----------------------------------------------------------------------------
   -- ReadPortFilterReg
   ---------------------------------------------------------------------------- */

/**
 * @brief Reads port filter register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORT_IOFLT.
 * @par Example:
 *      @code
 *      uint32_t result = iPort_ReadPortFilterReg(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define iPort_ReadPortFilterReg(PeripheralBase) ( \
    PORT_IOFLT_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- EnablePullupLowPortMask
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)))
/**
 * @brief Enables/Disables pullup resistors on low port pins specified by mask
 * parameters.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PullupDisableMask Mask of low port pins to be disabled. Use constants
 *        from group "Pin masks". This parameter is 32 bits wide.
 * @param PullupEnableMask Mask of low port pins to be enabled. Use constants
 *        from group "Pin masks". This parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUEL, PORT_PUE0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_EnablePullupLowPortMask(<peripheral>_BASE_PTR, iPORT_PIN_0,
 *      iPORT_PIN_0);
 *      @endcode
 */
  #define iPort_EnablePullupLowPortMask(PeripheralBase, PullupDisableMask, PullupEnableMask) ( \
      PORT_PUE0_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(PORT_PUE0_REG(PeripheralBase) & (uint32_t)(~(uint32_t)(PullupDisableMask)))) | ( \
        (uint32_t)(PullupEnableMask))) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */
/**
 * @brief Enables/Disables pullup resistors on low port pins specified by mask
 * parameters.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PullupDisableMask Mask of low port pins to be disabled. Use constants
 *        from group "Pin masks". This parameter is 32 bits wide.
 * @param PullupEnableMask Mask of low port pins to be enabled. Use constants
 *        from group "Pin masks". This parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUEL, PORT_PUE0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_EnablePullupLowPortMask(<peripheral>_BASE_PTR, iPORT_PIN_0,
 *      iPORT_PIN_0);
 *      @endcode
 */
  #define iPort_EnablePullupLowPortMask(PeripheralBase, PullupDisableMask, PullupEnableMask) ( \
      PORT_PUEL_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(PORT_PUEL_REG(PeripheralBase) & (uint32_t)(~(uint32_t)(PullupDisableMask)))) | ( \
        (uint32_t)(PullupEnableMask))) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */

/* ----------------------------------------------------------------------------
   -- WritePullupEnableLowReg
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)))
/**
 * @brief Writes pullup enable low register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Parameter specifying mask of the new pullup enable setting for
 *        low port pins. Bit #0 of the mask controls pullup setting of the low
 *        port pin #0, bit #31 controls setting of the pin #31. Bit value 0 disables
 *        pullup for associated low port pin, bit value 1 enables pullup for
 *        associated low port pin. This parameter is a 32-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUEL, PORT_PUE0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_WritePullupEnableLowReg(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
  #define iPort_WritePullupEnableLowReg(PeripheralBase, Value) ( \
      PORT_PUE0_REG(PeripheralBase) = \
       (uint32_t)(Value) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */
/**
 * @brief Writes pullup enable low register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Parameter specifying mask of the new pullup enable setting for
 *        low port pins. Bit #0 of the mask controls pullup setting of the low
 *        port pin #0, bit #31 controls setting of the pin #31. Bit value 0 disables
 *        pullup for associated low port pin, bit value 1 enables pullup for
 *        associated low port pin. This parameter is a 32-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUEL, PORT_PUE0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_WritePullupEnableLowReg(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
  #define iPort_WritePullupEnableLowReg(PeripheralBase, Value) ( \
      PORT_PUEL_REG(PeripheralBase) = \
       (uint32_t)(Value) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */

/* ----------------------------------------------------------------------------
   -- ReadPullupEnableLowReg
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)))
/**
 * @brief Reads pullup enable configuration of the low port pins. Bit #0 of
 * return value contains pullup setting of the low port pin #0, bit #31 contains
 * setting of the pin #31.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORT_PUEL, PORT_PUE0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result =
 *      iPort_ReadPullupEnableLowReg(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_ReadPullupEnableLowReg(PeripheralBase) ( \
      PORT_PUE0_REG(PeripheralBase) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */
/**
 * @brief Reads pullup enable configuration of the low port pins. Bit #0 of
 * return value contains pullup setting of the low port pin #0, bit #31 contains
 * setting of the pin #31.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORT_PUEL, PORT_PUE0
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result =
 *      iPort_ReadPullupEnableLowReg(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_ReadPullupEnableLowReg(PeripheralBase) ( \
      PORT_PUEL_REG(PeripheralBase) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN642)) || (defined(MCU_SKEAZN84)) */

/* ----------------------------------------------------------------------------
   -- EnablePullupHighPortMask
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_SKEAZN642)))
/**
 * @brief Enables/Disables pullup resistors on high port pins specified by mask
 * parameters.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PullupDisableMask Mask of high port pins with pullup to be disabled.
 *        Use constants from group "Pin masks". This parameter is 32 bits wide.
 * @param PullupEnableMask Mask of high port pins with pullup to be enabled. Use
 *        constants from group "Pin masks". This parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUEH, PORT_PUE1
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_EnablePullupHighPortMask(<peripheral>_BASE_PTR,
 *      iPORT_PIN_0, iPORT_PIN_0);
 *      @endcode
 */
  #define iPort_EnablePullupHighPortMask(PeripheralBase, PullupDisableMask, PullupEnableMask) ( \
      PORT_PUEH_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(PORT_PUEH_REG(PeripheralBase) & (uint32_t)(~(uint32_t)(PullupDisableMask)))) | ( \
        (uint32_t)(PullupEnableMask))) \
    )
#else /* (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) */
/**
 * @brief Enables/Disables pullup resistors on high port pins specified by mask
 * parameters.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PullupDisableMask Mask of high port pins with pullup to be disabled.
 *        Use constants from group "Pin masks". This parameter is 32 bits wide.
 * @param PullupEnableMask Mask of high port pins with pullup to be enabled. Use
 *        constants from group "Pin masks". This parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUEH, PORT_PUE1
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_EnablePullupHighPortMask(<peripheral>_BASE_PTR,
 *      iPORT_PIN_0, iPORT_PIN_0);
 *      @endcode
 */
  #define iPort_EnablePullupHighPortMask(PeripheralBase, PullupDisableMask, PullupEnableMask) ( \
      PORT_PUE1_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(PORT_PUE1_REG(PeripheralBase) & (uint32_t)(~(uint32_t)(PullupDisableMask)))) | ( \
        (uint32_t)(PullupEnableMask))) \
    )
#endif /* (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) */

/* ----------------------------------------------------------------------------
   -- WritePullupEnableHighReg
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_SKEAZN642)))
/**
 * @brief Writes pullup enable high register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Parameter specifying mask of the new pullup enable setting for
 *        high port pins. Bit #0 of the mask controls pullup setting of the high
 *        port pin #0, bit #31 controls setting of the pin #31. Bit value 0
 *        disables pullup for associated high port pin, bit value 1 enables pullup for
 *        associated high port pin. This parameter is a 32-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUEH, PORT_PUE1
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_WritePullupEnableHighReg(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
  #define iPort_WritePullupEnableHighReg(PeripheralBase, Value) ( \
      PORT_PUEH_REG(PeripheralBase) = \
       (uint32_t)(Value) \
    )
#else /* (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) */
/**
 * @brief Writes pullup enable high register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Parameter specifying mask of the new pullup enable setting for
 *        high port pins. Bit #0 of the mask controls pullup setting of the high
 *        port pin #0, bit #31 controls setting of the pin #31. Bit value 0
 *        disables pullup for associated high port pin, bit value 1 enables pullup for
 *        associated high port pin. This parameter is a 32-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUEH, PORT_PUE1
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      iPort_WritePullupEnableHighReg(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
  #define iPort_WritePullupEnableHighReg(PeripheralBase, Value) ( \
      PORT_PUE1_REG(PeripheralBase) = \
       (uint32_t)(Value) \
    )
#endif /* (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) */

/* ----------------------------------------------------------------------------
   -- ReadPullupEnableHighReg
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_SKEAZN642)))
/**
 * @brief Reads pullup enable configuration of the high port pins. Bit #0 of
 * return value contains pullup setting of the high port pin #0, bit #31 contains
 * setting of the pin #31.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORT_PUEH, PORT_PUE1
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result =
 *      iPort_ReadPullupEnableHighReg(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_ReadPullupEnableHighReg(PeripheralBase) ( \
      PORT_PUEH_REG(PeripheralBase) \
    )
#else /* (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) */
/**
 * @brief Reads pullup enable configuration of the high port pins. Bit #0 of
 * return value contains pullup setting of the high port pin #0, bit #31 contains
 * setting of the pin #31.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORT_PUEH, PORT_PUE1
 *          (depending on the peripheral).
 * @par Example:
 *      @code
 *      uint32_t result =
 *      iPort_ReadPullupEnableHighReg(<peripheral>_BASE_PTR);
 *      @endcode
 */
  #define iPort_ReadPullupEnableHighReg(PeripheralBase) ( \
      PORT_PUE1_REG(PeripheralBase) \
    )
#endif /* (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) */

/* ----------------------------------------------------------------------------
   -- EnableHighDriveMask
   ---------------------------------------------------------------------------- */

#if ((defined(MCU_MKE04Z4)) || (defined(MCU_SKEAZN84)))
/**
 * @brief Enables/Disables high current drive capability on port pins specified
 * by mask parameters.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param HighDriveDisableMask Mask of pins with high drive to be disabled. Use
 *        constants from group "List of pins offering high drive capability".
 *        This parameter is 32 bits wide.
 * @param HighDriveEnableMask Mask of pins with high drive to be enabled. Use
 *        constants from group "List of pins offering high drive capability". This
 *        parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_HDRVE.
 * @par Example:
 *      @code
 *      iPort_EnableHighDriveMask(<peripheral>_BASE_PTR, iPORT_PTB5,
 *      iPORT_PTB5);
 *      @endcode
 */
  #define iPort_EnableHighDriveMask(PeripheralBase, HighDriveDisableMask, HighDriveEnableMask) ( \
      PORT_HDRVE_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(PORT_HDRVE_REG(PeripheralBase) & (uint32_t)(~(uint32_t)(HighDriveDisableMask)))) | ( \
        (uint32_t)(HighDriveEnableMask))) \
    )
#else /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) || (defined(MCU_SKEAZN642)) */
/**
 * @brief Enables/Disables high current drive capability on port pins specified
 * by mask parameters.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param HighDriveDisableMask Mask of pins with high drive to be disabled. Use
 *        constants from group "List of pins offering high drive capability".
 *        This parameter is 32 bits wide.
 * @param HighDriveEnableMask Mask of pins with high drive to be enabled. Use
 *        constants from group "List of pins offering high drive capability". This
 *        parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_HDRVE.
 * @par Example:
 *      @code
 *      iPort_EnableHighDriveMask(<peripheral>_BASE_PTR, iPORT_PTB4,
 *      iPORT_PTB4);
 *      @endcode
 */
  #define iPort_EnableHighDriveMask(PeripheralBase, HighDriveDisableMask, HighDriveEnableMask) ( \
      PORT_HDRVE_REG(PeripheralBase) = \
       (uint32_t)(( \
        (uint32_t)(PORT_HDRVE_REG(PeripheralBase) & (uint32_t)(~(uint32_t)(HighDriveDisableMask)))) | ( \
        (uint32_t)(HighDriveEnableMask))) \
    )
#endif /* (defined(MCU_MKE02Z2)) || (defined(MCU_MKE02Z4)) || (defined(MCU_MKE04Z1284)) || (defined(MCU_MKE06Z4)) || (defined(MCU_SKEAZ1284)) || (defined(MCU_SKEAZN642)) */

/* ----------------------------------------------------------------------------
   -- WriteHighDriveEnableReg
   ---------------------------------------------------------------------------- */

/**
 * @brief Writes high drive enable register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Parameter specifying mask of the new high drive enable setting
 *        for associated pins. Pins supporting high drive capability are defined
 *        by High drive pin list. This parameter is a 32-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_HDRVE.
 * @par Example:
 *      @code
 *      iPort_WriteHighDriveEnableReg(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
#define iPort_WriteHighDriveEnableReg(PeripheralBase, Value) ( \
    PORT_HDRVE_REG(PeripheralBase) = \
     (uint32_t)(Value) \
  )

/* ----------------------------------------------------------------------------
   -- ReadHighDriveEnableReg
   ---------------------------------------------------------------------------- */

/**
 * @brief Reads high drive enable configuration of the associated pins. Pins
 * supporting high drive capability are defined by High drive pin list.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORT_HDRVE.
 * @par Example:
 *      @code
 *      uint32_t result =
 *      iPort_ReadHighDriveEnableReg(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define iPort_ReadHighDriveEnableReg(PeripheralBase) ( \
    PORT_HDRVE_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- GetFilter0
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets filter 0 configuration for module input pins.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Module Module. Use constants from group "Modules offering input pin
 *        filtering capability". This parameter is 5 bits wide.
 * @return Use constants from group "Filter selection" for processing return
 *         value. The value is cast to "uint8_t".
 * @remarks The macro accesses the following registers: PORT_IOFLT0.
 * @par Example:
 *      @code
 *      uint8_t result = iPort_GetFilter0(<peripheral>_BASE_PTR,
 *      iPORT_PTA);
 *      @endcode
 */
#define iPort_GetFilter0(PeripheralBase, Module) ( \
    (uint8_t)(( \
     (uint8_t)(PORT_IOFLT0_REG(PeripheralBase) >> (uint8_t)(Module))) & ( \
     (uint8_t)0x3U)) \
  )

/* ----------------------------------------------------------------------------
   -- GetFilter1
   ---------------------------------------------------------------------------- */

/**
 * @brief Gets filter 1 configuration for module input pins.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Module Module. Use constants from group "Modules offering input pin
 *        filtering capability". This parameter is 5 bits wide.
 * @return Use constants from group "Filter selection" for processing return
 *         value. The value is cast to "uint8_t".
 * @remarks The macro accesses the following registers: PORT_IOFLT1.
 * @par Example:
 *      @code
 *      uint8_t result = iPort_GetFilter1(<peripheral>_BASE_PTR,
 *      iPORT_PTA);
 *      @endcode
 */
#define iPort_GetFilter1(PeripheralBase, Module) ( \
    (uint8_t)(( \
     (uint8_t)(PORT_IOFLT1_REG(PeripheralBase) >> (uint8_t)(Module))) & ( \
     (uint8_t)0x3U)) \
  )

/* ----------------------------------------------------------------------------
   -- SetFilter0
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets filter 0 for module input pins.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Module Module to be configured. Use constants from group "Modules
 *        offering input pin filtering capability". This parameter is 5 bits wide.
 * @param Filter Selected filter. Use constants from group "Filter selection".
 *        This parameter is 2 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT0.
 * @par Example:
 *      @code
 *      iPort_SetFilter0(<peripheral>_BASE_PTR, iPORT_PTA,
 *      iPORT_NO_FILTER);
 *      @endcode
 */
#define iPort_SetFilter0(PeripheralBase, Module, Filter) ( \
    PORT_IOFLT0_REG(PeripheralBase) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_IOFLT0_REG(PeripheralBase)) & ( \
       (uint32_t)(~(uint32_t)((uint32_t)0x3U << (uint8_t)(Module)))))) | ( \
      (uint32_t)((uint32_t)(Filter) << (uint8_t)(Module)))) \
  )

/* ----------------------------------------------------------------------------
   -- SetFilter1
   ---------------------------------------------------------------------------- */

/**
 * @brief Sets filter 1 for module input pins.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Module Module to be configured. Use constants from group "Modules
 *        offering input pin filtering capability". This parameter is 5 bits wide.
 * @param Filter Selected filter. Use constants from group "Filter selection".
 *        This parameter is 2 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT1.
 * @par Example:
 *      @code
 *      iPort_SetFilter1(<peripheral>_BASE_PTR, iPORT_PTA,
 *      iPORT_NO_FILTER);
 *      @endcode
 */
#define iPort_SetFilter1(PeripheralBase, Module, Filter) ( \
    PORT_IOFLT1_REG(PeripheralBase) = \
     (uint32_t)(( \
      (uint32_t)(( \
       PORT_IOFLT1_REG(PeripheralBase)) & ( \
       (uint32_t)(~(uint32_t)((uint32_t)0x3U << (uint8_t)(Module)))))) | ( \
      (uint32_t)((uint32_t)(Filter) << (uint8_t)(Module)))) \
  )

/* ----------------------------------------------------------------------------
   -- WritePortFilter0Reg
   ---------------------------------------------------------------------------- */

/**
 * @brief Writes port filter 0 register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Value to be written into IOFLT1 register. This parameter is a
 *        32-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT0.
 * @par Example:
 *      @code
 *      iPort_WritePortFilter0Reg(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
#define iPort_WritePortFilter0Reg(PeripheralBase, Value) ( \
    PORT_IOFLT0_REG(PeripheralBase) = \
     (uint32_t)(Value) \
  )

/* ----------------------------------------------------------------------------
   -- WritePortFilter1Reg
   ---------------------------------------------------------------------------- */

/**
 * @brief Writes port filter 1 register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Value to be written into IOFLT register. This parameter is a
 *        32-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_IOFLT1.
 * @par Example:
 *      @code
 *      iPort_WritePortFilter1Reg(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
#define iPort_WritePortFilter1Reg(PeripheralBase, Value) ( \
    PORT_IOFLT1_REG(PeripheralBase) = \
     (uint32_t)(Value) \
  )

/* ----------------------------------------------------------------------------
   -- ReadPortFilter0Reg
   ---------------------------------------------------------------------------- */

/**
 * @brief Reads port filter 0 register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORT_IOFLT0.
 * @par Example:
 *      @code
 *      uint32_t result = iPort_ReadPortFilter0Reg(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define iPort_ReadPortFilter0Reg(PeripheralBase) ( \
    PORT_IOFLT0_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- ReadPortFilter1Reg
   ---------------------------------------------------------------------------- */

/**
 * @brief Reads port filter 1 register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORT_IOFLT1.
 * @par Example:
 *      @code
 *      uint32_t result = iPort_ReadPortFilter1Reg(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define iPort_ReadPortFilter1Reg(PeripheralBase) ( \
    PORT_IOFLT1_REG(PeripheralBase) \
  )

/* ----------------------------------------------------------------------------
   -- EnablePullupPort2Mask
   ---------------------------------------------------------------------------- */

/**
 * @brief Enables/Disables pullup resistors on port 2 pins specified by mask
 * parameters.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param PullupDisableMask Mask of high port pins with pullup to be disabled.
 *        Use constants from group "Pin masks". This parameter is 32 bits wide.
 * @param PullupEnableMask Mask of high port pins with pullup to be enabled. Use
 *        constants from group "Pin masks". This parameter is 32 bits wide.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUE2.
 * @par Example:
 *      @code
 *      iPort_EnablePullupPort2Mask(<peripheral>_BASE_PTR, iPORT_PIN_0,
 *      iPORT_PIN_0);
 *      @endcode
 */
#define iPort_EnablePullupPort2Mask(PeripheralBase, PullupDisableMask, PullupEnableMask) ( \
    PORT_PUE2_REG(PeripheralBase) = \
     (uint32_t)(( \
      (uint32_t)(PORT_PUE2_REG(PeripheralBase) & (uint32_t)(~(uint32_t)(PullupDisableMask)))) | ( \
      (uint32_t)(PullupEnableMask))) \
  )

/* ----------------------------------------------------------------------------
   -- WritePort2PullupEnableReg
   ---------------------------------------------------------------------------- */

/**
 * @brief Writes port 2 pullup enable high register.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @param Value Parameter specifying mask of the new pullup enable setting for
 *        high port pins. Bit #0 of the mask controls pullup setting of the high
 *        port pin #0, bit #31 controls setting of the pin #31. Bit value 0
 *        disables pullup for associated high port pin, bit value 1 enables pullup for
 *        associated high port pin. This parameter is a 32-bit value.
 * @return Returns a value of void type.
 * @remarks The macro accesses the following registers: PORT_PUE2.
 * @par Example:
 *      @code
 *      iPort_WritePort2PullupEnableReg(<peripheral>_BASE_PTR, 1);
 *      @endcode
 */
#define iPort_WritePort2PullupEnableReg(PeripheralBase, Value) ( \
    PORT_PUE2_REG(PeripheralBase) = \
     (uint32_t)(Value) \
  )

/* ----------------------------------------------------------------------------
   -- ReadPort2PullupEnableReg
   ---------------------------------------------------------------------------- */

/**
 * @brief Reads port 2 pullup enable configuration of the high port pins. Bit #0
 * of return value contains pullup setting of the high port pin #0, bit #31
 * contains setting of the pin #31.
 * @param PeripheralBase Pointer to a peripheral registers structure (peripheral
 *        base address). You can use the constant defined in the registers
 *        definition header file (<peripheral>_BASE_PTR) or the constant defined in
 *        the peripheral initialization component header file
 *        (<component_name>_DEVICE).
 * @return Returns a 32-bit value.
 * @remarks The macro accesses the following registers: PORT_PUE2.
 * @par Example:
 *      @code
 *      uint32_t result =
 *      iPort_ReadPort2PullupEnableReg(<peripheral>_BASE_PTR);
 *      @endcode
 */
#define iPort_ReadPort2PullupEnableReg(PeripheralBase) ( \
    PORT_PUE2_REG(PeripheralBase) \
  )
#endif  /* #if defined(iPORT_H_) */

/* PORT_PDD.h, eof. */
