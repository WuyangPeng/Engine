///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DRAWING_STATE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DRAWING_STATE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/State/DrawingState.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLDrawingState : public RendererObject
    {
    public:
        using ClassType = OpenGLDrawingState;
        using ParentType = RendererObject;

    public:
        OpenGLDrawingState(const DrawingStateSharedPtr& drawingState, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool Update() noexcept override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DRAWING_STATE_H
