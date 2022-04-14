// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:37)

#include "OpenGLVertexFormatDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/OpenGLVertexFormatDataDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexFormat.h"
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, OpenGLVertexFormatDataTesting)

void Rendering::OpenGLVertexFormatDataTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsagePositionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsageNormalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsageTangentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsageBinormalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsageBlendIndicesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsageBlendWeightTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsageFogCoordTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AttributeUsagePsizeTest);

    RendererManager::Destroy();
}

void Rendering::OpenGLVertexFormatDataTesting::AttributeUsagePositionTest()
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
        VertexFormatType(VertexFormatFlags::AttributeType::Half2,
                         VertexFormatFlags::AttributeUsage::Color, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half3,
                         VertexFormatFlags::AttributeUsage::BlendIndices, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half4,
                         VertexFormatFlags::AttributeUsage::BlendWeight, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
                         VertexFormatFlags::AttributeUsage::FogCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Short1,
                         VertexFormatFlags::AttributeUsage::Psize, 0)
    };

    auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Position> data;

    data.Init(firstVertexFormat.get());

    ASSERT_TRUE(data.IsHas());
    ASSERT_EQUAL(data.GetChannels(), 3u);
    ASSERT_ENUM_EQUAL(data.GetType(), System::OpenGLData::Float);
    const int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Position);
    ASSERT_EQUAL(boost::numeric_cast<int>(data.GetOffset()), firstVertexFormat->GetOffset(index));

    data.Enable(firstVertexFormat->GetStride());
    data.Disable();
}

void Rendering::OpenGLVertexFormatDataTesting::AttributeUsageNormalTest()
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
        VertexFormatType(VertexFormatFlags::AttributeType::Half2,
                         VertexFormatFlags::AttributeUsage::Color, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half3,
                         VertexFormatFlags::AttributeUsage::BlendIndices, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half4,
                         VertexFormatFlags::AttributeUsage::BlendWeight, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
                         VertexFormatFlags::AttributeUsage::FogCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Short1,
                         VertexFormatFlags::AttributeUsage::Psize, 0)
    };

    auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Normal> data;

    data.Init(firstVertexFormat.get());

    ASSERT_TRUE(data.IsHas());
    ASSERT_EQUAL(data.GetChannels(), 2u);
    ASSERT_ENUM_EQUAL(data.GetType(), System::OpenGLData::Float);
    const int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Normal);
    ASSERT_EQUAL(boost::numeric_cast<int>(data.GetOffset()), firstVertexFormat->GetOffset(index));

    data.Enable(firstVertexFormat->GetStride());
    data.Disable();
}

void Rendering::OpenGLVertexFormatDataTesting::AttributeUsageTangentTest()
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
        VertexFormatType(VertexFormatFlags::AttributeType::Half2,
                         VertexFormatFlags::AttributeUsage::Color, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half3,
                         VertexFormatFlags::AttributeUsage::BlendIndices, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half4,
                         VertexFormatFlags::AttributeUsage::BlendWeight, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
                         VertexFormatFlags::AttributeUsage::FogCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Short1,
                         VertexFormatFlags::AttributeUsage::Psize, 0)
    };

    auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Tangent> data;

    data.Init(firstVertexFormat.get());

    ASSERT_TRUE(data.IsHas());
    ASSERT_EQUAL(data.GetChannels(), 3u);
    ASSERT_ENUM_EQUAL(data.GetType(), System::OpenGLData::Float);
    const int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Tangent);
    ASSERT_EQUAL(boost::numeric_cast<int>(data.GetOffset()), firstVertexFormat->GetOffset(index));

    data.Enable(firstVertexFormat->GetStride());
    data.Disable();
}

void Rendering::OpenGLVertexFormatDataTesting::AttributeUsageBinormalTest()
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
        VertexFormatType(VertexFormatFlags::AttributeType::Half2,
                         VertexFormatFlags::AttributeUsage::Color, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half3,
                         VertexFormatFlags::AttributeUsage::BlendIndices, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half4,
                         VertexFormatFlags::AttributeUsage::BlendWeight, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
                         VertexFormatFlags::AttributeUsage::FogCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Short1,
                         VertexFormatFlags::AttributeUsage::Psize, 0)
    };

    auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Binormal> data;

    data.Init(firstVertexFormat.get());

    ASSERT_TRUE(data.IsHas());
    ASSERT_EQUAL(data.GetChannels(), 4u);
    ASSERT_ENUM_EQUAL(data.GetType(), System::OpenGLData::Float);
    const int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Binormal);
    ASSERT_EQUAL(boost::numeric_cast<int>(data.GetOffset()), firstVertexFormat->GetOffset(index));

    data.Enable(firstVertexFormat->GetStride());
    data.Disable();
}

