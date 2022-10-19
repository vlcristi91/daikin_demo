#include "AcController.h"
#include <unistd.h>


int main()
{
    AcController AcController;

    while(true)
    {
        AcController.cycle();
        
        // cycle time is 100 us
        constexpr useconds_t CYCLE_TIME_U_SEC = 100000U; 
        usleep(CYCLE_TIME_U_SEC);
    }

    return 0;
}