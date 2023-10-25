///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:14)

#include "CoreTools/CoreToolsExport.h"

#include "DeltaTimeManager.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, DeltaTimeManager)

CoreTools::DeltaTimeManager CoreTools::DeltaTimeManager::Create()
{
    return DeltaTimeManager{ DisableNotThrow::Disable };
}

CoreTools::DeltaTimeManager::DeltaTimeManager(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DeltaTimeManager)

void CoreTools::DeltaTimeManager::ResetCurrentTime()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->ResetCurrentTime();
}

int64_t CoreTools::DeltaTimeManager::GetElapsedTimeInMicroseconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetElapsedTimeInMicroseconds();
}

int64_t CoreTools::DeltaTimeManager::GetElapsedTimeInSeconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetElapsedTimeInSeconds();
}

int64_t CoreTools::DeltaTimeManager::GetNowTimeInMicroseconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetNowTimeInMicroseconds();
}

int64_t CoreTools::DeltaTimeManager::GetNowTimeInSeconds() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetNowTimeInSeconds();
}
