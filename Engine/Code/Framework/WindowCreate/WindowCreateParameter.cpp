///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:12)

#include "Framework/FrameworkExport.h"

#include "WindowCreateParameter.h"
#include "Detail/WindowCreateParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::WindowCreateParameter::WindowCreateParameter(const String& windowsName, WindowStyles style, WindowsHWnd parent, WindowsHMenu menu, const WindowPoint& leftTopCorner)
    : impl{ windowsName, style, parent, menu, leftTopCorner }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowCreateParameter::WindowCreateParameter(const String& windowsName)
    : WindowCreateParameter{ windowsName, WindowStyles::OverlappedWindow | WindowStyles::Visible }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowCreateParameter::WindowCreateParameter(const String& windowsName, WindowStyles style)
    : WindowCreateParameter{ windowsName, style, nullptr, nullptr, WindowPoint{ System::WindowsPointUse::Default } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowCreateParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowCreateParameter, GetWindowsName, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateParameter, GetStyle, System::WindowsStyles)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateParameter, GetLeftTopCorner, Framework::WindowPoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateParameter, GetParent, Framework::WindowCreateParameter::WindowsHWnd)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateParameter, GetMenu, Framework::WindowCreateParameter::WindowsHMenu)
