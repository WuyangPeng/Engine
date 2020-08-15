// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/17 14:14)

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
        // ��8λͨ������һ��32λRGB����ɫ��alphaͨ������Ϊ255��
        static constexpr unsigned int MakeR8G8B8(unsigned char red, unsigned char green, unsigned char blue) noexcept
        {
            return MakeR8G8B8A8(red, green, blue, 255);
        }

        // ��8λͨ������һ��32λRGB����ɫ��
        static constexpr unsigned int MakeR8G8B8A8(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) noexcept
        {
#ifdef SYSTEM_BIG_ENDIAN
            return (alpha | (blue << 8) | (green << 16) | (red << 24));
#else  // !SYSTEM_BIG_ENDIAN
            return (red | (green << 8) | (blue << 16) | (alpha << 24));
#endif  // SYSTEM_BIG_ENDIAN
        }

        // ��ȡ8λͨ����32λRGBA��ɫ��alphaͨ�������ԡ�
        static void ExtractR8G8B8(unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue) noexcept;

        // ��ȡ8λͨ����32λRGBA��ɫ��
        static void ExtractR8G8B8A8(unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue, unsigned char& alpha) noexcept;
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_MANAGE_H
