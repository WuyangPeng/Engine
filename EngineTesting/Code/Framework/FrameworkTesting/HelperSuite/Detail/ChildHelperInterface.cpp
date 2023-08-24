///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 19:21)

#include "ChildHelperInterface.h"
#include "ChildHelperInterfaceImpl.h"
#include "ChildHelperMiddleLayerFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

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
