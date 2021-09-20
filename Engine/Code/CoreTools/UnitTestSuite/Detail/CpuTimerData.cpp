//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 14:40)

#include "CoreTools/CoreToolsExport.h"

#include "CpuTimerData.h"
#include "System/Helper/PragmaWarning/Chrono.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::CpuTimerData::CpuTimerData()
    : m_CpuTimer{ make_shared<CpuTimer>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CpuTimerData::IsValid() const noexcept
{
    if (m_CpuTimer != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

const CoreTools::CpuTimerData::CpuTimerSharedPtr CoreTools::CpuTimerData::GetCpuTimer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_CpuTimer;
}

void CoreTools::CpuTimerData::Start() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_CpuTimer->start();
}

void CoreTools::CpuTimerData::Resume() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_CpuTimer->resume();
}

void CoreTools::CpuTimerData::Stop() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_CpuTimer->stop();
}
