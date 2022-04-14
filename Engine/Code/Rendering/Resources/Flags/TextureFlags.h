///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/30 10:25)

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
    enum
    {
        TextureMaximumMipmapLevels = 16
    };

    // �û��ֶΡ���Щ���������ڴ洢�ض���Ӧ�ó����δ֪��Ϣ�ṹ�ࡣ
    enum
    {
        TextureMaxUserFields = 8
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_FLAGS_H
