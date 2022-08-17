///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/18 16:36)

#include "OpenGLVertexFormatDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/OpenGLVertexFormatDataDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, OpenGLVertexFormatDataTesting)

void Rendering::OpenGLVertexFormatDataTesting::MainTest()
{
    RendererManager::Create();

    RendererManager::Destroy();
}
 