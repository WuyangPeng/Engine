///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 13:56)

#include "Framework/FrameworkExport.h"

#include "SystemManagerInterface.h"
#include "Flags/SystemMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::SystemManagerInterface::SystemManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ System::EnumCastUnderlying(SystemMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SystemManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Message)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Event)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Resource)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Audio)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, CameraSystems)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Rendering)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, System, Engine)

bool Framework::SystemManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Paint();
}

bool Framework::SystemManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Move(point);
}

bool Framework::SystemManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::SystemManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyUp(key, point);
}

bool Framework::SystemManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyDown(key, point);
}

bool Framework::SystemManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::SystemManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::SystemManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::PassiveMotion(point);
}

bool Framework::SystemManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::SystemManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::SystemManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
