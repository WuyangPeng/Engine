///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 13:51)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileHandleImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::WriteFileHandleImpl::WriteFileHandleImpl(const String& fileName, FileHandleCreationDisposition creation)
    : ParentType{ fileName, FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, creation }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::WriteFileHandleImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && InterfaceType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::WriteFileHandleImpl::GetFileByteSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(ParentType::GetFileLength());
}

void CoreTools::WriteFileHandleImpl::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

    Write(itemSize, 1, data);
}

void CoreTools::WriteFileHandleImpl::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

    WriteToFile(itemSize, itemsNumber, data);
}

void CoreTools::WriteFileHandleImpl::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_4(false, "WriteFileHandleImpl禁止调用ReadFromFile！");

    System::UnusedFunction(itemSize, itemsNumber, data);
}
