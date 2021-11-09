///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:25)

#include "CoreTools/CoreToolsExport.h"

#include "WriteBufferIOImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/FileManager/Flags/BufferIOFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;
using std::make_shared;

CoreTools::WriteBufferIOImpl::WriteBufferIOImpl(int bufferSize)
    : ParentType{}, buffer{ make_shared<FileBuffer>(bufferSize) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::WriteBufferIOImpl ::IsValid() const noexcept
{
    if (ParentType::IsValid() && buffer != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::WriteBufferIOImpl::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "������Ч");

    WriteToBuffer(itemSize, 1, data);
}

void CoreTools::WriteBufferIOImpl::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "������Ч");

    WriteToBuffer(itemSize, itemsNumber, data);
}

uint32_t CoreTools::WriteBufferIOImpl::WriteToBuffer(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "׼����ȡ��������Ч��");
    CORE_TOOLS_ASSERTION_2(GetBufferIOType() == BufferIO::Write, "��������֧��д�룡");

    auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);
    auto nextBytesProcessed = GetBytesProcessed() + numberToCopy;
    if (nextBytesProcessed <= GetBytesTotal())
    {
        // ��û�������ǰָ��λ�á�
        auto target = buffer->GetBuffer(GetBytesProcessed());

        SetBytesProcessed(nextBytesProcessed);
        System::MemoryCopy(target, data, numberToCopy);

#ifdef SYSTEM_BIG_ENDIAN
        if (1 < itemSize)
        {
            Endian::SwapByteOrder(itemSize, itemsNumber, target);
        }
#endif  // SYSTEM_BIG_ENDIAN

        return numberToCopy;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Ҫд����ֽ��������˻�������С��"s));
    }
}

int CoreTools::WriteBufferIOImpl::GetBytesTotal() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(buffer->GetSize());
}

CoreTools::BufferIO CoreTools::WriteBufferIOImpl::GetBufferIOType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return BufferIO::Write;
}

CoreTools::ConstFileBufferSharedPtr CoreTools::WriteBufferIOImpl::GetFileBuffer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return buffer;
}
