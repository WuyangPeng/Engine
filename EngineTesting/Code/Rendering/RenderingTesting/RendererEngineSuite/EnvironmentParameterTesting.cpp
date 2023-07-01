///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:05)

#include "EnvironmentParameterTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"

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

    // RenderingOpenGLTesting有WglEnvironmentParameter的测试。
}

void Rendering::EnvironmentParameterTesting::HWndExceptionTest()
{
    const auto environmentParameter = EnvironmentParameter::Create();

    MAYBE_UNUSED const auto* const windowsHWnd = environmentParameter.GetWindowsHWnd();
}