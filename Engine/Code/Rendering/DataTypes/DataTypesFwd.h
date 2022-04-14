///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/28 18:25)

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