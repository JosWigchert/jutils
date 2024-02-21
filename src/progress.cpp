#include <cmath>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

#include "progress.h"

Progress::Progress(const std::string& name)
    : _name(name)
{
}

Progress::~Progress()
{
}

void Progress::set_total(uint32_t total)
{
    _total = total;
}

void Progress::update(uint32_t current)
{
    _current = current;

    uint8_t bar_index = (_current / _total) / 100;
    std::cout << (int)bar_index << std::endl;

    if (_current_bar_index != bar_index)
    {
        _current_bar_index = bar_index;
        print();
    }
}

void Progress::print()
{
    std::string progress;
    get_progress_string(progress);
    std::cout << "\r" << progress;

}

uint8_t Progress::num_digits(uint32_t value)
{
    return 1 + floor(log10(value));
}

void Progress::get_progress_string(std::string& progress)
{
    uint8_t current_digits = num_digits(_current);
    uint8_t total_digits = num_digits(_total);

    std::stringstream ss;
    ss << _name << " [";

    for (int i = 0; i < bar_length; i++) 
    {
        if (_current > ((_total / bar_length) * (i + 1)))
        {
            ss << "=";
        }
        else
        {
            ss << "-";
        }
    }

    ss << "] ";
    
    uint8_t percentage = (uint8_t)(((float)_current / (float)_total) * 100.0);
    uint8_t percentage_digits = num_digits(percentage);

    for (int i = percentage_digits; i < 3; i++)
    {
        ss << " ";
    }
    ss << (int)percentage << "% | ";


    for (int i = total_digits - current_digits; i > 0; i--)
    {
        ss << " ";
    }

    ss << _current << "/" << _total;

    progress = ss.str();
}
