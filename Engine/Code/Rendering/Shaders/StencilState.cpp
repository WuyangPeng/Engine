///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:54)

#include "Rendering/RenderingExport.h"

#include "StencilState.h"
#include "Detail/StencilStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, StencilState)

CORE_TOOLS_RTTI_DEFINE(Rendering, StencilState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, StencilState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, StencilState);

Rendering::StencilState::StencilState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, StencilState)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, StencilState)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, StencilState)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, StencilState)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, StencilState)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, StencilState)

Rendering::StencilState::StencilState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "StencilState" }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, StencilState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, StencilState, IsEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, StencilState, GetCompare, Rendering::StencilState::CompareMode)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, StencilState, GetReference, unsigned int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, StencilState, GetMask, unsigned int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, StencilState, GetWriteMask, unsigned int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, StencilState, GetOnFail, Rendering::StencilState::OperationType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, StencilState, GetOnZFail, Rendering::StencilState::OperationType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, StencilState, GetOnZPass, Rendering::StencilState::OperationType)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, StencilState, SetEnabled, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, StencilState, SetCompare, CompareMode, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, StencilState, SetReference, unsigned int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, StencilState, SetMask, unsigned int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, StencilState, SetWriteMask, unsigned int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, StencilState, SetOnFail, OperationType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, StencilState, SetOnZFail, OperationType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, StencilState, SetOnZPass, OperationType, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::StencilState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
