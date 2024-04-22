/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:47)

#include "CoreTools/CoreToolsExport.h"

#include "CheckItemSize.h"
#include "WriteFileHandleImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
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
    return ParentType::IsValid() && InterfaceType::IsValid();
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

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

    Write(itemSize, 1, data);
}

void CoreTools::WriteFileHandleImpl::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

    WriteToFile(itemSize, itemsNumber, data);
}

void CoreTools::WriteFileHandleImpl::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("WriteFileHandleImpl禁止调用ReadFromFile！", itemSize, itemsNumber, data);
}
