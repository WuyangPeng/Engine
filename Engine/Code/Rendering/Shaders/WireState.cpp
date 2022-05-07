///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 21:13)

#include "Rendering/RenderingExport.h"

#include "WireState.h"
#include "Detail/WireStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, WireState)

CORE_TOOLS_RTTI_DEFINE(Rendering, WireState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, WireState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, WireState);

Rendering::WireState::WireState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, WireState)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, WireState)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, WireState)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, WireState)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, WireState)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, WireState)

Rendering::WireState::WireState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "WireState" }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WireState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WireState, IsEnabled, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, WireState, SetEnabled, bool, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, WireState, SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, WireState, LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::WireState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
