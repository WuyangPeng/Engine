// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 14:11)

#ifndef RENDERING_RENDERERS_OPENGL_ES_RENDERER_INPUT_H
#define RENDERING_RENDERERS_OPENGL_ES_RENDERER_INPUT_H

#include "Rendering/RenderingDll.h"

#include "RendererInputImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLESRendererInput : public RendererInputImpl
    {
    public:
        using ClassType = OpenGLESRendererInput;
        using ParentType = RendererInputImpl;
       
    public:
        OpenGLESRendererInput();
        virtual ~OpenGLESRendererInput();
        
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        virtual RendererTypes GetRendererType() const override;  
		virtual	void SetWindowID(int windowID) override;
		virtual	void SetWindowHandle(HWnd windowID) override;

    private:
    	HWnd m_WindowHandle;
 
    };
}

#endif // RENDERING_RENDERERS_OPENGL_ES_RENDERER_INPUT_H
