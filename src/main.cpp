#include <cstdint>
#include <iostream>

#include "progress.h"

int main()
{
    Progress progress("test");

    uint32_t total = 100000;
    progress.set_total(total);
    for (uint32_t i = 0; i < total; i++)
    {
        progress.update(i);
        progress.print();
    }
}
