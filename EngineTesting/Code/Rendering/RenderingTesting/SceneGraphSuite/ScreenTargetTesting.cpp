///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 11:48)

#include "ScreenTargetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Rendering/Renderers/RendererManager.h" 
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/ScreenTarget.h"
#include "Rendering/Shaders/ShaderManager.h"

#include <vector>

using std::swap;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ScreenTargetTesting)

void Rendering::ScreenTargetTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();
    RendererManager::Create();
    ShaderManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CameraTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrianglesMeshTest);

    ShaderManager::Destroy();
    RendererManager::Destroy();
    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::ScreenTargetTesting::CameraTest() noexcept
{
}

void Rendering::ScreenTargetTesting::TrianglesMeshTest() noexcept
{
}
