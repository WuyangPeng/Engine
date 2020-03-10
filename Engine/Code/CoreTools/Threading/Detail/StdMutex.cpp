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
	::StdMutex()
	:m_Mutex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::StdMutex
	::~StdMutex()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StdMutex)

void CoreTools::StdMutex
	::Initialize()
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::StdMutex
	::Delete()
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
		m_Mutex.unlock();
	}
	EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
}

bool CoreTools::StdMutex
	::TryEnter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_Mutex.try_lock();
}



