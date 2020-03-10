// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:54)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_IMPL_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentImpl
	{
	public:
		using ClassType = CommandArgumentImpl;
		using CommandArgumentSharedPtr = std::shared_ptr<CommandArgumentImpl>;

	public:
		CommandArgumentImpl(int index, const std::string& name);
		virtual ~CommandArgumentImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		int GetIndex() const noexcept;
		const std::string GetName() const;

		virtual int GetInteger() const = 0;
		virtual float GetFloat() const = 0;
		virtual double GetDouble() const = 0;
		virtual const std::string GetString() const = 0;

		virtual bool IsInteger() const = 0;
		virtual bool IsFloat() const = 0;
		virtual bool IsDouble() const = 0;
		virtual bool IsString() const = 0;
		virtual bool IsNoValue() const = 0;

		bool IsUsed() const noexcept;
		void SetUsed() noexcept;

		virtual CommandArgumentSharedPtr Clone() const = 0;

		virtual void AddArgumentValue(const std::string& value) = 0;

	private:
		int m_Index;
		std::string m_Name;
		bool m_Used; // 跟踪已处理的参数	
	};
}

#endif // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_IMPL_H
