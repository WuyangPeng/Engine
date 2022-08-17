///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/18 16:36)

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
 