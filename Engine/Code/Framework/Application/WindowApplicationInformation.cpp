///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:50)

#include "Framework/FrameworkExport.h"

#include "WindowApplicationInformation.h"
#include "Detail/WindowApplicationInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::WindowApplicationInformation::WindowApplicationInformation(const String& windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize)
    : impl{ windowTitle, size, point, allowResize }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, WindowApplicationInformation)
Framework::WindowApplicationInformation::WindowApplicationInformation(const String& windowTitle, const WindowSize& size)
    : impl{ windowTitle, size }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowApplicationInformation::WindowApplicationInformation(HInstance instance, const RendererParameter& rendererParameter)
    : impl{ instance, rendererParameter }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowApplicationInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowApplicationInformation, GetWindowTitle, System::String);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowApplicationInformation, GetWindowTitleWithMultiByte, std::string);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowApplicationInformation, GetXPosition, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowApplicationInformation, GetYPosition, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowApplicationInformation, GetWidth, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowApplicationInformation, GetHeight, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowApplicationInformation, GetWindowSize, Framework::WindowSize);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowApplicationInformation, GetAspectRatio, float);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowApplicationInformation, GetStyle, System::WindowsStyles);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, WindowApplicationInformation, SetWindowSize, WindowSize, void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowApplicationInformation, GetWindowName, Framework::WindowName);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowApplicationInformation, GetWindowPictorial, Framework::WindowPictorial);