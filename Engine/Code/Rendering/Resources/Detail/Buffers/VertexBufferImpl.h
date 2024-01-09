/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:50)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_IMPL_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VertexBufferImpl
    {
    public:
        using ClassType = VertexBufferImpl;
        using VertexBufferSharedPtr = std::shared_ptr<ClassType>;

        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;

        using Semantic = VertexFormatFlags::Semantic;
        using VertexFormatSharedPtr = std::shared_ptr<VertexFormat>;
        using StructuredBufferSharedPtr = std::shared_ptr<StructuredBuffer>;
        using ConstStructuredBufferSharedPtr = std::shared_ptr<const StructuredBuffer>;

    public:
        VertexBufferImpl() noexcept;
        explicit VertexBufferImpl(const VertexFormat& format);
        VertexBufferImpl(const VertexFormat& format, const StructuredBuffer& structuredBuffer);
        ~VertexBufferImpl() noexcept = default;
        VertexBufferImpl(const VertexBufferImpl& rhs);
        VertexBufferImpl& operator=(const VertexBufferImpl& rhs);
        VertexBufferImpl(VertexBufferImpl&& rhs) noexcept;
        VertexBufferImpl& operator=(VertexBufferImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD VertexFormat GetFormat() const;
        MAYBE_NULLPTR StructuredBufferSharedPtr GetStructuredBuffer() noexcept;
        MAYBE_NULLPTR ConstStructuredBufferSharedPtr GetStructuredBuffer() const noexcept;
        NODISCARD bool StandardUsage() const noexcept;

        NODISCARD int GetIndex(Semantic usage, int usageIndex) const noexcept;
        NODISCARD DataFormatType GetAttributeType(int attribute) const;
        NODISCARD int GetOffset(int attribute) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);
        void Register(ObjectRegister& target) const;
        void Link(ObjectLink& source);

    private:
        void CheckVertexFormat() const;

    private:
        using VertexFormatObjectAssociated = CoreTools::ObjectAssociated<VertexFormat>;
        using StructuredBufferObjectAssociated = CoreTools::ObjectAssociated<StructuredBuffer>;

    private:
        VertexFormatObjectAssociated vertexFormat;
        StructuredBufferObjectAssociated structuredBuffer;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_IMPL_H