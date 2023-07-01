///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 16:09)

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
    : ParentType{ delta, "����Ⱦ�⡿Window��Ԫ�����׼�"s }
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
    auto rendererEngineSuite = GenerateSuite("��Ⱦ����"s);

    ADD_TEST_USE_PARAMETER_1(rendererEngineSuite, RenderingEnvironmentTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(rendererEngineSuite, RenderingDeviceTesting, hWnd);

    AddSuite(rendererEngineSuite);
}
