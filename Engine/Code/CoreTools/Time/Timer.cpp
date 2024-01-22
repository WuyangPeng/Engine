/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:19)

#include "CoreTools/CoreToolsExport.h"

#include "Timer.h"
#include "Detail/TimerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, Timer)

CoreTools::Timer CoreTools::Timer::Create()
{
    return Timer{ DisableNotThrow::Disable };
}

CoreTools::Timer::Timer(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Timer)

int64_t CoreTools::Timer::GetNanoseconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetNanoseconds();
}

int64_t CoreTools::Timer::GetMicroseconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetMicroseconds();
}

int64_t CoreTools::Timer::GetMilliseconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetMilliseconds();
}

double CoreTools::Timer::GetSeconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetSeconds();
}

void CoreTools::Timer::Reset() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Reset();
}
