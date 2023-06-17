///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:55)

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
