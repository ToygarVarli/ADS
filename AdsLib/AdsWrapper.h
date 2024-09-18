#ifdef BUILDING_DLL
#define ADSWRAPPER_API __declspec(dllexport)
#else 
#define ADSWRAPPER_API __declspec(dllimport)
#endif


#ifndef ADSWRAPPER_H
#define ADSWRAPPER_H

#include "AdsLib.h"
#include <string>


#ifdef __cplusplus
extern "C" {
#endif



// writeValue fonksiyonu için basitleştirilmiş versiyon


// writeValueTest fonksiyonu için basitleştirilmiş versiyon
ADSWRAPPER_API void writeValueTest();

#ifdef __cplusplus
}
#endif



class AdsWrapper {
public:
    AdsWrapper();
    ~AdsWrapper();

     void writeValue(AmsNetId remoteNetId, char remoteIpV4[], int16_t value, const std::string& symbol);
     //void writeValueTest();
};

#endif // ADSWRAPPER_H