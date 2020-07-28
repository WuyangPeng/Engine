// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:29)

#include "CoreTools/CoreToolsExport.h"

#include "TryScopedMutex.h"
#include "DllMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"
CoreTools::TryScopedMutex
	::TryScopedMutex(MasterType& mutex)
	:m_Mutex{ mutex }, m_IsSuccess{ m_Mutex.TryEnter() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::TryScopedMutex
	::~TryScopedMutex()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;


#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)

	if (m_IsSuccess)
	{
		EXCEPTION_TRY
		{
			m_Mutex.Leave();
		}
		EXCEPTION_ALL_CATCH(CoreTools)		
	}

#include STSTEM_WARNING_POP
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TryScopedMutex)

bool CoreTools::TryScopedMutex
	::IsSuccess() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_IsSuccess;
}

