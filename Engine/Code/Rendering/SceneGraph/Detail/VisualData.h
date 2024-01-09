/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:52)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_DATA_H
#define RENDERING_SCENE_GRAPH_VISUAL_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/LocalEffects/VisualEffect.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VisualData
    {
    public:
        using ClassType = VisualData;

        using Object = CoreTools::Object;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;

        using Container = std::vector<char>;
        using ContainerConstIter = Container::const_iterator;
        using ConstSpanIterator = CoreTools::SpanIterator<ContainerConstIter>;
        using ContainerIter = Container::iterator;
        using SpanIterator = CoreTools::SpanIterator<ContainerIter>;

        using Semantic = VertexFormatFlags::Semantic;
        using DataFormatTypeContainer = std::set<DataFormatType>;

    public:
        VisualData() noexcept;
        VisualData(const VertexBufferSharedPtr& vertexBuffer,
                   const IndexBufferSharedPtr& indexBuffer) noexcept;
        ~VisualData() noexcept = default;
        VisualData(const VisualData& rhs);
        VisualData& operator=(const VisualData& rhs);
        VisualData(VisualData&& rhs) noexcept;
        VisualData& operator=(VisualData&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD IndexFormatType GetPrimitiveType() const;

        void SetVertexBuffer(const VertexBufferSharedPtr& aVertexBuffer) noexcept;
        NODISCARD ConstVertexBufferSharedPtr GetConstVertexBuffer() const noexcept;
        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;

        void SetIndexBuffer(const IndexBufferSharedPtr& aIndexBuffer) noexcept;
        NODISCARD ConstIndexBufferSharedPtr GetConstIndexBuffer() const noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        void Register(ObjectRegister& target) const;
        void Link(ObjectLink& source);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD bool IsVertexSharedPtrValid() const noexcept;
        NODISCARD int GetVertexBufferNumElements() const noexcept;

        NODISCARD ConstSpanIterator GetVertexBufferReadOnlyData() const noexcept;

        NODISCARD SpanIterator GetChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes);
        NODISCARD ConstSpanIterator GetConstChannel(Semantic semantic, int unit, const DataFormatTypeContainer& requiredTypes) const;

    private:
        using VertexBufferObjectAssociated = CoreTools::ObjectAssociated<VertexBuffer>;
        using IndexBufferObjectAssociated = CoreTools::ObjectAssociated<IndexBuffer>;

    private:
        VertexBufferObjectAssociated vertexBuffer;
        IndexBufferObjectAssociated indexBuffer;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISUAL_DATA_H
