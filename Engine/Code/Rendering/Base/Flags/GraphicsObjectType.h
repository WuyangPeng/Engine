///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/07 16:57)

#ifndef RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H
#define RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H

#include "System/Helper/UserMacro.h"

namespace Rendering
{
    enum class GraphicsObjectType
    {
        None,  // 抽象的

        Resource,  // 抽象的

        Buffer,  // 抽象的
        ConstantBuffer,
        TextureBuffer,
        VertexBuffer,
        IndexBuffer,
        StructuredBuffer,
        TypedBuffer,
        RawBuffer,
        IndirectArgumentsBuffer,

        Texture,  // 抽象的
        TextureSingle,  // 抽象的
        Texture1,
        Texture2,
        TextureRenderTarget,
        TextureDepthStencil,
        Texture3,
        TextureArray,  // 抽象的
        Texture1Array,
        Texture2Array,
        TextureCube,
        TextureCubeArray,

        Shader,  // 抽象的
        VertexShader,
        GeometryShader,
        PixelShader,
        ComputeShader,

        DrawingState,  // 抽象的
        SamplerState,
        BlendState,
        DepthStencilState,
        RasterizerState,

        NumTypes,
    };
}

#endif  // RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H
