///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 17:08)

#include "OpenGLGlutCallBackInterfaceTesting.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"

Framework::OpenGLGlutCallBackInterfaceTesting::OpenGLGlutCallBackInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutCallBackInterfaceTesting)

void Framework::OpenGLGlutCallBackInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutCallBackInterfaceTesting::MainTest() noexcept
{
}
