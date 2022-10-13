///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/20 20:38)

#include "PtrToIntTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::PtrToIntTesting::PtrToIntTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, PtrToIntTesting)

void System::PtrToIntTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::PtrToIntTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PtrToIntTest);
}

void System::PtrToIntTesting::PtrToIntTest()
{
    const int* ptr{ nullptr };
    const auto result = PtrConversionInt(ptr);

    ASSERT_EQUAL(result, 0);
}
