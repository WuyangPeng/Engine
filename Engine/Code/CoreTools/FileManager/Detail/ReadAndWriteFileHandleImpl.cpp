//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 13:21)

#include "CoreTools/CoreToolsExport.h"

#include "ReadAndWriteFileHandleImpl.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ReadAndWriteFileHandleImpl::ReadAndWriteFileHandleImpl(const String& fileName)
    : ParentType{ fileName, FileHandleDesiredAccess::ReadWrite, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ReadAndWriteFileHandleImpl)

void CoreTools::ReadAndWriteFileHandleImpl::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

    Read(itemSize, 1, data);
}

void CoreTools::ReadAndWriteFileHandleImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

    ReadFromFile(itemSize, itemsNumber, data);
}

void CoreTools::ReadAndWriteFileHandleImpl::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

    Write(itemSize, 1, data);
}

void CoreTools::ReadAndWriteFileHandleImpl::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

    WriteToFile(itemSize, itemsNumber, data);
}
