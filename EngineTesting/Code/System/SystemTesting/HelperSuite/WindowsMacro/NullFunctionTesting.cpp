///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/16 19:44)

#include "NullFunctionTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;
using namespace std::literals;

System::NullFunctionTesting::NullFunctionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, NullFunctionTesting)

void System::NullFunctionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::NullFunctionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullFunctionTest);
}

void System::NullFunctionTesting::NullFunctionTest()
{
    NullFunction();
    NullFunction<int>(0);
    NullFunction<int, int>(0, 1);
    NullFunction<int, int, int>(0, 1, 2);
    NullFunction<int, int, int, string>(0, 1, 2, "3"s);
}
