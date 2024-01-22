/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/17 10:31)

#include "Framework/FrameworkExport.h"

#include "ResourceManagerInterface.h"
#include "Flags/ResourceMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ResourceManagerInterface::ResourceManagerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ System::EnumCastUnderlying(ResourceMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ResourceManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Resource, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Resource, Audio)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Resource, Rendering)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Resource, GUI)

bool Framework::ResourceManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Paint();
}

bool Framework::ResourceManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Move(point);
}

bool Framework::ResourceManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::ResourceManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyUp(key, point);
}

bool Framework::ResourceManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::KeyDown(key, point);
}

bool Framework::ResourceManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::ResourceManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::ResourceManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::PassiveMotion(point);
}

bool Framework::ResourceManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::ResourceManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::ResourceManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
