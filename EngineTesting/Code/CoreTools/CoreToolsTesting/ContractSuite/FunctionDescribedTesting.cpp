///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 15:35)

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
    constexpr const char* fileName{ __FILE__ };
    constexpr auto line = 37;

    constexpr FunctionDescribed functionDescribed{ currentFunction, fileName, line };

    static_assert(currentFunction == functionDescribed.GetCurrentFunction());
    static_assert(fileName == functionDescribed.GetFileName());
    static_assert(line == functionDescribed.GetLine());
    static_assert(functionDescribed == functionDescribed);
}
