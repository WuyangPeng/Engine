/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/15 14:13)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_ATTRIBUTE_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_ATTRIBUTE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexFormatAttribute
    {
    public:
        using ClassType = VertexFormatAttribute;

        using Semantic = VertexFormatFlags::Semantic;

        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;

    public:
        VertexFormatAttribute(DataFormatType type, Semantic semantic, int unit) noexcept;
        VertexFormatAttribute(DataFormatType type, Semantic semantic, int unit, int offset) noexcept;
        VertexFormatAttribute() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD DataFormatType GetType() const noexcept;
        void SetType(DataFormatType type) noexcept;
        NODISCARD Semantic GetSemantic() const noexcept;
        void SetSemantic(Semantic aSemantic) noexcept;
        NODISCARD int GetUnit() const noexcept;
        void SetUnit(int aUnit) noexcept;
        NODISCARD int GetOffset() const noexcept;
        void SetOffset(int aOffset) noexcept;
        void SetVertexFormatAttribute(DataFormatType type, Semantic aSemantic, int aUnit, int aOffset) noexcept;

        void Clear() noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

    private:
        DataFormatType dataFormatType;
        Semantic semantic;
        int unit;
        int offset;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_ATTRIBUTE_H
