/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 14:05)

#include "Rendering/RenderingExport.h"

#include "ResourceImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <gsl/util>
#include <string>

Rendering::ResourceImpl::ResourceImpl() noexcept
    : numElements{ 0 },
      elementSize{ 0 },
      numBytes{ 0 },
      usage{ UsageType::Immutable },
      copy{ CopyType::None },
      offset{ 0 },
      numActiveElements{ 0 },
      storage{},
      createStorage{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ResourceImpl::ResourceImpl(int numElements, int elementSize, bool createStorage)
    : numElements{ 0 < numElements ? numElements : 0 },
      elementSize{ 0 < elementSize ? elementSize : 0 },
      numBytes{ (0 < numElements && 0 < elementSize) ? (numElements * elementSize) : 0 },
      usage{ UsageType::Immutable },
      copy{ CopyType::None },
      offset{ 0 },
      numActiveElements{ 0 < numElements ? numElements : 0 },
      storage((0 < numElements && 0 < elementSize && createStorage) ? numBytes : 0),
      createStorage{ createStorage }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ResourceImpl::ResourceImpl(int numElements, int elementSize, const StorageType& storage)
    : numElements{ 0 < numElements ? numElements : 0 },
      elementSize{ 0 < elementSize ? elementSize : 0 },
      numBytes{ (0 < numElements && 0 < elementSize) ? (numElements * elementSize) : 0 },
      usage{ UsageType::Immutable },
      copy{ CopyType::None },
      offset{ 0 },
      numActiveElements{ 0 < numElements ? numElements : 0 },
      storage{ storage },
      createStorage{ true }
{
    if (boost::numeric_cast<int>(storage.size()) != numBytes)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݺ������С��һ��"s))
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::ResourceImpl::IsValid() const noexcept
{
    if (0 <= numElements &&
        0 <= elementSize &&
        (numBytes == numElements * elementSize) &&
        0 <= offset &&
        (!createStorage ||
         gsl::narrow_cast<int>(storage.size()) == numBytes))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::ResourceImpl::CreateStorage()
{
    RENDERING_CLASS_IS_VALID_1;

    if (storage.empty() && 0 < numBytes)
    {
        storage.resize(numBytes);
        createStorage = true;
    }
}

void Rendering::ResourceImpl::DestroyStorage()
{
    RENDERING_CLASS_IS_VALID_1;

    /// DestroyStorage��Ŀ������ֻ��ҪGPU�ڴ���Դ��������ͷŲ���Ҫ��CPU�ڴ档
    /// clear���ý���С����Ϊ0�����������ֲ��䣻Ҳ����˵���ڴ�û�б��ͷš�
    /// ��Ҫshrink_to_fit���ò����ͷ��ڴ档
    if (!storage.empty() && createStorage)
    {
        createStorage = false;
        storage.clear();
        storage.shrink_to_fit();
    }
}

int Rendering::ResourceImpl::GetNumElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numElements;
}

int Rendering::ResourceImpl::GetElementSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return elementSize;
}

int Rendering::ResourceImpl::GetNumBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numBytes;
}

void Rendering::ResourceImpl::SetUsage(UsageType aUsage) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    usage = aUsage;
}

Rendering::UsageType Rendering::ResourceImpl::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return usage;
}

void Rendering::ResourceImpl::SetCopy(CopyType aCopy) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    copy = aCopy;
}

Rendering::CopyType Rendering::ResourceImpl::GetCopy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return copy;
}

Rendering::ResourceImpl::ConstSpanIterator Rendering::ResourceImpl::GetStorage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ConstSpanIterator{ storage.cbegin(), storage.cend() };
}

Rendering::ResourceImpl::SpanIterator Rendering::ResourceImpl::GetStorage(int aOffset)
{
    RENDERING_CLASS_IS_VALID_1;

    SpanIterator result{ storage.begin(), storage.end() };

    result += aOffset;

    return result;
}

Rendering::ResourceImpl::ConstSpanIterator Rendering::ResourceImpl::GetStorage(int aOffset) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ConstSpanIterator result{ storage.cbegin(), storage.cend() };

    result += aOffset;

    return result;
}

