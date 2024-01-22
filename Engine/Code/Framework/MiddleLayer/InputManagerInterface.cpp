/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:03)

#include "Framework/FrameworkExport.h"

#include "InputManagerInterface.h"
#include "Flags/InputMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::InputManagerInterface::InputManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ System::EnumCastUnderlying(InputMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, InputManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, Network)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Input, CameraSystems)

bool Framework::InputManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Paint();
}

bool Framework::InputManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Move(point);
}

bool Framework::InputManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Resize(windowDisplay, size);
}
