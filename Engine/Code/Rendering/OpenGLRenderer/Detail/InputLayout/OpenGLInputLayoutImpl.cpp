/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:51)

#include "Rendering/RenderingExport.h"

#include "OpenGLInputLayoutImpl.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Flags/ChannelType.h"

Rendering::OpenGLInputLayoutImpl::OpenGLInputLayoutImpl(OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBuffer& vertexBuffer)
    : vertexBufferHandle{ vertexBufferHandle },
      vertexArrayHandle{ 0 },
      numAttributes{ 0 },
      attributes{}
{
    System::UnusedFunction(programHandle);
    vertexArrayHandle = System::GetGLGenVertexArrays();
    System::SetGLBindVertexArray(vertexArrayHandle);

    const auto format = vertexBuffer.GetFormat();
    numAttributes = format.GetNumAttributes();
    for (auto i = 0; i < numAttributes; ++i)
    {
        auto& attribute = attributes.at(i);

        const auto type = format.GetAttributeType(i);

        attribute.SetNumChannels(DataFormat::GetNumChannels(type));
        attribute.SetChannelType(EnumCastUnderlying(GetChannelType(DataFormat::GetChannelType(type))));
        attribute.SetNormalize(DataFormat::ConvertChannel(type) ? GL_TRUE : GL_FALSE);
        attribute.SetLocation(i);
        attribute.SetOffset(format.GetOffset(i));
        attribute.SetStride(format.GetUnit(i));

        System::SetGLEnableVertexAttributeArray(attribute.GetLocation());
        System::SetGLBindVertexBuffer(i, vertexBufferHandle, attribute.GetOffset(), attribute.GetStride());
        SetGLVertexAttributeFormat(attribute.GetLocation(), attribute.GetNumChannels(), System::UnderlyingCastEnum<System::OpenGLData>(attribute.GetChannelType()), attribute.GetNormalize(), 0);
        System::SetGLVertexAttributeBinding(attribute.GetLocation(), i);
    }

    System::SetGLBindVertexArray(0);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLInputLayoutImpl::~OpenGLInputLayoutImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    System::SetGLDeleteVertexArrays(vertexArrayHandle);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLInputLayoutImpl)

void Rendering::OpenGLInputLayoutImpl::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLBindVertexArray(vertexArrayHandle);
}

void Rendering::OpenGLInputLayoutImpl::Disable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLBindVertexArray(0);
}

System::OpenGLData Rendering::OpenGLInputLayoutImpl::GetChannelType(ChannelType channelType)
{
    using Container = std::array<System::OpenGLData, System::EnumCastUnderlying(ChannelType::NumChannelTypes)>;
    static Container container{ OpenGLData::None,
                                OpenGLData::Byte,
                                OpenGLData::UnsignedByte,
                                OpenGLData::Short,
                                OpenGLData::UnsignedShort,
                                OpenGLData::Int,
                                OpenGLData::UnsignedInt,
                                OpenGLData::HalfFloat,
                                OpenGLData::Float,
                                OpenGLData::Double,
                                OpenGLData::Int2_10_10_10Rev,
                                OpenGLData::UnsignedInt2_10_10_10Rev,
                                OpenGLData::UnsignedInt10F11F11FRev };

    return container.at(System::EnumCastUnderlying(channelType));
}
