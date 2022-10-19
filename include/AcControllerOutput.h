#include "IAcControllerOutput.h"


class AcControllerOutput : public IAcControllerOutput
{
public:
    AcControllerOutput();

    // int demand is a value betwwen -100 and 100 descibing the cooling or heating intensity required.
    // -100 being max cooling, 0 meaning off and 100 meaning max heating.
    void setCoolingHeatingDemand(int demand) override { _demand = demand;}
    void cycle() override;

private:
    int _demand;

};