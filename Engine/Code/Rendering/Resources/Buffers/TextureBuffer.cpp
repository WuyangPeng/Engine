///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 17:01)

#include "Rendering/RenderingExport.h"

#include "TextureBuffer.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Detail/Buffers/BufferLayout.h"
#include "Rendering/Resources/Flags/UsageType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TextureBuffer)

CORE_TOOLS_RTTI_DEFINE(Rendering, TextureBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextureBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextureBuffer);

Rendering::TextureBuffer::TextureBuffer(DataFormatType format, int numElements, bool allowDynamicUpdate, const MemberLayoutContainer& memberLayoutContainer)
    : ParentType{ "TextureBuffer", numElements, DataFormat::GetNumBytesPerStruct(format), GraphicsObjectType::TextureBuffer }, impl{ memberLayoutContainer }, format{ format }
{
    SetUsage(allowDynamicUpdate ? UsageType::DynamicUpdate : UsageType::Immutable);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureBuffer)

Rendering::DataFormatType Rendering::TextureBuffer::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return format;
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, TextureBuffer, SetLayout, MemberLayoutContainer, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, TextureBuffer, GetLayout, Rendering::TextureBuffer::MemberLayoutContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, TextureBuffer, HasMember, std::string, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, TextureBuffer, GetMember, std::string, Rendering::MemberLayout)

CoreTools::ObjectInterfaceSharedPtr Rendering::TextureBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::GraphicsObject::RendererObjectSharedPtr Rendering::TextureBuffer::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererTypes);

    THROW_EXCEPTION(SYSTEM_TEXT("��Ⱦ���Ͳ����ڡ�"s))
}

Rendering::TextureBuffer::TextureBuffer(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }, format{ DataFormatType::Unknown }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::TextureBuffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    size += CoreTools::GetStreamSize(format);

    return size;
}

int64_t Rendering::TextureBuffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::TextureBuffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    target.WriteEnum(format);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TextureBuffer::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::TextureBuffer::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::TextureBuffer::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    source.ReadEnum(format);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
