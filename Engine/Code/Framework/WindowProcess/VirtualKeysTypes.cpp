/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:30)

#include "Framework/FrameworkExport.h"

#include "VirtualKeysTypes.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

Framework::VirtualKeysTypes::VirtualKeysTypes(WParam wParam) noexcept
    : isCtrlKeyDown{ (wParam & WindowApplicationTrait::MouseModifiers::modifierControl) != 0 },
      isLeftMouseDown{ (wParam & WindowApplicationTrait::MouseModifiers::modifierLeftButton) != 0 },
      isMiddleMouseDown{ (wParam & WindowApplicationTrait::MouseModifiers::modifierMiddleButton) != 0 },
      isRightMouseDown{ (wParam & WindowApplicationTrait::MouseModifiers::modifierRightButton) != 0 },
      isShiftKeyDown{ (wParam & WindowApplicationTrait::MouseModifiers::modifierShift) != 0 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, VirtualKeysTypes)

bool Framework::VirtualKeysTypes::IsCtrlKeyDown() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return isCtrlKeyDown;
}

bool Framework::VirtualKeysTypes::IsLeftMouseDown() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return isLeftMouseDown;
}

bool Framework::VirtualKeysTypes::IsMiddleMouseDown() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return isMiddleMouseDown;
}

bool Framework::VirtualKeysTypes::IsRightMouseDown() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return isRightMouseDown;
}

bool Framework::VirtualKeysTypes::IsShiftKeyDown() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return isShiftKeyDown;
}

bool Framework::VirtualKeysTypes::IsMouseDown() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return isLeftMouseDown || isMiddleMouseDown || isRightMouseDown;
}

void Framework::VirtualKeysTypes::SetModifiers(int modifiers) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    isShiftKeyDown = (GlutApplicationTrait::KeyboardModifiers::keyShift == modifiers);
    isCtrlKeyDown = (GlutApplicationTrait::KeyboardModifiers::keyControl == modifiers);
}

void Framework::VirtualKeysTypes::SetMouseButtonsTypes(int button) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    isLeftMouseDown = (GlutApplicationTrait::MouseButtons::mouseLeftButton == button);
    isMiddleMouseDown = (GlutApplicationTrait::MouseButtons::mouseMiddleButton == button);
    isRightMouseDown = (GlutApplicationTrait::MouseButtons::mouseRightButton == button);
}

void Framework::VirtualKeysTypes::ClearMouseButtonsTypes() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    isLeftMouseDown = false;
    isMiddleMouseDown = false;
    isRightMouseDown = false;
}

void Framework::VirtualKeysTypes::ClearKeyDownTypes() noexcept
{
    isShiftKeyDown = false;
    isCtrlKeyDown = false;
}
