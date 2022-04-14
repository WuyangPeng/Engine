///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 13:16)

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
