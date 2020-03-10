// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/17 14:08)

#ifndef RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_H
#define RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_H

#include "Rendering/RenderingDll.h"

#include "Colour.h"
#include "Flags/TextureFormat.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ColourConvertTo
    {
    public:
		using ClassType = ColourConvertTo;
        using FloatColour = Colour<float>;
        using ByteColour = Colour<unsigned char>;
        
    public:
		enum
		{
			ConvertToQuantity = TextureFormat::Quantity
		};
        
        // �����߱��뱣֤inTexels��outTexels������Ч��
        // ��32λ��RGBAת����ָ���ĸ�ʽ��
        
        // inTexels�ĳ���ΪnumInTexels��
  
        // outTexels�ĳ���ΪnumInTexels * 2��
        static void ConvertToR5G6B5 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 2��
        static void ConvertToA1R5G5B5 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 2��
        static void ConvertToA4R4G4B4 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels��
        static void ConvertToA8 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels��
        static void ConvertToL8 (int numInTexels, const FloatColour* inTexels, char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 2��
        static void ConvertToA8L8 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 3��
        static void ConvertToR8G8B8 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 4��
        static void ConvertToA8R8G8B8 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 4��
        static void ConvertToA8B8G8R8 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 2��
        static void ConvertToL16 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 4��
        static void ConvertToG16R16 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 8��
        static void ConvertToA16B16G16R16 (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 2��
        static void ConvertToR16F (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 4��
        static void ConvertToG16R16F (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 8��
        static void ConvertToA16B16G16R16F (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 4��
        static void ConvertToR32F (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 8��
        static void ConvertToG32R32F (int numInTexels, const FloatColour* inTexels,char* outTexels);

        // outTexels�ĳ���ΪnumInTexels * 16��
        static void ConvertToA32B32G32R32F (int numInTexels, const FloatColour* inTexels,char* outTexels);
        
        using ConvertToFunction = void (*)(int, const FloatColour*, char*);
        static ConvertToFunction sm_ToFunction[ConvertToQuantity];
   };
}

#endif // RENDERING_DATA_TYPES_COLOUR_CONVERT_TO_H
