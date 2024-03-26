///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.3 (2024/01/09 09:29)

#ifndef RENDERING_OPENGL_RENDERER_PROGRAM_INDEX_UNIT_CONTAINER_H
#define RENDERING_OPENGL_RENDERER_PROGRAM_INDEX_UNIT_CONTAINER_H

#include "Rendering/RenderingDll.h"

#include "LinkInfo.h"
#include "System/OpenGL/Using/OpenGLUsing.h"

#include <vector>

namespace Rendering
{
    /// 跟踪可用的纹理采样器/图像单元和均匀/阴影存储缓冲单元。
    /// 如果单元正在使用，则链接计数为正，绑定到该单元的程序+索引将被存储。
    class RENDERING_HIDDEN_DECLARE ProgramIndexUnitContainer
    {
    public:
        using ClassType = ProgramIndexUnitContainer;

        using OpenGLInt = System::OpenGLInt;
        using OpenGLUInt = System::OpenGLUnsignedInt;

    public:
        ProgramIndexUnitContainer() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int AcquireUnit(OpenGLUInt program, OpenGLInt index);
        NODISCARD int GetUnit(OpenGLUInt program, OpenGLInt index) const noexcept;
        void ReleaseUnit(int index);
        NODISCARD int GetUnitLinkCount(int unit) const;
        NODISCARD LinkInfo GetUnitProgramIndex(int unit) const;

    private:
        using LinkInfoContainer = std::vector<LinkInfo>;

    private:
        LinkInfoContainer linkContainer;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_PROGRAM_INDEX_UNIT_CONTAINER_H
