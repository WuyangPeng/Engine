///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:21)

#include "OpenGLMaskTesting.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLMaskTesting::OpenGLMaskTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLMaskTesting)

void System::OpenGLMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLColorMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLSampleMaskTest);
}

void System::OpenGLMaskTesting::SetGLColorMaskTest() noexcept
{
    SetGLColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    SetGLColorMask(0, GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
}

void System::OpenGLMaskTesting::SetGLSampleMaskTest() noexcept
{
    SetGLSampleMask(0, 0);
}
