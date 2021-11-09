///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:21)

#include "CoreTools/CoreToolsExport.h"

#include "ReadBufferIOImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/FileManager/Flags/BufferIOFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::ReadBufferIOImpl::ReadBufferIOImpl(const ConstFileBufferSharedPtr& fileBuffer) noexcept
    : ParentType{}, buffer{ fileBuffer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ReadBufferIOImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && buffer != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::ReadBufferIOImpl::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "������Ч");

    ReadFromBuffer(itemSize, 1, data);
}

void CoreTools::ReadBufferIOImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "������Ч");

    ReadFromBuffer(itemSize, itemsNumber, data);
}

int CoreTools::ReadBufferIOImpl::ReadFromBuffer(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "׼��д���������Ч��");
    CORE_TOOLS_ASSERTION_2(GetBufferIOType() == BufferIO::Read, "��������֧�ֶ�ȡ��");

    auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);
    auto nextBytesProcessed = GetBytesProcessed() + numberToCopy;
    if (nextBytesProcessed <= GetBytesTotal())
    {
        // ��û�������ǰָ��λ�á�
        auto source = buffer->GetBuffer(GetBytesProcessed());

        SetBytesProcessed(nextBytesProcessed);

        System::MemoryCopy(data, source, numberToCopy);

#ifdef SYSTEM_BIG_ENDIAN
        if (1 < itemSize)
        {
            Endian::SwapByteOrder(itemSize, itemsNumber, data);
        }
#endif  // SYSTEM_BIG_ENDIAN

        return numberToCopy;
    }
    else
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("Ҫ��ȡ���ֽ���%1%�����˻�������С%2%��ԭ�ֽ���Ϊ��%3%")) % numberToCopy % GetBytesTotal() % GetBytesProcessed()).str());
    }
}

std::string CoreTools::ReadBufferIOImpl::GetText(int length) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto nextProcessed = boost::numeric_cast<size_t>(GetBytesProcessed() + length);

    if (nextProcessed <= buffer->GetSize())
    {
        auto text = buffer->GetBuffer(GetBytesProcessed());
        std::string datum{ text, boost::numeric_cast<size_t>(length) };

        return datum;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Ҫ��ȡ���ֽ��������˻�������С��"s));
    }
}

int CoreTools::ReadBufferIOImpl::GetBytesTotal() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(buffer->GetSize());
}

CoreTools::BufferIO CoreTools::ReadBufferIOImpl::GetBufferIOType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return BufferIO::Read;
}
