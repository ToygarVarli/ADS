#include "AdsWrapper.h"
#include "AdsLib.h"
#include "AdsVariable.h"
#include <iostream>
#include <vector>
#include <string>
#include <array>
/*void AdsWrapper::writeValue(AmsNetId remoteNetId, char remoteIpV4[], int16_t value, const char* symbolPath)
{
    try
    {
        AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
        AdsVariable<int16_t> simpleVar{route, symbolPath};

        simpleVar = value; // Değeri yaz

        std::cout << "Successfully wrote " << value << " to path: " << symbolPath << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error writing value: " << ex.what() << std::endl;
    }
}*/

extern "C"
{

    static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};                 // Statik ağ kimliği
    static char remoteIpV4[] = "192.168.110.107";                        // Statik IP adresi
    static AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3}; // Statik cihaz nesnesi





    void writeValueTestWrapper()
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};
        static char remoteIpV4[] = "192.168.110.107";

        int16_t value = 12345;
        std::string path = "ToygarMAIN.toygar";

        try
        {
            AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
            AdsVariable<int16_t> simpleVar{route, path};

            simpleVar = value;

            std::cout << "Successfully wrote " << value << " to path: " << path << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error writing value: " << ex.what() << std::endl;
        }
    }

    bool writeIntValueToPath(const char *symbolPath, uint16_t value)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};
        static char remoteIpV4[] = "192.168.110.107";

        try
        {
            AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
            AdsVariable<int16_t> simpleVar{route, symbolPath};

            simpleVar = value;

            std::cout << "Successfully wrote " << value << " to path: " << symbolPath << std::endl;
            return true;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error writing value: " << ex.what() << std::endl;
            return false;
        }
    }

    bool writeRealValueToPath(const char *symbolPath, float value)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};                 // Statik ağ kimliği
        static char remoteIpV4[] = "192.168.110.107";                        // Statik IP adresi
        static AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3}; // Statik cihaz nesnesi

        try
        {
            AdsVariable<float> simpleVar{route, symbolPath};

            simpleVar = value;

            std::cout << "Successfully wrote " << value << " to path: " << symbolPath << std::endl;
            return true;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error writing value: " << ex.what() << std::endl;
            return false;
        }
    }

    bool writeStringValueToPath(const char *symbolPath, const char *value)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};
        static char remoteIpV4[] = "192.168.110.107";

        try
        {
            AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
            AdsVariable<std::string> simpleVar{route, symbolPath};

            simpleVar = value;

            std::cout << "Successfully wrote " << value << " to path: " << symbolPath << std::endl;
            return true;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error writing value: " << ex.what() << std::endl;
            return false;
        }
    }

    uint16_t readInt16ValueFromPath(const char *symbolPath)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};
        static char remoteIpV4[] = "192.168.110.107";
        try
        {
            AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
            AdsVariable<uint16_t> readVar{route, symbolPath};

            return (uint16_t)readVar;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    float readRealValueFromPath(const char *symbolPath)
    {
        try
        {
            AdsVariable<float> readVar{route, symbolPath};
            return (float)readVar;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    float *readRealArrayFromPath(float *destination, const char *path, short size)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};                 
        static char remoteIpV4[] = "192.168.110.107";                        
        static AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3}; 

        try
        {
            AdsVariable<std::array<float, 10>> data{route, path};
            std::array<float, 10> array = data; // Veri al*/
            std::copy(array.begin(), array.end(), destination);

            if (array.size() < size)
            {
                std::cerr << "Hata: Alınan veri boyutu, istenen boyuttan küçük!" << std::endl;
                return nullptr;
            }

            std::copy(array.begin(), array.begin() + size, destination);

            /*for (size_t i = 0; i < size; ++i)
            {
                std::cout << destination[i] << " "; 
            }
            std::cout << std::endl;*/

            return destination;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Hata: " << e.what() << '\n';
            return nullptr;
        }
    }

    bool writeRealArrayToPath(float *source, const char *path, short size)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};                 // Uzak ağ kimliği
        static char remoteIpV4[] = "192.168.110.107";                        // Uzak IP adresi
        static AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3}; // Cihaz bağlantısı

        try
        {
            // Gönderilecek verileri std::array'e dönüştür
            std::array<float, 10> dataToSend = {0}; // std::array sabit boyutlu olduğu için 10 elemanlı olarak tanımlanmalı
            if (size > 10)
            {
                std::cerr << "Hata: Gönderilecek veri boyutu 10'dan büyük olamaz!" << std::endl;
                return false;
            }

            // Kaynak diziyi std::array'e kopyala
            std::copy(source, source + size, dataToSend.begin());

            // AdsVariable kullanarak veriyi yaz
            AdsVariable<std::array<float, 10>> data{route, path};
            data = dataToSend; // Veriyi PLC'ye yaz

            // Yazılan veriyi ekrana yazdır
            std::cout << "PLC'ye yazılan veriler: ";
            for (const auto &val : dataToSend)
            {
                std::cout << val << " ";
            }
            std::cout << std::endl;

            return true;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Hata: " << e.what() << '\n';
            return false;
        }
    }

    void copyRealArray(float *destination, const float *source, short numElements)
    {
        // memcpy işlevini burada doğrudan kullanabilirsiniz
        std::memcpy(destination, source, numElements * sizeof(float));
    }
    void freeRealArray(float *array)
    {
        free(array);
    }

    const char *readStringValueFromPath(const char *symbolPath)
    {
        static AmsNetId remoteNetId{169, 254, 53, 70, 1, 1};
        static char remoteIpV4[] = "192.168.110.107";
        try
        {
            AdsDevice route{remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
            AdsVariable<std::string> readVar{route, symbolPath};
            std::string strValue = readVar; // readVar'dan std::string al
            return strValue.c_str();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}