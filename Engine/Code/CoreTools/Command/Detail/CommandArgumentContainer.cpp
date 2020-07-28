// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 11:11)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentContainerDetail.h"
#include "CommandArgumentType.h"
#include "CoreTools/Command/CommandArgument.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using namespace std::literals;

CoreTools::CommandArgumentContainer
	::CommandArgumentContainer(int argumentsNumber)
	:m_ArgumentsNumber{ argumentsNumber }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CommandArgumentContainer
	::IsValid() const noexcept
{
	if (0 < m_ArgumentsNumber)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::CommandArgumentContainer
	::AddArgument(int index, const string& argumentsName, const string& argumentsValue)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(0 < index && index < m_ArgumentsNumber, "索引错误！");

	CommandArgument commandArgument{ index, argumentsName, argumentsValue };
	m_CommandArgument.insert({ argumentsName, commandArgument });
}

void CoreTools::CommandArgumentContainer
	::AddArgument(int index, const string& argumentsName)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(0 < index && index < m_ArgumentsNumber, "索引错误！");

	CommandArgument commandArgument{ index, argumentsName };
	m_CommandArgument.insert({ argumentsName, commandArgument });
}

int CoreTools::CommandArgumentContainer
	::GetArgumentsNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_ArgumentsNumber;
}

bool CoreTools::CommandArgumentContainer
	::IsUsed(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::IsUsed);
}

void CoreTools::CommandArgumentContainer
	::SetUsed(const string& argumentsName)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	const auto iter = m_CommandArgument.find(argumentsName);

	if (iter != m_CommandArgument.cend())
	{
		auto& commandArgument = iter->second;

		return commandArgument.SetUsed();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("未找到命令行索引！"s));
	}
}

int CoreTools::CommandArgumentContainer
	::GetIndex(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::GetIndex);
}

int CoreTools::CommandArgumentContainer
	::GetInteger(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::GetInteger);
}

float CoreTools::CommandArgumentContainer
	::GetFloat(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::GetFloat);
}

double CoreTools::CommandArgumentContainer
	::GetDouble(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::GetDouble);
}

const string CoreTools::CommandArgumentContainer
	::GetString(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::GetString);
}

bool CoreTools::CommandArgumentContainer
	::IsInteger(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::IsInteger);
}

bool CoreTools::CommandArgumentContainer
	::IsFloat(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::IsFloat);
}

bool CoreTools::CommandArgumentContainer
	::IsDouble(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::IsDouble);
}

bool CoreTools::CommandArgumentContainer
	::IsString(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return Find(argumentsName, &CommandArgument::IsString);
}

bool CoreTools::CommandArgumentContainer
	::IsExist(const string& argumentsName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	const auto iter = m_CommandArgument.find(argumentsName);

	if (iter != m_CommandArgument.cend())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CoreTools::CommandArgumentContainer
	::AddEndArgumentValue(const string& argumentsValue)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (!m_CommandArgument.empty())
	{
		auto iter = m_CommandArgument.end();
		--iter;

		auto& commandArgument = iter->second;

		commandArgument.AddEndArgumentValue(argumentsValue);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("命令行不允许以字符串打头！"s));
	}
}

const string CoreTools::CommandArgumentContainer
	::ExcessArguments() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	for (const auto& value : m_CommandArgument)
	{
		const auto& commandArgument = value.second;
		if (!commandArgument.IsUsed())
		{
			return commandArgument.GetName();
		}
	}

	THROW_EXCEPTION(SYSTEM_TEXT("命令行没有未处理的参数！"s));
}

int CoreTools::CommandArgumentContainer
	::GetExcessArgumentsCount() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	int count{ 0 };

	for (const auto& value : m_CommandArgument)
	{
		const auto& commandArgument = value.second;
		if (!commandArgument.IsUsed())
		{
			++count;
		}
	}

	return count;
}

