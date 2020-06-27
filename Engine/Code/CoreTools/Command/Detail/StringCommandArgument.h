// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:54)

#ifndef CORE_TOOLS_COMMAND_STRING_COMMAND_ARGUMENT_H
#define CORE_TOOLS_COMMAND_STRING_COMMAND_ARGUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentImpl.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE StringCommandArgument : public CommandArgumentImpl
	{
	public:
		using ClassType = StringCommandArgument;
		using ParentType = CommandArgumentImpl;

	public:
		StringCommandArgument(int index, const std::string& name, const std::string& value); 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual int GetInteger() const override;
		virtual float GetFloat() const override;
		virtual double GetDouble() const override;
		virtual const std::string GetString() const override;

		virtual bool IsInteger() const override;
		virtual bool IsFloat() const override;
		virtual bool IsDouble() const override;
		virtual bool IsString() const override;
		virtual bool IsNoValue() const override;

		virtual CommandArgumentSharedPtr Clone() const override;

		virtual void AddArgumentValue(const std::string& value) override;

	private:
		std::string m_String;
	};
}

#endif // CORE_TOOLS_COMMAND_STRING_COMMAND_ARGUMENT_H
