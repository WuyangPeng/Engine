///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 14:13)

#include "CoreTools/CoreToolsExport.h"

#include "ReadBufferIO.h"
#include "Detail/ReadBufferIOImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::ReadBufferIO::ReadBufferIO(const ConstFileBufferSharedPtr& fileBuffer)
    : impl{ fileBuffer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReadBufferIO)

std::string CoreTools::ReadBufferIO::GetText(int length) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetText(length);
}

int CoreTools::ReadBufferIO::GetBytesTotal() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetBytesTotal();
}

int CoreTools::ReadBufferIO::GetBytesProcessed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetBytesProcessed();
}

void CoreTools::ReadBufferIO::IncrementBytesProcessed(int bytesNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->IncrementBytesProcessed(bytesNumber);
}

void CoreTools::ReadBufferIO::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Read(itemSize, data);
}

void CoreTools::ReadBufferIO::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Read(itemSize, itemsNumber, data);
}
