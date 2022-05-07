///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 15:47)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    template <VertexFormatFlags::AttributeUsage usage>
    class OpenGLVertexFormatData
    {
    public:
        using ClassType = OpenGLVertexFormatData<usage>;
        using UInt = System::OpenGLUInt;
        using DataType = System::OpenGLData;

    public:
        OpenGLVertexFormatData() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Init(const VertexFormat* vertexFormat);

        void Set(UInt has, UInt channels, DataType type, UInt offset) noexcept;

        NODISCARD bool IsHas() const noexcept;
        NODISCARD UInt GetChannels() const noexcept;
        NODISCARD DataType GetType() const noexcept;
        NODISCARD UInt GetOffset() const noexcept;

        void Enable(int stride) noexcept;
        void Disable() noexcept;

    private:
        UInt openGLHas;
        UInt openGLChannels;
        DataType openGLType;
        UInt openGLOffset;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_H
