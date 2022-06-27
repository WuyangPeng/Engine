///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/14 18:29)

#include "ShaderFloatTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/ShaderFloats/ShaderFloat.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ShaderFloatTesting)

void Rendering::ShaderFloatTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::ShaderFloatTesting::InitTest()
{
    constexpr int firstNumRegisters = 5;
    ShaderFloat firstShaderFloat{ CoreTools::DisableNotThrow::Disable };
    ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 0);

    firstShaderFloat.SetNumRegisters(firstNumRegisters);
    ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), firstNumRegisters);

    ASSERT_UNEQUAL_NULL_PTR(firstShaderFloat.GetData());

    ASSERT_TRUE(firstShaderFloat.AllowUpdater());
    firstShaderFloat.DisableUpdater();
    ASSERT_FALSE(firstShaderFloat.AllowUpdater());
    firstShaderFloat.EnableUpdater();
    ASSERT_TRUE(firstShaderFloat.AllowUpdater());

    vector<float> firstData(firstNumRegisters * 4, 1);
    firstShaderFloat.SetRegisters(firstData);
    ASSERT_EQUAL(firstData, firstShaderFloat.GetRegisters());

    constexpr int secondNumRegisters = 10;
    const ShaderFloat secondShaderFloat(secondNumRegisters);
    ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), secondNumRegisters);
    ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat.GetData());
    ASSERT_TRUE(secondShaderFloat.AllowUpdater());

    constexpr int thirdNumRegisters = 6;
    vector<float> thirdData(thirdNumRegisters * 4);
    ShaderFloat thirdShaderFloat(thirdData);
    ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), thirdNumRegisters);

    ASSERT_UNEQUAL_NULL_PTR(thirdShaderFloat.GetData());

    ASSERT_TRUE(thirdShaderFloat.AllowUpdater());
    thirdShaderFloat.DisableUpdater();
    ASSERT_FALSE(thirdShaderFloat.AllowUpdater());
    thirdShaderFloat.EnableUpdater();
    ASSERT_TRUE(thirdShaderFloat.AllowUpdater());

    for (int i = 0; i < thirdNumRegisters; ++i)
    {
        vector<float> fourthData(4, static_cast<float>(i));
        thirdShaderFloat.SetRegister(i, fourthData);

        vector<float> fifthData = thirdShaderFloat.GetRegister(i);

        for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
        {
            ASSERT_APPROXIMATE(thirdShaderFloat[i * 4 + registerIndex], static_cast<float>(i), 1e-8f);
            ASSERT_APPROXIMATE(fifthData.at(registerIndex), fourthData.at(registerIndex), 1e-8f);
        }
    }
}

void Rendering::ShaderFloatTesting::CopyTest()
{
    constexpr int firstNumRegisters = 5;
    constexpr int secondNumRegisters = 15;

    ShaderFloat firstShaderFloat{ CoreTools::DisableNotThrow::Disable };
    ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 0);

    ShaderFloat secondShaderFloat(firstShaderFloat);
    ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), 0);

    firstShaderFloat.SetNumRegisters(firstNumRegisters);
    ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), firstNumRegisters);
    ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), 0);

    ShaderFloat thirdShaderFloat(secondNumRegisters);
    ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), secondNumRegisters);

    thirdShaderFloat = secondShaderFloat;
    ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), 0);

    secondShaderFloat = firstShaderFloat;
    ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), 0);
    ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), firstNumRegisters);
}

void Rendering::ShaderFloatTesting::StreamTest() noexcept
{
}