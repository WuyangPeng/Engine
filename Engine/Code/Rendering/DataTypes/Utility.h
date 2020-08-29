//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/18 15:48)

#ifndef RENDERING_DATA_TYPES_UTILITY_H
#define RENDERING_DATA_TYPES_UTILITY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/BaseFwd.h"

#include <vector>

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Utility
    {
    public:
        using ClassType = Utility;
        using PixelType = std::vector<char>;
        using PixelTypeIter = PixelType::iterator;
        using SpanIterator = CoreTools::SpanIterator<PixelTypeIter>;

    public:
        // x方向为xSize * numBytesPerPixel，y方向为ySize。
        static void ReflectX(PixelTypeIter begin, PixelTypeIter end, int xSize, int ySize, int numBytesPerPixel);
        static void ReflectY(PixelTypeIter begin, PixelTypeIter end, int xSize, int ySize, int numBytesPerPixel);

    private:
        static constexpr int GetNumBytes(int xSize, int ySize, int numBytesPerPixel) noexcept
        {
            return xSize * ySize * numBytesPerPixel;
        }

        static void ReflectX(const SpanIterator& lhs, const SpanIterator& rhs, int xSize, int numBytesPerPixel);
        static void ReflectY(const SpanIterator& lhs, const SpanIterator& rhs, int xSize, int numBytesPerPixel);
    };
}

#endif  // RENDERING_DATA_TYPES_UTILITY_H
