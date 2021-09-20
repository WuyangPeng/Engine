//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 19:33)

#include "CoreTools/CoreToolsExport.h"

#include "../Contract/Flags/ImplFlags.h"
#include "DeltaTimeManager.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "System/Helper/PragmaWarning.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::DeltaTimeManager::DeltaTimeManager()
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DeltaTimeManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetElapsedTimeInMicroseconds, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetElapsedTimeInSeconds, uint64_t)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, DeltaTimeManager, ResetCurrentTime, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetNowTimeInMicroseconds, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetNowTimeInSeconds, uint64_t)
COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, DeltaTimeManager)