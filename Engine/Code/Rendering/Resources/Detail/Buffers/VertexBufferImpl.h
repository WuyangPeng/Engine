///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:23)

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