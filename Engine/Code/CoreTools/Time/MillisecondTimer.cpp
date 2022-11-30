///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/16 21:57)

#include "CoreTools/CoreToolsExport.h"

#include "MillisecondTimer.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, MillisecondTimer)

CoreTools::MillisecondTimer::MillisecondTimer(uint64_t millisecond)
    : impl{ ImplCreateUseDefaultConstruction::Default }, m_Millisecond{ millisecond }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::MillisecondTimer::IsValid() const noexcept
{
    if (0 <= m_Millisecond)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

uint64_t CoreTools::MillisecondTimer::GetRemain() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto elapsedTime = GetElapsedTime();

    if (elapsedTime <= m_Millisecond)
        return m_Millisecond - elapsedTime;
    else
        return 0;
}

uint64_t CoreTools::MillisecondTimer::GetElapsedTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetElapsedTimeInMicroseconds() / System::gMillisecond;
}

bool CoreTools::MillisecondTimer::IsElapsed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto elapsedTime = GetElapsedTime();

    if (m_Millisecond <= elapsedTime)
        return true;
    else
        return false;
}

uint64_t CoreTools::MillisecondTimer::GetNowTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetNowTimeInMicroseconds() / System::gMillisecond;
}

void CoreTools::MillisecondTimer::ReTiming(uint64_t millisecond)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl->ResetCurrentTime();
    m_Millisecond = millisecond;
}
