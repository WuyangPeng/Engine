///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/11 13:43)

#include "Rendering/RenderingExport.h"

#include "VertexBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"

Rendering::VertexBufferImpl::VertexBufferImpl(const VertexFormat& format)
    : vertexFormat{ format.Clone() }, structuredBuffer{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBufferImpl::VertexBufferImpl(const VertexFormat& format, const StructuredBufferSharedPtr& structuredBuffer)
    : vertexFormat{ format.Clone() }, structuredBuffer{ structuredBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::VertexBufferImpl::IsValid() const noexcept
{
    return vertexFormat != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::VertexFormat Rendering::VertexBufferImpl::GetFormat() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return *vertexFormat;
}

Rendering::VertexBufferImpl::StructuredBufferSharedPtr Rendering::VertexBufferImpl::GetStructuredBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return structuredBuffer;
}

bool Rendering::VertexBufferImpl::StandardUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexFormat->GetNumAttributes() != 0 && structuredBuffer == nullptr;
}

int Rendering::VertexBufferImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = vertexFormat->GetStreamingSize();

    size += CoreTools::GetStreamSize<bool>();

    if (structuredBuffer != nullptr)
    {
        size += structuredBuffer->GetStreamingSize();
    }

    return size;
}

void Rendering::VertexBufferImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    vertexFormat->Save(target);

    if (structuredBuffer != nullptr)
    {
        target.Write(true);
        structuredBuffer->Save(target);
    }
    else
    {
        target.Write(false);
    }
}

void Rendering::VertexBufferImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    vertexFormat->Load(source);

    const auto hasStructuredBuffer = source.ReadBool();

    if (hasStructuredBuffer)
    {
        structuredBuffer = std::make_shared<StructuredBuffer>(0, 0);
        structuredBuffer->Load(source);
    }
}

Rendering::VertexBufferImpl::ImplSharedPtr Rendering::VertexBufferImpl::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*vertexFormat, structuredBuffer);
}

int Rendering::VertexBufferImpl::GetIndex(Semantic usage, int usageIndex) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexFormat->GetIndex(usage, usageIndex);
}

Rendering::DataFormatType Rendering::VertexBufferImpl::GetAttributeType(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexFormat->GetAttributeType(attribute);
}

int Rendering::VertexBufferImpl::GetOffset(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexFormat->GetOffset(attribute);
}
