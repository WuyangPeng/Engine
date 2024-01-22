/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:27)

#include "Framework/FrameworkExport.h"

#include "MousePosition.h"
#include "Detail/MousePositionImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Framework, MousePosition)

Framework::MousePosition::MousePosition(HWnd hWnd)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, MousePosition)

Framework::WindowPoint Framework::MousePosition::GetMousePosition() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetMousePosition();
}

void Framework::MousePosition::SetMousePosition(const WindowPoint& windowPoint)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMousePosition(windowPoint);
}
