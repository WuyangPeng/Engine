/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:31)

#include "CoreTools/CoreToolsExport.h"

#include "MillisecondTimer.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, MillisecondTimer)

CoreTools::MillisecondTimer::MillisecondTimer(int64_t millisecond)
    : impl{ ImplCreateUseDefaultConstruction::Default }, millisecond{ millisecond }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::MillisecondTimer::IsValid() const noexcept
{
    return 0 <= millisecond;
}

#endif  // OPEN_CLASS_INVARIANT

int64_t CoreTools::MillisecondTimer::GetRemain() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto elapsedTime = GetElapsedTime(); elapsedTime <= millisecond)
        return millisecond - elapsedTime;
    else
        return 0;
}

int64_t CoreTools::MillisecondTimer::GetElapsedTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetElapsedTimeInMicroseconds() / System::gMillisecond;
}

bool CoreTools::MillisecondTimer::IsElapsed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto elapsedTime = GetElapsedTime();

    return millisecond <= elapsedTime;
}

int64_t CoreTools::MillisecondTimer::GetNowTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ImplType::GetNowTimeInMicroseconds() / System::gMillisecond;
}

void CoreTools::MillisecondTimer::ReTiming(int64_t aMillisecond)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl->ResetCurrentTime();
    millisecond = aMillisecond;
}
