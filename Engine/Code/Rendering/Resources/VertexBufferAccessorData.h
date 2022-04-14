///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 18:36)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/VertexFormatFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    template <VertexFormatFlags::AttributeUsage usage>
    class VertexBufferAccessorData
    {
    public:
        using ClassType = VertexBufferAccessorData<usage>;
        using AttributeType = VertexFormatFlags::AttributeType;

    public:
        VertexBufferAccessorData() noexcept;
        VertexBufferAccessorData(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer);

        CLASS_INVARIANT_DECLARE;

        void Init(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer, int number = 0);

        NODISCARD const char* GetData(int stride, int index) const noexcept;
        NODISCARD bool HasData() const noexcept;
        NODISCARD int GetDataChannels() const noexcept;
        NODISCARD const float* GetDataTuple(int stride, int index) const noexcept;

    private:
        const char* data;
        int dataChannels;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_H
