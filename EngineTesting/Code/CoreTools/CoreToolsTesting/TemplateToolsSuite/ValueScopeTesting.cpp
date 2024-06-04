/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/31 09:31)

#include "ValueScopeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ValueScopeDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ValueScopeTesting::ValueScopeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      original0{ "Original 1" },
      original1{ "Original 2" },
      rebel{ "Rebel" },
      matthew{ "Matthew" },
      sarah{ "Sarah" },
      result{ "woz 'ere" }
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
    ASSERT_NOT_THROW_EXCEPTION_0(ValueScope0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ValueScope1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ValueScope2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ValueScope3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ValueScope4Test);
}

void CoreTools::ValueScopeTesting::ValueScope0Test()
{
    auto value = value0;

    ASSERT_EQUAL(value, value0);

    ASSERT_NOT_THROW_EXCEPTION_1(DoValueScope0Test, value);

    ASSERT_EQUAL(value, value0);
}

void CoreTools::ValueScopeTesting::DoValueScope0Test(int& value)
{
    ValueScope valueScope{ value, value1 };

    ASSERT_EQUAL(value, value1);
}

void CoreTools::ValueScopeTesting::ValueScope1Test()
{
    auto value = value2;

    ASSERT_EQUAL(value, value2);

    ASSERT_NOT_THROW_EXCEPTION_1(DoValueScope1Test, value);

    ASSERT_EQUAL(value, value2);
}

void CoreTools::ValueScopeTesting::DoValueScope1Test(int& value)
{
    ValueScope valueScope{ value, value3 };

    ASSERT_EQUAL(value, value3);
}

void CoreTools::ValueScopeTesting::ValueScope2Test()
{
    auto value = value2;

    ASSERT_EQUAL(value, value2);

    ASSERT_NOT_THROW_EXCEPTION_1(DoValueScope2Test, value);

    ASSERT_EQUAL(value, value4);
}

void CoreTools::ValueScopeTesting::DoValueScope2Test(int& value)
{
    ValueScope valueScope{ value, value3, value4 };

    ASSERT_EQUAL(value, value3);
}

void CoreTools::ValueScopeTesting::ValueScope3Test()
{
    auto value = original0;

    ASSERT_EQUAL(value, original0);

    ASSERT_NOT_THROW_EXCEPTION_1(DoValueScope3Test, value);

    ASSERT_EQUAL(value, original0);
}

void CoreTools::ValueScopeTesting::DoValueScope3Test(std::string& value)
{
    ValueScope valueScope{ value, rebel };

    ASSERT_EQUAL(value, rebel);
}

void CoreTools::ValueScopeTesting::ValueScope4Test()
{
    std::string value{ original1 };

    ASSERT_EQUAL(value, original1);

    ASSERT_NOT_THROW_EXCEPTION_1(DoValueScope4Test, value);

    ASSERT_EQUAL(value, result);
}

void CoreTools::ValueScopeTesting::DoValueScope4Test(std::string& value)
{
    ValueScope valueScope{ value, matthew, result };

    ASSERT_EQUAL(value, matthew);

    ASSERT_NOT_THROW_EXCEPTION_1(DoValueScope5Test, value);
}

void CoreTools::ValueScopeTesting::DoValueScope5Test(std::string& value)
{
    ValueScope valueScope{ value, sarah, "is out" };

    ASSERT_EQUAL(value, sarah);
}