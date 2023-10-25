///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 13:47)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManagerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/Tools.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::CReadFileManagerImpl::CReadFileManagerImpl(const String& fileName)
    : ParentType{ fileName, SYSTEM_TEXT("rbS"s) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CReadFileManagerImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && InterfaceType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::CReadFileManagerImpl::GetFileByteSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(ParentType::GetFileLength());
}

void CoreTools::CReadFileManagerImpl::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

    Read(itemSize, 1, data);
}

void CoreTools::CReadFileManagerImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

    if (const auto readNumber = ReadFromFile(itemSize, itemsNumber, data); readNumber != itemsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("读入文件数据错误！"s))
    }

#ifdef SYSTEM_BIG_ENDIAN

    if (1 < itemSize)
    {
        Endian::SwapByteOrder(itemSize, itemsNumber, data);
    }

#endif  // SYSTEM_BIG_ENDIAN
}

size_t CoreTools::CReadFileManagerImpl::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    System::UnusedFunction(itemSize, itemsNumber, data);

    CORE_TOOLS_ASSERTION_4(false, "CReadFileManageImpl禁止调用WriteToFile！");

    return 0;
}

bool CoreTools::CReadFileManagerImpl::PutCharacter(int character) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    System::UnusedFunction(character);

    CORE_TOOLS_ASSERTION_4(false, "CReadFileManageImpl禁止调用PutCharacter！");

    return false;
}

bool CoreTools::CReadFileManagerImpl::PutString(const std::string& str) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    System::UnusedFunction(str);

    CORE_TOOLS_ASSERTION_4(false, "CReadFileManageImpl禁止调用PutString！");

    return false;
}