void Rendering::OpenGLVertexFormatDataTesting::AttributeUsageBlendIndicesTest()
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
        VertexFormatType(VertexFormatFlags::AttributeType::Half2,
                         VertexFormatFlags::AttributeUsage::Color, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half3,
                         VertexFormatFlags::AttributeUsage::BlendIndices, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half4,
                         VertexFormatFlags::AttributeUsage::BlendWeight, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
                         VertexFormatFlags::AttributeUsage::FogCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Short1,
                         VertexFormatFlags::AttributeUsage::Psize, 0)
    };

    auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::BlendIndices> data;

    data.Init(firstVertexFormat.get());

    ASSERT_TRUE(data.IsHas());
    ASSERT_EQUAL(data.GetChannels(), 3u);
    ASSERT_ENUM_EQUAL(data.GetType(), System::OpenGLData::HalfFloat);
    const int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::BlendIndices);
    ASSERT_EQUAL(boost::numeric_cast<int>(data.GetOffset()), firstVertexFormat->GetOffset(index));

    data.Enable(firstVertexFormat->GetStride());
    data.Disable();
}

void Rendering::OpenGLVertexFormatDataTesting::AttributeUsageBlendWeightTest()
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
        VertexFormatType(VertexFormatFlags::AttributeType::Half2,
                         VertexFormatFlags::AttributeUsage::Color, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half3,
                         VertexFormatFlags::AttributeUsage::BlendIndices, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half4,
                         VertexFormatFlags::AttributeUsage::BlendWeight, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
                         VertexFormatFlags::AttributeUsage::FogCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Short1,
                         VertexFormatFlags::AttributeUsage::Psize, 0)
    };

    auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::BlendWeight> data;

    data.Init(firstVertexFormat.get());

    ASSERT_TRUE(data.IsHas());
    ASSERT_EQUAL(data.GetChannels(), 4u);
    ASSERT_ENUM_EQUAL(data.GetType(), System::OpenGLData::HalfFloat);
    const int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::BlendWeight);
    ASSERT_EQUAL(boost::numeric_cast<int>(data.GetOffset()), firstVertexFormat->GetOffset(index));

    data.Enable(firstVertexFormat->GetStride());
    data.Disable();
}

void Rendering::OpenGLVertexFormatDataTesting::AttributeUsageFogCoordTest()
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
        VertexFormatType(VertexFormatFlags::AttributeType::Half2,
                         VertexFormatFlags::AttributeUsage::Color, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half3,
                         VertexFormatFlags::AttributeUsage::BlendIndices, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half4,
                         VertexFormatFlags::AttributeUsage::BlendWeight, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
                         VertexFormatFlags::AttributeUsage::FogCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Short1,
                         VertexFormatFlags::AttributeUsage::Psize, 0)
    };

    auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::FogCoord> data;

    data.Init(firstVertexFormat.get());

    ASSERT_TRUE(data.IsHas());
    ASSERT_EQUAL(data.GetChannels(), 4u);
    ASSERT_ENUM_EQUAL(data.GetType(), System::OpenGLData::UnsignedByte);
    const int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::FogCoord);
    ASSERT_EQUAL(boost::numeric_cast<int>(data.GetOffset()), firstVertexFormat->GetOffset(index));

    data.Enable(firstVertexFormat->GetStride());
    data.Disable();
}

void Rendering::OpenGLVertexFormatDataTesting::AttributeUsagePsizeTest()
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
        VertexFormatType(VertexFormatFlags::AttributeType::Half2,
                         VertexFormatFlags::AttributeUsage::Color, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half3,
                         VertexFormatFlags::AttributeUsage::BlendIndices, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Half4,
                         VertexFormatFlags::AttributeUsage::BlendWeight, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::UByte4,
                         VertexFormatFlags::AttributeUsage::FogCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Short1,
                         VertexFormatFlags::AttributeUsage::Psize, 0)
    };

    auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Psize> data;

    data.Init(firstVertexFormat.get());

    ASSERT_TRUE(data.IsHas());
    ASSERT_EQUAL(data.GetChannels(), 1u);
    ASSERT_ENUM_EQUAL(data.GetType(), System::OpenGLData::Short);
    const int index = firstVertexFormat->GetIndex(VertexFormatFlags::AttributeUsage::Psize);
    ASSERT_EQUAL(boost::numeric_cast<int>(data.GetOffset()), firstVertexFormat->GetOffset(index));

    data.Enable(firstVertexFormat->GetStride());
    data.Disable();
}
