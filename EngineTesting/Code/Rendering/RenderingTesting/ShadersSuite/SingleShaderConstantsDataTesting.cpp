///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:07)

#include "SingleShaderConstantsDataTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Shaders/SingleShaderConstantsData.h"

Rendering::SingleShaderConstantsDataTesting::SingleShaderConstantsDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SingleShaderConstantsDataTesting)

void Rendering::SingleShaderConstantsDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
