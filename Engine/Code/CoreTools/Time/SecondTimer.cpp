///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:10)

#include "CoreTools/CoreToolsExport.h"

#include "SecondTimer.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::SecondTimer::SecondTimer(int64_t second)
    : impl{ ImplCreateUseDefaultConstruction::Default }, second{ second }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::SecondTimer::IsValid() const noexcept
{
    if (0 <= second)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, SecondTimer)

int64_t CoreTools::SecondTimer::GetRemain() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto elapsedTime = GetElapsedTime(); elapsedTime <= second)
        return second - elapsedTime;
    else
        return 0;
}

int64_t CoreTools::SecondTimer::GetElapsedTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetElapsedTimeInSeconds();
}

bool CoreTools::SecondTimer::IsElapsed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto elapsedTime = GetElapsedTime(); second <= elapsedTime)
        return true;
    else
        return false;
}

int64_t CoreTools::SecondTimer::GetNowTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetNowTimeInSeconds();
}

void CoreTools::SecondTimer::ReTiming(int64_t aSecond)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl->ResetCurrentTime();
    second = aSecond;
}
