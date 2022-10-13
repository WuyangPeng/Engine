///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/07 19:35)

#include "EnvironmentParameterTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Renderers/EnvironmentParameter.h"

Rendering::EnvironmentParameterTesting::EnvironmentParameterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, EnvironmentParameterTesting)

void Rendering::EnvironmentParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::EnvironmentParameterTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(HWndExceptionTest);
}

void Rendering::EnvironmentParameterTesting::HWndExceptionTest()
{
    auto environmentParameter = EnvironmentParameter::Create();

    auto windowsHWnd = environmentParameter.GetWindowsHWnd();

    windowsHWnd = environmentParameter.GetWindowsHWnd();
}