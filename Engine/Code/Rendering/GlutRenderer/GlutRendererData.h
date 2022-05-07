///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/24 11:08)

#ifndef RENDERING_GLUT_RENDERER_DATA_H
#define RENDERING_GLUT_RENDERER_DATA_H

#include "Rendering/RenderingDll.h"

#include "Rendering/OpenGLRenderer/OpenGLRendererData.h"

namespace Rendering
{
    class GlutRendererData : public RendererData
    {
    public:
        int windowID;
    };

}

#endif  // RENDERING_GLUT_RENDERER_DATA_H
