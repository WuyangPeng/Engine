/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:52)

#include "CoreTools/CoreToolsExport.h"

#include "WriteBufferIO.h"
#include "Detail/WriteBufferIOImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::WriteBufferIO::WriteBufferIO(int bufferSize)
    : impl{ bufferSize }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteBufferIO)

int CoreTools::WriteBufferIO::GetBytesTotal() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetBytesTotal();
}

int CoreTools::WriteBufferIO::GetBytesProcessed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetBytesProcessed();
}

CoreTools::ConstFileBufferSharedPtr CoreTools::WriteBufferIO::GetFileBuffer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileBuffer();
}

void CoreTools::WriteBufferIO::IncrementBytesProcessed(int bytesNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->IncrementBytesProcessed(bytesNumber);
}

void CoreTools::WriteBufferIO::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, data);
}

void CoreTools::WriteBufferIO::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, itemsNumber, data);
}
