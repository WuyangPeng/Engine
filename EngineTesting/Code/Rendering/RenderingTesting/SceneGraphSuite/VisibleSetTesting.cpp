///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/15 15:41)

#include "SpatialTest.h"
#include "VisibleSetTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/SceneGraph/VisibleSet.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VisibleSetTesting)

void Rendering::VisibleSetTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(VisibleSetTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::VisibleSetTesting::VisibleSetTest()
{
    VisibleSet firstVisibleSet = VisibleSet::Create();

    ASSERT_EQUAL(firstVisibleSet.GetNumVisible(), 0);

    VisualSharedPtr firstSpatialPtr(std::make_shared<SpatialTest>(CoreTools::DisableNotThrow::Disable));
    VisualSharedPtr secondSpatialPtr(std::make_shared<SpatialTest>(CoreTools::DisableNotThrow::Disable));
    VisualSharedPtr thirdSpatialPtr(std::make_shared<SpatialTest>(CoreTools::DisableNotThrow::Disable));

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
