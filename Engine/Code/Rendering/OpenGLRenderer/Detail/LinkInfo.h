///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.3 (2024/01/09 09:17)

#ifndef RENDERING_OPENGL_RENDERER_LINK_INFO_H
#define RENDERING_OPENGL_RENDERER_LINK_INFO_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE LinkInfo
    {
    public:
        using ClassType = LinkInfo;

        using OpenGLInt = System::OpenGLInt;
        using OpenGLUInt = System::OpenGLUInt;

    public:
        LinkInfo() noexcept;
        LinkInfo(int linkCount, OpenGLUInt program, OpenGLInt index) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetLinkCount() const noexcept;
        NODISCARD OpenGLUInt GetProgram() const noexcept;
        NODISCARD OpenGLInt GetIndex() const noexcept;

        void SetLinkCount(int aLinkCount) noexcept;
        void SetProgram(OpenGLUInt aProgram) noexcept;
        void SetIndex(OpenGLInt aIndex) noexcept;
        void AddLinkCount() noexcept;
        void ReduceLinkCount() noexcept;

    private:
        int linkCount;
        OpenGLUInt program;
        OpenGLInt index;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_LINK_INFO_H
