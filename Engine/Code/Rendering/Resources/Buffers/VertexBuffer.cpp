/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:05)

#include "Rendering/RenderingExport.h"

#include "VertexBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/OpenGLRenderer/Resources/Buffers/OpenGLVertexBuffer.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Detail/Buffers/VertexBufferImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VertexBuffer)

CORE_TOOLS_RTTI_DEFINE(Rendering, VertexBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VertexBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VertexBuffer);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VertexBuffer)

Rendering::VertexBuffer::VertexBufferSharedPtr Rendering::VertexBuffer::Create(const std::string& name, int numVertices)
{
    return std::make_shared<ClassType>(VertexBufferCreate::Init, name, numVertices);
}

Rendering::VertexBuffer::VertexBufferSharedPtr Rendering::VertexBuffer::Create(const std::string& name, const VertexFormat& format, const StructuredBuffer& structuredBuffer)
{
    return std::make_shared<ClassType>(VertexBufferCreate::Init, name, format, structuredBuffer);
}

Rendering::VertexBuffer::VertexBufferSharedPtr Rendering::VertexBuffer::Create(const std::string& name, const VertexFormat& format, int numVertices, bool createStorage)
{
    return std::make_shared<ClassType>(VertexBufferCreate::Init, name, format, numVertices, createStorage);
}

Rendering::VertexBuffer::VertexBuffer(VertexBufferCreate vertexBufferCreate, const std::string& name, const VertexFormat& format, const StructuredBuffer& structuredBuffer)
    : ParentType{ name, structuredBuffer.GetNumElements(), format.GetVertexSize(), GraphicsObjectType::VertexBuffer }, impl{ format, structuredBuffer }
{
    System::UnusedFunction(vertexBufferCreate);

    SetNumActiveElements(structuredBuffer.GetNumElements());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexBuffer::VertexBuffer(VertexBufferCreate vertexBufferCreate, const std::string& name, const VertexFormat& format, int numVertices, bool createStorage)
    : ParentType{ name, numVertices, format.GetVertexSize(), GraphicsObjectType::VertexBuffer, createStorage }, impl{ format }
{
    System::UnusedFunction(vertexBufferCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexBuffer::VertexBuffer(VertexBufferCreate vertexBufferCreate, const std::string& name, int numVertices)
    : ParentType{ name, numVertices, 0, GraphicsObjectType::VertexBuffer, false }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(vertexBufferCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VertexBuffer)

Rendering::VertexFormat Rendering::VertexBuffer::GetFormat() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFormat();
}

bool Rendering::VertexBuffer::StandardUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->StandardUsage();
}

Rendering::VertexBuffer::StructuredBufferSharedPtr Rendering::VertexBuffer::GetStructuredBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<StructuredBuffer>(static_cast<const ClassType*>(this)->GetStructuredBuffer());

#include SYSTEM_WARNING_POP
}

Rendering::VertexBuffer::ConstStructuredBufferSharedPtr Rendering::VertexBuffer::GetStructuredBuffer() const
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
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
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

    const auto registerId = ParentType::Register(target);

    if (0 < registerId)
    {
        impl->Register(target);
    }

    return registerId;
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

    impl->Link(source);
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

    const auto offset = CheckChannel(semantic, unit, requiredTypes);

    const auto structuredBuffer = impl->GetStructuredBuffer();

    return (structuredBuffer == nullptr) ? GetStorage(offset) : structuredBuffer->GetStorage(offset);
}

Rendering::Resource::ConstSpanIterator Rendering::VertexBuffer::GetConstChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto offset = CheckChannel(semantic, unit, requiredTypes);

    const auto structuredBuffer = impl->GetStructuredBuffer();

    return (structuredBuffer == nullptr) ? GetStorage(offset) : structuredBuffer->GetStorage(offset);
}

int Rendering::VertexBuffer::CheckChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes) const
{
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

    return impl->GetOffset(index);
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
