///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:03)

#include "Rendering/RenderingExport.h"

#include "RenderTarget.h"
#include "Detail/RenderTargetImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Renderers/RendererManager.h"

using std::make_shared;
using std::string;
using std::vector;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RenderTarget)

CORE_TOOLS_RTTI_DEFINE(Rendering, RenderTarget);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RenderTarget);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RenderTarget);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, RenderTarget);

Rendering::RenderTarget::RenderTarget(int numTargets, TextureFormat format, int width, int height, bool hasMipmaps, bool hasDepthStencil)
    : ParentType{ "RenderTarget" }, impl{ numTargets, format, width, height, hasMipmaps, hasDepthStencil }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RenderTarget)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RenderTarget, GetNumTargets, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RenderTarget, GetFormat, Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RenderTarget, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, RenderTarget, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RenderTarget, GetColorTexture, int, Rendering::RenderTarget::ConstTexture2DSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RenderTarget, GetDepthStencilTexture, Rendering::RenderTarget::ConstTexture2DSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RenderTarget, HasMipmaps, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, RenderTarget, HasDepthStencil, bool)

Rendering::RenderTarget::RenderTarget(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::RenderTarget::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

uint64_t Rendering::RenderTarget::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto uniqueID = ParentType::Register(target);
    if (uniqueID != 0)
    {
        impl->Register(target);
    }

    return uniqueID;
}

void Rendering::RenderTarget::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::RenderTarget::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::RenderTarget::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::RenderTarget::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::RenderTarget::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
