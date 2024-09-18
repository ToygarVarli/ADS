#include "AdsWrapper.h"
#include "AdsLib.h"
#include "AdsNotificationOOI.h"
#include "AdsVariable.h"

#include <array>
#include <cstring>
#include <iostream>
#include <iomanip>

AdsWrapper::AdsWrapper() : m_value(0) {
    // Constructor implementation
}

AdsWrapper::~AdsWrapper() {
    // Destructor implementation
}

void AdsWrapper::writeValue(int value) {
    m_value = value;

    static const AmsNetId remoteNetId { 169,254,53,70,1,1 };
    static const char remoteIpV4[] = "192.168.110.107";

    AdsDevice route {remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
    AdsVariable<uint8_t> simpleVar {route, "ToygarMAIN.toygar[0]"};
    AdsVariable<uint8_t> validation {route, "ToygarMAIN.toygar[0]"};

    //out << __FUNCTION__ << "():\n";
    simpleVar = 0xA5;
    //out << "Wrote " << 0xA5 << " to MAIN.byByte and read " << (uint32_t)validation << " back\n";
    simpleVar = 0x5A;
    //out << "Wrote " << (uint32_t)simpleVar << " to MAIN.byByte and read " << (uint32_t)validation << " back\n";
}

