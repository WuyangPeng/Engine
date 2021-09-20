// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:37)

#include "OpenGLVertexFormatArrayDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/OpenGLRenderer/OpenGLVertexFormatArrayDataDetail.h"
#include "Rendering/OpenGLRenderer/OpenGLVertexFormatDataDetail.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, OpenGLVertexFormatArrayDataTesting) 

void Rendering::OpenGLVertexFormatArrayDataTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsageTextureCoordTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsageColorTest);

	RendererManager::Destroy();
}

void Rendering::OpenGLVertexFormatArrayDataTesting
	::AttributeUsageTextureCoordTest() 
{
	vector<VertexFormatType> firstVertexFormatType{
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Position, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float2,
							 VertexFormatFlags::AttributeUsage::Normal, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Tangent, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float4,
							 VertexFormatFlags::AttributeUsage::Binormal, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Half1,
							 VertexFormatFlags::AttributeUsage::TextureCoord, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::TextureCoord, 1),
			VertexFormatType(VertexFormatFlags::AttributeType::Float4,
							 VertexFormatFlags::AttributeUsage::TextureCoord, 2),
			VertexFormatType(VertexFormatFlags::AttributeType::Half2,
							 VertexFormatFlags::AttributeUsage::Color, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Color, 1),
			VertexFormatType(VertexFormatFlags::AttributeType::Half3,
							 VertexFormatFlags::AttributeUsage::BlendIndices, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Half4,
							 VertexFormatFlags::AttributeUsage::BlendWeight, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
							 VertexFormatFlags::AttributeUsage::FogCoord, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Short1,
							 VertexFormatFlags::AttributeUsage::Psize, 0) };

	auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

	OpenGLVertexFormatArrayData<VertexFormatFlags::AttributeUsage::TextureCoord,
	                            VertexFormatFlags::MaximumNumber::TextureCoordinateUnits> data;

	data.Init(firstVertexFormat.get());

	ASSERT_TRUE(data.IsHas(0));
	ASSERT_EQUAL(data.GetChannels(0), 1u);
	ASSERT_EQUAL(data.GetType(0),static_cast<unsigned int>( System::OpenGLData::HalfFloat));
	int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::TextureCoord, 0);
	ASSERT_EQUAL(data.GetOffset(0), firstVertexFormat->GetOffset(index)); 

	ASSERT_TRUE(data.IsHas(1));
	ASSERT_EQUAL(data.GetChannels(1), 3u);
	ASSERT_EQUAL(data.GetType(1), static_cast<unsigned int>( System::OpenGLData::Float));
	index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::TextureCoord, 1);
	ASSERT_EQUAL(data.GetOffset(1), firstVertexFormat->GetOffset(index));

	ASSERT_TRUE(data.IsHas(2));
	ASSERT_EQUAL(data.GetChannels(2), 4u);
	ASSERT_EQUAL(data.GetType(2), static_cast<unsigned int>( System::OpenGLData::Float));
	index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::TextureCoord, 2);
	ASSERT_EQUAL(data.GetOffset(2), firstVertexFormat->GetOffset(index));

	for (int i = 3; i < System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);++i)
	{
		ASSERT_FALSE(data.IsHas(i));
	}

	data.Enable(firstVertexFormat->GetStride());
	data.Disable();
}

void Rendering::OpenGLVertexFormatArrayDataTesting
	::AttributeUsageColorTest()
{
	vector<VertexFormatType> firstVertexFormatType{
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Position, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float2,
							 VertexFormatFlags::AttributeUsage::Normal, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Tangent, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float4,
							 VertexFormatFlags::AttributeUsage::Binormal, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Half1,
							 VertexFormatFlags::AttributeUsage::TextureCoord, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::TextureCoord, 1),
			VertexFormatType(VertexFormatFlags::AttributeType::Float4,
							 VertexFormatFlags::AttributeUsage::TextureCoord, 2),
			VertexFormatType(VertexFormatFlags::AttributeType::Half3,
							 VertexFormatFlags::AttributeUsage::Color, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Color, 1),
			VertexFormatType(VertexFormatFlags::AttributeType::Half3,
							 VertexFormatFlags::AttributeUsage::BlendIndices, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Half4,
							 VertexFormatFlags::AttributeUsage::BlendWeight, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
							 VertexFormatFlags::AttributeUsage::FogCoord, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Short1,
							 VertexFormatFlags::AttributeUsage::Psize, 0) };

	auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

	OpenGLVertexFormatArrayData<VertexFormatFlags::AttributeUsage::Color,
	                            VertexFormatFlags::MaximumNumber::ColorUnits> data;

	data.Init(firstVertexFormat.get());

	ASSERT_TRUE(data.IsHas(0));
	ASSERT_EQUAL(data.GetChannels(0), 3u);
	ASSERT_EQUAL(data.GetType(0),static_cast<unsigned int>( System::OpenGLData::HalfFloat));
	int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Color, 0);
	ASSERT_EQUAL(data.GetOffset(0), firstVertexFormat->GetOffset(index)); 

	ASSERT_TRUE(data.IsHas(1));
	ASSERT_EQUAL(data.GetChannels(1), 3u);
	ASSERT_EQUAL(data.GetType(1),static_cast<unsigned int>(  System::OpenGLData::Float));
	index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Color, 1);
	ASSERT_EQUAL(data.GetOffset(1), firstVertexFormat->GetOffset(index));

	data.Enable(firstVertexFormat->GetStride());
	data.Disable();
}

