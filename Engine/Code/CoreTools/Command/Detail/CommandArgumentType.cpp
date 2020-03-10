// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:13)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentType.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::CommandArgumentType
	::CommandArgumentType(const string& argument)
	:m_Argument{ argument }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CommandArgumentType)

bool CoreTools::CommandArgumentType
	::IsArgumentsName() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (!m_Argument.empty() && m_Argument[0] == '-' && 1 < m_Argument.size())
		return true;
	else
		return false;
}

bool CoreTools::CommandArgumentType
	::IsDigit() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (m_Argument.empty() || m_Argument[0] == '-' || !isdigit(m_Argument[0]))
		return false;
	else
		return true;
}

bool CoreTools::CommandArgumentType
	::IsString() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (!m_Argument.empty() && m_Argument[0] != '-')
		return true;
	else
		return false;
}
