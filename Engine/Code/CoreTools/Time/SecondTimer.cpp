//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 19:34)

#include "CoreTools/CoreToolsExport.h"

#include "../Contract/Flags/ImplFlags.h"
#include "SecondTimer.h"
#include "Detail/DeltaTimeManagerImpl.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;

CoreTools::SecondTimer::SecondTimer(uint64_t second)
    : impl{ ImplCreateUseDefaultConstruction::Default }, m_Second{ second }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::SecondTimer::IsValid() const noexcept
{
    if (0 <= m_Second)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, SecondTimer)

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

    return impl->GetElapsedTimeInSeconds();
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

    return impl->GetNowTimeInSeconds();
}

void CoreTools::SecondTimer::ReTiming(uint64_t second)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl->ResetCurrentTime();
    m_Second = second;
}
