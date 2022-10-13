///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/07 16:57)

#ifndef RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H
#define RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H

#include "System/Helper/UserMacro.h"

namespace Rendering
{
    enum class GraphicsObjectType
    {
        None,  // �����

        Resource,  // �����

        Buffer,  // �����
        ConstantBuffer,
        TextureBuffer,
        VertexBuffer,
        IndexBuffer,
        StructuredBuffer,
        TypedBuffer,
        RawBuffer,
        IndirectArgumentsBuffer,

        Texture,  // �����
        TextureSingle,  // �����
        Texture1,
        Texture2,
        TextureRenderTarget,
        TextureDepthStencil,
        Texture3,
        TextureArray,  // �����
        Texture1Array,
        Texture2Array,
        TextureCube,
        TextureCubeArray,

        Shader,  // �����
        VertexShader,
        GeometryShader,
        PixelShader,
        ComputeShader,

        DrawingState,  // �����
        SamplerState,
        BlendState,
        DepthStencilState,
        RasterizerState,

        NumTypes,
    };
}

#endif  // RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H
