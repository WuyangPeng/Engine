///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/02 22:07)

#include "BlendStateTargetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/State/BlendStateTarget.h"
#include "Rendering/State/Flags/BlendStateColorWrite.h"
#include "Rendering/State/Flags/BlendStateMode.h"
#include "Rendering/State/Flags/BlendStateOperation.h"

namespace Rendering
{
    ENUM_INCREMENTABLE_OPERATOR_DEFINE(BlendStateMode)
    ENUM_INCREMENTABLE_OPERATOR_DEFINE(BlendStateOperation)
    ENUM_INCREMENTABLE_OPERATOR_DEFINE(BlendStateColorWrite)
}

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
    auto streamingSize = CORE_TOOLS_STREAM_SIZE(enable);

    streamingSize += CORE_TOOLS_STREAM_SIZE(sourceColor);
    streamingSize += CORE_TOOLS_STREAM_SIZE(destinationColor);
    streamingSize += CORE_TOOLS_STREAM_SIZE(operationColor);

    streamingSize += CORE_TOOLS_STREAM_SIZE(sourceAlpha);
    streamingSize += CORE_TOOLS_STREAM_SIZE(destinationAlpha);
    streamingSize += CORE_TOOLS_STREAM_SIZE(operationAlpha);

    streamingSize += CORE_TOOLS_STREAM_SIZE(mask);

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
