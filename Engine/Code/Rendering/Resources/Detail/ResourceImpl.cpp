///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/08 15:56)

#include "Rendering/RenderingExport.h"

#include "ResourceImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <gsl/util>
#include <string>

Rendering::ResourceImpl::ResourceImpl(int numElements, int elementSize)
    : numElements{ 0 < numElements ? numElements : 0 },
      elementSize{ 0 < elementSize ? elementSize : 0 },
      numBytes{ (0 < numElements && 0 < elementSize) ? (numElements * elementSize) : 0 },
      usage{ UsageType::Immutable },
      copy{ CopyType::None },
      offset{ 0 },
      numActiveElements{ 0 < numElements ? numElements : 0 },
      storage(numBytes)
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
      storage{ storage }
{
    if (boost::numeric_cast<int>(storage.size()) != numBytes)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据和数组大小不一致"s));
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
        gsl::narrow_cast<int>(storage.size()) == numBytes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

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

void Rendering::ResourceImpl::SetUsage(UsageType usageType) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    usage = usageType;
}

Rendering::UsageType Rendering::ResourceImpl::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return usage;
}

void Rendering::ResourceImpl::SetCopy(CopyType copyType) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    copy = copyType;
}

Rendering::CopyType Rendering::ResourceImpl::GetCopy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return copy;
}

Rendering::ResourceImpl::ConstSpanIterator Rendering::ResourceImpl::GetData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ConstSpanIterator{ storage.cbegin(), storage.cend() };
}

Rendering::ResourceImpl::SpanIterator Rendering::ResourceImpl::GetData(int aOffset)
{
    RENDERING_CLASS_IS_VALID_1;

    SpanIterator result{ storage.begin(), storage.end() };

    result += aOffset;

    return result;
}

Rendering::ResourceImpl::ConstSpanIterator Rendering::ResourceImpl::GetData(int aOffset) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ConstSpanIterator result{ storage.cbegin(), storage.cend() };

    result += aOffset;

    return result;
}

Rendering::ResourceImpl::SpanIterator Rendering::ResourceImpl::GetData() noexcept
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
        THROW_EXCEPTION(SYSTEM_TEXT("无效的offset值。"s));
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
        THROW_EXCEPTION(SYSTEM_TEXT("无效的numActiveElements值。"s));
    }
}

void Rendering::ResourceImpl::SetNewData(const StorageType& newStorage)
{
    RENDERING_CLASS_IS_VALID_1;

    if (boost::numeric_cast<int>(newStorage.size()) != numBytes)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据和数组大小不一致"s));
    }

    storage = newStorage;
}

const char* Rendering::ResourceImpl::GetOriginalData() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (storage.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据为空。"s));
    }

    return storage.data();
}

char* Rendering::ResourceImpl::GetOriginalData(int aOffset)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return &storage.at(aOffset);
}

const char* Rendering::ResourceImpl::GetOriginalData(int aOffset) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return &storage.at(aOffset);
}

void Rendering::ResourceImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numElements);
    source.Read(elementSize);
    numBytes = numElements * elementSize;

    source.ReadEnum(usage);
    source.ReadEnum(copy);
    source.Read(offset);
    source.Read(numActiveElements);

    storage = source.ReadVectorWithNumber<char>(numBytes);
}

void Rendering::ResourceImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numElements);
    target.Write(elementSize);

    target.WriteEnum(usage);
    target.WriteEnum(copy);
    target.Write(offset);
    target.Write(numActiveElements);

    target.WriteContainerWithoutNumber(storage);
}

int Rendering::ResourceImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(numElements);

    size += CORE_TOOLS_STREAM_SIZE(elementSize);
    size += CORE_TOOLS_STREAM_SIZE(usage);
    size += CORE_TOOLS_STREAM_SIZE(copy);
    size += CORE_TOOLS_STREAM_SIZE(offset);
    size += CORE_TOOLS_STREAM_SIZE(numActiveElements);

    size += boost::numeric_cast<int>(storage.size()) * CoreTools::GetStreamSize<char>();

    return size;
}
