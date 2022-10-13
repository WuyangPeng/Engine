///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:35)

#include "Framework/FrameworkExport.h"

#include "EventManagerInterface.h"
#include "Flags/EventMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::EventManagerInterface::EventManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ System::EnumCastUnderlying(EventMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EventManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Event, Message)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Event, System)

bool Framework::EventManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Paint();
}

bool Framework::EventManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Move(point);
}

bool Framework::EventManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::EventManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyUp(key, point);
}

bool Framework::EventManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyDown(key, point);
}

bool Framework::EventManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::EventManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::EventManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::PassiveMotion(point);
}

bool Framework::EventManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::EventManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::EventManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
