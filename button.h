#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#define DEBOUNCE_TIME 50
class Button
{
 public:
	Button(int pin);
	uint8_t getState();
	void update();
 private:
    int _buttonState;
    int _lastButtonState=LOW;
    int _pin;
    unsigned long _lastDebounceTime = 0;
	unsigned long _debounceDelay = DEBOUNCE_TIME;
};

#endif // BUTTON_H_INCLUDED
