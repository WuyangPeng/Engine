///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:47)

#include "RenderingEnvironmentTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Rendering/Renderers/RendererParameter.h"
#include "Rendering/Renderers/RenderingEnvironment.h"

Rendering::RenderingEnvironmentTesting::RenderingEnvironmentTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RenderingEnvironmentTesting)

void Rendering::RenderingEnvironmentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::RenderingEnvironmentTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullRenderingEnvironmentTest);
}

void Rendering::RenderingEnvironmentTesting::NullRenderingEnvironmentTest()
{
    auto hWnd = System::GetActiveWindow();

    auto environmentParameter = EnvironmentParameter::Create(hWnd);
    RendererParameter rendererParameter("Configuration/NullRenderer.json");

    RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
}
