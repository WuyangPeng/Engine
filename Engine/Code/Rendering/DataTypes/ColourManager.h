// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/17 14:14)

#ifndef RENDERING_DATA_TYPES_COLOUR_MANAGE_H
#define RENDERING_DATA_TYPES_COLOUR_MANAGE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ColourManager
    {
    public:
        typedef ColourManager ClassType;

    public:
        // 从8位通道创建一个32位RGB的颜色。alpha通道设置为255。
        static constexpr unsigned int MakeR8G8B8(unsigned char red, unsigned char green, unsigned char blue) noexcept
        {
            return MakeR8G8B8A8(red, green, blue, 255);
        }

        // 从8位通道创建一个32位RGB的颜色。
        static constexpr unsigned int MakeR8G8B8A8(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) noexcept
        {
#ifdef SYSTEM_BIG_ENDIAN
            return (alpha | (blue << 8) | (green << 16) | (red << 24));
#else  // !SYSTEM_BIG_ENDIAN
            return (red | (green << 8) | (blue << 16) | (alpha << 24));
#endif  // SYSTEM_BIG_ENDIAN
        }

        // 提取8位通道从32位RGBA颜色，alpha通道被忽略。
        static void ExtractR8G8B8(unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue) noexcept;

        // 提取8位通道从32位RGBA颜色。
        static void ExtractR8G8B8A8(unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue, unsigned char& alpha) noexcept;
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_MANAGE_H
