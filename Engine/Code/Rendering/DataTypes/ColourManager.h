///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:55)

#ifndef RENDERING_DATA_TYPES_COLOUR_MANAGE_H
#define RENDERING_DATA_TYPES_COLOUR_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Colour.h"
#include "ColourDefaultTraits.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ColourManager
    {
    public:
        using ClassType = ColourManager;

    public:
        // 从8位通道创建一个32位RGB的颜色。alpha通道设置为255。
        NODISCARD static constexpr uint32_t MakeR8G8B8(uint8_t red, uint8_t green, uint8_t blue) noexcept
        {
            return MakeR8G8B8A8(red, green, blue, ColourDefaultTraits<uint8_t>::maxValue);
        }

        // 从8位通道创建一个32位RGB的颜色。
        NODISCARD static constexpr uint32_t MakeR8G8B8A8(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) noexcept
        {
#ifdef SYSTEM_BIG_ENDIAN
            return (alpha | (blue << 8) | (green << 16) | (red << 24));
#else  // !SYSTEM_BIG_ENDIAN
            return (red | (green << 8) | (blue << 16) | (alpha << 24));
#endif  // SYSTEM_BIG_ENDIAN
        }

        // 提取8位通道从32位RGBA颜色，alpha通道被忽略。
        NODISCARD static ByteColour ExtractR8G8B8(uint32_t color) noexcept;

        // 提取8位通道从32位RGBA颜色。
        NODISCARD static ByteColour ExtractR8G8B8A8(uint32_t color) noexcept;
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_MANAGE_H
