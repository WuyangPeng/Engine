/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/08 16:21)

#ifndef RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H
#define RENDERING_BASE_GRAPHICS_OBJECT_TYPE_H

#include "System/Helper/UserMacro.h"

namespace Rendering
{
    /// ͼ�ζ���ĵ�ǰ��νṹΪ
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

    /// ͼ�ζ���������������ʱ������Ϣ��
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
