// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/18 11:20)

#ifndef RENDERING_DATA_TYPES_UTILITY_H
#define RENDERING_DATA_TYPES_UTILITY_H

#include "Rendering/RenderingDll.h"

// Utility类只包含静态函数。

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Utility
    {
    public:
		using ClassType = Utility;
        
    public:
		// pixels数组大小为x方向为xSize * numBytesPerPixel，
		// y方向为ySize
        static void ReflectX (int xSize, int ySize,int numBytesPerPixel,char* pixels);

        static void ReflectY (int xSize, int ySize,int numBytesPerPixel,char* pixels);
    };
}

#endif // RENDERING_DATA_TYPES_UTILITY_H
