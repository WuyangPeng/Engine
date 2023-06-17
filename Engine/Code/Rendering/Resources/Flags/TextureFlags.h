///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:24)

#ifndef RENDERING_RESOURCES_TEXTURE_FLAGS_H
#define RENDERING_RESOURCES_TEXTURE_FLAGS_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    enum class TextureFlags
    {
        Texture1D,
        Texture2D,
        Texture3D,
        TextureCube,
        Quantity
    };

    // �����������������mipmap�������ڵ����Կ��㹻�ࡣ
    // һ��4096 x 40096ͼ����һ������13�ȼ���
    constexpr auto textureMaximumMipmapLevels = 16;

    // �û��ֶΡ���Щ���������ڴ洢�ض���Ӧ�ó����δ֪��Ϣ�ṹ�ࡣ
    enum
    {
        TextureMaxUserFields = 8
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_FLAGS_H
