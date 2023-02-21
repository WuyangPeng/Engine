///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 13:47)

#include "StaticPropertyExternalTesting.h"
#include "Detail/StaticPropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;

CoreTools::StaticPropertyExternalTesting::StaticPropertyExternalTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StaticPropertyExternalTesting)

void CoreTools::StaticPropertyExternalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StaticPropertyExternalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::StaticPropertyExternalTesting::GetSetTest()
{
    StaticPropertyExternal StaticPropertyExternal{};

    string value{ StaticPropertyExternal.getExternalType };

    ASSERT_EQUAL(value, "");

    string setValue{ "set" };

    StaticPropertyExternal.setExternalType = setValue;

    value = StaticPropertyExternal.getSetExternalType;

    ASSERT_EQUAL(value, setValue);

    StaticPropertyExternal.getSetExternalType = setValue + setValue;

    value = StaticPropertyExternal.getExternalType;

    ASSERT_EQUAL(value, setValue + setValue);

    StaticPropertyExternal.getSetType = setValue + setValue + setValue;

    value = StaticPropertyExternal.getSetType;

    ASSERT_EQUAL(value, setValue + setValue + setValue);
}
