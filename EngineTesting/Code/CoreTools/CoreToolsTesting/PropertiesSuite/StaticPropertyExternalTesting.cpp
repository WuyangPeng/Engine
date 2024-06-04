/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:55)

#include "StaticPropertyExternalTesting.h"
#include "Detail/StaticPropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::StaticPropertyExternalTesting::StaticPropertyExternalTesting(const OStreamShared& stream)
    : ParentType{ stream }, setValue{ "set" }
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
    ASSERT_NOT_THROW_EXCEPTION_0(GetSet0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetSet1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetSet2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetSet3Test);
}

void CoreTools::StaticPropertyExternalTesting::GetSet0Test()
{
    StaticPropertyExternal staticPropertyExternal{};

    const std::string value{ staticPropertyExternal.getExternalType };

    ASSERT_TRUE(value.empty());
}

void CoreTools::StaticPropertyExternalTesting::GetSet1Test()
{
    StaticPropertyExternal staticPropertyExternal{};

    staticPropertyExternal.setExternalType = setValue;

    const std::string value{ staticPropertyExternal.getSetExternalType };

    ASSERT_EQUAL(value, setValue);
}

void CoreTools::StaticPropertyExternalTesting::GetSet2Test()
{
    StaticPropertyExternal staticPropertyExternal{};

    staticPropertyExternal.getSetExternalType = setValue + setValue;

    const std::string value{ staticPropertyExternal.getExternalType };

    ASSERT_EQUAL(value, setValue + setValue);
}

void CoreTools::StaticPropertyExternalTesting::GetSet3Test()
{
    StaticPropertyExternal staticPropertyExternal{};

    staticPropertyExternal.getSetType = setValue + setValue + setValue;

    const std::string value{ staticPropertyExternal.getSetType };

    ASSERT_EQUAL(value, setValue + setValue + setValue);
}
