// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:33)

#include "SingleShaderConstantsDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Shaders/SingleShaderConstantsData.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SingleShaderConstantsDataTesting)

void Rendering::SingleShaderConstantsDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
}

void Rendering::SingleShaderConstantsDataTesting::InitTest()
{
    SingleShaderConstantsData firstSingleShaderConstantsData{ CoreTools::DisableNotThrow::Disable };

    ASSERT_EQUAL(firstSingleShaderConstantsData.GetConstantName(), "");
    ASSERT_EQUAL(firstSingleShaderConstantsData.GetNumRegistersUsed(), 0);

    firstSingleShaderConstantsData.SetConstant("Constant", 5);

    ASSERT_EQUAL(firstSingleShaderConstantsData.GetConstantName(), "Constant");
    ASSERT_EQUAL(firstSingleShaderConstantsData.GetNumRegistersUsed(), 5);

    SingleShaderConstantsData secondSingleShaderConstantsData("Data", 15);

    ASSERT_EQUAL(secondSingleShaderConstantsData.GetConstantName(), "Data");
    ASSERT_EQUAL(secondSingleShaderConstantsData.GetNumRegistersUsed(), 15);
}

void Rendering::SingleShaderConstantsDataTesting::CopyTest()
{
    SingleShaderConstantsData firstSingleShaderConstantsData{ CoreTools::DisableNotThrow::Disable };

    ASSERT_EQUAL(firstSingleShaderConstantsData.GetConstantName(), "");
    ASSERT_EQUAL(firstSingleShaderConstantsData.GetNumRegistersUsed(), 0);

    SingleShaderConstantsData secondSingleShaderConstantsData(firstSingleShaderConstantsData);

    ASSERT_EQUAL(firstSingleShaderConstantsData.GetConstantName(), secondSingleShaderConstantsData.GetConstantName());
    ASSERT_EQUAL(firstSingleShaderConstantsData.GetNumRegistersUsed(), secondSingleShaderConstantsData.GetNumRegistersUsed());

    firstSingleShaderConstantsData.SetConstant("Constant", 1);

    ASSERT_EQUAL(firstSingleShaderConstantsData.GetConstantName(), "Constant");
    ASSERT_EQUAL(firstSingleShaderConstantsData.GetNumRegistersUsed(), 1);
    ASSERT_EQUAL(secondSingleShaderConstantsData.GetConstantName(), "");
    ASSERT_EQUAL(secondSingleShaderConstantsData.GetNumRegistersUsed(), 0);

    SingleShaderConstantsData thirdSingleShaderConstantsData("Data", 2);

    secondSingleShaderConstantsData = thirdSingleShaderConstantsData;

    ASSERT_EQUAL(thirdSingleShaderConstantsData.GetConstantName(), secondSingleShaderConstantsData.GetConstantName());
    ASSERT_EQUAL(thirdSingleShaderConstantsData.GetNumRegistersUsed(), secondSingleShaderConstantsData.GetNumRegistersUsed());

    thirdSingleShaderConstantsData.SetConstant("ConstantsData", 12);

    ASSERT_EQUAL(secondSingleShaderConstantsData.GetConstantName(), "Data");
    ASSERT_EQUAL(secondSingleShaderConstantsData.GetNumRegistersUsed(), 2);
    ASSERT_EQUAL(thirdSingleShaderConstantsData.GetConstantName(), "ConstantsData");
    ASSERT_EQUAL(thirdSingleShaderConstantsData.GetNumRegistersUsed(), 12);
}
