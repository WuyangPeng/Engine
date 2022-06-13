///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/11 18:52)

#include "SingleShaderProfileDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Shaders/SingleShaderProfileData.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SingleShaderProfileDataTesting)

void Rendering::SingleShaderProfileDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
}

void Rendering::SingleShaderProfileDataTesting::InitTest()
{
    SingleShaderProfileData firstSingleShaderProfileData(10, 12);

    ASSERT_EQUAL(firstSingleShaderProfileData.GetBaseRegisterSize(), 10);
    ASSERT_EQUAL(firstSingleShaderProfileData.GetTextureUnitSize(), 12);

    ASSERT_EQUAL(firstSingleShaderProfileData.GetProgram(), "");

    for (int i = 0; i < 10; ++i)
    {
        ASSERT_EQUAL(firstSingleShaderProfileData.GetBaseRegister(i), 0);
    }

    for (int i = 0; i < 12; ++i)
    {
        ASSERT_EQUAL(firstSingleShaderProfileData.GetTextureUnit(i), 0);
    }

    firstSingleShaderProfileData.SetProgram("1");

    ASSERT_EQUAL(firstSingleShaderProfileData.GetProgram(), "1");

    for (int i = 0; i < 10; ++i)
    {
        firstSingleShaderProfileData.SetBaseRegister(i, i);
        ASSERT_EQUAL(firstSingleShaderProfileData.GetBaseRegister(i), i);
    }

    for (int i = 0; i < 12; ++i)
    {
        firstSingleShaderProfileData.SetTextureUnit(i, i * 2);
        ASSERT_EQUAL(firstSingleShaderProfileData.GetTextureUnit(i), i * 2);
    }
}

void Rendering::SingleShaderProfileDataTesting::CopyTest()
{
    SingleShaderProfileData firstSingleShaderProfileData(10, 12);

    firstSingleShaderProfileData.SetProgram("1");

    for (int i = 0; i < 10; ++i)
    {
        firstSingleShaderProfileData.SetBaseRegister(i, i);
    }

    for (int i = 0; i < 12; ++i)
    {
        firstSingleShaderProfileData.SetTextureUnit(i, i * 2);
    }

    SingleShaderProfileData secondSingleShaderProfileData(firstSingleShaderProfileData);

    ASSERT_EQUAL(firstSingleShaderProfileData.GetBaseRegisterSize(), secondSingleShaderProfileData.GetBaseRegisterSize());
    ASSERT_EQUAL(firstSingleShaderProfileData.GetTextureUnitSize(), secondSingleShaderProfileData.GetTextureUnitSize());
    ASSERT_EQUAL(firstSingleShaderProfileData.GetProgram(), secondSingleShaderProfileData.GetProgram());

    for (int i = 0; i < 10; ++i)
    {
        ASSERT_EQUAL(firstSingleShaderProfileData.GetBaseRegister(i), secondSingleShaderProfileData.GetBaseRegister(i));
    }

    for (int i = 0; i < 12; ++i)
    {
        ASSERT_EQUAL(firstSingleShaderProfileData.GetTextureUnit(i), secondSingleShaderProfileData.GetTextureUnit(i));
    }

    firstSingleShaderProfileData.SetTextureUnit(0, 3);

    ASSERT_EQUAL(firstSingleShaderProfileData.GetTextureUnit(0), 3);
    ASSERT_EQUAL(secondSingleShaderProfileData.GetTextureUnit(0), 0);
}
