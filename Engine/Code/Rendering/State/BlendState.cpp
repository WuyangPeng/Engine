///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 11:16)

#include "Rendering/RenderingExport.h"

#include "BlendState.h"
#include "Detail/BlendStateImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/OpenGLRenderer/State/OpenGLBlendState.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, BlendState)

CORE_TOOLS_RTTI_DEFINE(Rendering, BlendState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BlendState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BlendState);

Rendering::BlendState::BlendStateSharedPtr Rendering::BlendState::Create(const std::string& name)
{
    return std::make_shared<BlendState>(BlendStateCreate::Init, name);
}

Rendering::BlendState::BlendState(BlendStateCreate blendStateCreate, const std::string& name)
    : ParentType{ name, GraphicsObjectType::BlendState },
      impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(blendStateCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BlendState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendState, IsEnableAlphaToCoverage, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, BlendState, SetEnableAlphaToCoverage, bool, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendState, IsEnableIndependentBlend, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, BlendState, SetEnableIndependentBlend, bool, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendState, GetBlendColor, Rendering::BlendState::Colour)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, BlendState, SetBlendColor, Colour, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendState, GetSampleMask, uint32_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, BlendState, SetSampleMask, uint32_t, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, BlendState, GetBlendStateTarget, int, Rendering::BlendStateTarget)

void Rendering::BlendState::SetBlendStateTarget(int index, const BlendStateTarget& blendStateTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBlendStateTarget(index, blendStateTarget);
}

Rendering::BlendState::BlendState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::BlendState::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + impl->GetStreamingSize();
}

int64_t Rendering::BlendState::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::BlendState::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::BlendState::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::BlendState::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::BlendState::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CheckBlendState();
}

CoreTools::ObjectInterfaceSharedPtr Rendering::BlendState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::BlendState::RendererObjectSharedPtr Rendering::BlendState::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
            return std::make_shared<OpenGLBlendState>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        default:
            return ParentType::CreateRendererObject(rendererTypes);
    }
}

void Rendering::BlendState::CheckBlendState()
{
    if (GetType() != GraphicsObjectType::BlendState)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GraphicsObject类型错误。"s));
    }
}
