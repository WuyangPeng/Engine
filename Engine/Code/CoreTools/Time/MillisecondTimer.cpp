// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 16:57)

#include "CoreTools/CoreToolsExport.h"

#include "MillisecondTimer.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::MillisecondTimer
	::MillisecondTimer(uint64_t millisecond)
	:m_Impl{ make_shared<ImplType>() }, m_Millisecond{ millisecond }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MillisecondTimer
	::IsValid() const noexcept
{
	if (m_Impl != nullptr && 0 <= m_Millisecond)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, MillisecondTimer)

uint64_t CoreTools::MillisecondTimer
	::GetRemain() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto elapsedTime = GetElapsedTime();

	if (elapsedTime <= m_Millisecond)
		return m_Millisecond - elapsedTime;
	else
		return 0;
}

uint64_t CoreTools::MillisecondTimer
	::GetElapsedTime() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetElapsedTimeInMicroseconds() / System::g_Millisecond;
}

bool CoreTools::MillisecondTimer
	::IsElapsed() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto elapsedTime = GetElapsedTime();

	if (m_Millisecond <= elapsedTime)
		return true;
	else
		return false;
}

uint64_t CoreTools::MillisecondTimer
	::GetNowTime() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetNowTimeInMicroseconds() / System::g_Millisecond;
}

void CoreTools::MillisecondTimer
	::ReTiming(uint64_t millisecond)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->ResetCurrentTime();
	m_Millisecond = millisecond;
}
