//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/18 21:28)

#ifndef RENDERING_DATA_TYPES_FWD_H
#define RENDERING_DATA_TYPES_FWD_H

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