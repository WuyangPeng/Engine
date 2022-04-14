// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:13)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_H

#include "Rendering/RenderingDll.h"

#include "OpenGLVertexFormatData.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"

#include <array>

namespace Rendering
{
    class VertexFormat;

    template <VertexFormatFlags::AttributeUsage usage, VertexFormatFlags::MaximumNumber number>
    class OpenGLVertexFormatArrayData
    {
    public:
        using ClassType = OpenGLVertexFormatArrayData<usage, number>;
        using UInt = System::OpenGLUInt;

    public:
        OpenGLVertexFormatArrayData();

        CLASS_INVARIANT_DECLARE;

        void Init(const VertexFormat* vertexFormat);

        bool IsHas(int index) const;
        UInt GetChannels(int index) const;
        UInt GetType(int index) const;
        UInt GetOffset(int index) const;

        void Enable(int stride) noexcept;
        void Disable() noexcept;

    private:
        std::array<OpenGLVertexFormatData<usage>, System::EnumCastUnderlying(number)> m_Data;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_H
