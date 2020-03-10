// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/17 14:06)

#ifndef RENDERING_DATA_TYPES_COLOUR_CONVERT_FROM_H
#define RENDERING_DATA_TYPES_COLOUR_CONVERT_FROM_H

#include "Rendering/RenderingDll.h"

#include "Colour.h"
#include "Flags/TextureFormat.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ColourConvertFrom
    {
    public:
		using ClassType = ColourConvertFrom;
        using FloatColour = Colour<float>;
        using ByteColour = Colour<unsigned char>;
        
    public:
		enum
		{
			ConvertFromQuantity = TextureFormat::Quantity
		};
		
        // �����߱��뱣֤inTexels��outTexels������Ч��
        // ��ָ���ĸ�ʽת����Colour<float>��
        
        // outTexels�ĳ���ΪnumOutTexels��
        
        // inTexels�ĳ���ΪnumOutTexels * 2��
        static void ConvertFromR5G6B5 (int numOutTexels, const char* inTexels,FloatColour* outTexels);
        
        // inTexels�ĳ���ΪnumOutTexels * 2��
        static void ConvertFromA1R5G5B5 (int numOutTexels, const char* inTexels,FloatColour* outTexels);
        
        // inTexels�ĳ���ΪnumOutTexels * 2��
        static void ConvertFromA4R4G4B4 (int numOutTexels, const char* inTexels,FloatColour* outTexels);
        
        // inTexels�ĳ���ΪnumOutTexels��
        static void ConvertFromA8 (int numOutTexels, const char* inTexels,FloatColour* outTexels);
        
        // inTexels�ĳ���ΪnumOutTexels��
        static void ConvertFromL8 (int numOutTexels, const char* inTexels,FloatColour* outTexels);
        
        // inTexels�ĳ���ΪnumOutTexels * 2��
        static void ConvertFromA8L8 (int numOutTexels, const char* inTexels, FloatColour* outTexels);
  
        // inTexels�ĳ���ΪnumOutTexels * 3��
        static void ConvertFromR8G8B8 (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 4��
        static void ConvertFromA8R8G8B8 (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 4��
        static void ConvertFromA8B8G8R8 (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 2��
        static void ConvertFromL16 (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 4��
        static void ConvertFromG16R16 (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 8��
        static void ConvertFromA16B16G16R16 (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 2��
        static void ConvertFromR16F (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 4��
        static void ConvertFromG16R16F (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 8��
        static void ConvertFromA16B16G16R16F (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 4��
        static void ConvertFromR32F (int numOutTexels, const char* inTexels,FloatColour* outTexels);

        // inTexels�ĳ���ΪnumOutTexels * 8��
        static void ConvertFromG32R32F (int numOutTexels, const char* inTexels,FloatColour* outTexels);
        
        // inTexels�ĳ���ΪnumOutTexels * 16��
        static void ConvertFromA32B32G32R32F (int numOutTexels, const char* inTexels, FloatColour* outTexels);

    
         // �����Һ���ʱ��Ϊ��Ӧ�ó���ı����ԡ�
        using ConvertFromFunction = void (*)(int, const char*, FloatColour*);
        static ConvertFromFunction sm_FromFunction[ConvertFromQuantity];
    };
}

#endif // RENDERING_DATA_TYPES_COLOUR_CONVERT_FROM_H
