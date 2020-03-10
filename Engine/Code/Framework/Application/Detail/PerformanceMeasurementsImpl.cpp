// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:17)

#include "Framework/FrameworkExport.h"

#include "PerformanceMeasurementsImpl.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/CharacterString/FormatString.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::PerformanceMeasurementsImpl
	::PerformanceMeasurementsImpl(int maxTimer)
	:m_CustomTime(),
	 m_AccumulatedTime(0),
	 m_FrameCount(0),
	 m_AccumulatedFrameCount(0),
	 m_Timer(maxTimer),
	 m_MaxTimer(maxTimer)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::PerformanceMeasurementsImpl
	::IsValid() const noexcept
{
	if(0 <= m_AccumulatedTime &&
	   0 <= m_FrameCount &&
	   0 <= m_AccumulatedFrameCount &&
	   0 <= m_Timer &&
	   0 <= m_MaxTimer)
	    return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT

double Framework::PerformanceMeasurementsImpl
	::GetFrameRate() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if (0 < m_AccumulatedTime)	
		return m_AccumulatedFrameCount / static_cast<double>(m_AccumulatedTime) * System::g_Microseconds;
	else	
		return  0.0;	
}

void Framework::PerformanceMeasurementsImpl
	::ResetTime()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_CustomTime.ResetCustomTime();

	m_AccumulatedTime = 0;
	m_FrameCount = 0;
	m_AccumulatedFrameCount = 0;
	m_Timer = m_MaxTimer;
}

void Framework::PerformanceMeasurementsImpl
	::MeasureTime()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (--m_Timer == 0)
	{		
		int64_t delta = m_CustomTime.GetThisElapsedMillisecondTime();
		m_AccumulatedTime += delta;
		m_AccumulatedFrameCount += m_FrameCount;
		m_FrameCount = 0;
		m_Timer = m_MaxTimer;
	}
}

void Framework::PerformanceMeasurementsImpl
	::UpdateFrameCount()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	 ++m_FrameCount;
}

std::string Framework::PerformanceMeasurementsImpl
	::GetFrameRateMessage() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	const int size = 256;

	char message[size];
	System::SNPrintf(message, size, size, "fps: %.1lf", GetFrameRate());

	return message;
}


