// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:23)

#include "CoreTools/CoreToolsExport.h"

#include "StdRecursiveMutex.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

CoreTools::StdRecursiveMutex
	::StdRecursiveMutex()
	:m_Mutex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::StdRecursiveMutex
	::~StdRecursiveMutex()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StdRecursiveMutex)

void CoreTools::StdRecursiveMutex
	::Initialize()
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::StdRecursiveMutex
	::Delete()
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::StdRecursiveMutex
	::Enter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Mutex.lock();
}

void CoreTools::StdRecursiveMutex
	::Leave()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	EXCEPTION_TRY
	{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26110)

		m_Mutex.unlock();

#include STSTEM_WARNING_POP
	}
	EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
}

bool CoreTools::StdRecursiveMutex
	::TryEnter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_Mutex.try_lock();
}



