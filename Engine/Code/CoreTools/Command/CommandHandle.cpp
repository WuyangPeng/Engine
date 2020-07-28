// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.2 (2020/01/22 11:16)

#include "CoreTools/CoreToolsExport.h"

#include "CommandHandle.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::pair;
using std::string;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

namespace
{
	const System::String g_ArgumentOutOfRange{ SYSTEM_TEXT("²ÎÊý³¬³ö·¶Î§£¡") };
}
#include STSTEM_WARNING_POP

CoreTools::CommandHandle
	::CommandHandle(int argumentsNumber, char** arguments)
	:m_CommandLineInformation{ argumentsNumber,arguments },
	 m_Small{ 0.0 }, m_Large{ 0.0 }, m_MinSet{ false },
	 m_MaxSet{ false }, m_InfSet{ false }, m_SupSet{ false }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CommandHandle
	::CommandHandle(const char* commandLine)
	:m_CommandLineInformation{ commandLine },
	 m_Small{ 0.0 }, m_Large{ 0.0 }, m_MinSet{ false },
	 m_MaxSet{ false }, m_InfSet{ false }, m_SupSet{ false }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CommandHandle)

const string CoreTools::CommandHandle
	::ExcessArguments() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CommandLineInformation.ExcessArguments();
}

CoreTools::CommandHandle& CoreTools::CommandHandle
	::SetMinValue(double value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Small = value;
	m_MinSet = true;

	return *this;
}

CoreTools::CommandHandle& CoreTools::CommandHandle
	::SetMaxValue(double value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Large = value;
	m_MaxSet = true;

	return *this;
}

CoreTools::CommandHandle& CoreTools::CommandHandle
	::SetInfValue(double value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Small = value;
	m_InfSet = true;

	return *this;
}

CoreTools::CommandHandle& CoreTools::CommandHandle
	::SetSupValue(double value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Large = value;
	m_SupSet = true;

	return *this;
}

bool CoreTools::CommandHandle
	::GetBoolean(const string& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CommandLineInformation.GetBoolean(name);
}

int CoreTools::CommandHandle
	::GetInteger(const string& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	const auto value = m_CommandLineInformation.GetInteger(name);

	if (IsArgumentOutOfRange(value))
	{
		THROW_EXCEPTION(g_ArgumentOutOfRange);
	}

	return value;
}

float CoreTools::CommandHandle
	::GetFloat(const string& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	const auto value = m_CommandLineInformation.GetFloat(name);

	if (IsArgumentOutOfRange(value))
	{
		THROW_EXCEPTION(g_ArgumentOutOfRange);
	}

	return value;
}

double CoreTools::CommandHandle
	::GetDouble(const string& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	const auto value = m_CommandLineInformation.GetDouble(name);

	if (IsArgumentOutOfRange(value))
	{
		THROW_EXCEPTION(g_ArgumentOutOfRange);
	}

	return value;
}

const string CoreTools::CommandHandle
	::GetString(const string& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CommandLineInformation.GetString(name);
}

const string CoreTools::CommandHandle
	::GetFileName() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CommandLineInformation.GetFileName();
}

// private
bool CoreTools::CommandHandle
	::IsArgumentOutOfRange(double value) const noexcept
{
	if ((m_MinSet && value < m_Small) || (m_MaxSet && m_Large < value) || (m_InfSet && value <= m_Small) || (m_SupSet && m_Large <= value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CoreTools::CommandHandle
	::ClearBoundary() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_MinSet = false;
	m_MaxSet = false;
	m_InfSet = false;
	m_SupSet = false;
	m_Large = 0.0;
	m_Small = 0.0;
}

void CoreTools::CommandHandle
	::SetFileNmaeUsed()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_CommandLineInformation.SetFileNmaeUsed();
}

void CoreTools::CommandHandle
	::SetUsed(const string& argumentsName)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_CommandLineInformation.SetUsed(argumentsName);
}

int CoreTools::CommandHandle
	::GetExcessArgumentsCount() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CommandLineInformation.GetExcessArgumentsCount();
}



