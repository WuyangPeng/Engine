///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:06)

#include "ShaderBaseDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Shaders/ShaderBaseData.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Rendering::ShaderBaseDataTesting::ShaderBaseDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderBaseDataTesting)

void Rendering::ShaderBaseDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ShaderBaseDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
}

void Rendering::ShaderBaseDataTesting::InitTest()
{
    ShaderBaseData firstShaderBaseData{ 0 };

    ASSERT_EQUAL(firstShaderBaseData.GetNumber(), 0);

    firstShaderBaseData.InsertData("TestData1", ShaderFlags::VariableType::Half, ShaderFlags::VariableSemantic::Color1);

    ASSERT_EQUAL(firstShaderBaseData.GetNumber(), 1);

    firstShaderBaseData.InsertData("TestData2", ShaderFlags::VariableType::Half1X4, ShaderFlags::VariableSemantic::TextureCoord5);

    ASSERT_EQUAL(firstShaderBaseData.GetNumber(), 2);

    ASSERT_EQUAL(firstShaderBaseData.GetName(0), "TestData1");
    ASSERT_EQUAL(firstShaderBaseData.GetName(1), "TestData2");

    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetType(0), ShaderFlags::VariableType::Half);
    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetType(1), ShaderFlags::VariableType::Half1X4);

    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetSemantic(0), ShaderFlags::VariableSemantic::Color1);
    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetSemantic(1), ShaderFlags::VariableSemantic::TextureCoord5);

    firstShaderBaseData.SetData(0, "TestData3", ShaderFlags::VariableType::Float4X2, ShaderFlags::VariableSemantic::BlendWeight);

    ASSERT_EQUAL(firstShaderBaseData.GetName(0), "TestData3");
    ASSERT_EQUAL(firstShaderBaseData.GetName(1), "TestData2");

    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetType(0), ShaderFlags::VariableType::Float4X2);
    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetType(1), ShaderFlags::VariableType::Half1X4);

    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetSemantic(0), ShaderFlags::VariableSemantic::BlendWeight);
    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetSemantic(1), ShaderFlags::VariableSemantic::TextureCoord5);

    ShaderBaseData secondShaderBaseData(7);

    ASSERT_EQUAL(secondShaderBaseData.GetNumber(), 7);

    for (int i = 0; i < 7; ++i)
    {
        ASSERT_EQUAL(secondShaderBaseData.GetName(i), "");
        ASSERT_ENUM_EQUAL(secondShaderBaseData.GetType(i), ShaderFlags::VariableType::None);
        ASSERT_ENUM_EQUAL(secondShaderBaseData.GetSemantic(i), ShaderFlags::VariableSemantic::None);
    }
}

void Rendering::ShaderBaseDataTesting::CopyTest()
{
    ShaderBaseData firstShaderBaseData(4);

    ShaderBaseData secondShaderBaseData(firstShaderBaseData);

    ASSERT_EQUAL(firstShaderBaseData.GetNumber(), secondShaderBaseData.GetNumber());

    firstShaderBaseData.InsertData("TestData1", ShaderFlags::VariableType::Half, ShaderFlags::VariableSemantic::Color1);

    ASSERT_EQUAL(firstShaderBaseData.GetNumber(), 5);
    ASSERT_EQUAL(secondShaderBaseData.GetNumber(), 4);

    ShaderBaseData thirdShaderBaseData(15);

    secondShaderBaseData = thirdShaderBaseData;

    ASSERT_EQUAL(secondShaderBaseData.GetNumber(), thirdShaderBaseData.GetNumber());

    firstShaderBaseData.SetData(0, "TestData3", ShaderFlags::VariableType::Float4X2, ShaderFlags::VariableSemantic::BlendWeight);

    ASSERT_EQUAL(firstShaderBaseData.GetName(0), "TestData3");
    ASSERT_EQUAL(thirdShaderBaseData.GetName(0), "");

    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetType(0), ShaderFlags::VariableType::Float4X2);
    ASSERT_ENUM_EQUAL(thirdShaderBaseData.GetType(0), ShaderFlags::VariableType::None);

    ASSERT_ENUM_EQUAL(firstShaderBaseData.GetSemantic(0), ShaderFlags::VariableSemantic::BlendWeight);
    ASSERT_ENUM_EQUAL(thirdShaderBaseData.GetSemantic(0), ShaderFlags::VariableSemantic::None);

    ShaderBaseData fourthShaderBaseData(thirdShaderBaseData);

    ASSERT_EQUAL(fourthShaderBaseData.GetNumber(), thirdShaderBaseData.GetNumber());

    fourthShaderBaseData.Resize(20);
    ASSERT_EQUAL(fourthShaderBaseData.GetNumber(), 20);
    ASSERT_EQUAL(thirdShaderBaseData.GetNumber(), 15);
}
