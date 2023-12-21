///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:33)

#include "PickRecordContainerTesting.h"
#include "Detail/SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/SceneGraph/PickRecord.h"
#include "Rendering/SceneGraph/PickRecordContainer.h"

Rendering::PickRecordContainerTesting::PickRecordContainerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PickRecordContainerTesting)

void Rendering::PickRecordContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::PickRecordContainerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Rendering::PickRecordContainerTesting::BaseTest()
{
    PickRecordContainer firstPickRecordContainer = PickRecordContainer::Create();

    ASSERT_EQUAL(firstPickRecordContainer.GetSize(), 0);
    ASSERT_TRUE(firstPickRecordContainer.IsEmpty());

    for (int i = 0; i < 10; ++i)
    {
        PickRecord pickRecord = PickRecord::Create();
        pickRecord.SetParameter(static_cast<float>(i));

        firstPickRecordContainer.InsertPickRecord(pickRecord);
    }

    ASSERT_EQUAL(firstPickRecordContainer.GetSize(), 10);
    ASSERT_FALSE(firstPickRecordContainer.IsEmpty());

    for (int i = 0; i < 10; ++i)
    {
        ASSERT_APPROXIMATE(firstPickRecordContainer.GetPickRecord(i).GetParameter(), i, 1e-8f);
    }

    PickRecordContainer secondPickRecordContainer = PickRecordContainer::Create();

    secondPickRecordContainer.InsertPickRecord(firstPickRecordContainer);

    ASSERT_EQUAL(secondPickRecordContainer.GetSize(), 10);

    for (int i = 0; i < 10; ++i)
    {
        ASSERT_APPROXIMATE(secondPickRecordContainer.GetPickRecord(i).GetParameter(), i, 1e-8f);
    }

    ASSERT_FALSE(secondPickRecordContainer.IsEmpty());
}
