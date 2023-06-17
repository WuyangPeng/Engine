///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:22)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_ATTRIBUTE_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_ATTRIBUTE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"
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
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        VertexFormatAttribute(DataFormatType type, Semantic usage, int usageIndex, int offset) noexcept;
        VertexFormatAttribute() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD DataFormatType GetType() const noexcept;
        void SetType(DataFormatType type) noexcept;
        NODISCARD Semantic GetUsage() const noexcept;
        void SetUsage(Semantic usage) noexcept;
        NODISCARD int GetUsageIndex() const noexcept;
        void SetUsageIndex(int aUsageIndex) noexcept;
        NODISCARD int GetOffset() const noexcept;
        void SetOffset(int aOffset) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        DataFormatType dataFormatType;
        Semantic semantic;
        int usageIndex;
        int offset;
    };
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_ATTRIBUTE_H
