///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:36)

#include "VisibleSetTesting.h"
#include "Detail/SpatialTest.h"
#include "Detail/VisualTest.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"
#include "Rendering/SceneGraph/VisibleSet.h"

Rendering::VisibleSetTesting::VisibleSetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisibleSetTesting)

void Rendering::VisibleSetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::VisibleSetTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(VisibleSetTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::VisibleSetTesting::VisibleSetTest()
{
    VisibleSet firstVisibleSet = VisibleSet::Create();

    ASSERT_EQUAL(firstVisibleSet.GetNumVisible(), 0);

    VisualSharedPtr firstSpatialPtr(std::make_shared<VisualTest>(""));
    VisualSharedPtr secondSpatialPtr(std::make_shared<VisualTest>(""));
    VisualSharedPtr thirdSpatialPtr(std::make_shared<VisualTest>(""));

    firstVisibleSet.Insert(firstSpatialPtr);
    firstVisibleSet.Insert(secondSpatialPtr);
    firstVisibleSet.Insert(thirdSpatialPtr);

    ASSERT_EQUAL(firstVisibleSet.GetNumVisible(), 3);

    ASSERT_EQUAL(firstVisibleSet.GetVisible(0), firstSpatialPtr);
    ASSERT_EQUAL(firstVisibleSet.GetVisible(1), secondSpatialPtr);
    ASSERT_EQUAL(firstVisibleSet.GetVisible(2), thirdSpatialPtr);

    firstVisibleSet.Clear();

    ASSERT_EQUAL(firstVisibleSet.GetNumVisible(), 0);
}
