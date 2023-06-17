///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:42)

#ifndef RENDERING_SHADERS_ALPHA_STATE_FLAGS_H
#define RENDERING_SHADERS_ALPHA_STATE_FLAGS_H

namespace Rendering
{
    namespace AlphaStateFlags
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
}

#endif  // RENDERING_SHADERS_ALPHA_STATE_FLAGS_H
