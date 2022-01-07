///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/16 19:44)

#include "UnusedFunctionTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;
using namespace std::literals;

System::UnusedFunctionTesting::UnusedFunctionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, UnusedFunctionTesting)

void System::UnusedFunctionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::UnusedFunctionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UnusedFunctionTest);
}

void System::UnusedFunctionTesting::UnusedFunctionTest()
{
    UnusedFunction();
    UnusedFunction(0);
    UnusedFunction(0, 1);
    UnusedFunction(0, 1, 2);
    UnusedFunction(0, 1, 2, "3"s);
}
