// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:53)

#ifndef CORE_TOOLS_COMMAND_MAIN_COMMAND_ARGUMENT_CONTAINER_H
#define CORE_TOOLS_COMMAND_MAIN_COMMAND_ARGUMENT_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentContainer.h" 

#include <vector>
#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE AnalysisCommandArgumentContainer
	{
	public:
		using ClassType = AnalysisCommandArgumentContainer;
		using CommandArgumentContainerSharedPtr = std::shared_ptr<CommandArgumentContainer>;

	public:
		AnalysisCommandArgumentContainer(int argumentsNumber, char** arguments);
		explicit AnalysisCommandArgumentContainer(char* commandLine);

		CommandArgumentContainerSharedPtr GetCommandArgumentContainer();

		CLASS_INVARIANT_DECLARE;

	private:
		enum class ArgumentsType 
		{
			FullArgument,
			NoValueArgument,
			EndArgumentValue,
		};

	private:
		void Init(char** arguments);
		void Init(char* commandLine);

		void AddCommandArguments();

		void AddArgumentValue(int index);
		void AddNoValueArgument(int index);
		void AddEndArgumentValue(int index);

		ArgumentsType GetArgumentsType(int index);
		ArgumentsType GetNextArgumentsType(int index);

	private:
		using ArgumentContainer = std::vector<std::string>;

	private:
		// 索引0为程序名。
		static constexpr auto sm_FristCheckIndex = 1;

		ArgumentContainer m_Argument;
		CommandArgumentContainerSharedPtr m_CommandArgumentContainer;
	};
}

#endif // CORE_TOOLS_COMMAND_MAIN_COMMAND_ARGUMENT_CONTAINER_H
