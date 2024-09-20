#include "AdsWrapper.h"
#include "AdsLib.h"
#include "AdsVariable.h"
#include <iostream>

AdsWrapper::AdsWrapper()
{
    // Constructor implementation
}

AdsWrapper::~AdsWrapper()
{
    // Destructor implementation
}

void AdsWrapper::writeValue(AmsNetId remoteNetId, char remoteIpV4[], int16_t value, const std::string &symbol)
{
    try
    {
        AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
        AdsVariable<int16_t> simpleVar{route, symbol};

        simpleVar = value; // Değeri yaz

        std::cout << "Successfully wrote " << value << " to symbol: " << symbol << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error writing value: " << ex.what() << std::endl;
    }
}

extern "C"
{
    void writeValueTestWrapper()
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};
        static char remoteIpV4[] = "192.168.110.107";

        int16_t value = 12345;
        std::string symbol = "ToygarMAIN.toygar";

        try
        {
            AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
            AdsVariable<int16_t> simpleVar{route, symbol};

            simpleVar = value;

            std::cout << "Successfully wrote " << value << " to symbol: " << symbol << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error writing value: " << ex.what() << std::endl;
        }
    }

    bool writeIntValueToPath(const std::string &path, int16_t value)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};
        static char remoteIpV4[] = "192.168.110.107";

        try
        {
            AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
            AdsVariable<int16_t> simpleVar{route, symbol};

            simpleVar = value;

            std::cout << "Successfully wrote " << value << " to symbol: " << symbol << std::endl;
            return true;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error writing value: " << ex.what() << std::endl;
            return false;
        }
    }

    bool writeDoubleValueToPath(const std::string &&symbol, double_t value)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};
        static char remoteIpV4[] = "192.168.110.107";

        try
        {
            AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
            AdsVariable<double_t> simpleVar{route, symbol};

            simpleVar = value;

            std::cout << "Successfully wrote " << value << " to symbol: " << symbol << std::endl;
            return true;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error writing value: " << ex.what() << std::endl;
            return false;
        }
    }

    bool writeStringValueToPath(const std::string &&symbol, const std::string &&value)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};
        static char remoteIpV4[] = "192.168.110.107";

        try
        {
            AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
            AdsVariable<std::string> simpleVar{route, symbol};

            simpleVar = value;

            std::cout << "Successfully wrote " << value << " to symbol: " << symbol << std::endl;
            return true;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error writing value: " << ex.what() << std::endl;
            return false;
        }
    }

    bool readIntValueFromPath(const std::string& path)
    {
        
    }

}