/*
 * LedBlinkTimerAdapter.h
 *
 *  Created on: 18.05.2023
 *      Author: didi
 */

#ifndef LEDBLINKTIMERADAPTER_H_
#define LEDBLINKTIMERADAPTER_H_

#include <functional>
#include <Timer.h>

class LedBlinkTimerAdapter: public TimerAdapter
{
private:
  std::function<void(void)> m_Callback;

public:
  LedBlinkTimerAdapter(std::function<void(void)> callback)
  : m_Callback(callback)
  { }

  virtual ~LedBlinkTimerAdapter() { }

  void timeExpired()
  {
    m_Callback();
  }
};

#endif /* LEDBLINKTIMERADAPTER_H_ */
