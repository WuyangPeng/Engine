///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 13:49)

#include "OpenGLGlutProcessTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"

Framework::OpenGLGlutProcessTesting::OpenGLGlutProcessTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutProcessTesting)

void Framework::OpenGLGlutProcessTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutProcessTesting::MainTest() noexcept
{
}
