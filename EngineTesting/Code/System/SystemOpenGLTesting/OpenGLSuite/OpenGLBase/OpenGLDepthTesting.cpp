/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/14 23:48)

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

void System::OpenGLDepthTesting::SetGLDepthFuncTest() const noexcept
{
    for (const auto depthStencilStateMode : depthStencilStateModes)
    {
        SetGLDepthFunc(depthStencilStateMode);
    }
}

void System::OpenGLDepthTesting::SetGLDepthMaskTest() const noexcept
{
    for (const auto depthStencilStateWriteMask : depthStencilStateWriteMasks)
    {
        SetGLDepthMask(depthStencilStateWriteMask);
    }
}
