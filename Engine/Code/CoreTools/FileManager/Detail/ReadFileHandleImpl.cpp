///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/09 1:43)

#include "CoreTools/CoreToolsExport.h"

#include "ReadFileHandleImpl.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using boost::numeric_cast;

CoreTools::ReadFileHandleImpl::ReadFileHandleImpl(const String& fileName)
    : ParentType{ fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::ReadFileHandleImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && InterfaceType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::ReadFileHandleImpl::GetFileByteSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return numeric_cast<int>(ParentType::GetFileLength());
}

void CoreTools::ReadFileHandleImpl::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

    Read(itemSize, 1, data);
}

void CoreTools::ReadFileHandleImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

    ReadFromFile(itemSize, itemsNumber, data);
}

void CoreTools::ReadFileHandleImpl::WriteToFile(MAYBE_UNUSED size_t itemSize, MAYBE_UNUSED size_t itemsNumber, MAYBE_UNUSED const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_4(false, "ReadFileHandleImpl禁止调用WriteToFile！");
}

void CoreTools::ReadFileHandleImpl::AppendToFile(MAYBE_UNUSED size_t itemSize, MAYBE_UNUSED size_t itemsNumber, MAYBE_UNUSED const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_4(false, "ReadFileHandleImpl禁止调用AppendToFile！");
}
