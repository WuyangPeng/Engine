/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 16:21)

#ifndef RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H
#define RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H

#include "System/Helper/UserMacro.h"

namespace Rendering
{
    /// 图形对象的当前层次结构为
    ///  GraphicsObject
    ///      Resource
    ///          Buffer
    ///              ConstantBuffer
    ///              TextureBuffer
    ///              VertexBuffer
    ///              IndexBuffer
    ///              StructuredBuffer
    ///              TypedBuffer
    ///              RawBuffer
    ///              IndirectArgumentsBuffer
    ///          Texture
    ///              TextureSingle
    ///                  Texture1
    ///                  Texture2
    ///                      TextureRenderTarget
    ///                      TextureDepthStencil
    ///                  Texture3
    ///              TextureArray
    ///                  Texture1Array
    ///                  Texture2Array
    ///                  TextureCube
    ///                  TextureCubeArray
    ///      ShaderBase
    ///          Shader
    ///              VertexShader
    ///              GeometryShader
    ///              PixelShader
    ///              ComputeShader
    ///      DrawingState
    ///          SamplerState
    ///          BlendState
    ///          DepthStencilState
    ///          RasterizerState

    /// 图形对象类型用于运行时类型信息。
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
