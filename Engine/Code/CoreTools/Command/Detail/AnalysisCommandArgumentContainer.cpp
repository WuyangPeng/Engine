// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:55)

#include "CoreTools/CoreToolsExport.h"

#include "AnalysisCommandArgumentContainer.h"
#include "CommandArgumentType.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp> 

using std::string;
using std::make_pair;
using std::make_shared;

CoreTools::AnalysisCommandArgumentContainer
	::AnalysisCommandArgumentContainer(int argumentsNumber, char** arguments)
	:m_Argument{}, m_CommandArgumentContainer{ make_shared<CommandArgumentContainer>(argumentsNumber) }
{
	Init(arguments);
	AddCommandArguments();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AnalysisCommandArgumentContainer
	::Init(char** arguments)
{
	auto argumentsNumber = m_CommandArgumentContainer->GetArgumentsNumber();

	for (auto i = 0; i < argumentsNumber; ++i)
	{
		CORE_TOOLS_ASSERTION_0(arguments[i] != nullptr, "命令行参数无效！");

		string argument{ arguments[i] != nullptr ? arguments[i] : "" };

		m_Argument.push_back(argument);
	}
}

CoreTools::AnalysisCommandArgumentContainer
	::AnalysisCommandArgumentContainer(char* commandLine)
	:m_Argument{}, m_CommandArgumentContainer{}
{
	Init(commandLine);
	AddCommandArguments();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AnalysisCommandArgumentContainer
	::Init(char* commandLine)
{
	string trimCommandLine{ commandLine };
	boost::algorithm::trim(trimCommandLine);
	boost::algorithm::split(m_Argument, trimCommandLine, boost::is_any_of(" \t"), boost::token_compress_on);

	auto argumentsNumber = boost::numeric_cast<int>(m_Argument.size());

	m_CommandArgumentContainer = make_shared<CommandArgumentContainer>(argumentsNumber);
}

// private
void CoreTools::AnalysisCommandArgumentContainer
	::AddCommandArguments()
{
	// 从1开始索引
	auto index = sm_FristCheckIndex;
	auto argumentsNumber = boost::numeric_cast<int>(m_Argument.size());
	while (index < argumentsNumber)
	{
		auto argumentsType = GetArgumentsType(index);

		switch (argumentsType)
		{
			case ArgumentsType::FullArgument:
				AddArgumentValue(index);
				index += 2;
				break;
			case ArgumentsType::NoValueArgument:
				AddNoValueArgument(index);
				++index;
				break;
			case ArgumentsType::EndArgumentValue:
				AddEndArgumentValue(index);
				++index;
				break;
			default:
				break;
		}
	}
}

CoreTools::AnalysisCommandArgumentContainer::ArgumentsType CoreTools::AnalysisCommandArgumentContainer
	::GetArgumentsType(int index)
{
	const auto& argumentsName = m_Argument[index];

	CommandArgumentType argumentsNameType{ argumentsName };

	if (argumentsNameType.IsArgumentsName())
	{
		return GetNextArgumentsType(index);
	}
	else
	{
		return ArgumentsType::EndArgumentValue;
	}
}

CoreTools::AnalysisCommandArgumentContainer::ArgumentsType CoreTools::AnalysisCommandArgumentContainer
	::GetNextArgumentsType(int index)
{
	auto argumentsNumber = boost::numeric_cast<int>(m_Argument.size());

	auto nextIndex = index + 1;

	if (nextIndex < argumentsNumber)
	{
		const auto& argumentsValue = m_Argument[nextIndex];

		CommandArgumentType argumentsValueType{ argumentsValue };

		if (!argumentsValueType.IsArgumentsName())
		{
			return ArgumentsType::FullArgument;
		}
	}

	return ArgumentsType::NoValueArgument;
}

void CoreTools::AnalysisCommandArgumentContainer
	::AddArgumentValue(int index)
{
	auto argumentsName = m_Argument[index].substr(1, m_Argument[index].size() - 1);

	auto nextIndex = index + 1;

	string argumentsValue{ m_Argument[nextIndex] };

	m_CommandArgumentContainer->AddArgument(index, argumentsName, argumentsValue);
}

void CoreTools::AnalysisCommandArgumentContainer
	::AddNoValueArgument(int index)
{
	CommandArgumentType commandArgumentType{ m_Argument[index] };

	if (commandArgumentType.IsArgumentsName())
	{
		auto argumentsName = m_Argument[index].substr(1, m_Argument[index].size() - 1);
		m_CommandArgumentContainer->AddArgument(index, argumentsName);
	}
}

void CoreTools::AnalysisCommandArgumentContainer
	::AddEndArgumentValue(int index)
{
	const auto& argumentsName = m_Argument[index];

	m_CommandArgumentContainer->AddEndArgumentValue(argumentsName);
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::AnalysisCommandArgumentContainer
	::IsValid() const noexcept
{
	if (m_CommandArgumentContainer != nullptr && m_CommandArgumentContainer->GetArgumentsNumber() == static_cast<int>(m_Argument.size()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::AnalysisCommandArgumentContainer::CommandArgumentContainerSharedPtr CoreTools::AnalysisCommandArgumentContainer
	::GetCommandArgumentContainer()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_CommandArgumentContainer;
}

