// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 16:57)

#include "CoreTools/CoreToolsExport.h"

#include "SecondTimer.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::SecondTimer
	::SecondTimer(uint64_t second)
	:m_Impl{ make_shared<ImplType>() }, m_Second{ second }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::SecondTimer
	::IsValid() const noexcept
{
	if (m_Impl != nullptr && 0 <= m_Second)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, SecondTimer)

uint64_t CoreTools::SecondTimer
	::GetRemain() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto elapsedTime = GetElapsedTime();

	if (elapsedTime <= m_Second)
		return m_Second - elapsedTime;
	else
		return 0;
}

uint64_t CoreTools::SecondTimer
	::GetElapsedTime() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetElapsedTimeInSeconds();
}

bool CoreTools::SecondTimer
	::IsElapsed() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto elapsedTime = GetElapsedTime();

	if (m_Second <= elapsedTime)
		return true;
	else
		return false;
}

uint64_t CoreTools::SecondTimer
	::GetNowTime() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetNowTimeInSeconds();
}

void CoreTools::SecondTimer
	::ReTiming(uint64_t second)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->ResetCurrentTime();
	m_Second = second;
}
