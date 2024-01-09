/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 13:49)

#ifndef RENDERING_SHADERS_SHADER_DATA_LOOKUP_H
#define RENDERING_SHADERS_SHADER_DATA_LOOKUP_H

namespace Rendering
{
    enum class ShaderDataLookup
    {
        ConstantBufferShaderDataLookup = 0,  // ConstantBuffer
        TextureBufferShaderDataLookup = 1,  // TextureBuffer
        StructuredBufferShaderDataLookup = 2,  // StructuredBuffer
        RawBufferShaderDataLookup = 3,  // RawBuffer
        TypedBufferShaderDataLookup = 4,  // TypedBuffer
        TextureSingleShaderDataLookup = 5,  // TextureSingle
        TextureArrayShaderDataLookup = 6,  // TextureArray
        SamplerStateShaderDataLookup = 7,  //  SamplerState
        AtomicCounterBufferShaderDataLookup = 8,  // AtomicCounterBuffer
        AtomicCounterShaderDataLookup = 9,  // AtomicCounter
        NumLookupIndices = 10
    };

}

#endif  // RENDERING_SHADERS_SHADER_DATA_LOOKUP_H
