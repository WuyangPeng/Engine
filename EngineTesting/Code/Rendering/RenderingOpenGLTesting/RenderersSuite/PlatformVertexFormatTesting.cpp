// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:29)

#include "PlatformVertexFormatTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/PlatformVertexFormat.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexFormat.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformVertexFormatTesting)

void Rendering::PlatformVertexFormatTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(VertexFormatTest);

    RendererManager::Destroy();
}
#include SYSTEM_WARNING_DISABLE(26414)
void Rendering::PlatformVertexFormatTesting::VertexFormatTest()
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
                         VertexFormatFlags::AttributeUsage::Psize, 0)
    };

    auto firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
    renderer->Init();

    PlatformVertexFormat platformVertexFormat(renderer.get(), firstVertexFormat.get());

    platformVertexFormat.Enable(renderer.get());
    platformVertexFormat.Disable(renderer.get());
}
