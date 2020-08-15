// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:16)

#include "CoreTools/CoreToolsExport.h"

#include "BoostMutex.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

CoreTools::BoostMutex
	::BoostMutex() noexcept
	:m_Mutex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BoostMutex)

void CoreTools::BoostMutex
	::Initialize() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::BoostMutex
	::Delete() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::BoostMutex
	::Enter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Mutex.lock();
}

void CoreTools::BoostMutex
	::Leave()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	EXCEPTION_TRY
	{
		m_Mutex.unlock();
	}
	EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
}

bool CoreTools::BoostMutex
	::TryEnter() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_Mutex.try_lock();
}



