/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 23:26)

#include "CoreTools/CoreToolsExport.h"

#include "BufferIOImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::BufferIOImpl::BufferIOImpl() noexcept
    : bytesProcessed{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::BufferIOImpl::IsValid() const noexcept
{
    return 0 <= bytesProcessed;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::BufferIOImpl::GetBytesProcessed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return bytesProcessed;
}

void CoreTools::BufferIOImpl::IncrementBytesProcessed(int bytesNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_0(0 < bytesNumber, "增量必须是正数！\n");

    const auto nextBytesProcessed = bytesProcessed + bytesNumber;

    if (nextBytesProcessed < 0 || GetBytesTotal() < nextBytesProcessed)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("增量超过了缓冲区大小！\n"s))
    }

    bytesProcessed = nextBytesProcessed;
}

void CoreTools::BufferIOImpl::SetBytesProcessed(int aBytesProcessed) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    bytesProcessed = aBytesProcessed;
}
