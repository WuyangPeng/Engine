///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 13:46)

#include "PropertyExternalTesting.h"
#include "Detail/PropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;

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

    string value{ simplePropertyExternal.getType };

    ASSERT_EQUAL(value, "");

    string setValue{ "set" };

    simplePropertyExternal.setType = setValue;

    value = simplePropertyExternal.getSetType;

    ASSERT_EQUAL(value, setValue);

    simplePropertyExternal.getSetType = setValue + setValue;

    value = simplePropertyExternal.getType;

    ASSERT_EQUAL(value, setValue + setValue);
}
