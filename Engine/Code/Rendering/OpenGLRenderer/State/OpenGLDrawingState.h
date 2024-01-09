/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 11:36)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DRAWING_STATE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DRAWING_STATE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/OpenGLRenderer/OpenGLRendererObject.h"
#include "Rendering/State/DrawingState.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLDrawingState : public OpenGLRendererObject
    {
    public:
        using ClassType = OpenGLDrawingState;
        using ParentType = OpenGLRendererObject;

    public:
        OpenGLDrawingState(const DrawingStateSharedPtr& drawingState, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DRAWING_STATE_H