Rendering::ResourceImpl::SpanIterator Rendering::ResourceImpl::GetStorage() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return SpanIterator{ storage.begin(), storage.end() };
}

int Rendering::ResourceImpl::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return offset;
}

void Rendering::ResourceImpl::SetOffset(int aOffset)
{
    RENDERING_CLASS_IS_VALID_1;

    if (aOffset < numElements)
    {
        offset = aOffset;
    }
    else
    {
        const auto message = SYSTEM_TEXT("��Ч��offset (") +
                             System::ToString(offset) +
                             SYSTEM_TEXT(")") +
                             SYSTEM_TEXT("; ��Ԫ�� = ") +
                             System::ToString(numElements) +
                             SYSTEM_TEXT("��");
        THROW_EXCEPTION(message)
    }
}

int Rendering::ResourceImpl::GetNumActiveElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numActiveElements;
}

int Rendering::ResourceImpl::GetNumActiveBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numActiveElements * elementSize;
}

void Rendering::ResourceImpl::SetNumActiveElements(int aNumActiveElements)
{
    RENDERING_CLASS_IS_VALID_1;

    if (aNumActiveElements + offset <= numElements)
    {
        numActiveElements = aNumActiveElements;
    }
    else
    {
        const auto message = SYSTEM_TEXT("�Ԫ�ص�������Ч (") +
                             System::ToString(numActiveElements) +
                             SYSTEM_TEXT(")") +
                             SYSTEM_TEXT("; offset = ") +
                             System::ToString(offset) +
                             SYSTEM_TEXT("; ��Ԫ�� = ") +
                             System::ToString(numElements) +
                             SYSTEM_TEXT("��");

        THROW_EXCEPTION(message)
    }
}

void Rendering::ResourceImpl::SetStorage(const StorageType& aStorage)
{
    RENDERING_CLASS_IS_VALID_1;

    if (boost::numeric_cast<int>(aStorage.size()) != numBytes)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݺ������С��һ��"s))
    }

    storage = aStorage;
}

const char* Rendering::ResourceImpl::GetOriginalData() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (storage.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Ϊ�ա�"s))
    }

    return storage.data();
}

char* Rendering::ResourceImpl::GetOriginalData(int aOffset)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (boost::numeric_cast<int>(storage.size()) <= aOffset)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������С��ƫ��ֵ��"s))
    }

    return &storage.at(aOffset);
}

bool Rendering::ResourceImpl::IsCreateStorage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return createStorage;
}

const char* Rendering::ResourceImpl::GetOriginalData(int aOffset) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (boost::numeric_cast<int>(storage.size()) <= aOffset)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������С��ƫ��ֵ��"s))
    }

    return &storage.at(aOffset);
}

char* Rendering::ResourceImpl::GetOriginalData()
{
    RENDERING_CLASS_IS_VALID_1;

    if (storage.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Ϊ�ա�"s))
    }

    return storage.data();
}

void Rendering::ResourceImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numElements);
    source.Read(elementSize);
    numBytes = numElements * elementSize;

    source.ReadEnum(usage);
    source.ReadEnum(copy);
    source.Read(offset);
    source.Read(numActiveElements);

    storage = source.ReadVectorUseNumber<char>(numBytes);
    createStorage = source.ReadBool();
}

void Rendering::ResourceImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numElements);
    target.Write(elementSize);

    target.WriteEnum(usage);
    target.WriteEnum(copy);
    target.Write(offset);
    target.Write(numActiveElements);

    target.WriteContainerWithoutNumber(storage);
    target.Write(createStorage);
}

int Rendering::ResourceImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(numElements);

    size += CoreTools::GetStreamSize(elementSize);
    size += CoreTools::GetStreamSize(usage);
    size += CoreTools::GetStreamSize(copy);
    size += CoreTools::GetStreamSize(offset);
    size += CoreTools::GetStreamSize(numActiveElements);

    size += boost::numeric_cast<int>(storage.size()) * CoreTools::GetStreamSize<char>();
    size += CoreTools::GetStreamSize(createStorage);

    return size;
}
