///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/24 11:08)

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
