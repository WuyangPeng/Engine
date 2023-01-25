///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/29 11:33)

#ifndef RENDERING_DATA_TYPES_TEXTURE_FORMAT_H
#define RENDERING_DATA_TYPES_TEXTURE_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumOperator.h"

#include <iostream>

namespace Rendering
{
    // Ŀǰ֧�ֵĸ�ʽ��������Ҫ������ӡ�
    enum class TextureFormat
    {
        First = 0,

        None = First,

        // Сλ��ɫ��ʽ
        R5G6B5 = 1,
        A1R5G5B5 = 2,
        A4R4G4B4 = 3,

        // 8λ���͸�ʽ
        A8 = 4,
        L8 = 5,
        A8L8 = 6,
        R8G8B8 = 7,
        A8R8G8B8 = 8,
        A8B8G8R8 = 9,

        // 16λ���͸�ʽ
        L16 = 10,
        G16R16 = 11,
        A16B16G16R16 = 12,

        // 16λ�����ʽ���븡��������
        R16F = 13,
        G16R16F = 14,
        A16B16G16R16F = 15,

        // 32λ�����ʽ������������
        R32F = 16,
        G32R32F = 17,
        A32B32G32R32F = 18,

        // DXTѹ����ʽ
        DXT1 = 19,
        DXT3 = 20,
        DXT5 = 21,

        // ���ģ���ʽ��
        D24S8 = 22,

        DefaultColour = A8R8G8B8,
        DefaultDepth = D24S8,

        Quantity = 23,

        Max = Quantity
    };

}

#endif  // RENDERING_DATA_TYPES_TEXTURE_FORMAT_H
