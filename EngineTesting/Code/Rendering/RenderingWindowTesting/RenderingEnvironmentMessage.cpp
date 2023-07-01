///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:09)

#include "RenderingEnvironmentMessage.h"
#include "Testing.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

using namespace std::literals;

RenderingWindowTesting::RenderingEnvironmentMessage::RenderingEnvironmentMessage(int64_t delta, MAYBE_UNUSED const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, "【渲染库】Window单元测试套件"s }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RenderingWindowTesting, RenderingEnvironmentMessage)

void RenderingWindowTesting::RenderingEnvironmentMessage::InitSuite()
{
    AddRendererEngineSuite();
}

void RenderingWindowTesting::RenderingEnvironmentMessage::AddRendererEngineSuite()
{
    const auto hWnd = GetHwnd();
    auto rendererEngineSuite = GenerateSuite("渲染引擎"s);

    ADD_TEST_USE_PARAMETER_1(rendererEngineSuite, RenderingEnvironmentTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(rendererEngineSuite, RenderingDeviceTesting, hWnd);

    AddSuite(rendererEngineSuite);
}
