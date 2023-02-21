///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 13:47)

#include "SimplePropertyExternalTesting.h"
#include "Detail/SimplePropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;

CoreTools::SimplePropertyExternalTesting::SimplePropertyExternalTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SimplePropertyExternalTesting)

void CoreTools::SimplePropertyExternalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SimplePropertyExternalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::SimplePropertyExternalTesting::GetSetTest()
{
    SimplePropertyExternal simplePropertyExternal{};

    string value{ simplePropertyExternal.getType };

    ASSERT_EQUAL(value, "");

    string setValue{ "set" };

    simplePropertyExternal.setType = setValue;

    value = simplePropertyExternal.getType;

    ASSERT_EQUAL(value, setValue);
}
