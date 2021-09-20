// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 11:05)

#include "VertexFormatTypeTesting.h"
#include "Rendering/Resources/VertexFormatType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VertexFormatTypeTesting) 

void Rendering::VertexFormatTypeTesting
	::MainTest()
{ 
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}
 
void Rendering::VertexFormatTypeTesting 
	::BaseTest()
{
	VertexFormatType firstVertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position,1);

	ASSERT_ENUM_EQUAL(firstVertexFormatType.GetType(), VertexFormatFlags::AttributeType::Float3);
	ASSERT_ENUM_EQUAL(firstVertexFormatType.GetUsage(), VertexFormatFlags::AttributeUsage::Position);
	ASSERT_EQUAL(firstVertexFormatType.GetUsageIndex(), 1u);

	VertexFormatType secondVertexFormatType;

	ASSERT_ENUM_EQUAL(secondVertexFormatType.GetType(), VertexFormatFlags::AttributeType::None);
	ASSERT_ENUM_EQUAL(secondVertexFormatType.GetUsage(), VertexFormatFlags::AttributeUsage::None);
	ASSERT_EQUAL(secondVertexFormatType.GetUsageIndex(), 0u);

	secondVertexFormatType.SetType(VertexFormatFlags::AttributeType::Half1);
	secondVertexFormatType.SetUsage(VertexFormatFlags::AttributeUsage::Color);
	secondVertexFormatType.SetUsageIndex(5);

	ASSERT_ENUM_EQUAL(secondVertexFormatType.GetType(), VertexFormatFlags::AttributeType::Half1);
	ASSERT_ENUM_EQUAL(secondVertexFormatType.GetUsage(), VertexFormatFlags::AttributeUsage::Color);
	ASSERT_EQUAL(secondVertexFormatType.GetUsageIndex(), 5u);
}

 