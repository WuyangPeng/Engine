///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/13 11:34)

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

    const auto msecs = GetMilliseconds();

    return static_cast<double>(msecs) / 1000.0;
}

void CoreTools::TimerImpl::Reset() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    initialTime = std::chrono::high_resolution_clock::now();
}