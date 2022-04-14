///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:19)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_ELEMENT_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_ELEMENT_H

#include "Rendering/RenderingDll.h"

#include "VertexFormatType.h"
#include "Flags/VertexFormatFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

namespace Rendering
{
    // 信息图形API。并不是所有的API都使用所有信息。
    class RENDERING_DEFAULT_DECLARE VertexFormatElement
    {
    public:
        using ClassType = VertexFormatElement;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using AttributeType = VertexFormatFlags::AttributeType;
        using AttributeUsage = VertexFormatFlags::AttributeUsage;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        VertexFormatElement() noexcept;
        VertexFormatElement(int32_t streamIndex, int32_t offset, const VertexFormatType& vertexFormatType) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int32_t GetStreamIndex() const noexcept;
        void SetStreamIndex(int32_t aStreamIndex) noexcept;
        NODISCARD int32_t GetOffset() const noexcept;
        void SetOffset(int32_t aOffset) noexcept;
        NODISCARD AttributeType GetType() const noexcept;
        void SetType(AttributeType type) noexcept;
        NODISCARD AttributeUsage GetUsage() const noexcept;
        void SetUsage(AttributeUsage usage) noexcept;
        NODISCARD int32_t GetUsageIndex() const noexcept;
        void SetUsageIndex(int32_t usageIndex) noexcept;
        void SetVertexFormatType(const VertexFormatType& aVertexFormatType) noexcept;
        void Set(int32_t aStreamIndex, int32_t aOffset, const VertexFormatType& aVertexFormatType) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        int32_t streamIndex;
        int32_t offset;
        VertexFormatType vertexFormatType;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_ELEMENT_H
