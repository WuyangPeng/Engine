// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:46)

#include "Framework/FrameworkExport.h"

#include "WindowCreateParameter.h"
#include "Detail/WindowCreateParameterImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::WindowCreateParameter
	::WindowCreateParameter(const String& windowsName,WindowStyles style, HWnd parent, HMenu menu,const WindowPoint& leftTopCorner)
	:m_Impl{ make_shared<ImplType>(windowsName, style, parent, menu, leftTopCorner) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowCreateParameter
	::WindowCreateParameter(const String& windowsName)
	:WindowCreateParameter{ windowsName, WindowStyles::OverlappedWindow | WindowStyles::Visible }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowCreateParameter
	::WindowCreateParameter(const String& windowsName, WindowStyles style)
	:WindowCreateParameter{ windowsName, style, nullptr, nullptr, WindowPoint{ System::WindowPointUse::Default } }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, WindowCreateParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowCreateParameter, GetWindowsName, const System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateParameter, GetStyle, System::WindowStyles)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateParameter, GetLeftTopCorner, const Framework::WindowPoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateParameter, GetParent, Framework::WindowCreateParameter::HWnd)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateParameter, GetMenu, Framework::WindowCreateParameter::HMenu)
