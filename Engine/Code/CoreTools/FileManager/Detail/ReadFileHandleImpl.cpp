/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:45)

#include "CoreTools/CoreToolsExport.h"

#include "ReadFileHandleImpl.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ReadFileHandleImpl::ReadFileHandleImpl(const String& fileName)
    : ParentType{ fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::ReadFileHandleImpl::IsValid() const noexcept
{
    return ParentType::IsValid() && InterfaceType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::ReadFileHandleImpl::GetFileByteSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(ParentType::GetFileLength());
}

void CoreTools::ReadFileHandleImpl::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    Read(itemSize, 1, data);
}

void CoreTools::ReadFileHandleImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ReadFromFile(itemSize, itemsNumber, data);
}

void CoreTools::ReadFileHandleImpl::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("ReadFileHandleImpl禁止调用WriteToFile！", itemSize, itemsNumber, data);
}

void CoreTools::ReadFileHandleImpl::AppendToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("ReadFileHandleImpl禁止调用AppendToFile！", itemSize, itemsNumber, data);
}
