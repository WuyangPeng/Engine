//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/24 12:48)

#include "System/SystemExport.h"

#include "CurrentDeltaTime.h"

System::CurrentDeltaTime::CurrentDeltaTime() noexcept
    : m_CurrentTime{}
{
#ifdef SYSTEM_PLATFORM_MACOS
    ::gettimeofday(&m_CurrentTime, nullptr);
#else  // !SYSTEM_PLATFORM_MACOS
    ::ftime(&m_CurrentTime);
#endif  // SYSTEM_PLATFORM_MACOS
}

const System::DeltaTimeValueData System::CurrentDeltaTime::GetDeltaTimeValueData() const noexcept
{
#ifdef SYSTEM_PLATFORM_MACOS
    return DeltaTimeValueData(m_CurrentTime);
#else  // !SYSTEM_PLATFORM_MACOS
    return DeltaTimeValueData(m_CurrentTime.time, g_Millisecond * m_CurrentTime.millitm);
#endif  // SYSTEM_PLATFORM_MACOS
}
