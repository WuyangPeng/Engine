///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:18)

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
