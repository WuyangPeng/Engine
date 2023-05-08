///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:10)

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetElapsedTimeInMicroseconds, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetElapsedTimeInSeconds, int64_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, DeltaTimeManager, ResetCurrentTime, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetNowTimeInMicroseconds, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetNowTimeInSeconds, int64_t)
