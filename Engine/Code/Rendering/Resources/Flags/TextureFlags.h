// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 09:48)

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

#endif // RENDERING_RESOURCES_TEXTURE_FLAGS_H
