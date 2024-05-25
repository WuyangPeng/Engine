/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:55)

#include "PropertyExternalTesting.h"
#include "Detail/PropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::PropertyExternalTesting::PropertyExternalTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PropertyExternalTesting)

void CoreTools::PropertyExternalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::PropertyExternalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::PropertyExternalTesting::GetSetTest()
{
    PropertyExternal simplePropertyExternal{};

    std::string value{ simplePropertyExternal.getType };

    ASSERT_TRUE(value.empty());

    const std::string setValue{ "set" };

    simplePropertyExternal.setType = setValue;

    value = simplePropertyExternal.getSetType;

    ASSERT_EQUAL(value, setValue);

    simplePropertyExternal.getSetType = setValue + setValue;

    value = simplePropertyExternal.getType;

    ASSERT_EQUAL(value, setValue + setValue);
}
