#include "Solution1.h"

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_1

float Solution1::ConvertTemperature(float _value, TemperatureUnits _from, TemperatureUnits _to)
{
	/*
	 * Exercice 1 : Temperature Converter
	 *
	 * This exercice aim to create a temperature converter between Celsius, Fahrenheit and Kelvin.
	 * An enum TemperatureUnits is provided to help you.
	 * All result will be approximated to 2 decimals for testing purpose.
	 *
	 * CONVERSION FORMULAS :
	 *		Celsius to Fahrenheit �F = 9/5 (�C) + 32
	 *		Kelvin to Fahrenheit �F = 9/5 (K - 273) + 32
	 *		Fahrenheit to Celsius �C = 5/9 (�F - 32)
	 *		Celsius to Kelvin K = �C + 273
	 *		Kelvin to Celsius �C = K - 273
	 *		Fahrenheit to Kelvin K = 5/9 (�F - 32) + 273
	 */
	float result;
	switch(_from){
		case TemperatureUnits::CELSIUS:
			switch(_to){
				case TemperatureUnits::FAHRENHEIT:
					result = 9 / 5 * (_value)+32;
					return result;
				case TemperatureUnits::KELVIN:
					result = _value + 273;
					return result;
			}
		case TemperatureUnits::KELVIN:
			switch (_to)
			{
			case TemperatureUnits::FAHRENHEIT:
				result = 9/5 * (_value - 273) + 32;
			case TemperatureUnits::CELSIUS:
				result = _value - 273;
			}
		case TemperatureUnits::FAHRENHEIT:
			switch (_to)
			{
			case TemperatureUnits::KELVIN:
				result = 5/9  * (_value - 32) + 273;
			case TemperatureUnits::CELSIUS:
				result = 5/9 * (_value - 32);
			}
	}
	return result;
}

#endif
