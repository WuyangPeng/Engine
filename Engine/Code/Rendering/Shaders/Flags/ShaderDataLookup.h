///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/19 13:36)

#ifndef RENDERING_SHADERS_SHADER_DATA_LOOKUP_H
#define RENDERING_SHADERS_SHADER_DATA_LOOKUP_H

namespace Rendering
{
    enum class ShaderDataLookup
    {
        ConstantBufferShaderDataLookup = 0,  // CB
        TextureBufferShaderDataLookup = 1,  // TB
        StructuredBufferShaderDataLookup = 2,  // SB
        RawBufferShaderDataLookup = 3,  // RB
        TypedBufferShaderDataLookup = 4,  // TY
        TextureSingleShaderDataLookup = 5,  // TX
        TextureArrayShaderDataLookup = 6,  // TA
        SamplerStateShaderDataLookup = 7,  // SS
        AtomicCounterBufferShaderDataLookup = 8,  // AB
        AtomicCounterShaderDataLookup = 9,  // AC
        NumLookupIndices = 10
    };

}

#endif  // RENDERING_SHADERS_SHADER_DATA_LOOKUP_H
