/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/12 13:15)

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

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        using StorageType = std::vector<char>;
        using SpanIterator = CoreTools::SpanIterator<StorageType::iterator>;
        using ConstSpanIterator = CoreTools::SpanIterator<StorageType::const_iterator>;

    public:
        ResourceImpl() noexcept; 
        ResourceImpl(int numElements, int elementSize, bool createStorage);
        ResourceImpl(int numElements, int elementSize, const StorageType& storage);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsCreateStorage() const noexcept;

        void CreateStorage();
        void DestroyStorage();

        NODISCARD int GetNumElements() const noexcept;
        NODISCARD int GetElementSize() const noexcept;
        NODISCARD int GetNumBytes() const noexcept;

        void SetUsage(UsageType aUsage) noexcept;
        NODISCARD UsageType GetUsage() const noexcept;

        void SetCopy(CopyType aCopy) noexcept;
        NODISCARD CopyType GetCopy() const noexcept;

        NODISCARD ConstSpanIterator GetStorage() const noexcept;
        NODISCARD SpanIterator GetStorage() noexcept;

        NODISCARD ConstSpanIterator GetStorage(int aOffset) const;
        NODISCARD SpanIterator GetStorage(int aOffset);

        void SetOffset(int aOffset);
        NODISCARD int GetOffset() const noexcept;

        void SetNumActiveElements(int aNumActiveElements);
        NODISCARD int GetNumActiveElements() const noexcept;
        NODISCARD int GetNumActiveBytes() const noexcept;

        void SetStorage(const StorageType& aStorage);

        NODISCARD const char* GetOriginalData() const;
        NODISCARD const char* GetOriginalData(int aOffset) const;

        NODISCARD char* GetOriginalData();
        NODISCARD char* GetOriginalData(int aOffset);

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        int numElements;  // Ĭ��: 0
        int elementSize;  // Ĭ��: 0
        int numBytes;  // Ĭ��: 0
        UsageType usage;  // Ĭ��: Immutable
        CopyType copy;  // Ĭ��: None
        int offset;  // Ĭ��: 0
        int numActiveElements;  // Ĭ��: 0
        std::vector<char> storage;  // Ĭ��: ��
        bool createStorage;
    };
}

#endif  // RENDERING_RESOURCES_RESOURCE_IMPL_H