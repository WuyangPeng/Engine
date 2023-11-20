///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:42)

#include "MiddleLayerModuleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"

AssistTools::MiddleLayerModuleTesting::MiddleLayerModuleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, MiddleLayerModuleTesting)

void AssistTools::MiddleLayerModuleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::MiddleLayerModuleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerModuleReadTest);
}

void AssistTools::MiddleLayerModuleTesting::MiddleLayerModuleReadTest()
{
    const auto middleLayerName = SYSTEM_TEXT("MiddleLayerName");
    const auto uppercaseName = SYSTEM_TEXT("UppercaseName");
    constexpr bool isManager = true;

    const MiddleLayerModule middleLayerModule{ middleLayerName, uppercaseName, isManager };

    ASSERT_EQUAL(middleLayerModule.GetMiddleLayerName(), middleLayerName);
    ASSERT_EQUAL(middleLayerModule.GetUppercaseName(), uppercaseName);
    ASSERT_EQUAL(middleLayerModule.IsManager(), isManager);
}
