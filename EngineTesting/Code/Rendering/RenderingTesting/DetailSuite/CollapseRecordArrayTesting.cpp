///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:54)

#include "CollapseRecordArrayTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Detail/CollapseRecordArray.h"

Rendering::CollapseRecordArrayTesting::CollapseRecordArrayTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CollapseRecordArrayTesting)

void Rendering::CollapseRecordArrayTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::CollapseRecordArrayTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::CollapseRecordArrayTesting::InitTest()
{
    std::vector<CollapseRecord> collapseRecordVector;
    for (int i = 0; i < 10; ++i)
    {
        CollapseRecord firstCollapseRecord(12 - i, 7, 10 + i, 12 + i);

        std::vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3, i };

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
    std::vector<CollapseRecord> collapseRecordVector;
    for (int i = 0; i < 10; ++i)
    {
        CollapseRecord firstCollapseRecord(12 - i, 7, 10 + i, 12 + i);

        std::vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3, i };

        firstCollapseRecord.SetIndices(indices);

        collapseRecordVector.push_back(firstCollapseRecord);
    }

    CollapseRecordArray firstCollapseRecordArray(collapseRecordVector);

    firstCollapseRecordArray.SetUniqueId(2);

    CollapseRecordArray secondCollapseRecordArray(firstCollapseRecordArray);

    ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueId(), 2u);
    ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueId(), 2u);

    secondCollapseRecordArray.SetUniqueId(1);

    ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueId(), 2u);
    ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueId(), 1u);

    firstCollapseRecordArray = secondCollapseRecordArray;

    ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueId(), 1u);
    ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueId(), 1u);

    firstCollapseRecordArray.SetUniqueId(3);

    ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueId(), 3u);
    ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueId(), 1u);
}

void Rendering::CollapseRecordArrayTesting::StreamTest()
{
    std::vector<CollapseRecord> collapseRecordVector;
    for (int i = 0; i < 10; ++i)
    {
        CollapseRecord firstCollapseRecord(12 - i, 7, 10 + i, 12 + i);

        std::vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3, i };

        firstCollapseRecord.SetIndices(indices);

        collapseRecordVector.push_back(firstCollapseRecord);
    }
}
