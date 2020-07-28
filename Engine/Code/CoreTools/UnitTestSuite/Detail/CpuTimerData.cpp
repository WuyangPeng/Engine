// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 10:18)

#include "CoreTools/CoreToolsExport.h"

#include "CpuTimerData.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/Timer.h"
#include "System/Helper/PragmaWarning/Chrono.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::CpuTimerData
	::CpuTimerData()
	:m_CpuTimerPtr{ make_shared<CpuTimer>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CpuTimerData
	::IsValid() const noexcept
{
	if (m_CpuTimerPtr != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const CoreTools::CpuTimerData::CpuTimerPtr CoreTools::CpuTimerData
	::GetCpuTimerPtr() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_CpuTimerPtr;
}

void CoreTools::CpuTimerData
	::Start() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_CpuTimerPtr->start();
}

void CoreTools::CpuTimerData
	::Resume() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_CpuTimerPtr->resume();
}

void CoreTools::CpuTimerData
	::Stop() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_CpuTimerPtr->stop();
}



