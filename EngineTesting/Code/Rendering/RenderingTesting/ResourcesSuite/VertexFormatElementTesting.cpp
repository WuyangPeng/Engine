// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 09:59)

#include "VertexFormatElementTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Resources/VertexFormatElement.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VertexFormatElementTesting)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)
void Rendering::VertexFormatElementTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Rendering::VertexFormatElementTesting::BaseTest()
{
    VertexFormatType firstVertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 1);

    VertexFormatElement firstVertexFormatElement(5, 6, firstVertexFormatType);

    ASSERT_EQUAL(firstVertexFormatElement.GetStreamIndex(), 5);
    ASSERT_EQUAL(firstVertexFormatElement.GetOffset(), 6);
    ASSERT_ENUM_EQUAL(firstVertexFormatElement.GetType(), VertexFormatFlags::AttributeType::Float3);
    ASSERT_ENUM_EQUAL(firstVertexFormatElement.GetUsage(), VertexFormatFlags::AttributeUsage::Position);
    ASSERT_EQUAL(firstVertexFormatElement.GetUsageIndex(), 1);

    VertexFormatElement secondVertexFormatElement;

    ASSERT_EQUAL(secondVertexFormatElement.GetStreamIndex(), 0);
    ASSERT_EQUAL(secondVertexFormatElement.GetOffset(), 0);
    ASSERT_ENUM_EQUAL(secondVertexFormatElement.GetType(), VertexFormatFlags::AttributeType::None);
    ASSERT_ENUM_EQUAL(secondVertexFormatElement.GetUsage(), VertexFormatFlags::AttributeUsage::None);
    ASSERT_EQUAL(secondVertexFormatElement.GetUsageIndex(), 0);

    secondVertexFormatElement.SetStreamIndex(2);
    secondVertexFormatElement.SetOffset(7);
    secondVertexFormatElement.SetType(VertexFormatFlags::AttributeType::Half1);
    secondVertexFormatElement.SetUsage(VertexFormatFlags::AttributeUsage::Color);
    secondVertexFormatElement.SetUsageIndex(5);

    ASSERT_EQUAL(secondVertexFormatElement.GetStreamIndex(), 2);
    ASSERT_EQUAL(secondVertexFormatElement.GetOffset(), 7);
    ASSERT_ENUM_EQUAL(secondVertexFormatElement.GetType(), VertexFormatFlags::AttributeType::Half1);
    ASSERT_ENUM_EQUAL(secondVertexFormatElement.GetUsage(), VertexFormatFlags::AttributeUsage::Color);
    ASSERT_EQUAL(secondVertexFormatElement.GetUsageIndex(), 5);

    secondVertexFormatElement.SetVertexFormatType(firstVertexFormatType);

    ASSERT_EQUAL(secondVertexFormatElement.GetStreamIndex(), 2);
    ASSERT_EQUAL(secondVertexFormatElement.GetOffset(), 7);
    ASSERT_ENUM_EQUAL(secondVertexFormatElement.GetType(), VertexFormatFlags::AttributeType::Float3);
    ASSERT_ENUM_EQUAL(secondVertexFormatElement.GetUsage(), VertexFormatFlags::AttributeUsage::Position);
    ASSERT_EQUAL(secondVertexFormatElement.GetUsageIndex(), 1);

    VertexFormatType secondVertexFormatType(VertexFormatFlags::AttributeType::Float1, VertexFormatFlags::AttributeUsage::Color, 11);

    secondVertexFormatElement.Set(7, 8, secondVertexFormatType);

    ASSERT_EQUAL(secondVertexFormatElement.GetStreamIndex(), 7);
    ASSERT_EQUAL(secondVertexFormatElement.GetOffset(), 8);
    ASSERT_ENUM_EQUAL(secondVertexFormatElement.GetType(), VertexFormatFlags::AttributeType::Float1);
    ASSERT_ENUM_EQUAL(secondVertexFormatElement.GetUsage(), VertexFormatFlags::AttributeUsage::Color);
    ASSERT_EQUAL(secondVertexFormatElement.GetUsageIndex(), 11);
}
