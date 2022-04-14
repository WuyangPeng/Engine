///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 18:31)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_H

#include "Rendering/RenderingDll.h"

#include "ResourcesFwd.h"
#include "VertexBufferAccessorData.h"

namespace Rendering
{
    template <VertexFormatFlags::AttributeUsage usage, VertexFormatFlags::MaximumNumber number>
    class VertexBufferAccessorArrayData
    {
    public:
        using ClassType = VertexBufferAccessorArrayData<usage, number>;

    public:
        VertexBufferAccessorArrayData();
        VertexBufferAccessorArrayData(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer);

        CLASS_INVARIANT_DECLARE;

        void Init(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer);

        NODISCARD const char* GetData(int stride, int unit, int index) const;
        NODISCARD bool HasData(int unit) const;
        NODISCARD int GetDataChannels(int unit) const;
        NODISCARD const float* GetDataTuple(int stride, int unit, int index) const;

    private:
        std::array<VertexBufferAccessorData<usage>, System::EnumCastUnderlying(number)> data;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_H
