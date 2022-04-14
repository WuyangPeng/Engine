// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 17:37)

#include "VertexBufferAccessorTesting.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/VisualTest.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VertexBufferAccessorTesting)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26414)
void Rendering::VertexBufferAccessorTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(HaveNotTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::VertexBufferAccessorTesting::BaseTest()
{
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float4, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Normal, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Tangent, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Binormal, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::TextureCoord, 3),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Color, 1),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Short2, VertexFormatFlags::AttributeUsage::BlendIndices, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Short2, VertexFormatFlags::AttributeUsage::BlendWeight, 0) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    VertexBufferSharedPtr firstVertexBufer(VertexBuffer::Create());

    CoreTools::ReadFileManager manage(SYSTEM_TEXT("Resource/ResourcesSuite/VertexBuffer.vb"));

    // 	firstVertexBufer->ReadFromFile(manage,  firstVertexFormat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>());
    //
    // 	ASSERT_EQUAL(firstVertexFormat->GetStride(), firstVertexBufer->GetElementSize());
    // 	ASSERT_EQUAL(12, firstVertexBufer->GetNumElements());
    //
    // 	VertexBufferAccessor firstVertexBufferAccessor(firstVertexFormat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>(),
    // 		                                           firstVertexBufer.PolymorphicDowncastConstObjectSharedPtr<ConstVertexBufferSharedPtr>());
    //
    // 	ASSERT_EQUAL(firstVertexBufferAccessor.GetData(), firstVertexBufer->GetReadOnlyData());
    //
    // 	ASSERT_EQUAL(firstVertexBufferAccessor.GetNumVertices(),  firstVertexBufer->GetNumElements());
    //
    // 	ASSERT_EQUAL(firstVertexBufferAccessor.GetStride(),  firstVertexFormat->GetStride());
    //
    // 	int numElements = firstVertexBufferAccessor.GetNumVertices();
    // 	int stride = firstVertexFormat->GetStride();
    //
    // 	for (int index = 0; index < numElements; ++index)
    // 	{
    // 		// position
    // 		int attribute = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Position);
    //
    // 		const char* positionPtr = firstVertexBufer->GetReadOnlyData(firstVertexFormat->GetOffset(attribute));
    //
    // 		float position = firstVertexBufferAccessor.GetPosition<float>(index);
    //
    // 		ASSERT_TRUE(0.0f <= position && position <= 1.0f);
    //
    // 		ASSERT_EQUAL(position,  *(reinterpret_cast<const float*>(positionPtr + index * stride)));
    //
    // 		ASSERT_TRUE(firstVertexBufferAccessor.HasPosition());
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetPosition(index),
    // 			         positionPtr + index * stride);
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetPositionChannels(), 4);
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetPositionTuple(index), reinterpret_cast<const float*>(positionPtr + index * stride));
    //
    // 		// normal
    // 		attribute = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Normal);
    //
    // 		const char* normalPtr = firstVertexBufer->GetReadOnlyData(firstVertexFormat->GetOffset(attribute));
    //
    // 		float normal = firstVertexBufferAccessor.GetNormal<float>(index);
    //
    // 		ASSERT_TRUE(0.0f <= normal && normal <= 1.0f);
    //
    // 		ASSERT_EQUAL(normal, *(reinterpret_cast<const float*>(normalPtr + index * stride)));
    //
    // 		ASSERT_TRUE(firstVertexBufferAccessor.HasNormal());
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetNormal(index), normalPtr + index * stride);
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetNormalChannels(), 3);
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetNormalTuple(index), reinterpret_cast<const float*>(normalPtr + index * stride));
    //
    // 		// tangent
    // 		attribute = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Tangent);
    //
    // 		const char* tangentPtr = firstVertexBufer->GetReadOnlyData(firstVertexFormat->GetOffset(attribute));
    //
    // 		float tangent = firstVertexBufferAccessor.GetTangent<float>(index);
    //
    // 		ASSERT_TRUE(0.0f <= tangent && tangent <= 1.0f);
    //
    // 		ASSERT_EQUAL(tangent, *(reinterpret_cast<const float*>(tangentPtr + index * stride)));
    //
    // 		ASSERT_TRUE(firstVertexBufferAccessor.HasTangent());
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetTangent(index),
    // 			         tangentPtr + index * stride);
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetTangentChannels(), 3);
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetTangentTuple(index), reinterpret_cast<const float*>(tangentPtr + index * stride));
    //
    // 		// binormal
    // 		attribute = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Binormal);
    //
    // 		const char* binormalPtr = firstVertexBufer->GetReadOnlyData(firstVertexFormat->GetOffset(attribute));
    //
    // 		float binormal = firstVertexBufferAccessor.GetBinormal<float>(index);
    //
    // 		ASSERT_TRUE(0.0f <= binormal && binormal <= 1.0f);
    //
    // 		ASSERT_EQUAL(binormal,  *(reinterpret_cast<const float*>(binormalPtr + index * stride)));
    //
    // 		ASSERT_TRUE(firstVertexBufferAccessor.HasBinormal());
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetBinormal(index),
    // 			         binormalPtr + index * stride);
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetBinormalChannels(), 3);
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetBinormalTuple(index), reinterpret_cast<const float*>(binormalPtr + index * stride));
    //
    //
    // 		attribute = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::TextureCoord,3);
    //
    // 		const char* textureCoordPtr = firstVertexBufer->GetReadOnlyData(firstVertexFormat->GetOffset(attribute));
    //
    // 		float textureCoord = firstVertexBufferAccessor.GetTextureCoord<float>(3,index);
    //
    // 		ASSERT_TRUE(0.0f <= textureCoord && textureCoord <= 1.0f);
    //
    // 		ASSERT_EQUAL(textureCoord,  *(reinterpret_cast<const float*>(textureCoordPtr + index * stride)));
    //
    // 		ASSERT_TRUE(firstVertexBufferAccessor.HasTextureCoord(3));
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetTextureCoord(3,index),
    // 			         textureCoordPtr + index * stride);
    //
    // 	    ASSERT_EQUAL(firstVertexBufferAccessor.GetTextureCoordChannels(3), 3);
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetTextureCoordTuple(3, index),  reinterpret_cast<const float*>(textureCoordPtr + index * stride));
    //
    // 		for (int textureCoordIndex = 0;  textureCoordIndex < System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits); ++textureCoordIndex)
    // 		{
    // 			if (textureCoordIndex != 3)
    // 				ASSERT_FALSE(firstVertexBufferAccessor.HasTextureCoord(textureCoordIndex));
    // 		}
    //
    // 		// color
    // 		attribute = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Color,1);
    //
    // 		const char* colorPtr = firstVertexBufer->GetReadOnlyData(firstVertexFormat->GetOffset(attribute));
    //
    // 		float color = firstVertexBufferAccessor.GetColor<float>(1, index);
    //
    // 		ASSERT_TRUE(0.0f <= color && color <= 1.0f);
    //
    // 		ASSERT_EQUAL(color, *(reinterpret_cast<const float*>(colorPtr + index * stride)));
    //
    // 		ASSERT_TRUE(firstVertexBufferAccessor.HasColor(1));
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetColor(1,index),
    // 			         colorPtr + index * stride);
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetColorChannels(1), 3);
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetColorTuple(1, index), reinterpret_cast<const float*>(colorPtr + index * stride));
    //
    // 		ASSERT_FALSE(firstVertexBufferAccessor.HasColor(0));
    //
    // 		// blendIndices
    // 		attribute = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::BlendIndices);
    //
    // 		const char* blendIndicesPtr = firstVertexBufer->GetReadOnlyData(firstVertexFormat->GetOffset(attribute));
    //
    // 		int blendIndices = firstVertexBufferAccessor.GetBlendIndices<int>(index);
    //
    // 		ASSERT_EQUAL(blendIndices, *(reinterpret_cast<const int*>(blendIndicesPtr + index * stride)));
    //
    // 		ASSERT_TRUE(firstVertexBufferAccessor.HasBlendIndices());
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetBlendIndices(index), blendIndicesPtr + index * stride);
    //
    // 		// blendWeight
    // 		attribute = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::BlendWeight);
    //
    // 		const char* blendWeightPtr = firstVertexBufer->GetReadOnlyData(firstVertexFormat->GetOffset(attribute));
    //
    // 		int blendWeight = firstVertexBufferAccessor.GetBlendWeight<int>(index);
    //
    // 		ASSERT_EQUAL(blendWeight, *(reinterpret_cast<const int*>(blendWeightPtr + index * stride)));
    //
    // 		ASSERT_TRUE(firstVertexBufferAccessor.HasBlendWeight());
    //
    // 		ASSERT_EQUAL(firstVertexBufferAccessor.GetBlendWeight(index), blendWeightPtr + index * stride);
    // 	}
}

