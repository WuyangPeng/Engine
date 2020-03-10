// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 09:30)

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

#endif // RENDERING_RESOURCES_BUFFER_FLAGS_H
