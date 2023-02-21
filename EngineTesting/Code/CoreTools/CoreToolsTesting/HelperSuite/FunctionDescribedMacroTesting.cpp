///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/05 15:12)

#include "FunctionDescribedMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/FunctionDescribedMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    constexpr auto line = 38;

    const FunctionDescribed functionDescribed{ CORE_TOOLS_FUNCTION_DESCRIBED };

    std::string currentFunction{ functionDescribed.GetCurrentFunction() };
    std::string fileName{ functionDescribed.GetFileName() };

    ASSERT_UNEQUAL(currentFunction.find("FunctionDescribedTest"), std::string::npos);
    ASSERT_UNEQUAL(fileName.find("FunctionDescribedMacroTesting"), std::string::npos);
    ASSERT_EQUAL(functionDescribed.GetLine(), line);
}
