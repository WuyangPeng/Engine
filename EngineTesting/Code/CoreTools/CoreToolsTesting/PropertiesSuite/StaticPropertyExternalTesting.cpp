///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 13:47)

#include "StaticPropertyExternalTesting.h"
#include "Detail/StaticPropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, StaticPropertyExternalTesting)

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
