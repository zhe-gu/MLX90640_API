#pragma once

#ifdef MLX90640API_EXPORTS
	#define DLL_API __declspec(dllexport)
#else
	#define DLL_API __declspec(dllimport)
#endif

/* exact-width signed integer types */
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed int int32_t;

/* exact-width unsigned integer types */
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;

extern "C" {
    #define SCALEALPHA 0.000001

    #pragma pack(1)
    typedef struct
    {
        int16_t kVdd;
        int16_t vdd25;
        float KvPTAT;
        float KtPTAT;
        uint16_t vPTAT25;
        float alphaPTAT;
        int16_t gainEE;
        float tgc;
        float cpKv;
        float cpKta;
        uint8_t resolutionEE;
        uint8_t calibrationModeEE;
        float KsTa;
        float ksTo[5];
        int16_t ct[5];
        uint16_t alpha[768];
        uint8_t alphaScale;
        int16_t offset[768];
        int8_t kta[768];
        uint8_t ktaScale;
        int8_t kv[768];
        uint8_t kvScale;
        float cpAlpha[2];
        int16_t cpOffset[2];
        float ilChessC[3];
        uint16_t brokenPixels[5];
        uint16_t outlierPixels[5];
    } paramsMLX90640;

    DLL_API int MLX90640_ExtractParameters(uint16_t* eeData, paramsMLX90640* mlx90640);
    DLL_API float MLX90640_GetVdd(uint16_t* frameData, const paramsMLX90640* params);
    DLL_API float MLX90640_GetTa(uint16_t* frameData, const paramsMLX90640* params);
    DLL_API void MLX90640_GetImage(uint16_t* frameData, const paramsMLX90640* params, float* result);
    DLL_API void MLX90640_CalculateTo(uint16_t* frameData, const paramsMLX90640* params, float emissivity, float tr, float* result);
    DLL_API int MLX90640_GetSubPageNumber(uint16_t* frameData);
    DLL_API void MLX90640_BadPixelsCorrection(uint16_t* pixels, float* to, int mode, paramsMLX90640* params);
}
