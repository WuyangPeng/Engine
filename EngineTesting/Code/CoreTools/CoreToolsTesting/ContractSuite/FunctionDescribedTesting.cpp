/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 09:47)

#include "FunctionDescribedTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::FunctionDescribedTesting::FunctionDescribedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FunctionDescribedTesting)

void CoreTools::FunctionDescribedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FunctionDescribedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FunctionDescribedTest);
}

void CoreTools::FunctionDescribedTesting::FunctionDescribedTest() noexcept
{
    constexpr const char* currentFunction{ __func__ };
    constexpr const auto* fileName = __FILE__;
    constexpr auto line = 37;

    constexpr FunctionDescribed functionDescribed0{ currentFunction, fileName, line };
    constexpr FunctionDescribed functionDescribed1{ currentFunction, fileName, line };

    static_assert(currentFunction == functionDescribed0.GetCurrentFunction());
    static_assert(fileName == functionDescribed0.GetFileName());
    static_assert(line == functionDescribed0.GetLine());
    static_assert(functionDescribed0 == functionDescribed1);
}
