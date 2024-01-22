///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.4 (2024/01/15 11:03)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_HANDLE_H
#define RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_HANDLE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Contract/ContractFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GLSLProgramHandle
    {
    public:
        using ClassType = GLSLProgramHandle;

        using OpenGLUInt = System::OpenGLUInt;

    public:
        NODISCARD static GLSLProgramHandle Create();
        explicit GLSLProgramHandle(CoreTools::DisableNotThrow disableNotThrow);
        ~GLSLProgramHandle() noexcept;
        GLSLProgramHandle(const GLSLProgramHandle& rhs) = default;
        GLSLProgramHandle& operator=(const GLSLProgramHandle& rhs) = default;
        GLSLProgramHandle(GLSLProgramHandle&& rhs) noexcept = default;
        GLSLProgramHandle& operator=(GLSLProgramHandle&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLUInt GetProgramHandle() const noexcept;

        void Link() const;

    private:
        OpenGLUInt programHandle;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_HANDLE_H
