///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 16:18)

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
