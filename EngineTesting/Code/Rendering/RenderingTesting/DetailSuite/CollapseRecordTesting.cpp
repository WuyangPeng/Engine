///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:54)

#include "CollapseRecordTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Detail/CollapseRecord.h"

Rendering::CollapseRecordTesting::CollapseRecordTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CollapseRecordTesting)

void Rendering::CollapseRecordTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::CollapseRecordTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Rendering::CollapseRecordTesting::InitTest()
{
    CollapseRecord firstCollapseRecord(2, 7, 10, 12);

    ASSERT_EQUAL(firstCollapseRecord.GetIndicesSize(), 0);
    ASSERT_EQUAL(firstCollapseRecord.GetVKeep(), 2);
    ASSERT_EQUAL(firstCollapseRecord.GetVThrow(), 7);
    ASSERT_EQUAL(firstCollapseRecord.GetNumVertices(), 10);
    ASSERT_EQUAL(firstCollapseRecord.GetNumTriangles(), 12);

    std::vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3 };

    firstCollapseRecord.SetIndices(indices);

    ASSERT_EQUAL(firstCollapseRecord.GetIndicesSize(), static_cast<int>(indices.size()));

    for (int i = 0; i < firstCollapseRecord.GetIndicesSize(); ++i)
    {
        ASSERT_EQUAL(firstCollapseRecord.GetIndex(i), indices.at(i));
    }

    ASSERT_EQUAL(firstCollapseRecord.GetIndices(), indices);

    firstCollapseRecord.SetVKeep(5);
    ASSERT_EQUAL(firstCollapseRecord.GetVKeep(), 5);

    firstCollapseRecord.SetVThrow(114);
    ASSERT_EQUAL(firstCollapseRecord.GetVThrow(), 114);

    firstCollapseRecord.SetNumVertices(12);
    ASSERT_EQUAL(firstCollapseRecord.GetNumVertices(), 12);

    firstCollapseRecord.SetNumTriangles(111);
    ASSERT_EQUAL(firstCollapseRecord.GetNumTriangles(), 111);
}
