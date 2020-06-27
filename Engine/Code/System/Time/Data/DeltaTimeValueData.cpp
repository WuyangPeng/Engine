// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 13:21)

#include "System/SystemExport.h"

#include "DeltaTimeValueData.h"

System::DeltaTimeValueData
	::DeltaTimeValueData() noexcept
	:m_DeltaTimeValue{ }
{
}

System::DeltaTimeValueData
	::DeltaTimeValueData(const DeltaTimeValue& deltaTimeValue) noexcept
	:m_DeltaTimeValue{ deltaTimeValue }
{
}

System::DeltaTimeValueData
	::DeltaTimeValueData(int64_t second, int32_t microsecond) noexcept
	:m_DeltaTimeValue{ }
{
	m_DeltaTimeValue.tv_sec = second;
	m_DeltaTimeValue.tv_usec = microsecond;
}

const System::DeltaTimeValue System::DeltaTimeValueData
	::GetDeltaTimeValue() const noexcept
{
	return m_DeltaTimeValue;
}

void System::DeltaTimeValueData
	::SetValue(int64_t second, int32_t microsecond) noexcept
{
	m_DeltaTimeValue.tv_sec = second;
	m_DeltaTimeValue.tv_usec = microsecond;
}

int64_t System::DeltaTimeValueData
	::GetSecond() const noexcept
{
	return m_DeltaTimeValue.tv_sec;
}

int32_t System::DeltaTimeValueData
	::GetMicrosecond() const noexcept
{
	return m_DeltaTimeValue.tv_usec;
}

void System::DeltaTimeValueData
	::Correction() noexcept
{
	if (m_DeltaTimeValue.tv_usec < 0)
	{
		m_DeltaTimeValue.tv_usec += g_Microseconds;
		--m_DeltaTimeValue.tv_sec;
	}
}

System::DeltaTimeValueData System
	::operator-(const DeltaTimeValueData& lhs, const DeltaTimeValueData& rhs) noexcept
{
#ifdef SYSTEM_PLATFORM_MACOS

	auto copyLhs = lhs.GetDeltaTimeValue();
	auto copyRhs = rhs.GetDeltaTimeValue();
	DeltaTimeValue result{ };

	timersub(&copyLhs, &copyRhs, &result);

	return DeltaTimeValueData{ result };

#else // !SYSTEM_PLATFORM_MACOS

	DeltaTimeValueData result{ lhs.GetSecond() - rhs.GetSecond() , lhs.GetMicrosecond() - rhs.GetMicrosecond() };

	result.Correction();

	return result;

#endif // SYSTEM_PLATFORM_MACOS
}

