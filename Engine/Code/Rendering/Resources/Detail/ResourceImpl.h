///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/08 16:00)

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
        int numElements;  // Ĭ��: 0
        int elementSize;  // Ĭ��: 0
        int numBytes;  // Ĭ��: 0
        UsageType usage;  // Ĭ��: Immutable
        CopyType copy;  // Ĭ��: None
        int offset;  // Ĭ��: 0
        int numActiveElements;  // Ĭ��: 0
        std::vector<char> storage;  // Ĭ��: ��
    };
}

#endif  // RENDERING_RESOURCES_RESOURCE_IMPL_H