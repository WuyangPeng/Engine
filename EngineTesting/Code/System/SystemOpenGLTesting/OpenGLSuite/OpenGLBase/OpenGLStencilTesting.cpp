///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 19:45)

#include "OpenGLStencilTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLStencilTesting::OpenGLStencilTesting(const OStreamShared& stream)
    : ParentType{ stream },
      rasterizerStateCullFaces{ RasterizerStateCullFace::Front,
                                RasterizerStateCullFace::Back,
                                RasterizerStateCullFace::FrontAndBack },
      depthStencilStateModes{ DepthStencilStateMode::Never,
                              DepthStencilStateMode::Less,
                              DepthStencilStateMode::Equal,
                              DepthStencilStateMode::LessEqual,
                              DepthStencilStateMode::Greater,
                              DepthStencilStateMode::NotEqual,
                              DepthStencilStateMode::GreaterEqual,
                              DepthStencilStateMode::Always },
      stencilFails{ DepthStencilStateOperation::Keep,
                    DepthStencilStateOperation::Zero,
                    DepthStencilStateOperation::Replace,
                    DepthStencilStateOperation::Increment,
                    DepthStencilStateOperation::Decrement,
                    DepthStencilStateOperation::Invert },
      depthFails{ DepthStencilStateOperation::Keep,
                  DepthStencilStateOperation::Zero,
                  DepthStencilStateOperation::Replace,
                  DepthStencilStateOperation::Increment,
                  DepthStencilStateOperation::Decrement,
                  DepthStencilStateOperation::Invert },
      depthPasses{ DepthStencilStateOperation::Keep,
                   DepthStencilStateOperation::Zero,
                   DepthStencilStateOperation::Replace,
                   DepthStencilStateOperation::Increment,
                   DepthStencilStateOperation::Decrement,
                   DepthStencilStateOperation::Invert }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLStencilTesting)

void System::OpenGLStencilTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLStencilTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLStencilFuncSeparateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLStencilMaskSeparateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLStencilOpSeparateTest);
}

void System::OpenGLStencilTesting::SetGLStencilFuncSeparateTest() noexcept
{
    for (auto rasterizerStateCullFace : rasterizerStateCullFaces)
    {
        for (auto depthStencilStateMode : depthStencilStateModes)
        {
            SetGLStencilFuncSeparate(rasterizerStateCullFace, depthStencilStateMode, 0, 0);
        }
    }
}

void System::OpenGLStencilTesting::SetGLStencilMaskSeparateTest() noexcept
{
    for (auto rasterizerStateCullFace : rasterizerStateCullFaces)
    {
        SetGLStencilMaskSeparate(rasterizerStateCullFace, 0);
    }
}

void System::OpenGLStencilTesting::SetGLStencilOpSeparateTest() noexcept
{
    for (auto rasterizerStateCullFace : rasterizerStateCullFaces)
    {
        for (auto stencilFail : stencilFails)
        {
            for (auto depthFail : depthFails)
            {
                for (auto depthPass : depthPasses)
                {
                    SetGLStencilOpSeparate(rasterizerStateCullFace, stencilFail, depthFail, depthPass);
                }
            }
        }
    }
}
