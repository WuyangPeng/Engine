// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:54)

#include "Framework/FrameworkExport.h"

#include "PerformanceMeasurementsImpl.h"
#include "System/Time/Using/DeltaTimeUsing.h" 
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::array;
using std::string;

Framework::PerformanceMeasurementsImpl
	::PerformanceMeasurementsImpl(int maxTimer) noexcept
	:m_CustomTime{ }, m_AccumulatedTime{ 0 }, m_FrameCount{ 0 }, m_AccumulatedFrameCount{ 0 }, m_Timer{ maxTimer }, m_MaxTimer{ maxTimer }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::PerformanceMeasurementsImpl
	::IsValid() const noexcept
{
	if (0 <= m_AccumulatedTime && 0 <= m_FrameCount && 0 <= m_AccumulatedFrameCount && 0 <= m_Timer && 0 <= m_MaxTimer)
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
		return m_AccumulatedFrameCount / boost::numeric_cast<double>(m_AccumulatedTime) * System::g_Millisecond;
	else
		return 0.0;
}

string Framework::PerformanceMeasurementsImpl
	::GetFrameRateMessage() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	boost::format message{ "fps: %.2lf" };
	message % GetFrameRate();

	return message.str();
}

void Framework::PerformanceMeasurementsImpl
	::ResetTime() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_CustomTime.ResetCustomTime();

	m_AccumulatedTime = 0;
	m_FrameCount = 0;
	m_AccumulatedFrameCount = 0;
	m_Timer = m_MaxTimer;
}

void Framework::PerformanceMeasurementsImpl
	::MeasureTime() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (--m_Timer == 0)
	{
		const auto delta = m_CustomTime.GetThisElapsedMillisecondTime();
		m_AccumulatedTime += delta;
		m_AccumulatedFrameCount += m_FrameCount;
		m_FrameCount = 0;
		m_Timer = m_MaxTimer;
	}
}

void Framework::PerformanceMeasurementsImpl
	::UpdateFrameCount() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	++m_FrameCount;
}




