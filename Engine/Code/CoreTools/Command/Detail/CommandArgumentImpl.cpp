// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 11:13)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::CommandArgumentImpl
	::CommandArgumentImpl(int index, const std::string& name)
	:m_Index{ index }, m_Name{ name }, m_Used{ false }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
} 

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CommandArgumentImpl
	::IsValid() const noexcept
{
	if (1 <= m_Index)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::CommandArgumentImpl
	::GetIndex() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Index;
}

const string CoreTools::CommandArgumentImpl
	::GetName() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Name;
}

bool CoreTools::CommandArgumentImpl
	::IsUsed() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Used;
}

void CoreTools::CommandArgumentImpl
	::SetUsed() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Used = true;
}

