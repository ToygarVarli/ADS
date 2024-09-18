#include "AdsWrapper.h"
#include "AdsLib.h"
#include "AdsVariable.h"
#include <iostream>

AdsWrapper::AdsWrapper() {
    // Constructor implementation
}

AdsWrapper::~AdsWrapper() {
    // Destructor implementation
}

void AdsWrapper::writeValue(AmsNetId remoteNetId, char remoteIpV4[], int16_t value, const std::string& symbol) {
    try {
        //static const AmsNetId remoteNetId { 169,254,53,70,1,1 };
         //static const char remoteIpV4[] = "192.168.110.107";
        AdsDevice route {remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
        AdsVariable<int16_t> simpleVar {route, symbol};

        simpleVar = value;  // Değeri yaz

        std::cout << "Successfully wrote " << value << " to symbol: " << symbol << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error writing value: " << ex.what() << std::endl;
    }
}


void AdsWrapper::writeValueTest(){
    static AmsNetId remoteNetId { 169,254,53,70,1,1 };
    static char remoteIpV4[] = "192.168.110.107"; 
    AdsWrapper adsWrapper;

    // Remote PLC bilgileri
     int16_t value = 12345;                        
     std::string symbol = "ToygarMAIN.toygar";  

     try {
        //static const AmsNetId remoteNetId { 169,254,53,70,1,1 };
         //static const char remoteIpV4[] = "192.168.110.107";
        AdsDevice route {remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
        AdsVariable<int16_t> simpleVar {route, symbol};

        simpleVar = value;  // Değeri yaz

        std::cout << "Successfully wrote " << value << " to symbol: " << symbol << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error writing value: " << ex.what() << std::endl;
    }
}