// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 16:58)

#include "CoreTools/CoreToolsExport.h"

#include "CustomTime.h"
#include "System/Time/DeltaTime.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/PosixTime.h" 
#include "System/Helper/PragmaWarning/Gregorian.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CustomTime
	::CustomTime()
	:m_StartTime{ System::GetTimeInMicroseconds() },
	m_CurrentTime{ 0 }, m_TimeLastTick{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

System::String CoreTools::CustomTime
	::GetSystemTimeDescribe()
{
	auto nowTime = boost::posix_time::second_clock::local_time();

	return boost::gregorian::to_simple_string_type<System::TChar>(nowTime.date());
}

System::String CoreTools::CustomTime
	::GetSystemTimeDescribe(const String& dateFormat)
{
	auto nowTime = boost::posix_time::second_clock::local_time();
	auto data = nowTime.date();
	boost::basic_format<System::TChar> format{ dateFormat };

	format % data.year();
	format % data.month();
	format % data.day();

	return format.str();
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CustomTime
	::IsValid() const noexcept
{
	if (0 <= m_StartTime && 0 <= m_CurrentTime && 0 <= m_TimeLastTick)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::CustomTime
	::ResetCustomTime() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_StartTime = System::GetTimeInMicroseconds();
	m_CurrentTime = 0;
	m_TimeLastTick = 0;
}

int64_t CoreTools::CustomTime
	::GetThisElapsedTime() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	MarkTimeThisTick();

	return m_TimeLastTick / System::g_Microseconds;
}

int64_t CoreTools::CustomTime
	::GetNowTime() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	MarkTimeThisTick();

	return m_CurrentTime / System::g_Microseconds;
}

int64_t CoreTools::CustomTime
	::GetThisElapsedMillisecondTime() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	MarkTimeThisTick();

	return m_TimeLastTick;
}

int64_t CoreTools::CustomTime
	::GetNowMillisecondTime() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	MarkTimeThisTick();

	return m_CurrentTime;
}

// private
void CoreTools::CustomTime
	::MarkTimeThisTick() noexcept
{
	auto newTime = System::GetTimeInMicroseconds() - m_StartTime;

	m_TimeLastTick = newTime - m_CurrentTime;
	m_CurrentTime = newTime;

	if (m_TimeLastTick <= 0)
	{
		m_TimeLastTick = 0;
	}
}
