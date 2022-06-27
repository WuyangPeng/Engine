///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 18:27)

#include "CollapseRecordArrayTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Detail/CollapseRecordArray.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CollapseRecordArrayTesting)

void Rendering::CollapseRecordArrayTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::CollapseRecordArrayTesting::InitTest()
{
    vector<CollapseRecord> collapseRecordVector;
    for (int i = 0; i < 10; ++i)
    {
        CollapseRecord firstCollapseRecord(12 - i, 7, 10 + i, 12 + i);

        vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3, i };

        firstCollapseRecord.SetIndices(indices);

        collapseRecordVector.push_back(firstCollapseRecord);
    }

    CollapseRecordArray collapseRecordArray(collapseRecordVector);

    ASSERT_EQUAL(collapseRecordArray.GetNumRecords(), static_cast<int>(collapseRecordVector.size()));
    ASSERT_EQUAL(collapseRecordVector, collapseRecordArray.GetRecords());

    for (int i = 0; i < collapseRecordArray.GetNumRecords(); ++i)
    {
        ASSERT_EQUAL(collapseRecordArray.GetRecord(i), collapseRecordVector.at(i));
    }
}

void Rendering::CollapseRecordArrayTesting::CopyTest()
{
    vector<CollapseRecord> collapseRecordVector;
    for (int i = 0; i < 10; ++i)
    {
        CollapseRecord firstCollapseRecord(12 - i, 7, 10 + i, 12 + i);

        vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3, i };

        firstCollapseRecord.SetIndices(indices);

        collapseRecordVector.push_back(firstCollapseRecord);
    }

    CollapseRecordArray firstCollapseRecordArray(collapseRecordVector);

    firstCollapseRecordArray.SetUniqueID(2);

    CollapseRecordArray secondCollapseRecordArray(firstCollapseRecordArray);

    ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueID(), 2u);
    ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueID(), 2u);

    secondCollapseRecordArray.SetUniqueID(1);

    ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueID(), 2u);
    ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueID(), 1u);

    firstCollapseRecordArray = secondCollapseRecordArray;

    ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueID(), 1u);
    ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueID(), 1u);

    firstCollapseRecordArray.SetUniqueID(3);

    ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueID(), 3u);
    ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueID(), 1u);
}

void Rendering::CollapseRecordArrayTesting::StreamTest()
{
    vector<CollapseRecord> collapseRecordVector;
    for (int i = 0; i < 10; ++i)
    {
        CollapseRecord firstCollapseRecord(12 - i, 7, 10 + i, 12 + i);

        vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3, i };

        firstCollapseRecord.SetIndices(indices);

        collapseRecordVector.push_back(firstCollapseRecord);
    }
}
