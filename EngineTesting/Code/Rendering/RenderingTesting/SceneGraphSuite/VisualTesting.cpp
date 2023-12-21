/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/20 16:21)

#include "VisualTesting.h"
#include "Detail/VisualTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Rendering::VisualTesting::VisualTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualTesting)

void Rendering::VisualTesting::DoRunUnitTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::VisualTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Rendering::VisualTesting::InitTest()
{
    const VisualTest visualTest{ "VisualTest" };

    ASSERT_EQUAL(visualTest.GetName(), "VisualTest");
}
