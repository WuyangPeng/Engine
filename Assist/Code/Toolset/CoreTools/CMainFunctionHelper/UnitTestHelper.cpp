// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/03 22:50)

#include "UnitTestHelper.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26455)
CMainFunctionHelper::UnitTestHelper ::UnitTestHelper()
    : ParentType{ OStreamShared{} }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CMainFunctionHelper, UnitTestHelper)

void CMainFunctionHelper::UnitTestHelper ::DoRunUnitTest() noexcept
{
}
