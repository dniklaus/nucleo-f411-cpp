/*
 * App.cpp
 *
 *  Created on: 18.05.2023
 *      Author: didi
 */
#include "main.h"
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_gpio.h>
#include <Timer.h>
#include <STM32UptimeInfoAdapter.h>
#include <LedBlinkTimerAdapter.h>
#include "App.h"

void toggleLed()
{
  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
}

App::App()
{ }

App::~App()
{ }

void App::setup()
{
  const unsigned long int cLedBlinkTimeMillis = 1000;
  UptimeInfo::Instance()->setAdapter(new STM32UptimeInfoAdapter());
  new Timer(new LedBlinkTimerAdapter(toggleLed), Timer::IS_RECURRING, cLedBlinkTimeMillis);
}

void App::loop()
{
  scheduleTimers();
}
