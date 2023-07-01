///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 11:27)

#ifndef RENDERING_RESOURCES_BUFFER_FLAGS_H
#define RENDERING_RESOURCES_BUFFER_FLAGS_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    // Usage���ʹ���ڶ��㻺����,����������,������
    enum class BufferUsage
    {
        Static,
        Dynamic,
        RenderTarget,
        DepthStencil,
        Texture,
        Quantity
    };

    // ����ģʽʹ���ڷ�����Ƶ�ڴ���ڻ�����������
    enum class BufferLocking
    {
        ReadOnly,
        WriteOnly,
        ReadWrite,
        Quantity
    };
}

#endif  // RENDERING_RESOURCES_BUFFER_FLAGS_H
