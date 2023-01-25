///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 19:35)

#include "OpenGLDepthTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLDepthTesting::OpenGLDepthTesting(const OStreamShared& stream)
    : ParentType{ stream },
      depthStencilStateModes{ DepthStencilStateMode::Never,
                              DepthStencilStateMode::Less,
                              DepthStencilStateMode::Equal,
                              DepthStencilStateMode::LessEqual,
                              DepthStencilStateMode::Greater,
                              DepthStencilStateMode::NotEqual,
                              DepthStencilStateMode::GreaterEqual,
                              DepthStencilStateMode::Always },
      depthStencilStateWriteMasks{ DepthStencilStateWriteMask::False,
                                   DepthStencilStateWriteMask::True }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLDepthTesting)

void System::OpenGLDepthTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLDepthTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLDepthFuncTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLDepthMaskTest);
}

void System::OpenGLDepthTesting::SetGLDepthFuncTest() noexcept
{
    for (auto depthStencilStateMode : depthStencilStateModes)
    {
        SetGLDepthFunc(depthStencilStateMode);
    }
}

void System::OpenGLDepthTesting::SetGLDepthMaskTest() noexcept
{
    for (auto depthStencilStateWriteMask : depthStencilStateWriteMasks)
    {
        SetGLDepthMask(depthStencilStateWriteMask);
    }
}
