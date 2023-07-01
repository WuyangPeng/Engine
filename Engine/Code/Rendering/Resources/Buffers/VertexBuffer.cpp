///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 17:09)

#include "Rendering/RenderingExport.h"

#include "VertexBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/OpenGLRenderer/Resources/Buffers/OpenGLVertexBuffer.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Detail/Buffers/VertexBufferImpl.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, VertexBuffer)

CORE_TOOLS_RTTI_DEFINE(Rendering, VertexBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VertexBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VertexBuffer);

Rendering::VertexBuffer::VertexBuffer(VertexBufferCreate vertexBufferCreate, const VertexFormat& format, const StructuredBufferSharedPtr& structuredBuffer)
    : ParentType{ structuredBuffer->GetNumElements(), format.GetStride(), GraphicsObjectType::VertexBuffer }, impl{ format, structuredBuffer }
{
    System::UnusedFunction(vertexBufferCreate);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBuffer::VertexBuffer(VertexBufferCreate vertexBufferCreate, const VertexFormat& format, int numVertices)
    : ParentType{ numVertices, format.GetStride(), GraphicsObjectType::VertexBuffer }, impl{ format }
{
    System::UnusedFunction(vertexBufferCreate);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VertexBuffer)

Rendering::VertexBuffer::VertexBufferSharedPtr Rendering::VertexBuffer::Create(const VertexFormat& format, const StructuredBufferSharedPtr& structuredBuffer)
{
    return std::make_shared<ClassType>(VertexBufferCreate::Init, format, structuredBuffer);
}

Rendering::VertexBuffer::VertexBufferSharedPtr Rendering::VertexBuffer::Create(const VertexFormat& format, int numVertices)
{
    return std::make_shared<ClassType>(VertexBufferCreate::Init, format, numVertices);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VertexBuffer, GetFormat, Rendering::VertexFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBuffer, StandardUsage, bool)

Rendering::VertexBuffer::StructuredBufferSharedPtr Rendering::VertexBuffer::GetStructuredBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto buffer = impl->GetStructuredBuffer();

    if (buffer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Structured Buffer 指针为空。"))
    }

    return buffer;
}

Rendering::VertexBuffer::VertexBuffer(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ *VertexFormat::Create() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::VertexBuffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::VertexBuffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::VertexBuffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::VertexBuffer::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::VertexBuffer::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::VertexBuffer::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::VertexBufferSharedPtr Rendering::VertexBuffer::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::VertexBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Rendering::VertexBuffer::SpanIterator Rendering::VertexBuffer::GetChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto index = impl->GetIndex(semantic, unit);
    if (index < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区没有使用指定单位的指定语义。"s))
    }

    if (const auto type = impl->GetAttributeType(index);
        !requiredTypes.empty() && !requiredTypes.contains(type))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("语义的类型不在所需类型的集合中。"s))
    }

    const auto buffer = impl->GetStructuredBuffer();

    const auto offset = impl->GetOffset(index);

    return (buffer == nullptr) ? GetData(offset) : buffer->GetData(offset);
}

Rendering::VertexBuffer::RendererObjectSharedPtr Rendering::VertexBuffer::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLVertexBuffer>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}