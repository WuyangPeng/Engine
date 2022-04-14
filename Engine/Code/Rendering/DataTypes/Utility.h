///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/29 11:03)

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
        // x����ΪxSize * numBytesPerPixel��y����ΪySize��
        static void ReflectX(PixelTypeIter begin, PixelTypeIter end, int xSize, int ySize, int numBytesPerPixel);
        static void ReflectY(PixelTypeIter begin, PixelTypeIter end, int xSize, int ySize, int numBytesPerPixel);

    private:
        NODISCARD static constexpr int GetNumBytes(int xSize, int ySize, int numBytesPerPixel) noexcept
        {
            return xSize * ySize * numBytesPerPixel;
        }

        static void ReflectX(const SpanIterator& lhs, const SpanIterator& rhs, int xSize, int numBytesPerPixel);
        static void ReflectY(const SpanIterator& lhs, const SpanIterator& rhs, int xSize, int numBytesPerPixel);
    };
}

#endif  // RENDERING_DATA_TYPES_UTILITY_H
