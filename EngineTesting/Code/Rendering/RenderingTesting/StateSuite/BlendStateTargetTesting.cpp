///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:02)

#include "BlendStateTargetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/State/BlendStateTarget.h"
#include "Rendering/State/Flags/BlendStateColorWrite.h"
#include "Rendering/State/Flags/BlendStateMode.h"
#include "Rendering/State/Flags/BlendStateOperation.h"

using System::operator++;

Rendering::BlendStateTargetTesting::BlendStateTargetTesting(const OStreamShared& stream)
    : ParentType{ stream },
      enable{ false },
      sourceColor{ BlendStateMode::One },
      destinationColor{ BlendStateMode::Zero },
      operationColor{ BlendStateOperation::Add },
      sourceAlpha{ BlendStateMode::One },
      destinationAlpha{ BlendStateMode::Zero },
      operationAlpha{ BlendStateOperation::Add },
      mask{ BlendStateColorWrite::EnableAll },
      blendStateTarget{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BlendStateTargetTesting)

void Rendering::BlendStateTargetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::BlendStateTargetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);

    ASSERT_NOT_THROW_EXCEPTION_0(SetEnableTest);

    ASSERT_NOT_THROW_EXCEPTION_0(SetSourceColorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetDestinationColorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetOperationColorTest);

    ASSERT_NOT_THROW_EXCEPTION_0(SetSourceAlphaTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetDestinationAlphaTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetOperationAlphaTest);

    ASSERT_NOT_THROW_EXCEPTION_0(SetMaskTest);

    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);

    ASSERT_NOT_THROW_EXCEPTION_0(EqualTest);
}

void Rendering::BlendStateTargetTesting::ConstructorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);
}

void Rendering::BlendStateTargetTesting::BlendStateTargetTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetSaveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetValueTest);
}

void Rendering::BlendStateTargetTesting::BlendStateTargetValueTest()
{
    ASSERT_EQUAL(blendStateTarget.IsEnable(), enable);

    ASSERT_ENUM_EQUAL(blendStateTarget.GetSourceColor(), sourceColor);
    ASSERT_ENUM_EQUAL(blendStateTarget.GetDestinationColor(), destinationColor);
    ASSERT_ENUM_EQUAL(blendStateTarget.GetOperationColor(), operationColor);

    ASSERT_ENUM_EQUAL(blendStateTarget.GetSourceAlpha(), sourceAlpha);
    ASSERT_ENUM_EQUAL(blendStateTarget.GetDestinationAlpha(), destinationAlpha);
    ASSERT_ENUM_EQUAL(blendStateTarget.GetOperationAlpha(), operationAlpha);

    ASSERT_ENUM_EQUAL(blendStateTarget.GetMask(), mask);
}

void Rendering::BlendStateTargetTesting::BlendStateTargetSaveTest()
{
    constexpr auto bufferSize = 1024;

    auto objectRegister = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget{ bufferSize, objectRegister };

    blendStateTarget.Save(bufferTarget);

    CoreTools::BufferSource bufferSource{ bufferTarget.GetFileBuffer() };
    blendStateTarget = BlendStateTarget{};
    blendStateTarget.Load(bufferSource);
}

void Rendering::BlendStateTargetTesting::SetEnableTest()
{
    blendStateTarget.SetEnable(true);
    enable = true;
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);

    blendStateTarget.SetEnable(false);
    enable = false;
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);
}

void Rendering::BlendStateTargetTesting::SetSourceColorTest()
{
    for (auto mode = BlendStateMode::Zero; mode <= BlendStateMode::OneMinusSource1Alpha; ++mode)
    {
        blendStateTarget.SetSourceColor(mode);
        sourceColor = mode;
        ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);
    }
}

void Rendering::BlendStateTargetTesting::SetDestinationColorTest()
{
    for (auto mode = BlendStateMode::Zero; mode <= BlendStateMode::OneMinusSource1Alpha; ++mode)
    {
        blendStateTarget.SetDestinationColor(mode);
        destinationColor = mode;
        ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);
    }
}

void Rendering::BlendStateTargetTesting::SetOperationColorTest()
{
    for (auto operation = BlendStateOperation::Add; operation <= BlendStateOperation::Max; ++operation)
    {
        blendStateTarget.SetOperationColor(operation);
        operationColor = operation;
        ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);
    }
}

void Rendering::BlendStateTargetTesting::SetSourceAlphaTest()
{
    for (auto mode = BlendStateMode::Zero; mode <= BlendStateMode::OneMinusSource1Alpha; ++mode)
    {
        blendStateTarget.SetSourceAlpha(mode);
        sourceAlpha = mode;
        ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);
    }
}

void Rendering::BlendStateTargetTesting::SetDestinationAlphaTest()
{
    for (auto mode = BlendStateMode::Zero; mode <= BlendStateMode::OneMinusSource1Alpha; ++mode)
    {
        blendStateTarget.SetDestinationAlpha(mode);
        destinationAlpha = mode;
        ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);
    }
}

void Rendering::BlendStateTargetTesting::SetOperationAlphaTest()
{
    for (auto operation = BlendStateOperation::Add; operation <= BlendStateOperation::Max; ++operation)
    {
        blendStateTarget.SetOperationAlpha(operation);
        operationAlpha = operation;
        ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);
    }
}

void Rendering::BlendStateTargetTesting::SetMaskTest()
{
    for (auto stateColorWrite = BlendStateColorWrite::Disenable; stateColorWrite <= BlendStateColorWrite::EnableAll; ++stateColorWrite)
    {
        blendStateTarget.SetMask(stateColorWrite);
        mask = stateColorWrite;
        ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTargetTest);
    }
}

void Rendering::BlendStateTargetTesting::GetStreamingSizeTest()
{
    auto streamingSize = CoreTools::GetStreamSize(enable);

    streamingSize += CoreTools::GetStreamSize(sourceColor);
    streamingSize += CoreTools::GetStreamSize(destinationColor);
    streamingSize += CoreTools::GetStreamSize(operationColor);

    streamingSize += CoreTools::GetStreamSize(sourceAlpha);
    streamingSize += CoreTools::GetStreamSize(destinationAlpha);
    streamingSize += CoreTools::GetStreamSize(operationAlpha);

    streamingSize += CoreTools::GetStreamSize(mask);

    ASSERT_EQUAL(blendStateTarget.GetStreamingSize(), streamingSize);
}

void Rendering::BlendStateTargetTesting::EqualTest()
{
    BlendStateTarget testBlendStateTarget{};

    testBlendStateTarget.SetEnable(enable);
    testBlendStateTarget.SetSourceColor(sourceColor);
    testBlendStateTarget.SetDestinationColor(destinationColor);
    testBlendStateTarget.SetOperationColor(operationColor);

    testBlendStateTarget.SetSourceAlpha(sourceAlpha);
    testBlendStateTarget.SetDestinationAlpha(destinationAlpha);
    testBlendStateTarget.SetOperationAlpha(operationAlpha);

    testBlendStateTarget.SetMask(mask);

    ASSERT_EQUAL(testBlendStateTarget, blendStateTarget);
}
