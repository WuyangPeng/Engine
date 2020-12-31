//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/14 13:52)

#include "CoreTools/CoreToolsExport.h"

#include "WriteBufferIOImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/FileManager/Flags/BufferIOFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::WriteBufferIOImpl::WriteBufferIOImpl(int bufferSize)
    : ParentType{}, m_Buffer(bufferSize)
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::WriteBufferIOImpl ::IsValid() const noexcept
{
    if (ParentType::IsValid())
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
        auto target = m_Buffer.GetBuffer(GetBytesProcessed());

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

    return boost::numeric_cast<int>(m_Buffer.GetSize());
}

CoreTools::BufferIO CoreTools::WriteBufferIOImpl::GetBufferIOType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return BufferIO::Write;
}
