///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/11 13:41)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_IMPL_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SpanIterator.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>
#include <set>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VertexBufferImpl
    {
    public:
        using ClassType = VertexBufferImpl;
        using StructuredBufferSharedPtr = std::shared_ptr<StructuredBuffer>;
        using VertexFormatSharedPtr = std::shared_ptr<VertexFormat>;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ImplSharedPtr = std::shared_ptr<ClassType>;
        using Semantic = VertexFormatFlags::Semantic;

    public:
        explicit VertexBufferImpl(const VertexFormat& format);
        VertexBufferImpl(const VertexFormat& format, const StructuredBufferSharedPtr& structuredBuffer);

        CLASS_INVARIANT_DECLARE;

        NODISCARD VertexFormat GetFormat() const;
        MAYBE_NULLPTR StructuredBufferSharedPtr GetStructuredBuffer() const noexcept;
        NODISCARD bool StandardUsage() const noexcept;

        NODISCARD int GetStreamingSize() const;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

        NODISCARD ImplSharedPtr Clone() const;

        NODISCARD int GetIndex(Semantic usage, int usageIndex) const noexcept;
        NODISCARD DataFormatType GetAttributeType(int attribute) const;
        NODISCARD int GetOffset(int attribute) const;

    private:
        VertexFormatSharedPtr vertexFormat;
        StructuredBufferSharedPtr structuredBuffer;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_IMPL_H