///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 10:27)

#include "PropertiesBaseTesting.h"
#include "Detail/PropertiesBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::PropertiesBaseTesting::PropertiesBaseTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PropertiesBaseTesting)

void CoreTools::PropertiesBaseTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::PropertiesBaseTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::PropertiesBaseTesting::GetSetTest()
{
    PropertiesBase propertiesBase;

    ASSERT_EQUAL(propertiesBase.propValue, 0);

    propertiesBase.propValue = 1;

    ASSERT_EQUAL(propertiesBase.propValue, 1);
}
