/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:29)

#include "CoreTools/CoreToolsExport.h"

#include "DeltaTimeManagerImpl.h"
#include "System/Time/Data/CurrentDeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::DeltaTimeManagerImpl::DeltaTimeManagerImpl() noexcept
    : initial{ System::CurrentDeltaTime{}.GetDeltaTimeValueData() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DeltaTimeManagerImpl);

int64_t CoreTools::DeltaTimeManagerImpl::GetElapsedTimeInMicroseconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const System::CurrentDeltaTime currentTime{};

    const auto result = currentTime.GetDeltaTimeValueData();

    const auto deltaTime = result - initial;

    return GetTimeInMicroseconds(deltaTime);
}

int64_t CoreTools::DeltaTimeManagerImpl::GetElapsedTimeInSeconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const System::CurrentDeltaTime currentTime{};

    const auto result = currentTime.GetDeltaTimeValueData();

    const auto deltaTime = result - initial;

    return GetTimeInSeconds(deltaTime);
}

void CoreTools::DeltaTimeManagerImpl::ResetCurrentTime() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const System::CurrentDeltaTime currentTime{};

    initial = currentTime.GetDeltaTimeValueData();
}

int64_t CoreTools::DeltaTimeManagerImpl::GetNowTimeInMicroseconds() noexcept
{
    const System::CurrentDeltaTime currentTime{};

    return GetTimeInMicroseconds(currentTime.GetDeltaTimeValueData());
}

int64_t CoreTools::DeltaTimeManagerImpl::GetNowTimeInSeconds() noexcept
{
    const System::CurrentDeltaTime currentTime{};

    return GetTimeInSeconds(currentTime.GetDeltaTimeValueData());
}
