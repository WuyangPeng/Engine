///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 16:20)

#include "WindowsAPIFrameBuildTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

Framework::WindowsAPIFrameBuildTesting::WindowsAPIFrameBuildTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowsAPIFrameBuildTesting)

void Framework::WindowsAPIFrameBuildTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void Framework::WindowsAPIFrameBuildTesting::MainTest()
{
    CoreTools::DisableNoexcept();
}
