///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/01 14:55)

#ifndef RENDERING_SHADERS_ALPHA_STATE_FLAGS_H
#define RENDERING_SHADERS_ALPHA_STATE_FLAGS_H

namespace Rendering::AlphaStateFlags
{

    enum class SourceBlendMode
    {
        Zero,
        One,
        DestinationColor,
        OneMinusDestinationColor,
        SourceAlpha,
        OneMinusSourceAlpha,
        DestinationAlpha,
        OneMinusDestinationAlpha,
        SourceAlphaSaturate,
        ConstantColor,
        OneMinusConstantColor,
        ConstantAlpha,
        OneMinusConstantAlpha,

        Quantity
    };

    enum class DestinationBlendMode
    {
        Zero,
        One,
        SourceColor,
        OneMinusSourceColor,
        SourceAlpha,
        OneMinusSourceAlpha,
        DestinationAlpha,
        OneMinusDestinationAlpha,
        ConstantColor,
        OneMinusConstantColor,
        ConstantAlpha,
        OneMinusConstantAlpha,

        Quantity
    };

    enum class CompareMode
    {
        Never,
        Less,
        Equal,
        LessEqual,
        Greater,
        NotEqual,
        GreaterEqual,
        Always,

        Quantity
    };
}

#endif  // RENDERING_SHADERS_ALPHA_STATE_FLAGS_H
