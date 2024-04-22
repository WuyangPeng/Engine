/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:42)

#include "CoreTools/CoreToolsExport.h"

#include "ReadAndWriteFileHandleImpl.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ReadAndWriteFileHandleImpl::ReadAndWriteFileHandleImpl(const String& fileName)
    : ParentType{ fileName, FileHandleDesiredAccess::ReadWrite, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenAlways }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ReadAndWriteFileHandleImpl)

void CoreTools::ReadAndWriteFileHandleImpl::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    Read(itemSize, 1, data);
}

void CoreTools::ReadAndWriteFileHandleImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ReadFromFile(itemSize, itemsNumber, data);
}

void CoreTools::ReadAndWriteFileHandleImpl::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    Write(itemSize, 1, data);
}

void CoreTools::ReadAndWriteFileHandleImpl::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    WriteToFile(itemSize, itemsNumber, data);
}
