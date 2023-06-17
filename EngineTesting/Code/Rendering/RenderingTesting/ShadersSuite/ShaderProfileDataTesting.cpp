///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:07)

#include "ShaderProfileDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Shaders/ShaderProfileData.h"

Rendering::ShaderProfileDataTesting::ShaderProfileDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderProfileDataTesting)

void Rendering::ShaderProfileDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ShaderProfileDataTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::ShaderProfileDataTesting::InitTest()
{
    ShaderProfileData firstShaderProfileData(10, 12);

    ASSERT_EQUAL(firstShaderProfileData.GetBaseRegisterSize(), 10);
    ASSERT_EQUAL(firstShaderProfileData.GetTextureUnitSize(), 12);

    for (int profiles = 0; profiles < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++profiles)
    {
        ASSERT_EQUAL(firstShaderProfileData.GetProgram(profiles), "");

        for (int i = 0; i < 10; ++i)
        {
            ASSERT_EQUAL(firstShaderProfileData.GetBaseRegister(profiles, i), 0);
        }

        for (int i = 0; i < 12; ++i)
        {
            ASSERT_EQUAL(firstShaderProfileData.GetTextureUnit(profiles, i), 0);
        }
    }

    for (int profiles = 0; profiles < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++profiles)
    {
        firstShaderProfileData.SetProgram(profiles, "1");

        ASSERT_EQUAL(firstShaderProfileData.GetProgram(profiles), "1");

        for (int i = 0; i < 10; ++i)
        {
            firstShaderProfileData.SetBaseRegister(profiles, i, i);
            ASSERT_EQUAL(firstShaderProfileData.GetBaseRegister(profiles, i), i);
        }

        for (int i = 0; i < 12; ++i)
        {
            firstShaderProfileData.SetTextureUnit(profiles, i, i * 2);
            ASSERT_EQUAL(firstShaderProfileData.GetTextureUnit(profiles, i), i * 2);
        }
    }
}

void Rendering::ShaderProfileDataTesting::CopyTest()
{
    ShaderProfileData firstShaderProfileData(10, 12);

    for (int profiles = 0; profiles < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++profiles)
    {
        firstShaderProfileData.SetProgram(profiles, "1");

        for (int i = 0; i < 10; ++i)
        {
            firstShaderProfileData.SetBaseRegister(profiles, i, i);
        }

        for (int i = 0; i < 12; ++i)
        {
            firstShaderProfileData.SetTextureUnit(profiles, i, i * 2);
        }
    }

    ShaderProfileData secondShaderProfileData(firstShaderProfileData);

    ASSERT_EQUAL(firstShaderProfileData.GetBaseRegisterSize(), secondShaderProfileData.GetBaseRegisterSize());
    ASSERT_EQUAL(firstShaderProfileData.GetTextureUnitSize(), secondShaderProfileData.GetTextureUnitSize());

    for (int profiles = 0; profiles < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++profiles)
    {
        ASSERT_EQUAL(firstShaderProfileData.GetProgram(profiles), secondShaderProfileData.GetProgram(profiles));

        for (int i = 0; i < 10; ++i)
        {
            ASSERT_EQUAL(firstShaderProfileData.GetBaseRegister(profiles, i), secondShaderProfileData.GetBaseRegister(profiles, i));
        }

        for (int i = 0; i < 12; ++i)
        {
            ASSERT_EQUAL(firstShaderProfileData.GetTextureUnit(profiles, i), secondShaderProfileData.GetTextureUnit(profiles, i));
        }
    }

    firstShaderProfileData.SetTextureUnit(System::EnumCastUnderlying(ShaderFlags::VertexShaderProfile::VS11), 0, 3);

    ASSERT_EQUAL(firstShaderProfileData.GetTextureUnit(System::EnumCastUnderlying(ShaderFlags::VertexShaderProfile::VS11), 0), 3);
    ASSERT_EQUAL(secondShaderProfileData.GetTextureUnit(System::EnumCastUnderlying(ShaderFlags::VertexShaderProfile::VS11), 0), 0);
}
