//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 19:33)

#include "CoreTools/CoreToolsExport.h"

#include "../Contract/Flags/ImplFlags.h"
#include "MillisecondTimer.h"
#include "Detail/DeltaTimeManagerImpl.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;

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

    return impl->GetElapsedTimeInMicroseconds() / System::g_Millisecond;
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

    return impl->GetNowTimeInMicroseconds() / System::g_Millisecond;
}

void CoreTools::MillisecondTimer::ReTiming(uint64_t millisecond)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl->ResetCurrentTime();
    m_Millisecond = millisecond;
}
COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, MillisecondTimer)