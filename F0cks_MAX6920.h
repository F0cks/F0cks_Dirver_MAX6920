/*
 * F0cks_Dirver_MAX6920.h
 *
 *  Created on: Jun 27, 2018
 *      Author: f0cks
 */

#ifndef F0CKS_MAX6920_H_
#define F0CKS_MAX6920_H_


#include "stdint.h"

typedef struct
{
  uint32_t              port;
  uint16_t              pin;

}MAX6920_GPIO_TypeDef;

typedef struct
{
	MAX6920_GPIO_TypeDef clk;
	MAX6920_GPIO_TypeDef din;
	MAX6920_GPIO_TypeDef load;
	MAX6920_GPIO_TypeDef blank;

}MAX6920_ConfigurationTypeDef;

/**
  * @brief  MAX6920 handle Structure definition
  */
typedef struct
{
	MAX6920_GPIO_TypeDef clk;
	MAX6920_GPIO_TypeDef din;
	MAX6920_GPIO_TypeDef load;
	MAX6920_GPIO_TypeDef blank;

}MAX6920_HandleTypeDef;

void F0cks_MAX6920_Init(MAX6920_HandleTypeDef *handler, MAX6920_ConfigurationTypeDef config);
void F0cks_MAX6920_Set_Value(MAX6920_HandleTypeDef *handler, uint16_t value);

/* Functions that need to be implemented */
void F0cks_GPIO_Write(uint32_t port, uint16_t pin, uint16_t state);
void F0cks_Delay_Us(uint32_t delay);

#endif /* F0CKS_MAX6920_H_ */
