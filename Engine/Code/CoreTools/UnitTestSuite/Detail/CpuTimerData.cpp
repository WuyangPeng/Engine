///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 18:00)

#include "CoreTools/CoreToolsExport.h"

#include "CpuTimerData.h"
#include "System/Helper/PragmaWarning/Chrono.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::CpuTimerData::CpuTimerData(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : cpuTimer{ make_shared<CpuTimer>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CpuTimerData::CpuTimerData(CpuTimerData&& rhs) noexcept
    : cpuTimer{ std::move(rhs.cpuTimer) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CpuTimerData& CoreTools::CpuTimerData::operator=(CpuTimerData&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    cpuTimer = std::move(rhs.cpuTimer);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CpuTimerData::IsValid() const noexcept
{
    if (cpuTimer != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::CpuTimerData::ConstCpuTimerSharedPtr CoreTools::CpuTimerData::GetCpuTimer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return cpuTimer;
}

void CoreTools::CpuTimerData::Start() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    cpuTimer->start();
}

void CoreTools::CpuTimerData::Resume() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    cpuTimer->resume();
}

void CoreTools::CpuTimerData::Stop() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    cpuTimer->stop();
}

CoreTools::CpuTimerData CoreTools::CpuTimerData::Create()
{
    return CpuTimerData{ DisableNotThrow::Disable };
}

CoreTools::CpuTimerData::CpuTimerDataSharedPtr CoreTools::CpuTimerData::CreateSharedPtr()
{
    return std::make_shared<ClassType>(Create());
}
