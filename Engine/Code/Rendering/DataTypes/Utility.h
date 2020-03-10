// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/18 11:20)

#ifndef RENDERING_DATA_TYPES_UTILITY_H
#define RENDERING_DATA_TYPES_UTILITY_H

#include "Rendering/RenderingDll.h"

// Utility��ֻ������̬������

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Utility
    {
    public:
		using ClassType = Utility;
        
    public:
		// pixels�����СΪx����ΪxSize * numBytesPerPixel��
		// y����ΪySize
        static void ReflectX (int xSize, int ySize,int numBytesPerPixel,char* pixels);

        static void ReflectY (int xSize, int ySize,int numBytesPerPixel,char* pixels);
    };
}

#endif // RENDERING_DATA_TYPES_UTILITY_H
