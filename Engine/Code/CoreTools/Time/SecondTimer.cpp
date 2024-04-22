/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:31)

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
    return 0 <= second;
}

#endif  // OPEN_CLASS_INVARIANT

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, SecondTimer)

int64_t CoreTools::SecondTimer::GetRemain() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto elapsedTime = GetElapsedTime();
        elapsedTime <= second)
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

    const auto elapsedTime = GetElapsedTime();

    return second <= elapsedTime;
}

int64_t CoreTools::SecondTimer::GetNowTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ImplType::GetNowTimeInSeconds();
}

void CoreTools::SecondTimer::ReTiming(int64_t aSecond)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl->ResetCurrentTime();
    second = aSecond;
}
