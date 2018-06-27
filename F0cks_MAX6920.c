/*
 * F0cks_Dirver_MAX6920.c
 *
 *  Created on: Jun 27, 2018
 *      Author: f0cks
 */
#include "F0cks_MAX6920.h"

void F0cks_MAX6920_Init(MAX6920_HandleTypeDef *handler, MAX6920_ConfigurationTypeDef config)
{
	/* Store configuration in handler */
	handler->clk		= config.clk;
	handler->din		= config.din;
	handler->load		= config.load;
	handler->blank	= config.blank;

	/* Set default */
	F0cks_GPIO_Write(handler->clk.port,		handler->clk.pin,		0);
	F0cks_GPIO_Write(handler->din.port,		handler->din.pin,		0);
	F0cks_GPIO_Write(handler->load.port,	handler->load.pin,	0);
	F0cks_GPIO_Write(handler->blank.port, handler->blank.pin, 0);

}

void F0cks_MAX6920_Set_Value(MAX6920_HandleTypeDef *handler, uint16_t value)
{
	uint16_t i = 1;
	uint16_t tempo = value;

  for(i=1;i<=12;i++)
  {
  	if( (tempo&0x01) == 1 )
  	{
  		F0cks_GPIO_Write(handler->din.port, handler->din.pin, 1);
  	}
  	else
  	{
  		F0cks_GPIO_Write(handler->din.port, handler->din.pin, 0);
  	}
  	F0cks_Delay_Us(1);
  	F0cks_GPIO_Write(handler->clk.port,handler->clk.pin, 1);
  	F0cks_Delay_Us(1);
  	F0cks_GPIO_Write(handler->clk.port,handler->clk.pin, 0);
  	F0cks_Delay_Us(1);

  	tempo = (tempo >> 1);
  }

  F0cks_GPIO_Write(handler->din.port,   handler->din.pin,   0);
  F0cks_GPIO_Write(handler->load.port,	handler->load.pin,	1);
  F0cks_Delay_Us(1);
  F0cks_GPIO_Write(handler->load.port,	handler->load.pin,	0);
}
