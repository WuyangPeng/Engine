// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:31)

#include "ShaderConstantsDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Shaders/ShaderConstantsData.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ShaderConstantsDataTesting)

void Rendering::ShaderConstantsDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
}

void Rendering::ShaderConstantsDataTesting::InitTest()
{
    ShaderConstantsData firstShaderConstantsData{ 0 };

    ASSERT_EQUAL(firstShaderConstantsData.GetNumConstants(), 0);

    firstShaderConstantsData.InsertData("TestData1", 2);

    ASSERT_EQUAL(firstShaderConstantsData.GetNumConstants(), 1);

    firstShaderConstantsData.InsertData("TestData2", 3);

    ASSERT_EQUAL(firstShaderConstantsData.GetNumConstants(), 2);

    ASSERT_EQUAL(firstShaderConstantsData.GetConstantName(0), "TestData1");
    ASSERT_EQUAL(firstShaderConstantsData.GetConstantName(1), "TestData2");

    ASSERT_EQUAL(firstShaderConstantsData.GetNumRegistersUsed(0), 2);
    ASSERT_EQUAL(firstShaderConstantsData.GetNumRegistersUsed(1), 3);

    firstShaderConstantsData.SetConstant(0, "TestData3", 4);

    ASSERT_EQUAL(firstShaderConstantsData.GetConstantName(0), "TestData3");
    ASSERT_EQUAL(firstShaderConstantsData.GetConstantName(1), "TestData2");

    ASSERT_EQUAL(firstShaderConstantsData.GetNumRegistersUsed(0), 4);
    ASSERT_EQUAL(firstShaderConstantsData.GetNumRegistersUsed(1), 3);

    ShaderConstantsData secondShaderConstantsData(7);

    ASSERT_EQUAL(secondShaderConstantsData.GetNumConstants(), 7);

    for (int i = 0; i < 7; ++i)
    {
        ASSERT_EQUAL(secondShaderConstantsData.GetConstantName(i), "");
        ASSERT_EQUAL(secondShaderConstantsData.GetNumRegistersUsed(i), 0);
    }
}

void Rendering::ShaderConstantsDataTesting::CopyTest()
{
    ShaderConstantsData firstShaderConstantsData(4);

    ShaderConstantsData secondShaderConstantsData(firstShaderConstantsData);

    ASSERT_EQUAL(firstShaderConstantsData.GetNumConstants(), secondShaderConstantsData.GetNumConstants());

    firstShaderConstantsData.InsertData("TestData1", 7);

    ASSERT_EQUAL(firstShaderConstantsData.GetNumConstants(), 5);
    ASSERT_EQUAL(secondShaderConstantsData.GetNumConstants(), 4);

    ShaderConstantsData thirdShaderConstantsData(15);

    secondShaderConstantsData = thirdShaderConstantsData;

    ASSERT_EQUAL(secondShaderConstantsData.GetNumConstants(), thirdShaderConstantsData.GetNumConstants());

    firstShaderConstantsData.SetConstant(0, "TestData3", 1);

    ASSERT_EQUAL(firstShaderConstantsData.GetConstantName(0), "TestData3");
    ASSERT_EQUAL(thirdShaderConstantsData.GetConstantName(0), "");

    ASSERT_EQUAL(firstShaderConstantsData.GetNumRegistersUsed(0), 1);
    ASSERT_EQUAL(thirdShaderConstantsData.GetNumRegistersUsed(0), 0);

    ShaderConstantsData fourthShaderConstantsData(thirdShaderConstantsData);

    ASSERT_EQUAL(fourthShaderConstantsData.GetNumConstants(), thirdShaderConstantsData.GetNumConstants());

    fourthShaderConstantsData.Resize(20);
    ASSERT_EQUAL(fourthShaderConstantsData.GetNumConstants(), 20);
    ASSERT_EQUAL(thirdShaderConstantsData.GetNumConstants(), 15);
}
