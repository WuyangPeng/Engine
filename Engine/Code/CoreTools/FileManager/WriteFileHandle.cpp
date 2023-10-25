///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 14:16)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileHandle.h"
#include "Detail/WriteFileHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::WriteFileHandle::WriteFileHandle(const String& fileName, FileHandleCreationDisposition creation)
    : impl{ fileName, creation }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteFileHandle)

int CoreTools::WriteFileHandle::GetFileByteSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileByteSize();
}

void CoreTools::WriteFileHandle::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, data);
}

void CoreTools::WriteFileHandle::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, itemsNumber, data);
}
