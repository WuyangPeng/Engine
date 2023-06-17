///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:25)

#include "Rendering/RenderingExport.h"

#include "ConstantBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/OpenGLRenderer/Resources/Buffers/OpenGLConstantBuffer.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Resources/Detail/Buffers/BufferLayout.h"
#include "Rendering/Resources/Flags/UsageType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ConstantBuffer)

CORE_TOOLS_RTTI_DEFINE(Rendering, ConstantBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ConstantBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ConstantBuffer);

Rendering::ConstantBuffer::ConstantBuffer(int numBytes, bool allowDynamicUpdate)
    : ParentType{ 1, GetRoundedNumBytes(numBytes), GraphicsObjectType::ConstantBuffer }, impl{ MemberLayoutContainer{} }
{
    SetUsage(allowDynamicUpdate ? UsageType::DynamicUpdate : UsageType::Immutable);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ConstantBuffer::ConstantBuffer(int numBytes, bool allowDynamicUpdate, const MemberLayoutContainer& memberLayoutContainer)
    : ParentType{ 1, GetRoundedNumBytes(numBytes), GraphicsObjectType::ConstantBuffer }, impl{ memberLayoutContainer }
{
    SetUsage(allowDynamicUpdate ? UsageType::DynamicUpdate : UsageType::Immutable);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ConstantBuffer)

int Rendering::ConstantBuffer::GetRoundedNumBytes(int numBytes) noexcept
{
    if (0 < numBytes)
    {
        const auto remainder = numBytes % constantBufferRequiredMinimumBytes;
        if (remainder == 0)
        {
            return numBytes;
        }
        else
        {
            return numBytes + constantBufferRequiredMinimumBytes - remainder;
        }
    }
    else
    {
        return constantBufferRequiredMinimumBytes;
    }
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ConstantBuffer, SetLayout, MemberLayoutContainer, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ConstantBuffer, GetLayout, Rendering::ConstantBuffer::MemberLayoutContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ConstantBuffer, HasMember, std::string, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ConstantBuffer, GetMember, std::string, Rendering::MemberLayout)

CoreTools::ObjectInterfaceSharedPtr Rendering::ConstantBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::ConstantBuffer::RendererObjectSharedPtr Rendering::ConstantBuffer::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
            return std::make_shared<OpenGLConstantBuffer>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        default:
            return ParentType::CreateRendererObject(rendererTypes);
    }
}

Rendering::ConstantBuffer::ConstantBuffer(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::ConstantBuffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::ConstantBuffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::ConstantBuffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::ConstantBuffer::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::ConstantBuffer::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::ConstantBuffer::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
