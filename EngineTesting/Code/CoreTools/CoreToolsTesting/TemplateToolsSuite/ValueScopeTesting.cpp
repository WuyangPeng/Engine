///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 19:09)

#include "ValueScopeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ValueScopeDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;

CoreTools::ValueScopeTesting::ValueScopeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ValueScopeTesting)

void CoreTools::ValueScopeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ValueScopeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
}

void CoreTools::ValueScopeTesting::CastTest()
{
    auto value1 = 33;

    ASSERT_EQUAL(value1, 33);
    {
        ValueScope<int> valueScope{ value1, 20 };

        ASSERT_EQUAL(value1, 20);
    }
    ASSERT_EQUAL(value1, 33);

    int value2{ 33 };

    ASSERT_EQUAL(value2, 33);
    {
        ValueScope<int> valueScope{ value2, 20, 10 };

        ASSERT_EQUAL(value2, 20);
    }
    ASSERT_EQUAL(value2, 10);

    string value3{ "Original 1" };

    ASSERT_EQUAL(value3, "Original 1");
    {
        ValueScope<string> valueScope{ value3, "Rebel" };

        ASSERT_EQUAL(value3, "Rebel");
    }
    ASSERT_EQUAL(value3, "Original 1");

    string value4{ "Original 2" };

    ASSERT_EQUAL(value4, "Original 2");
    {
        ValueScope<string> firstValueScope{ value4, "Matthew", "woz 'ere" };

        ASSERT_EQUAL(value4, "Matthew");

        string sarah{ "Sarah" };
        string isOut{ "is out" };
        ValueScope<string> secondValueScope{ value4, sarah, isOut };

        ASSERT_EQUAL(value4, "Sarah");
    }
    ASSERT_EQUAL(value4, "woz 'ere");
}
