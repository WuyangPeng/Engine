///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:40)

#include "Framework/FrameworkExport.h"

#include "GUIManagerInterface.h"
#include "Flags/GUIMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::GUIManagerInterface::GUIManagerInterface(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }, impl{ System::EnumCastUnderlying(GUIMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GUIManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, GUI, Rendering)

bool Framework::GUIManagerInterface::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Paint();
}

bool Framework::GUIManagerInterface::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Move(point);
}

bool Framework::GUIManagerInterface::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::GUIManagerInterface::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyUp(key, point);
}

bool Framework::GUIManagerInterface::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::KeyDown(key, point);
}

bool Framework::GUIManagerInterface::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::GUIManagerInterface::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::GUIManagerInterface::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::PassiveMotion(point);
}

bool Framework::GUIManagerInterface::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::GUIManagerInterface::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::GUIManagerInterface::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
