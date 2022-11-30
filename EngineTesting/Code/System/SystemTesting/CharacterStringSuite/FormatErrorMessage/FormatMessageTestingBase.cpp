///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/26 22:29)

#include "FormatMessageTestingBase.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatMessageTestingBase::FormatMessageTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatMessageTestingBase)

void System::FormatMessageTestingBase::LocalMemoryFreeTest(WindowsHLocal errorMessage)
{
    if (errorMessage != nullptr)
    {
        ASSERT_TRUE(LocalMemoryFree(errorMessage));
    }
}
