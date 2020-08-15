// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:22)

#include "CoreTools/CoreToolsExport.h"

#include "StdMutex.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

using std::exception;

CoreTools::StdMutex
	::StdMutex() noexcept
	:m_Mutex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9; 
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StdMutex)

void CoreTools::StdMutex
	::Initialize() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::StdMutex
	::Delete() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::StdMutex
	::Enter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Mutex.lock();
}

void CoreTools::StdMutex
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

bool CoreTools::StdMutex
	::TryEnter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_Mutex.try_lock();
}



