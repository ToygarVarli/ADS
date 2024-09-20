#ifndef ADSWRAPPER_H
#define ADSWRAPPER_H

#include "AdsLib.h"
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

// writeValueTest fonksiyonu için basitleştirilmiş versiyon
void writeValueTestWrapper();

bool writeIntValueToPath(const std::string& path ,int16_t value );
bool writeDoubleValueToPath(const std::string&& symbol , double_t value);
bool writeStringValueToPath(const std::string& symbol,const std::string& value);
bool readIntValueFromPath(const std::string& path);
bool readDoubleValueFromPath(const std::string& path);
bool readStringValueFromPath(const std::string& path); 
#ifdef __cplusplus
}
#endif

class AdsWrapper {
public:
    AdsWrapper();
    ~AdsWrapper();

    void writeValue(AmsNetId remoteNetId, char remoteIpV4[], int16_t value, const std::string& symbol);
};

#endif // ADSWRAPPER_H
