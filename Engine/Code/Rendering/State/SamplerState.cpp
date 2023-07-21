///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 11:18)

#include "Rendering/RenderingExport.h"

#include "SamplerState.h"
#include "Detail/SamplerStateImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/OpenGLRenderer/State/OpenGLSamplerState.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SamplerState)

CORE_TOOLS_RTTI_DEFINE(Rendering, SamplerState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SamplerState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SamplerState);

Rendering::SamplerState::SamplerState(const std::string& name)
    : ParentType{ name, GraphicsObjectType::SamplerState },
      impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::SamplerState::SamplerState(SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1)
    : ParentType{ "SamplerState", GraphicsObjectType::SamplerState },
      impl{ filter, mode0, mode1 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::SamplerState::SamplerState(SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1, SamplerStateMode mode2)
    : ParentType{ "SamplerState", GraphicsObjectType::SamplerState },
      impl{ filter, mode0, mode1, mode2 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SamplerState)

Rendering::SamplerStateFilter Rendering::SamplerState::GetFilter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFilter();
}

Rendering::SamplerStateMode Rendering::SamplerState::GetMode(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMode(index);
}

float Rendering::SamplerState::GetMipLODBias() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMipLODBias();
}

int Rendering::SamplerState::GetMaxAnisotropy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMaxAnisotropy();
}

Rendering::SamplerStateComparison Rendering::SamplerState::GetComparison() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetComparison();
}

Rendering::SamplerState::Colour Rendering::SamplerState::GetBorderColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBorderColor();
}

float Rendering::SamplerState::GetMinLOD() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMinLOD();
}

float Rendering::SamplerState::GetMaxLOD() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMaxLOD();
}

Rendering::SamplerState::SamplerState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::SamplerState::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + impl->GetStreamingSize();
}

int64_t Rendering::SamplerState::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::SamplerState::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::SamplerState::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::SamplerState::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::SamplerState::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::SamplerState::RendererObjectSharedPtr Rendering::SamplerState::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
            return std::make_shared<OpenGLSamplerState>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        default:
            return ParentType::CreateRendererObject(rendererTypes);
    }
}

CoreTools::ObjectInterfaceSharedPtr Rendering::SamplerState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}