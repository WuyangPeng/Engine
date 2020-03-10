// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:54)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Command/CommandArgument.h"

#include <string>
#include <map>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentContainer
	{
	public:
		using ClassType = CommandArgumentContainer;

	public:
		explicit CommandArgumentContainer(int argumentsNumber);

		CLASS_INVARIANT_DECLARE;

		void AddArgument(int index, const std::string& argumentsName);
		void AddArgument(int index, const std::string& argumentsName, const std::string& argumentsValue);
		void AddEndArgumentValue(const std::string& argumentsValue);

		int GetArgumentsNumber() const noexcept;

		bool IsUsed(const std::string& argumentsName) const;
		void SetUsed(const std::string& argumentsName);

		int GetIndex(const std::string& argumentsName) const;

		int GetInteger(const std::string& argumentsName) const;
		float GetFloat(const std::string& argumentsName) const;
		double GetDouble(const std::string& argumentsName) const;
		const std::string GetString(const std::string& argumentsName) const;

		bool IsInteger(const std::string& argumentsName) const;
		bool IsFloat(const std::string& argumentsName) const;
		bool IsDouble(const std::string& argumentsName) const;
		bool IsString(const std::string& argumentsName) const;
		bool IsExist(const std::string& argumentsName) const;

		// 返回第一个未处理参数的名字。		
		const std::string ExcessArguments() const;
		int GetExcessArgumentsCount() const;

	private:
		using CommandArgumentUsedContainer = std::map<std::string, CommandArgument>;

	private:
		template<typename R>
		R Find(const std::string& argumentsName, R(CommandArgument::*function)() const) const;

	private:
		int m_ArgumentsNumber;
		CommandArgumentUsedContainer m_CommandArgument;
	};
}

#endif // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_CONTAINER_H
