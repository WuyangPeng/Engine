///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 10:58)

#include "Rendering/RenderingExport.h"

#include "AlphaState.h"
#include "Detail/AlphaStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, AlphaState)

CORE_TOOLS_RTTI_DEFINE(Rendering, AlphaState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, AlphaState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, AlphaState);

Rendering::AlphaState::AlphaState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, AlphaState)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, AlphaState)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, AlphaState)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, AlphaState)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, AlphaState)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, AlphaState)

Rendering::AlphaState::AlphaState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "AlphaState" }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, AlphaState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, AlphaState, IsBlendEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, AlphaState, GetSourceBlend, Rendering::AlphaState::SourceBlendMode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, AlphaState, GetDestinationBlend, Rendering::AlphaState::DestinationBlendMode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, AlphaState, IsCompareEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, AlphaState, GetCompare, Rendering::AlphaState::CompareMode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, AlphaState, GetReference, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, AlphaState, GetConstantColor, Rendering::AlphaState::Colour)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, AlphaState, SetBlendEnabled, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, AlphaState, SetSourceBlend, SourceBlendMode, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, AlphaState, SetDestinationBlend, DestinationBlendMode, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, AlphaState, SetCompareEnabled, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, AlphaState, SetCompare, CompareMode, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, AlphaState, SetReference, float, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, AlphaState, SetConstantColor, Colour, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, AlphaState, SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, AlphaState, LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::AlphaState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
