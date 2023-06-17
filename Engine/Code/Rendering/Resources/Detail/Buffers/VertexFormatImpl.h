///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:23)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
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
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        VertexFormatImpl() noexcept;
        explicit VertexFormatImpl(int numAttributes) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Reset() noexcept;

        void Bind(Semantic semantic, DataFormatType type, int unit);

        void SetAttribute(int attribute, DataFormatType type, Semantic usage, int usageIndex, int offset);
        void SetAttribute(int attribute, const VertexFormatAttribute& vertexFormatElement);

        NODISCARD int GetStride() const noexcept;
        void SetStride(int aStride);

        NODISCARD int GetNumAttributes() const noexcept;

        NODISCARD int GetOffset(int attribute) const;
        NODISCARD DataFormatType GetAttributeType(int attribute) const;
        NODISCARD Semantic GetAttributeUsage(int attribute) const;
        NODISCARD int GetUsageIndex(int attribute) const;

        NODISCARD int GetIndex(Semantic usage, int32_t usageIndex = 0) const noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        static constexpr auto attributes = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes);

        int numAttributes;
        int stride;
        std::array<VertexFormatAttribute, attributes> elements;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H
