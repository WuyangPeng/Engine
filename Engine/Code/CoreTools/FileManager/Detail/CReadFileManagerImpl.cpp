/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/01 09:44)

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
        THROW_EXCEPTION(SYSTEM_TEXT("�����ļ����ݴ���"s))
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

    FunctionProhibitedFromCalling("CReadFileManageImpl��ֹ����WriteToFile��", itemSize, itemsNumber, data);

    return 0;
}

bool CoreTools::CReadFileManagerImpl::PutCharacter(int character) noexcept(gAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("CReadFileManageImpl��ֹ����PutCharacter��", character);

    return false;
}

bool CoreTools::CReadFileManagerImpl::PutString(const std::string& str) noexcept(gAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("CReadFileManageImpl��ֹ����PutString��", str);

    return false;
}
