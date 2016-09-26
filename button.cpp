#include "arduino.h"
#include "button.h"

Button::Button(int pin)
{
	_pin = pin;
  pinMode(pin,INPUT_PULLUP);
}

uint8_t Button::getState(void)
{
	return _buttonState;
}

void Button::update(void)
{
	int reading = digitalRead(_pin);

	if (reading != _lastButtonState) _lastDebounceTime = millis();

	if ((millis() - _lastDebounceTime) > _debounceDelay)
		if (reading != _buttonState) {
				_buttonState = reading;
				}
  _lastButtonState = reading;
}
