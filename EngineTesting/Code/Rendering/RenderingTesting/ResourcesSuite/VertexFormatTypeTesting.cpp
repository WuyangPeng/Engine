///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 16:25)

#include "VertexFormatTypeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Resources/VertexFormatType.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VertexFormatTypeTesting)

void Rendering::VertexFormatTypeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Rendering::VertexFormatTypeTesting::BaseTest()
{
    const VertexFormatType firstVertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 1);

    ASSERT_ENUM_EQUAL(firstVertexFormatType.GetType(), VertexFormatFlags::AttributeType::Float3);
    ASSERT_ENUM_EQUAL(firstVertexFormatType.GetUsage(), VertexFormatFlags::AttributeUsage::Position);
    ASSERT_EQUAL(firstVertexFormatType.GetUsageIndex(), 1);

    VertexFormatType secondVertexFormatType;

    ASSERT_ENUM_EQUAL(secondVertexFormatType.GetType(), VertexFormatFlags::AttributeType::None);
    ASSERT_ENUM_EQUAL(secondVertexFormatType.GetUsage(), VertexFormatFlags::AttributeUsage::None);
    ASSERT_EQUAL(secondVertexFormatType.GetUsageIndex(), 0);

    secondVertexFormatType.SetType(VertexFormatFlags::AttributeType::Half1);
    secondVertexFormatType.SetUsage(VertexFormatFlags::AttributeUsage::Color);
    secondVertexFormatType.SetUsageIndex(5);

    ASSERT_ENUM_EQUAL(secondVertexFormatType.GetType(), VertexFormatFlags::AttributeType::Half1);
    ASSERT_ENUM_EQUAL(secondVertexFormatType.GetUsage(), VertexFormatFlags::AttributeUsage::Color);
    ASSERT_EQUAL(secondVertexFormatType.GetUsageIndex(), 5);
}
