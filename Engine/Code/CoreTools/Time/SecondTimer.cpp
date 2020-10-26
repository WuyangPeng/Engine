//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 19:34)

#include "CoreTools/CoreToolsExport.h"

#include "SecondTimer.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::SecondTimer::SecondTimer(uint64_t second)
    : m_Impl{ make_shared<ImplType>() }, m_Second{ second }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::SecondTimer::IsValid() const noexcept
{
    if (m_Impl != nullptr && 0 <= m_Second)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, SecondTimer)

uint64_t CoreTools::SecondTimer::GetRemain() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto elapsedTime = GetElapsedTime();

    if (elapsedTime <= m_Second)
        return m_Second - elapsedTime;
    else
        return 0;
}

uint64_t CoreTools::SecondTimer::GetElapsedTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetElapsedTimeInSeconds();
}

bool CoreTools::SecondTimer::IsElapsed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto elapsedTime = GetElapsedTime();

    if (m_Second <= elapsedTime)
        return true;
    else
        return false;
}

uint64_t CoreTools::SecondTimer::GetNowTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNowTimeInSeconds();
}

void CoreTools::SecondTimer::ReTiming(uint64_t second)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Impl->ResetCurrentTime();
    m_Second = second;
}
