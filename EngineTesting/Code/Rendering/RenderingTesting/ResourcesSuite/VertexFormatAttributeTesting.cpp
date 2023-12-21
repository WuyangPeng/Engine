/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/19 09:25)

#include "VertexFormatAttributeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Resources/Buffers/VertexFormatAttribute.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"

Rendering::VertexFormatAttributeTesting::VertexFormatAttributeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VertexFormatAttributeTesting)

void Rendering::VertexFormatAttributeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::VertexFormatAttributeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
}

void Rendering::VertexFormatAttributeTesting::DefaultTest()
{
    const VertexFormatAttribute vertexFormatAttribute{};

    ASSERT_EQUAL(vertexFormatAttribute.GetType(), DataFormatType::Unknown);
    ASSERT_EQUAL(vertexFormatAttribute.GetSemantic(), VertexFormatFlags::Semantic::None);
    ASSERT_EQUAL(vertexFormatAttribute.GetUnit(), 0);
    ASSERT_EQUAL(vertexFormatAttribute.GetOffset(), 0);
}

void Rendering::VertexFormatAttributeTesting::BaseTest()
{
    VertexFormatAttribute vertexFormatAttribute{ DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::Position, 5 };

    ASSERT_EQUAL(vertexFormatAttribute.GetType(), DataFormatType::R32G32B32A32Float);
    ASSERT_EQUAL(vertexFormatAttribute.GetSemantic(), VertexFormatFlags::Semantic::Position);
    ASSERT_EQUAL(vertexFormatAttribute.GetUnit(), 5);
    ASSERT_EQUAL(vertexFormatAttribute.GetOffset(), 0);

    vertexFormatAttribute.SetType(DataFormatType::R32G32B32Float);

    ASSERT_EQUAL(vertexFormatAttribute.GetType(), DataFormatType::R32G32B32Float);
    ASSERT_EQUAL(vertexFormatAttribute.GetSemantic(), VertexFormatFlags::Semantic::Position);
    ASSERT_EQUAL(vertexFormatAttribute.GetUnit(), 5);
    ASSERT_EQUAL(vertexFormatAttribute.GetOffset(), 0);

    vertexFormatAttribute.SetSemantic(VertexFormatFlags::Semantic::Normal);

    ASSERT_EQUAL(vertexFormatAttribute.GetType(), DataFormatType::R32G32B32Float);
    ASSERT_EQUAL(vertexFormatAttribute.GetSemantic(), VertexFormatFlags::Semantic::Normal);
    ASSERT_EQUAL(vertexFormatAttribute.GetUnit(), 5);
    ASSERT_EQUAL(vertexFormatAttribute.GetOffset(), 0);

    vertexFormatAttribute.SetUnit(3);

    ASSERT_EQUAL(vertexFormatAttribute.GetType(), DataFormatType::R32G32B32Float);
    ASSERT_EQUAL(vertexFormatAttribute.GetSemantic(), VertexFormatFlags::Semantic::Normal);
    ASSERT_EQUAL(vertexFormatAttribute.GetUnit(), 3);
    ASSERT_EQUAL(vertexFormatAttribute.GetOffset(), 0);

    vertexFormatAttribute.SetOffset(7);

    ASSERT_EQUAL(vertexFormatAttribute.GetType(), DataFormatType::R32G32B32Float);
    ASSERT_EQUAL(vertexFormatAttribute.GetSemantic(), VertexFormatFlags::Semantic::Normal);
    ASSERT_EQUAL(vertexFormatAttribute.GetUnit(), 3);
    ASSERT_EQUAL(vertexFormatAttribute.GetOffset(), 7);

    vertexFormatAttribute.SetVertexFormatAttribute(DataFormatType::R16G16B16A16Float, VertexFormatFlags::Semantic::Color, 2, 5);

    ASSERT_EQUAL(vertexFormatAttribute.GetType(), DataFormatType::R16G16B16A16Float);
    ASSERT_EQUAL(vertexFormatAttribute.GetSemantic(), VertexFormatFlags::Semantic::Color);
    ASSERT_EQUAL(vertexFormatAttribute.GetUnit(), 2);
    ASSERT_EQUAL(vertexFormatAttribute.GetOffset(), 5);

    vertexFormatAttribute.Clear();

    ASSERT_EQUAL(vertexFormatAttribute.GetType(), DataFormatType::Unknown);
    ASSERT_EQUAL(vertexFormatAttribute.GetSemantic(), VertexFormatFlags::Semantic::None);
    ASSERT_EQUAL(vertexFormatAttribute.GetUnit(), 0);
    ASSERT_EQUAL(vertexFormatAttribute.GetOffset(), 0);
}

void Rendering::VertexFormatAttributeTesting::StreamTest()
{
    const VertexFormatAttribute vertexFormatAttribute0{ DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::Position, 5, 6 };

    const auto bufferSize = vertexFormatAttribute0.GetStreamingSize();

    const auto objectRegister = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget{ bufferSize, objectRegister };

    vertexFormatAttribute0.Save(bufferTarget);

    CoreTools::BufferSource bufferSource0{ bufferTarget.GetFileBuffer() };

    VertexFormatAttribute vertexFormatAttribute1{};
    vertexFormatAttribute1.Load(bufferSource0);

    ASSERT_EQUAL(vertexFormatAttribute0.GetType(), vertexFormatAttribute1.GetType());
    ASSERT_EQUAL(vertexFormatAttribute0.GetSemantic(), vertexFormatAttribute1.GetSemantic());
    ASSERT_EQUAL(vertexFormatAttribute0.GetUnit(), vertexFormatAttribute1.GetUnit());
    ASSERT_EQUAL(vertexFormatAttribute0.GetOffset(), vertexFormatAttribute1.GetOffset());
}