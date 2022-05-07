///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 13:59)

#include "Rendering/RenderingExport.h"

#include "DepthState.h"
#include "Detail/DepthStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, DepthState)

CORE_TOOLS_RTTI_DEFINE(Rendering, DepthState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DepthState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DepthState);

Rendering::DepthState::DepthState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, DepthState)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, DepthState)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, DepthState)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, DepthState)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, DepthState)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, DepthState)

Rendering::DepthState::DepthState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "DepthState" }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DepthState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DepthState, IsEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DepthState, IsWritable, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, DepthState, GetCompare, Rendering::DepthState::CompareMode)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, DepthState, SetEnabled, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, DepthState, SetWritable, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, DepthState, SetCompare, CompareMode, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState, SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState, LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::DepthState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
