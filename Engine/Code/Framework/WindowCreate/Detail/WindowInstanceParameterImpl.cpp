// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 09:46)

#include "Framework/FrameworkExport.h"

#include "WindowInstanceParameterImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using namespace std::literals;

Framework::WindowInstanceParameterImpl
	::WindowInstanceParameterImpl(HInstance instance, const String& className)
	:m_HInstance{ instance }, m_ClassName{ className }
{
	if (instance == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("窗口实例不存在。"s));
	}

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowInstanceParameterImpl
	::IsValid() const noexcept
{
	if (m_HInstance != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Framework::WindowInstanceParameterImpl::HInstance Framework::WindowInstanceParameterImpl
	::GetHInstance() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_HInstance;
}

System::String Framework::WindowInstanceParameterImpl
	::GetWindowClassName() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_ClassName;
}

