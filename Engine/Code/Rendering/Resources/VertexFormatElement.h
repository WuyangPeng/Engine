// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 11:24)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_ELEMENT_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_ELEMENT_H

#include "Rendering/RenderingDll.h"

#include "VertexFormatType.h"
#include "Flags/VertexFormatFlags.h"

namespace CoreTools
{
    class BufferTarget;
    class BufferSource;
    class WriteFileManager;
    class ReadFileManager;
}

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
        VertexFormatElement(unsigned int streamIndex, unsigned int offset, const VertexFormatType& vertexFormatType) noexcept;

        CLASS_INVARIANT_DECLARE;

        unsigned int GetStreamIndex() const noexcept;
        void SetStreamIndex(unsigned int streamIndex) noexcept;
        unsigned int GetOffset() const noexcept;
        void SetOffset(unsigned int offset) noexcept;
        AttributeType GetType() const noexcept;
        void SetType(AttributeType type) noexcept;
        AttributeUsage GetUsage() const noexcept;
        void SetUsage(AttributeUsage usage) noexcept;
        unsigned int GetUsageIndex() const noexcept;
        void SetUsageIndex(unsigned int usageIndex) noexcept;
        void SetVertexFormatType(const VertexFormatType& vertexFormatType) noexcept;
        void Set(unsigned int streamIndex, unsigned int offset, const VertexFormatType& vertexFormatType) noexcept;

        int GetStreamingSize() const noexcept;
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        void Load(BufferSource& source);

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        unsigned int m_StreamIndex;
        unsigned int m_Offset;
        VertexFormatType m_VertexFormatType;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_ELEMENT_H
