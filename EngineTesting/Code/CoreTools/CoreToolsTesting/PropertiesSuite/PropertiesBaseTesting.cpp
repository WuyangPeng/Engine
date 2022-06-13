///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 13:46)

#include "PropertiesBaseTesting.h"
#include "Detail/PropertiesBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, PropertiesBaseTesting)

void CoreTools::PropertiesBaseTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::PropertiesBaseTesting::GetSetTest()
{
    PropertiesBase propertiesBase;

    ASSERT_EQUAL(propertiesBase.FifthValue, 0);

    propertiesBase.FifthValue = 1;

    ASSERT_EQUAL(propertiesBase.FifthValue, 1);
}
