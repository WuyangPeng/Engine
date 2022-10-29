///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/15 23:41)

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
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DRAWING_STATE_H
