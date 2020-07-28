// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 10:20)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestData.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "System/Time/DeltaTime.h"

CoreTools::UnitTestData
	::UnitTestData() noexcept
	:m_Pass{ 0 }, m_Fail{ 0 }, m_Error{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTestData
	::IsValid() const noexcept
{
	if (0 <= m_Fail && 0 <= m_Pass && 0 <= m_Error)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::UnitTestData
	::GetPassedNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Pass;
}

int CoreTools::UnitTestData
	::GetFailedNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Fail;
}

int CoreTools::UnitTestData
	::GetErrorNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Error;
}

bool CoreTools::UnitTestData
	::IsEmpty() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return (m_Pass == 0) && (m_Fail == 0) && (m_Error == 0);
}

void CoreTools::UnitTestData
	::AddPassedNumber() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	++m_Pass;
}

void CoreTools::UnitTestData
	::AddFailedNumber() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (m_Fail == 0)
	{
		System::SystemPause();
	}

	++m_Fail;
}

void CoreTools::UnitTestData
	::AddErrorNumber() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (m_Error == 0)
	{
		System::SystemPause();
	}

	++m_Error;
}

void CoreTools::UnitTestData
	::ClearData() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Pass = 0;
	m_Fail = 0;
	m_Error = 0;
}

