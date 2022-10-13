///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:42)

#include "Framework/FrameworkExport.h"

#include "InputManagerInterface.h"
#include "Flags/InputMiddleLayerFlags.h"
#include "Flags/MiddleLayerPlatformFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::InputManagerInterface::InputManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ System::EnumCastUnderlying(InputMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, InputManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, Network)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, CameraSystems)

bool Framework::InputManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Paint();
}

bool Framework::InputManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Move(point);
}

bool Framework::InputManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Resize(windowDisplay, size);
}
