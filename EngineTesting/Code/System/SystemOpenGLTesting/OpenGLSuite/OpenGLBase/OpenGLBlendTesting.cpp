///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 19:34)

#include "OpenGLBlendTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLBlendTesting::OpenGLBlendTesting(const OStreamShared& stream)
    : ParentType{ stream },
      sourceFactorRGBs{ BlendStateMode::Zero,
                        BlendStateMode::One,
                        BlendStateMode::SourceColor,
                        BlendStateMode::OneMinusSourceColor,
                        BlendStateMode::SourceAlpha,
                        BlendStateMode::OneMinusSourceAlpha,
                        BlendStateMode::DestinationAlpha,
                        BlendStateMode::OneMinusDestinationAlpha,
                        BlendStateMode::DestinationColor,
                        BlendStateMode::OneMinusDestinationColor,
                        BlendStateMode::SourceAlphaSaturate,
                        BlendStateMode::ConstantColor,
                        BlendStateMode::OneMinusConstantColor,
                        BlendStateMode::Source1Color,
                        BlendStateMode::OneMinusSource1Color,
                        BlendStateMode::Source1Alpha,
                        BlendStateMode::OneMinusSource1Alpha },
      destinationFactorRGBs{ BlendStateMode::Zero,
                             BlendStateMode::One,
                             BlendStateMode::SourceColor,
                             BlendStateMode::OneMinusSourceColor,
                             BlendStateMode::SourceAlpha,
                             BlendStateMode::OneMinusSourceAlpha,
                             BlendStateMode::DestinationAlpha,
                             BlendStateMode::OneMinusDestinationAlpha,
                             BlendStateMode::DestinationColor,
                             BlendStateMode::OneMinusDestinationColor,
                             BlendStateMode::SourceAlphaSaturate,
                             BlendStateMode::ConstantColor,
                             BlendStateMode::OneMinusConstantColor,
                             BlendStateMode::Source1Color,
                             BlendStateMode::OneMinusSource1Color,
                             BlendStateMode::Source1Alpha,
                             BlendStateMode::OneMinusSource1Alpha },
      sourceFactorAlphas{ BlendStateMode::Zero,
                          BlendStateMode::One,
                          BlendStateMode::SourceColor,
                          BlendStateMode::OneMinusSourceColor,
                          BlendStateMode::SourceAlpha,
                          BlendStateMode::OneMinusSourceAlpha,
                          BlendStateMode::DestinationAlpha,
                          BlendStateMode::OneMinusDestinationAlpha,
                          BlendStateMode::DestinationColor,
                          BlendStateMode::OneMinusDestinationColor,
                          BlendStateMode::SourceAlphaSaturate,
                          BlendStateMode::ConstantColor,
                          BlendStateMode::OneMinusConstantColor,
                          BlendStateMode::Source1Color,
                          BlendStateMode::OneMinusSource1Color,
                          BlendStateMode::Source1Alpha,
                          BlendStateMode::OneMinusSource1Alpha },
      destinationFactorAlphas{ BlendStateMode::Zero,
                               BlendStateMode::One,
                               BlendStateMode::SourceColor,
                               BlendStateMode::OneMinusSourceColor,
                               BlendStateMode::SourceAlpha,
                               BlendStateMode::OneMinusSourceAlpha,
                               BlendStateMode::DestinationAlpha,
                               BlendStateMode::OneMinusDestinationAlpha,
                               BlendStateMode::DestinationColor,
                               BlendStateMode::OneMinusDestinationColor,
                               BlendStateMode::SourceAlphaSaturate,
                               BlendStateMode::ConstantColor,
                               BlendStateMode::OneMinusConstantColor,
                               BlendStateMode::Source1Color,
                               BlendStateMode::OneMinusSource1Color,
                               BlendStateMode::Source1Alpha,
                               BlendStateMode::OneMinusSource1Alpha },
      modeRGBs{ BlendStateOperation::FuncAdd,
                BlendStateOperation::FuncSubtract,
                BlendStateOperation::FuncReverseSubtract,
                BlendStateOperation::Min,
                BlendStateOperation::Max },
      modeAlphas{ BlendStateOperation::FuncAdd,
                  BlendStateOperation::FuncSubtract,
                  BlendStateOperation::FuncReverseSubtract,
                  BlendStateOperation::Min,
                  BlendStateOperation::Max },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement<size_t>({ sourceFactorRGBs.size(),
                                               destinationFactorRGBs.size(),
                                               sourceFactorAlphas.size(),
                                               destinationFactorAlphas.size(),
                                               modeRGBs.size(),
                                               modeAlphas.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLBlendTesting)

void System::OpenGLBlendTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLBlendTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLBlendColorTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

void System::OpenGLBlendTesting::SetGLBlendColorTest() noexcept
{
    SetGLBlendColor(1.0f, 1.0f, 1.0f, 0.0f);
}

bool System::OpenGLBlendTesting::RandomShuffleFlags()
{
    shuffle(sourceFactorRGBs.begin(), sourceFactorRGBs.end(), randomEngine);
    shuffle(destinationFactorRGBs.begin(), destinationFactorRGBs.end(), randomEngine);
    shuffle(sourceFactorAlphas.begin(), sourceFactorAlphas.end(), randomEngine);
    shuffle(destinationFactorAlphas.begin(), destinationFactorAlphas.end(), randomEngine);

    shuffle(modeRGBs.begin(), modeRGBs.end(), randomEngine);
    shuffle(modeAlphas.begin(), modeAlphas.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(SetGLBlendFuncSeparateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLBlendEquationSeparateTest);

    return true;
}

void System::OpenGLBlendTesting::SetGLBlendFuncSeparateTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        const auto sourceFactorRGB = sourceFactorRGBs.at(index % sourceFactorRGBs.size());
        const auto destinationFactorRGB = destinationFactorRGBs.at(index % destinationFactorRGBs.size());
        const auto sourceFactorAlpha = sourceFactorAlphas.at(index % sourceFactorAlphas.size());
        const auto destinationFactorAlpha = destinationFactorAlphas.at(index % destinationFactorAlphas.size());

        SetGLBlendFuncSeparate(sourceFactorRGB, destinationFactorRGB, sourceFactorAlpha, destinationFactorAlpha);
        SetGLBlendFuncSeparate(0, sourceFactorRGB, destinationFactorRGB, sourceFactorAlpha, destinationFactorAlpha);
    }
}

void System::OpenGLBlendTesting::SetGLBlendEquationSeparateTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        const auto modeRGB = modeRGBs.at(index % modeRGBs.size());
        const auto modeAlpha = modeAlphas.at(index % modeAlphas.size());

        SetGLBlendEquationSeparate(modeRGB, modeAlpha);
        SetGLBlendEquationSeparate(0, modeRGB, modeAlpha);
    }
}
