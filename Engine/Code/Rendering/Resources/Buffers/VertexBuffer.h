///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/11 14:12)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "VertexFormat.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <set>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VertexBuffer, VertexBufferImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexBuffer : public Buffer
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VertexBuffer);
        using ParentType = Buffer;
        using VertexBufferSharedPtr = std::shared_ptr<ClassType>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const ClassType>;
        using StructuredBufferSharedPtr = std::shared_ptr<StructuredBuffer>;
        using DataFormatTypeContainer = std::set<DataFormatType>;
        using Semantic = VertexFormatFlags::Semantic;

    public:
        NODISCARD static VertexBufferSharedPtr Create(const VertexFormat& format, const StructuredBufferSharedPtr& structuredBuffer);
        NODISCARD static VertexBufferSharedPtr Create(const VertexFormat& format, int numVertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VertexBuffer);

        NODISCARD VertexFormat GetFormat() const;
        NODISCARD StructuredBufferSharedPtr GetStructuredBuffer() const;
        NODISCARD bool StandardUsage() const noexcept;

        NODISCARD SpanIterator GetChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes);

        NODISCARD virtual VertexBufferSharedPtr Clone() const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    protected:
        enum class VertexBufferCreate
        {
            Init,
        };

    public:
        explicit VertexBuffer(MAYBE_UNUSED VertexBufferCreate indexBufferCreate, const VertexFormat& format, const StructuredBufferSharedPtr& structuredBuffer);
        VertexBuffer(MAYBE_UNUSED VertexBufferCreate indexBufferCreate, const VertexFormat& format, int numVertices);

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(VertexBuffer);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VertexBuffer);
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_H
