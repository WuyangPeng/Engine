///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:55)

#ifndef RENDERING_DATA_TYPES_COLOUR_CONVERT_FROM_DETAIL_H
#define RENDERING_DATA_TYPES_COLOUR_CONVERT_FROM_DETAIL_H

#include "ColourConvertFrom.h"
#include "HalfFloat.h"

template <Rendering::TextureFormat Format>
float Rendering::ColourConvertFrom::GetHalfFloat(SpanConstIterator& source)
{
    using BytesType = typename ColourTextureFormatTraits<Format>::BytesType;

    auto result = source.Increase<BytesType>();

    const HalfFloat halfFloat{ result };

    return halfFloat.ToFloat();
}

#endif  // RENDERING_DATA_TYPES_COLOUR_CONVERT_FROM_DETAIL_H
