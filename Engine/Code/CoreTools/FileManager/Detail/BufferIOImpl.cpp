///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 23:45)

#include "CoreTools/CoreToolsExport.h"

#include "BufferIOImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::BufferIOImpl::BufferIOImpl() noexcept
    : m_BytesProcessed{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::BufferIOImpl::IsValid() const noexcept
{
    if (0 <= m_BytesProcessed)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::BufferIOImpl::GetBytesProcessed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_BytesProcessed;
}

void CoreTools::BufferIOImpl::IncrementBytesProcessed(int bytesNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(0 < bytesNumber, "增量必须是正数！\n");

    const auto nextBytesProcessed = m_BytesProcessed + bytesNumber;

    if (nextBytesProcessed < 0 || GetBytesTotal() < nextBytesProcessed)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("增量超过了缓冲区大小！\n"s));
    }

    m_BytesProcessed = nextBytesProcessed;
}

void CoreTools::BufferIOImpl::SetBytesProcessed(int bytesProcessed) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_BytesProcessed = bytesProcessed;
}
