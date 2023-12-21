/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/16 14:03)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Resources/Buffers/VertexFormatAttribute.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VertexFormatImpl
    {
    public:
        using ClassType = VertexFormatImpl;

        using Semantic = VertexFormatFlags::Semantic;

        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;

    public:
        VertexFormatImpl() noexcept;
        explicit VertexFormatImpl(int numAttributes) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Reset() noexcept;

        void Bind(DataFormatType type, Semantic semantic, int unit);

        void SetAttribute(int attribute, DataFormatType type, Semantic semantic, int unit, int offset);
        void SetAttribute(int attribute, const VertexFormatAttribute& vertexFormatAttribute);

        NODISCARD int GetVertexSize() const noexcept;
        void SetVertexSize(int aVertexSize);

        NODISCARD int GetNumAttributes() const noexcept;

        NODISCARD int GetOffset(int attribute) const;
        NODISCARD DataFormatType GetAttributeType(int attribute) const;
        NODISCARD Semantic GetSemantic(int attribute) const;
        NODISCARD int GetUnit(int attribute) const;

        NODISCARD int GetIndex(Semantic semantic, int unit) const noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

    private:
        static constexpr auto attributes = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes);
        using ElementsType = std::array<VertexFormatAttribute, attributes>;

    private:
        int numAttributes;
        int vertexSize;
        ElementsType elements;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H
