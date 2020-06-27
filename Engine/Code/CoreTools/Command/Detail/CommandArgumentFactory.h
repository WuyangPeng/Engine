// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:54)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_FACTORY_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include <string>
#include <memory>

namespace CoreTools
{
	class CommandArgumentImpl;

	class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentFactory
	{
	public:
		using ClassType = CommandArgumentFactory;
		using CommandArgumentSharedPtr = std::shared_ptr<CommandArgumentImpl>;

	public:
		static CommandArgumentSharedPtr Create(int index, const std::string& arguments, const std::string& value);
		static CommandArgumentSharedPtr Create(int index, const std::string& arguments);
	};
}

#endif // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_FACTORY_H
