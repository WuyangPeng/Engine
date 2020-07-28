// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 16:57)

#include "CoreTools/CoreToolsExport.h"

#include "DeltaTimeManager.h"
#include "Detail/DeltaTimeManagerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::DeltaTimeManager
	::DeltaTimeManager()
	:m_Impl{ make_shared<ImplType>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, DeltaTimeManager)

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, DeltaTimeManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetElapsedTimeInMicroseconds, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetElapsedTimeInSeconds, uint64_t)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(CoreTools, DeltaTimeManager, ResetCurrentTime, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetNowTimeInMicroseconds, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, DeltaTimeManager, GetNowTimeInSeconds, uint64_t)


