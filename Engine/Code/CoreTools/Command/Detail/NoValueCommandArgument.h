// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:54)

#ifndef CORE_TOOLS_COMMAND_NO_VALUE_COMMAND_ARGUMENT_H
#define CORE_TOOLS_COMMAND_NO_VALUE_COMMAND_ARGUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentImpl.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE NoValueCommandArgument : public CommandArgumentImpl
	{
	public:
		using ClassType = NoValueCommandArgument;
		using ParentType = CommandArgumentImpl;

	public:
		NoValueCommandArgument(int index, const std::string& name); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		int GetInteger() const override;
		float GetFloat() const override;
		double GetDouble() const override;
		const std::string GetString() const override;

		bool IsInteger() const noexcept override;
		bool IsFloat() const noexcept override;
		bool IsDouble() const noexcept override;
		bool IsString() const noexcept override;
		bool IsNoValue() const noexcept override;

		CommandArgumentSharedPtr Clone() const override;

		void AddArgumentValue(const std::string& value) override;
	};
}

#endif // CORE_TOOLS_COMMAND_NO_VALUE_COMMAND_ARGUMENT_H
