///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/27 13:48)

#include "Rendering/RenderingExport.h"

#include "OpenGLInputLayoutImpl.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Flags/ChannelType.h"

Rendering::OpenGLInputLayoutImpl::OpenGLInputLayoutImpl(MAYBE_UNUSED OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBuffer& vertexBuffer)
    : vertexBufferHandle{ vertexBufferHandle },
      vertexArrayHandle{ 0 },
      numAttributes{ 0 },
      attributes{}
{
    vertexArrayHandle = System::GetGLGenVertexArrays();
    System::SetGLBindVertexArray(vertexArrayHandle);

    auto format = vertexBuffer.GetFormat();
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
        attribute.SetStride(format.GetUsageIndex(i));

        System::SetGLEnableVertexAttribArray(attribute.GetLocation());
        System::SetGLBindVertexBuffer(i, vertexBufferHandle, attribute.GetOffset(), attribute.GetStride());
        System::SetGLVertexAttribFormat(attribute.GetLocation(), attribute.GetNumChannels(), System::UnderlyingCastEnum<System::OpenGLData>(attribute.GetChannelType()), attribute.GetNormalize(), 0);
        System::SetGLVertexAttribBinding(attribute.GetLocation(), i);
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
    static Container container{ System::OpenGLData::None,
                                System::OpenGLData::Byte,
                                System::OpenGLData::UnsignedByte,
                                System::OpenGLData::Short,
                                System::OpenGLData::UnsignedShort,
                                System::OpenGLData::Int,
                                System::OpenGLData::UnsignedInt,
                                System::OpenGLData::HalfFloat,
                                System::OpenGLData::Float,
                                System::OpenGLData::Double,
                                System::OpenGLData::Int2_10_10_10Rev,
                                System::OpenGLData::UnsignedInt2_10_10_10Rev,
                                System::OpenGLData::UnsignedInt10F11F11FRev };

    return container.at(System::EnumCastUnderlying(channelType));
}
