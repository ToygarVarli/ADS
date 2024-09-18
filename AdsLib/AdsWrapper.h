#ifndef ADSWRAPPER_H
#define ADSWRAPPER_H

#include "AdsLib.h"
#include <string>

class AdsWrapper {
public:
    AdsWrapper();
    ~AdsWrapper();

    void writeValue(AmsNetId remoteNetId, char remoteIpV4[], int16_t value, const std::string& symbol);
    void writeValueTest();
};

#endif // ADSWRAPPER_H
