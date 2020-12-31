//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.2 (2020/09/17 15:40)

#ifndef RENDERING_DATA_TYPES_FWD_H
#define RENDERING_DATA_TYPES_FWD_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class Utility;

    enum class TextureFormat;

    class ColourManager;
    class ColourConvertFrom;
    class ColourConvertTo;
    class HalfFloat;

    template <typename T, typename Enable>
    struct ColourDefaultTraits;

    template <typename T>
    class Colour;

    using ByteColour = Colour<uint8_t>;
    using IntColour = Colour<int>;
    using FloatColour = Colour<float>;
    using DoubleColour = Colour<double>;

    template <TextureFormat Format>
    struct ColourTextureFormatTraits;

    template <TextureFormat Format>
    class TextureColour;

    template <typename T>
    class Bound;

    using FloatBound = Bound<float>;
    using DoubleBound = Bound<double>;

    template <typename Real>
    class Transform;

    using FloatTransform = Transform<float>;
    using DoubleTransform = Transform<double>;
}

#endif  // RENDERING_DATA_TYPES_FWD_H