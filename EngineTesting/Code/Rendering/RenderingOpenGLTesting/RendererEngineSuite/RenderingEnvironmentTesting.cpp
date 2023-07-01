///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:51)

#include "RenderingEnvironmentTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Rendering/RendererEngine/RendererParameter.h"
#include "Rendering/RendererEngine/RenderingEnvironment.h"

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
    const auto hWnd = System::GetActiveWindow();

    const auto environmentParameter = EnvironmentParameter::Create(hWnd);
    const RendererParameter rendererParameter("Configuration/NullRenderer.json");

    const RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
}
