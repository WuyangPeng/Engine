///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/23 14:50)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_H

#include "Rendering/RenderingDll.h"

#include "OpenGLVertexFormatData.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <array>

namespace Rendering
{
    template <VertexFormatFlags::AttributeUsage usage, VertexFormatFlags::MaximumNumber number>
    class OpenGLVertexFormatArrayData
    {
    public:
        using ClassType = OpenGLVertexFormatArrayData<usage, number>;
        using UInt = System::OpenGLUInt;

    public:
        OpenGLVertexFormatArrayData() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Init(const VertexFormat* vertexFormat);

        NODISCARD bool IsHas(int index) const;
        NODISCARD UInt GetChannels(int index) const;
        NODISCARD UInt GetType(int index) const;
        NODISCARD UInt GetOffset(int index) const;

        void Enable(int stride) noexcept;
        void Disable() noexcept;

    private:
        std::array<OpenGLVertexFormatData<usage>, System::EnumCastUnderlying(number)> data;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_H
