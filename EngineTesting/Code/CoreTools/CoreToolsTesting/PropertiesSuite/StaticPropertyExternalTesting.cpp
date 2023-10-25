///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:43)

#include "StaticPropertyExternalTesting.h"
#include "Detail/StaticPropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    StaticPropertyExternal staticPropertyExternal{};

    std::string value{ staticPropertyExternal.getExternalType };

    ASSERT_TRUE(value.empty());

    const std::string setValue{ "set" };

    staticPropertyExternal.setExternalType = setValue;

    value = staticPropertyExternal.getSetExternalType;

    ASSERT_EQUAL(value, setValue);

    staticPropertyExternal.getSetExternalType = setValue + setValue;

    value = staticPropertyExternal.getExternalType;

    ASSERT_EQUAL(value, setValue + setValue);

    staticPropertyExternal.getSetType = setValue + setValue + setValue;

    value = staticPropertyExternal.getSetType;

    ASSERT_EQUAL(value, setValue + setValue + setValue);
}