void Rendering::VertexBufferAccessorTesting::HaveNotTest()
{
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float4, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::TextureCoord, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::TextureCoord, 1),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::TextureCoord, 2),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::TextureCoord, 3),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::TextureCoord, 4),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float1, VertexFormatFlags::AttributeUsage::TextureCoord, 5),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float1, VertexFormatFlags::AttributeUsage::TextureCoord, 6) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    VertexBufferSharedPtr firstVertexBufer(VertexBuffer::Create());

    CoreTools::ReadFileManager manage(SYSTEM_TEXT("Resource/ResourcesSuite/VertexBuffer.vb"));

    firstVertexBufer->ReadFromFile(manage, *firstVertexFormat);

    VisualTest firstVisual(VisualPrimitiveType::None, firstVertexFormat, firstVertexBufer, IndexBufferSharedPtr());

    VertexBufferAccessor firstVertexBufferAccessor(firstVisual);

    ASSERT_TRUE(firstVertexBufferAccessor.HasPosition());
    ASSERT_FALSE(firstVertexBufferAccessor.HasNormal());
    ASSERT_FALSE(firstVertexBufferAccessor.HasTangent());
    ASSERT_FALSE(firstVertexBufferAccessor.HasBinormal());
    ASSERT_FALSE(firstVertexBufferAccessor.HasColor(0));
    ASSERT_FALSE(firstVertexBufferAccessor.HasColor(1));
    ASSERT_FALSE(firstVertexBufferAccessor.HasBlendIndices());
    ASSERT_FALSE(firstVertexBufferAccessor.HasBlendWeight());

    ASSERT_TRUE(firstVertexBufferAccessor.HasTextureCoord(0));
    ASSERT_TRUE(firstVertexBufferAccessor.HasTextureCoord(1));
    ASSERT_TRUE(firstVertexBufferAccessor.HasTextureCoord(2));
    ASSERT_TRUE(firstVertexBufferAccessor.HasTextureCoord(3));
    ASSERT_TRUE(firstVertexBufferAccessor.HasTextureCoord(4));
    ASSERT_TRUE(firstVertexBufferAccessor.HasTextureCoord(5));
    ASSERT_TRUE(firstVertexBufferAccessor.HasTextureCoord(6));
    ASSERT_FALSE(firstVertexBufferAccessor.HasTextureCoord(7));
}
