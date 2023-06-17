///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:55)

#ifndef RENDERING_DATA_TYPES_FWD_H
#define RENDERING_DATA_TYPES_FWD_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class Utility;

    enum class TextureFormat;

    template <typename T, typename Enable>
    struct ColourDefaultTraits;

    template <TextureFormat Format>
    struct ColourTextureFormatTraits;

    class ColourManager;
    class ColourConvertFrom;
    class ColourConvertTo;
    class HalfFloat;

    template <typename T>
    class Colour;

    using ByteColour = Colour<uint8_t>;
    using IntColour = Colour<int>;
    using FloatColour = Colour<float>;
    using DoubleColour = Colour<double>;

    template <TextureFormat Format>
    class TextureColour;

    template <typename T>
    class Bound;

    using BoundF = Bound<float>;
    using BoundD = Bound<double>;

    template <typename Real>
    class Transform;

    using TransformF = Transform<float>;
    using TransformD = Transform<double>;

    template <typename Real>
    class TransformMatrix;
}

#endif  // RENDERING_DATA_TYPES_FWD_H