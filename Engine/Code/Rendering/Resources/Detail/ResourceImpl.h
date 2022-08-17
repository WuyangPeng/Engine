///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/08 16:00)

#ifndef RENDERING_RESOURCES_RESOURCE_IMPL_H
#define RENDERING_RESOURCES_RESOURCE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ResourceImpl
    {
    public:
        using ClassType = ResourceImpl;
        using StorageType = std::vector<char>;
        using SpanIterator = CoreTools::SpanIterator<StorageType::iterator>;
        using ConstSpanIterator = CoreTools::SpanIterator<StorageType::const_iterator>;

    public:
        ResourceImpl(int numElements, int elementSize);
        ResourceImpl(int numElements, int elementSize, const StorageType& storage);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumElements() const noexcept;
        NODISCARD int GetElementSize() const noexcept;
        NODISCARD int GetNumBytes() const noexcept;

        void SetUsage(UsageType usageType) noexcept;
        NODISCARD UsageType GetUsage() const noexcept;

        void SetCopy(CopyType copyType) noexcept;
        NODISCARD CopyType GetCopy() const noexcept;

        NODISCARD ConstSpanIterator GetData() const noexcept;
        NODISCARD SpanIterator GetData() noexcept;

        NODISCARD ConstSpanIterator GetData(int aOffset) const;
        NODISCARD SpanIterator GetData(int aOffset);

        void SetOffset(int aOffset);
        NODISCARD int GetOffset() const noexcept;

        void SetNumActiveElements(int aNumActiveElements);
        NODISCARD int GetNumActiveElements() const noexcept;
        NODISCARD int GetNumActiveBytes() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        void SetNewData(const StorageType& newStorage);

    private:
        int numElements;  // 默认: 0
        int elementSize;  // 默认: 0
        int numBytes;  // 默认: 0
        UsageType usage;  // 默认: Immutable
        CopyType copy;  // 默认: None
        int offset;  // 默认: 0
        int numActiveElements;  // 默认: 0
        std::vector<char> storage;  // 默认: 空
    };
}

#endif  // RENDERING_RESOURCES_RESOURCE_IMPL_H