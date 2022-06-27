///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 11:05)

#include "PickRecordTesting.h"
#include "SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/SceneGraph/PickRecord.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PickRecordTesting)

void Rendering::PickRecordTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::PickRecordTesting::BaseTest()
{
    PickRecord firstPickRecord = PickRecord::Create();

    ConstSpatialSharedPtr firstSpatialSharedPtr = firstPickRecord.GetIntersected();

    ASSERT_APPROXIMATE(firstPickRecord.GetParameter(), 0.0f, 1e-8f);
    ASSERT_EQUAL(firstPickRecord.GetTriangle(), -1);
    ASSERT_TRUE(0.0f <= firstPickRecord.GetBary(0) && firstPickRecord.GetBary(0) <= 1.0f);
    ASSERT_TRUE(0.0f <= firstPickRecord.GetBary(1) && firstPickRecord.GetBary(1) <= 1.0f);
    ASSERT_TRUE(0.0f <= firstPickRecord.GetBary(2) && firstPickRecord.GetBary(2) <= 1.0f);
    ASSERT_APPROXIMATE(firstPickRecord.GetBary(0) + firstPickRecord.GetBary(1) + firstPickRecord.GetBary(2), 1.0f, 1e-8f);
}

void Rendering::PickRecordTesting::OperatorTest()
{
    PickRecord firstPickRecord = PickRecord::Create();
    firstPickRecord.SetParameter(0.5f);

    PickRecord secondPickRecord = PickRecord::Create();
    secondPickRecord.SetParameter(0.15f);

    ASSERT_TRUE(firstPickRecord == firstPickRecord);
    ASSERT_TRUE(secondPickRecord == secondPickRecord);
    ASSERT_FALSE(firstPickRecord == secondPickRecord);

    ASSERT_FALSE(firstPickRecord != firstPickRecord);
    ASSERT_FALSE(secondPickRecord != secondPickRecord);
    ASSERT_TRUE(firstPickRecord != secondPickRecord);

    ASSERT_FALSE(firstPickRecord < secondPickRecord);
    ASSERT_FALSE(firstPickRecord <= secondPickRecord);
    ASSERT_TRUE(firstPickRecord > secondPickRecord);
    ASSERT_TRUE(firstPickRecord >= secondPickRecord);

    ASSERT_FALSE(firstPickRecord < firstPickRecord);
    ASSERT_TRUE(firstPickRecord <= firstPickRecord);
    ASSERT_FALSE(firstPickRecord > firstPickRecord);
    ASSERT_TRUE(firstPickRecord >= firstPickRecord);
}
