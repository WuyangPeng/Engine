///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:05)

#include "ChildHelperInterface.h"
#include "ChildHelperInterfaceImpl.h"
#include "ChildHelperMiddleLayerFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::ChildHelperInterface::ChildHelperInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ System::EnumCastUnderlying(ChildHelperMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ChildHelperInterface)

ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ChildHelper, ChildHelper, Input)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ChildHelper, ChildHelper, ObjectLogic)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ChildHelper, ChildHelper, Message)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ChildHelper, ChildHelper, Event)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ChildHelper, ChildHelper, Resource)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ChildHelper, ChildHelper, Audio)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ChildHelper, ChildHelper, CameraSystems)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ChildHelper, ChildHelper, Rendering)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ChildHelper, ChildHelper, Engine)

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::ChildHelperInterface::GetManager(ChildHelperMiddleLayer childHelperMiddleLayer) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetMiddleLayerInterface(System::EnumCastUnderlying(childHelperMiddleLayer));
}
