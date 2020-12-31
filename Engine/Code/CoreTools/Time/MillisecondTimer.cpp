//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 19:33)

#include "CoreTools/CoreToolsExport.h"

#include "MillisecondTimer.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::MillisecondTimer::MillisecondTimer(uint64_t millisecond)
    : m_Impl{ make_shared<ImplType>() }, m_Millisecond{ millisecond }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MillisecondTimer::IsValid() const noexcept
{
    if (m_Impl != nullptr && 0 <= m_Millisecond)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, MillisecondTimer)

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

    return m_Impl->GetElapsedTimeInMicroseconds() / System::g_Millisecond;
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

    return m_Impl->GetNowTimeInMicroseconds() / System::g_Millisecond;
}

void CoreTools::MillisecondTimer::ReTiming(uint64_t millisecond)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Impl->ResetCurrentTime();
    m_Millisecond = millisecond;
}
