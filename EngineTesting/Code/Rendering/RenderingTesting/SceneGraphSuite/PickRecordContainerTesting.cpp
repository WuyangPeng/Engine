///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/15 11:05)

#include "PickRecordContainerTesting.h"
#include "SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/SceneGraph/PickRecord.h"
#include "Rendering/SceneGraph/PickRecordContainer.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PickRecordContainerTesting)

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
