///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 14:03)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_DATA_H
#define RENDERING_SCENE_GRAPH_VISUAL_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VisualData
    {
    public:
        using ClassType = VisualData;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using Object = CoreTools::Object;
        using SpanIterator = CoreTools::SpanIterator<std::vector<char>::const_iterator>;

    public:
        explicit VisualData(VisualPrimitiveType type = VisualPrimitiveType::None) noexcept;
        VisualData(VisualPrimitiveType type,
                   const VertexFormatSharedPtr& vertexformat,
                   const VertexBufferSharedPtr& vertexbuffer,
                   const IndexBufferSharedPtr& indexbuffer) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetPrimitiveType(VisualPrimitiveType type) noexcept;
        NODISCARD VisualPrimitiveType GetPrimitiveType() const noexcept;

        void SetVertexFormat(const VertexFormatSharedPtr& vertexformat) noexcept;
        NODISCARD ConstVertexFormatSharedPtr GetConstVertexFormat() const noexcept;
        NODISCARD VertexFormatSharedPtr GetVertexFormat() noexcept;

        void SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer) noexcept;
        NODISCARD ConstVertexBufferSharedPtr GetConstVertexBuffer() const noexcept;
        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;

        void SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer) noexcept;
        NODISCARD ConstIndexBufferSharedPtr GetConstIndexBuffer() const noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        void Register(CoreTools::ObjectRegister& target) const;
        void Link(CoreTools::ObjectLink& source);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD bool IsVertexSharedPtrValid() const noexcept;
        NODISCARD int GetVertexBufferNumElements() const noexcept;
        NODISCARD int GetVertexFormatStride() const noexcept;
        NODISCARD int GetPositionOffset() const;
        NODISCARD SpanIterator GetVertexBufferReadOnlyData() const noexcept;

    private:
        VisualPrimitiveType visualPrimitiveType;
        CoreTools::ObjectAssociated<VertexFormat> vertexFormat;
        CoreTools::ObjectAssociated<VertexBuffer> vertexBuffer;
        CoreTools::ObjectAssociated<IndexBuffer> indexBuffer;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISUAL_DATA_H
