///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:43)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"
#include "Rendering/Resources/VertexFormatElement.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VertexFormatImpl
    {
    public:
        using ClassType = VertexFormatImpl;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using AttributeType = VertexFormatFlags::AttributeType;
        using AttributeUsage = VertexFormatFlags::AttributeUsage;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        VertexFormatImpl() noexcept;
        explicit VertexFormatImpl(int numAttributes) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetAttribute(int attribute, int32_t streamIndex, int32_t offset, AttributeType type, AttributeUsage usage, int32_t usageIndex);

        void SetAttribute(int attribute, int32_t streamIndex, int32_t offset, const VertexFormatType& vertexFormatType);

        void SetAttribute(int attribute, const VertexFormatElement& vertexFormatElement);

        void SetStride(int aStride);

        NODISCARD int32_t GetNumAttributes() const noexcept;

        NODISCARD int32_t GetStreamIndex(int attribute) const;
        NODISCARD int32_t GetOffset(int attribute) const;
        NODISCARD AttributeType GetAttributeType(int attribute) const;
        NODISCARD AttributeUsage GetAttributeUsage(int attribute) const;
        NODISCARD int32_t GetUsageIndex(int attribute) const;

        NODISCARD int GetStride() const noexcept;

        NODISCARD int GetIndex(AttributeUsage usage, int32_t usageIndex = 0) const noexcept;

        NODISCARD static int GetComponentSize(AttributeType type) noexcept;
        NODISCARD static int GetNumComponents(AttributeType type) noexcept;
        NODISCARD static int GetTypeSize(AttributeType type) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        int32_t numAttributes;
        std::array<VertexFormatElement, System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes)> elements;
        int32_t stride;

        static std::array<int, System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)> componentSize;
        static std::array<int, System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)> numComponents;
        static std::array<int, System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)> typeSize;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H
