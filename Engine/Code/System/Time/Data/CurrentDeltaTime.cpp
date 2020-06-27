// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 13:20)

#include "System/SystemExport.h"

#include "CurrentDeltaTime.h"

System::CurrentDeltaTime
	::CurrentDeltaTime() noexcept
	:m_CurrentTime{ }
{
#ifdef SYSTEM_PLATFORM_MACOS
	::gettimeofday(&m_CurrentTime, nullptr);
#else // !SYSTEM_PLATFORM_MACOS
	::ftime(&m_CurrentTime);
#endif // SYSTEM_PLATFORM_MACOS
}

const System::DeltaTimeValueData System::CurrentDeltaTime
	::GetDeltaTimeValueData() const noexcept
{
#ifdef SYSTEM_PLATFORM_MACOS
	return DeltaTimeValueData(m_CurrentTime);
#else // !SYSTEM_PLATFORM_MACOS
	return DeltaTimeValueData(m_CurrentTime.time, g_Millisecond * m_CurrentTime.millitm);
#endif // SYSTEM_PLATFORM_MACOS
}

