///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/27 11:54)

#include "Rendering/RenderingExport.h"

#include "OpenGLInputLayoutAttribute.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"

Rendering::OpenGLInputLayoutAttribute::OpenGLInputLayoutAttribute() noexcept
    : semantic{ VertexFormatFlags::Semantic::None },
      numChannels{ 0 },
      channelType{ 0 },
      normalize{ 0 },
      location{ 0 },
      offset{ 0 },
      stride{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLInputLayoutAttribute)

Rendering::VertexFormatFlags::Semantic Rendering::OpenGLInputLayoutAttribute::GetSemantic() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return semantic;
}

void Rendering::OpenGLInputLayoutAttribute::SetSemantic(VertexFormatFlags::Semantic aSemantic) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    semantic = aSemantic;
}

Rendering::OpenGLInputLayoutAttribute::OpenGLInt Rendering::OpenGLInputLayoutAttribute::GetNumChannels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numChannels;
}

void Rendering::OpenGLInputLayoutAttribute::SetNumChannels(OpenGLInt aNumChannels) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    numChannels = aNumChannels;
}

Rendering::OpenGLInputLayoutAttribute::OpenGLInt Rendering::OpenGLInputLayoutAttribute::GetChannelType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return channelType;
}

void Rendering::OpenGLInputLayoutAttribute::SetChannelType(OpenGLInt aChannelType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    channelType = aChannelType;
}

Rendering::OpenGLInputLayoutAttribute::OpenGLBoolean Rendering::OpenGLInputLayoutAttribute::GetNormalize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return normalize;
}

void Rendering::OpenGLInputLayoutAttribute::SetNormalize(OpenGLBoolean aNormalize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    normalize = aNormalize;
}

Rendering::OpenGLInputLayoutAttribute::OpenGLInt Rendering::OpenGLInputLayoutAttribute::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return location;
}

void Rendering::OpenGLInputLayoutAttribute::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    location = aLocation;
}

Rendering::OpenGLInputLayoutAttribute::OpenGLIntPtr Rendering::OpenGLInputLayoutAttribute::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::OpenGLInputLayoutAttribute::SetOffset(OpenGLIntPtr aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

Rendering::OpenGLInputLayoutAttribute::OpenGLSize Rendering::OpenGLInputLayoutAttribute::GetStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return stride;
}

void Rendering::OpenGLInputLayoutAttribute::SetStride(OpenGLSize aStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    stride = aStride;
}
