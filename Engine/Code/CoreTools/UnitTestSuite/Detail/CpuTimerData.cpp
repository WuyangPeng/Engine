/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:23)

#include "CoreTools/CoreToolsExport.h"

#include "CpuTimerData.h"
#include "System/Helper/PragmaWarning/Chrono.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CpuTimerData::CpuTimerData(DisableNotThrow disableNotThrow)
    : cpuTimer{ std::make_shared<CpuTimer>() }
{
    System::UnusedFunction(disableNotThrow);

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

    if (this != &rhs)
    {
        cpuTimer = std::move(rhs.cpuTimer);
    }

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
