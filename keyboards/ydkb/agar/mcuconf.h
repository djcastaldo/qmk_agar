#ifndef _MCUCONF_H_
#define _MCUCONF_H_

#define STM32F103_MCUCONF

/*
 * STM32F103 drivers configuration.
 * These settings override the default settings present in the various device driver implementation headers.
 */

/* HAL driver system settings */
#define STM32_NO_INIT                       FALSE
#define STM32_HSI_ENABLED                   TRUE
#define STM32_LSI_ENABLED                   TRUE
#define STM32_HSE_ENABLED                   FALSE
#define STM32_LSE_ENABLED                   FALSE
#define STM32_SW                            STM32_SW_PLL
#define STM32_PLLSRC                        STM32_PLLSRC_HSI
#define STM32_PLLXTPRE                      STM32_PLLXTPRE_DIV1
#define STM32_PLLMUL_VALUE                  12
#define STM32_HPRE                          STM32_HPRE_DIV1
#define STM32_PPRE1                         STM32_PPRE1_DIV2
#define STM32_PPRE2                         STM32_PPRE2_DIV1
#define STM32_ADCPRE                        STM32_ADCPRE_DIV4
#define STM32_USB_CLOCK_REQUIRED            TRUE
#define STM32_USBPRE                        STM32_USBPRE_DIV1
#define STM32_MCOSEL                        STM32_MCOSEL_NOCLOCK
#define STM32_RTCSEL                        STM32_RTCSEL_LSI
#define STM32_PVD_ENABLE                    FALSE
#define STM32_PLS                           STM32_PLS_LEV0

/* Other driver settings are kept at their default FALSE values as they are not used */

/* Only USB is enabled as it's required for keyboard operation */
#define STM32_USB_USE_USB1                  TRUE
#define STM32_USB_LOW_POWER_ON_SUSPEND      FALSE
#define STM32_USB_USB1_HP_IRQ_PRIORITY      13
#define STM32_USB_USB1_LP_IRQ_PRIORITY      14

#define STM32_ST_IRQ_PRIORITY               8
#define STM32_ST_USE_TIMER                  2

#endif /* _MCUCONF_H_ */