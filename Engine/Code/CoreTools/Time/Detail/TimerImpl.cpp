///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:09)

#include "CoreTools/CoreToolsExport.h"

#include "TimerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::TimerImpl::TimerImpl() noexcept
    : initialTime{ std::chrono::high_resolution_clock::now() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TimerImpl);

int64_t CoreTools::TimerImpl::GetNanoseconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto currentTime = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - initialTime).count();
}

int64_t CoreTools::TimerImpl::GetMicroseconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto currentTime = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(currentTime - initialTime).count();
}

int64_t CoreTools::TimerImpl::GetMilliseconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto currentTime = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - initialTime).count();
}

double CoreTools::TimerImpl::GetSeconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto milliseconds = GetMilliseconds();

    return static_cast<double>(milliseconds) / 1000.0;
}

void CoreTools::TimerImpl::Reset() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    initialTime = std::chrono::high_resolution_clock::now();
}
