///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/07/29 19:08)

#include "FunctionDescribedMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/FunctionDescribedMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;

CoreTools::FunctionDescribedMacroTesting::FunctionDescribedMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FunctionDescribedMacroTesting)

void CoreTools::FunctionDescribedMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FunctionDescribedMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FunctionDescribedTest);
}

void CoreTools::FunctionDescribedMacroTesting::FunctionDescribedTest()
{
    constexpr auto line = 40;

    const FunctionDescribed functionDescribed{ CORE_TOOLS_FUNCTION_DESCRIBED };

    string currentFunction{ functionDescribed.GetCurrentFunction() };
    string fileName{ functionDescribed.GetFileName() };

    ASSERT_UNEQUAL(currentFunction.find("FunctionDescribedTest"), string::npos);
    ASSERT_UNEQUAL(fileName.find("FunctionDescribedMacroTesting"), string::npos);
    ASSERT_EQUAL(functionDescribed.GetLine(), line);
}
