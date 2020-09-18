//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/17 15:40)

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
    class RENDERING_TEMPLATE_DEFAULT_DECLARE Colour;

    using ByteColour = Colour<uint8_t>;
    using IntColour = Colour<int>;
    using FloatColour = Colour<float>;
    using DoubleColour = Colour<double>;

    template <TextureFormat Format>
    struct ColourTextureFormatTraits;

    template <TextureFormat Format>
    class TextureColour;

    template <typename T>
    class RENDERING_TEMPLATE_DEFAULT_DECLARE Bound;

    using FloatBound = Bound<float>;
    using DoubleBound = Bound<double>;

    template <typename Real>
    class RENDERING_TEMPLATE_DEFAULT_DECLARE Transform;

    using FloatTransform = Transform<float>;
    using DoubleTransform = Transform<double>;
}

#endif  // RENDERING_DATA_TYPES_FWD_H