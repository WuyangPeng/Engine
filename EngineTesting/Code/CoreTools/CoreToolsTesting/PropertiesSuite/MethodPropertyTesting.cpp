///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 13:46)

#include "MethodPropertyTesting.h"
#include "Detail/MethodProperty.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MethodPropertyTesting)

void CoreTools::MethodPropertyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetTest);
}

void CoreTools::MethodPropertyTesting::GetTest()
{
    MethodProperty methodProperty;

    ASSERT_EQUAL(methodProperty.getType, 0);

    methodProperty.setType = 1;

    ASSERT_EQUAL(methodProperty.getSetType, 1);

    methodProperty.getSetType = 2;

    ASSERT_EQUAL(methodProperty.getType, 2);

    methodProperty.setExternalType = 3;

    ASSERT_EQUAL(methodProperty.getSetExternalType, 3);

    methodProperty.getSetExternalType = 4;

    ASSERT_EQUAL(methodProperty.getExternalType, 4);
}
