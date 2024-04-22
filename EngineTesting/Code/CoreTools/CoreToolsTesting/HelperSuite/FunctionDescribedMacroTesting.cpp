/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 18:22)

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

    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;

    std::string currentFunction{ functionDescribed.GetCurrentFunction() };
    std::string fileName{ functionDescribed.GetFileName() };

    ASSERT_UNEQUAL(currentFunction.find("FunctionDescribedTest"), std::string::npos);
    ASSERT_UNEQUAL(fileName.find("FunctionDescribedMacroTesting"), std::string::npos);
    ASSERT_EQUAL(functionDescribed.GetLine(), line);
}
