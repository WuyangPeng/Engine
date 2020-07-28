// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:29)

#include "CoreTools/CoreToolsExport.h"

#include "ScopedMutex.h"
#include "DllMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "../Helper/ExceptionMacro.h"
CoreTools::ScopedMutex
	::ScopedMutex(MasterType& mutex)
	:m_Mutex{ mutex }
{
	m_Mutex.Enter();

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ScopedMutex
	::~ScopedMutex()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
	 
		EXCEPTION_TRY
		{
			m_Mutex.Leave();
		}
		EXCEPTION_ALL_CATCH(CoreTools)	 

#include STSTEM_WARNING_POP 
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ScopedMutex)
