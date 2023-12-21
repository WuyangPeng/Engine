/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/19 10:04)

#include "VertexFormatTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/Resources/DataFormat.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::VertexFormatTesting::VertexFormatTesting(const OStreamShared& stream)
    : ParentType{ stream },
      attributeContainer{ VertexFormatAttribute{ DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::Position, 0 },
                          VertexFormatAttribute{ DataFormatType::R32G32B32Float, VertexFormatFlags::Semantic::Color, 1 },
                          VertexFormatAttribute{ DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::Binormal, 3 },
                          VertexFormatAttribute{ DataFormatType::R32G32B32Float, VertexFormatFlags::Semantic::Normal, 4 },
                          VertexFormatAttribute{ DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::PSize, 5 },
                          VertexFormatAttribute{ DataFormatType::R32G32B32Float, VertexFormatFlags::Semantic::BlendWeight, 2 } }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VertexFormatTesting)

void Rendering::VertexFormatTesting::DoRunUnitTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::VertexFormatTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AttributeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
}

void Rendering::VertexFormatTesting::BaseTest()
{
    const auto name = "VertexFormat";
    const auto vertexFormat = VertexFormat::Create(name);

    ASSERT_EQUAL(vertexFormat->GetName(), name);
    ASSERT_EQUAL(vertexFormat->GetNumAttributes(), 0);
    ASSERT_EQUAL(vertexFormat->GetVertexSize(), 0);
}

void Rendering::VertexFormatTesting::AttributeTest()
{
    const auto name = "VertexFormat";
    const auto vertexFormat = VertexFormat::Create(name, attributeContainer);

    ASSERT_EQUAL(vertexFormat->GetName(), name);
    ASSERT_EQUAL(vertexFormat->GetNumAttributes(), boost::numeric_cast<int>(attributeContainer.size()));

    auto vertexSize = 0;
    for (const auto& element : attributeContainer)
    {
        vertexSize += DataFormat::GetNumBytesPerStruct(element.GetType());
    }

    ASSERT_EQUAL(vertexFormat->GetVertexSize(), vertexSize);

    ASSERT_EQUAL(vertexFormat->GetIndex(VertexFormatFlags::Semantic::Position, 0), 0);
    ASSERT_EQUAL(vertexFormat->GetIndex(VertexFormatFlags::Semantic::Color, 1), 1);
    ASSERT_EQUAL(vertexFormat->GetIndex(VertexFormatFlags::Semantic::Binormal, 3), 2);
    ASSERT_EQUAL(vertexFormat->GetIndex(VertexFormatFlags::Semantic::Normal, 4), 3);
    ASSERT_EQUAL(vertexFormat->GetIndex(VertexFormatFlags::Semantic::PSize, 5), 4);
    ASSERT_EQUAL(vertexFormat->GetIndex(VertexFormatFlags::Semantic::BlendWeight, 2), 5);

    vertexFormat->Reset();

    ASSERT_EQUAL(vertexFormat->GetNumAttributes(), 0);
    ASSERT_EQUAL(vertexFormat->GetVertexSize(), 0);

    vertexFormat->Bind(DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::Color, 1);

    ASSERT_EQUAL(vertexFormat->GetNumAttributes(), 1);
    ASSERT_EQUAL(vertexFormat->GetVertexSize(), DataFormat::GetNumBytesPerStruct(vertexFormat->GetAttributeType(0)));

    ASSERT_EQUAL(vertexFormat->GetOffset(0), 0);
    ASSERT_EQUAL(vertexFormat->GetAttributeType(0), DataFormatType::R32G32B32A32Float);
    ASSERT_EQUAL(vertexFormat->GetSemantic(0), VertexFormatFlags::Semantic::Color);
    ASSERT_EQUAL(vertexFormat->GetUnit(0), 1);
}

void Rendering::VertexFormatTesting::StreamTest()
{
    const auto name = "VertexFormat";
    const auto vertexFormat0 = VertexFormat::Create(name, attributeContainer);

    auto outTopLevel = CoreTools::OutTopLevel::Create();
    outTopLevel.Insert(vertexFormat0);

    const CoreTools::BufferOutStream bufferOutStream{ outTopLevel };
    const auto buffer = bufferOutStream.GetBufferOutStreamInformation();

    const CoreTools::BufferInStream bufferInStream{ buffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 1, "流读取失败。");

    const auto vertexFormat1 = boost::polymorphic_pointer_cast<VertexFormat>(*inTopLevel.begin());

    ASSERT_EQUAL(vertexFormat0->GetName(), vertexFormat1->GetName());
    ASSERT_EQUAL(vertexFormat0->GetNumAttributes(), vertexFormat1->GetNumAttributes());
    ASSERT_EQUAL(vertexFormat0->GetVertexSize(), vertexFormat1->GetVertexSize());

    for (auto i = 0; i < vertexFormat0->GetNumAttributes(); ++i)
    {
        ASSERT_EQUAL(vertexFormat0->GetOffset(i), vertexFormat1->GetOffset(i));
        ASSERT_EQUAL(vertexFormat0->GetAttributeType(i), vertexFormat1->GetAttributeType(i));
        ASSERT_EQUAL(vertexFormat0->GetSemantic(i), vertexFormat1->GetSemantic(i));
        ASSERT_EQUAL(vertexFormat0->GetUnit(i), vertexFormat1->GetUnit(i));
    }
}
