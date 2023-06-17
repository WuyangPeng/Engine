///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:33)

#ifndef RENDERING_RENDERERS_GLUT_RENDERER_INPUT_H
#define RENDERING_RENDERERS_GLUT_RENDERER_INPUT_H

#include "Rendering/RenderingDll.h"

#include "RendererInputImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GlutRendererInput : public RendererInputImpl
    {
    public:
        using ClassType = GlutRendererInput;
        using ParentType = RendererInputImpl;

    public:
        GlutRendererInput() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RendererTypes GetRendererType() const noexcept override;
        void SetWindowID(int aWindowID) noexcept override;
        void SetWindowHandle(HWnd aWindowID) noexcept override;

    private:
        int windowID;
        bool disableVerticalSync;
    };
}

#endif  // RENDERING_RENDERERS_GLUT_RENDERER_INPUT_H
