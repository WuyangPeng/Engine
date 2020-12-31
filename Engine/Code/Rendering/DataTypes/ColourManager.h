//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.0 (2020/08/18 22:30)

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
        // ��8λͨ������һ��32λRGB����ɫ��alphaͨ������Ϊ255��
        static constexpr uint32_t MakeR8G8B8(uint8_t red, uint8_t green, uint8_t blue) noexcept
        {
            return MakeR8G8B8A8(red, green, blue, ColourDefaultTraits<uint8_t>::sm_MaxValue);
        }

        // ��8λͨ������һ��32λRGB����ɫ��
        static constexpr uint32_t MakeR8G8B8A8(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) noexcept
        {
#ifdef SYSTEM_BIG_ENDIAN
            return (alpha | (blue << 8) | (green << 16) | (red << 24));
#else  // !SYSTEM_BIG_ENDIAN
            return (red | (green << 8) | (blue << 16) | (alpha << 24));
#endif  // SYSTEM_BIG_ENDIAN
        }

        // ��ȡ8λͨ����32λRGBA��ɫ��alphaͨ�������ԡ�
        static ByteColour ExtractR8G8B8(uint32_t color) noexcept;

        // ��ȡ8λͨ����32λRGBA��ɫ��
        static ByteColour ExtractR8G8B8A8(uint32_t color) noexcept;
    };
}

#endif  // RENDERING_DATA_TYPES_COLOUR_MANAGE_H
