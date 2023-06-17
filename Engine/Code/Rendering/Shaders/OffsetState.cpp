///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:51)

#include "Rendering/RenderingExport.h"

#include "OffsetState.h"
#include "Detail/OffsetStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OffsetState)

CORE_TOOLS_RTTI_DEFINE(Rendering, OffsetState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, OffsetState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, OffsetState);

Rendering::OffsetState::OffsetState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, OffsetState)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, OffsetState)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, OffsetState)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, OffsetState)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, OffsetState)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, OffsetState)

Rendering::OffsetState::OffsetState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "OffsetState" }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OffsetState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, OffsetState, IsFillEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, OffsetState, IsLineEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, OffsetState, IsPointEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, OffsetState, GetScale, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, OffsetState, GetBias, float)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, OffsetState, SetFillEnabled, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, OffsetState, SetLineEnabled, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, OffsetState, SetPointEnabled, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, OffsetState, SetScale, float, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, OffsetState, SetBias, float, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OffsetState, SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OffsetState, LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::OffsetState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
