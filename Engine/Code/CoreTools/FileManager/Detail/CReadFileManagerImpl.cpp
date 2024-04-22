/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 09:44)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManagerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::CReadFileManagerImpl::CReadFileManagerImpl(const String& fileName)
    : ParentType{ fileName, SYSTEM_TEXT("rbS") }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CReadFileManagerImpl::IsValid() const noexcept
{
    return ParentType::IsValid() && InterfaceType::IsValid();
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

    Read(itemSize, 1, data);
}

void CoreTools::CReadFileManagerImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (const auto readNumber = ReadFromFile(itemSize, itemsNumber, data);
        readNumber != itemsNumber)
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

size_t CoreTools::CReadFileManagerImpl::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("CReadFileManageImpl禁止调用WriteToFile！", itemSize, itemsNumber, data);

    return 0;
}

bool CoreTools::CReadFileManagerImpl::PutCharacter(int character) noexcept(gAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("CReadFileManageImpl禁止调用PutCharacter！", character);

    return false;
}

bool CoreTools::CReadFileManagerImpl::PutString(const std::string& str) noexcept(gAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("CReadFileManageImpl禁止调用PutString！", str);

    return false;
}
