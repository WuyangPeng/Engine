///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_TARGET_H
#define RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_TARGET_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLBlendStateTarget
    {
    public:
        using ClassType = OpenGLBlendStateTarget;
        using OpenGLBoolean = System::OpenGLBoolean;
        using BlendStateMode = System::BlendStateMode;
        using BlendStateOperation = System::BlendStateOperation;

    public:
        OpenGLBlendStateTarget() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLBoolean IsEnable() const noexcept;
        void SetEnable(OpenGLBoolean aEnable) noexcept;

        NODISCARD BlendStateMode GetSourceColor() const noexcept;
        void SetSourceColor(BlendStateMode color) noexcept;

        NODISCARD BlendStateMode GetDestinationColor() const noexcept;
        void SetDestinationColor(BlendStateMode color) noexcept;

        NODISCARD BlendStateOperation GetOperationColor() const noexcept;
        void SetOperationColor(BlendStateOperation color) noexcept;

        NODISCARD BlendStateMode GetSourceAlpha() const noexcept;
        void SetSourceAlpha(BlendStateMode alpha) noexcept;

        NODISCARD BlendStateMode GetDestinationAlpha() const noexcept;
        void SetDestinationAlpha(BlendStateMode alpha) noexcept;

        NODISCARD BlendStateOperation GetOperationAlpha() const noexcept;
        void SetOperationAlpha(BlendStateOperation alpha) noexcept;

        NODISCARD OpenGLBoolean IsRedMask() const noexcept;
        void SetRedMask(OpenGLBoolean mask) noexcept;

        NODISCARD OpenGLBoolean IsGreenMask() const noexcept;
        void SetGreenMask(OpenGLBoolean mask) noexcept;

        NODISCARD OpenGLBoolean IsBlueMask() const noexcept;
        void SetBlueMask(OpenGLBoolean mask) noexcept;

        NODISCARD OpenGLBoolean IsAlphaMask() const noexcept;
        void SetAlphaMask(OpenGLBoolean mask) noexcept;

    private:
        OpenGLBoolean enable;
        BlendStateMode sourceColor;
        BlendStateMode destinationColor;
        BlendStateOperation operationColor;
        BlendStateMode sourceAlpha;
        BlendStateMode destinationAlpha;
        BlendStateOperation operationAlpha;
        OpenGLBoolean redMask;
        OpenGLBoolean greenMask;
        OpenGLBoolean blueMask;
        OpenGLBoolean alphaMask;
    };

}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_TARGET_H
