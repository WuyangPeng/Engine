// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.3.0.1 (2020/05/27 14:14)

#include "ChildHelperInterface.h"
#include "ChildHelperInterfaceImpl.h"
#include "ChildHelperMiddleLayerFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::ChildHelperInterface::ChildHelperInterface(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }, impl{ System::EnumCastUnderlying(ChildHelperMiddleLayer::Count) }
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

const Framework::ConstMiddleLayerInterfaceSharedPtr Framework::ChildHelperInterface::GetManager(ChildHelperMiddleLayer childHelperMiddleLayer) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetMiddleLayerInterface(System::EnumCastUnderlying(childHelperMiddleLayer));
}
