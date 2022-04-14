///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:13)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_TYPE_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_TYPE_H

#include "Rendering/RenderingDll.h"

#include "Flags/VertexFormatFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexFormatType
    {
    public:
        using ClassType = VertexFormatType;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using AttributeType = VertexFormatFlags::AttributeType;
        using AttributeUsage = VertexFormatFlags::AttributeUsage;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        VertexFormatType(AttributeType type, AttributeUsage usage, int32_t usageIndex) noexcept;
        VertexFormatType() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD AttributeType GetType() const noexcept;
        void SetType(AttributeType type) noexcept;
        NODISCARD AttributeUsage GetUsage() const noexcept;
        void SetUsage(AttributeUsage usage) noexcept;
        NODISCARD int32_t GetUsageIndex() const noexcept;
        void SetUsageIndex(int32_t aUsageIndex) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        AttributeType attributeType;
        AttributeUsage attributeUsage;
        int32_t usageIndex;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_TYPE_H
