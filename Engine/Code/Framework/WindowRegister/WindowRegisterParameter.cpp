// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:37)

#include "Framework/FrameworkExport.h"

#include "WindowRegisterParameter.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using namespace std::literals;

Framework::WindowRegisterParameter
	::WindowRegisterParameter(HInstance instance, WindowClassStyle styles, int windowClassExtra, int windowExtra)
	:m_Instance{ instance }, m_Style{ styles }, m_WindowClassExtra{ windowClassExtra }, m_WindowExtra{ windowExtra }
{
	if (instance == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("窗口实例不存在。"s));
	}

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowRegisterParameter
	::IsValid() const noexcept
{
	if (m_Instance != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

System::WindowHInstance Framework::WindowRegisterParameter
	::GetHInstance() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Instance;
}

System::WindowClassStyle Framework::WindowRegisterParameter
	::GetStyle() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Style;
}

int Framework::WindowRegisterParameter
	::GetWindowClassExtra() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowClassExtra;
}

int Framework::WindowRegisterParameter
	::GetWindowExtra() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowExtra;
}




