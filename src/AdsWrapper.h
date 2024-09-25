#ifndef ADSWRAPPER_H
#define ADSWRAPPER_H

#include <cstdint>
#include <cstring>
#include <vector>
#include <string>

#ifdef __cplusplus
extern "C"
{
#endif

    bool IsAdsRouteAvailable();
    bool CreateAdsRoute();


    bool writeRealValueToPath(const char *symbolPath, float value);
    float readRealValueFromPath(const char *symbolPath);

    float *readRealArrayFromPath(float *destination, const char *path, short size);
    bool writeRealArrayToPath(float *source, const char *path, short size);

    void freeRealArray(float *array);

    /*
    void writeValueTestWrapper();
    getVariablesFromDEviceBySearchTerm(const  char* searchTerm)
    float *readRealArrayFromPath(const char *path, short size);
    void copyRealArray(float *destination, const float *source, short numElements);
    bool writeIntValueToPath(const char* symbolPath, uint16_t value);
    double readDoubleValueFromPath(const char* symbolPath);
    bool writeStringValueToPath(const char* symbolPath, const char* value);
    uint16_t readInt16ValueFromPath(const char* symbolPath);
    const char* readStringValueFromPath(const char* symbolPath);
    */

#ifdef __cplusplus
}
#endif

#endif // ADSWRAPPER_H
