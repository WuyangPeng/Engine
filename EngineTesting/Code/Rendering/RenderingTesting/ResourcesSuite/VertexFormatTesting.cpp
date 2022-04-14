// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 10:00)

#include "VertexFormatTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexFormat.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VertexFormatTesting)

void Rendering::VertexFormatTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::VertexFormatTesting::BaseTest()
{
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float1, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::Normal, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Tangent, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float4, VertexFormatFlags::AttributeUsage::Binormal, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Half1, VertexFormatFlags::AttributeUsage::TextureCoord, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Half2, VertexFormatFlags::AttributeUsage::Color, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Half3, VertexFormatFlags::AttributeUsage::BlendIndices, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Half4, VertexFormatFlags::AttributeUsage::BlendWeight, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::UByte4, VertexFormatFlags::AttributeUsage::FogCoord, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Short1, VertexFormatFlags::AttributeUsage::Psize, 0) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(), static_cast<int>(firstVertexFormatType.size()));

    int offset = 0;

    for (unsigned i = 0; i < firstVertexFormatType.size(); ++i)
    {
        ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), 0);
        ASSERT_EQUAL(firstVertexFormat->GetOffset(i), offset);
        ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i), firstVertexFormatType[i].GetType());
        ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i), firstVertexFormatType[i].GetUsage());
        ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i), firstVertexFormatType[i].GetUsageIndex());

        offset += VertexFormat::GetTypeSize(firstVertexFormatType[i].GetType());
    }

    ASSERT_EQUAL(firstVertexFormat->GetStride(), static_cast<int>(offset));

    for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
    {
        ASSERT_EQUAL(i, firstVertexFormat->GetIndex(firstVertexFormatType[i].GetUsage(), firstVertexFormatType[i].GetUsageIndex()));
    }

    firstVertexFormat->SetAttribute(0, 0, 0, VertexFormatFlags::AttributeType::Half2, VertexFormatFlags::AttributeUsage::Position, 2);

    ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(0), 0);
    ASSERT_EQUAL(firstVertexFormat->GetOffset(0), 0);
    ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(0), VertexFormatFlags::AttributeType::Half2);
    ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(0), VertexFormatFlags::AttributeUsage::Position);
    ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(0), 2);
}

void Rendering::VertexFormatTesting::StreamTest()
{
    vector<VertexFormatElement> firstVertexFormatElement{ VertexFormatElement(0, 0, VertexFormatType(VertexFormatFlags::AttributeType::Float1, VertexFormatFlags::AttributeUsage::Position, 0)),
                                                          VertexFormatElement(1, 4, VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::Normal, 0)),
                                                          VertexFormatElement(2, 12, VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Tangent, 0)),
                                                          VertexFormatElement(3, 24, VertexFormatType(VertexFormatFlags::AttributeType::Float4, VertexFormatFlags::AttributeUsage::Binormal, 0)),
                                                          VertexFormatElement(4, 40, VertexFormatType(VertexFormatFlags::AttributeType::Half1, VertexFormatFlags::AttributeUsage::TextureCoord, 0)),
                                                          VertexFormatElement(5, 42, VertexFormatType(VertexFormatFlags::AttributeType::Half2, VertexFormatFlags::AttributeUsage::Color, 0)),
                                                          VertexFormatElement(6, 46, VertexFormatType(VertexFormatFlags::AttributeType::Half3, VertexFormatFlags::AttributeUsage::BlendIndices, 0)),
                                                          VertexFormatElement(7, 52, VertexFormatType(VertexFormatFlags::AttributeType::Half4, VertexFormatFlags::AttributeUsage::BlendWeight, 0)),
                                                          VertexFormatElement(8, 60, VertexFormatType(VertexFormatFlags::AttributeType::Short2, VertexFormatFlags::AttributeUsage::FogCoord, 0)),
                                                          VertexFormatElement(9, 64, VertexFormatType(VertexFormatFlags::AttributeType::Short4, VertexFormatFlags::AttributeUsage::Psize, 0)) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatElement);

    ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(), static_cast<int>(firstVertexFormatElement.size()));

    int offset = 0;

    for (auto i = 0; i < boost::numeric_cast<int>(firstVertexFormatElement.size()); ++i)
    {
        ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), i);
        ASSERT_EQUAL(firstVertexFormat->GetOffset(i), offset);
        ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i), firstVertexFormatElement[i].GetType());
        ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i), firstVertexFormatElement[i].GetUsage());
        ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i), firstVertexFormatElement[i].GetUsageIndex());

        offset += VertexFormat::GetTypeSize(firstVertexFormatElement[i].GetType());
    }

    ASSERT_EQUAL(firstVertexFormat->GetStride(), static_cast<int>(offset));

    for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
    {
        ASSERT_EQUAL(i, firstVertexFormat->GetIndex(firstVertexFormatElement[i].GetUsage(), firstVertexFormatElement[i].GetUsageIndex()));
    }

    // 	CoreTools::OutTopLevel outTopLevel;
    // 	CoreTools::ObjectInterfaceSharedPtr firstBuffer(firstVertexFormat.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
    //
    // 	outTopLevel.Insert(firstBuffer);
    //
    // 	CoreTools::BufferOutStream outStream(outTopLevel);
    //
    // 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
    //
    // 	CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 	VertexFormatSharedPtr secondVertexFormat = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<VertexFormatSharedPtr>();
    //
    // 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(), secondVertexFormat->GetNumAttributes());
    //
    // 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), secondVertexFormat->GetStreamIndex(i));
    // 		ASSERT_EQUAL(firstVertexFormat->GetOffset(i), secondVertexFormat->GetOffset(i));
    // 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i), secondVertexFormat->GetAttributeType(i));
    // 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i), secondVertexFormat->GetAttributeUsage(i));
    // 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i), secondVertexFormat->GetUsageIndex(i));
    // 	}
    //
    // 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride());
    //
    // 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVertexFormat->GetIndex(firstVertexFormatElement[i].GetUsage(), firstVertexFormatElement[i].GetUsageIndex()),
    // 					 secondVertexFormat->GetIndex(firstVertexFormatElement[i].GetUsage(),  firstVertexFormatElement[i].GetUsageIndex()));
    // 	}
}
