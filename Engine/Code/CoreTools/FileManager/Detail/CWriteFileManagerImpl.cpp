/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/01 09:46)

#include "CoreTools/CoreToolsExport.h"

#include "CWriteFileManagerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/Tools.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <vector>

CoreTools::CWriteFileManagerImpl::CWriteFileManagerImpl(const String& fileName, bool addition)
    : ParentType{ fileName, addition ? SYSTEM_TEXT("abS") : SYSTEM_TEXT("wbS") }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CWriteFileManagerImpl::IsValid() const noexcept
{
    return ParentType::IsValid() && InterfaceType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::CWriteFileManagerImpl::GetFileByteSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ParentType::GetFileLength();
}

void CoreTools::CWriteFileManagerImpl::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    Write(itemSize, 1, data);
}

void CoreTools::CWriteFileManagerImpl::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#ifdef SYSTEM_BIG_ENDIAN

    const auto writeNumber = WriteToFileWithBigEndian(itemSize, itemsNumber, data);

#else  // !SYSTEM_BIG_ENDIAN

    const auto writeNumber = WriteToFile(itemSize, itemsNumber, data);

#endif  // SYSTEM_BIG_ENDIAN

    if (writeNumber != itemsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ļ����ݴ���"s))
    }
}

#ifdef SYSTEM_BIG_ENDIAN

size_t CoreTools::CWriteFileManagerImpl::WriteToFileWithBigEndian(size_t itemSize, size_t itemsNumber, const void* data)
{
    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "������Ч");

    switch (itemSize)
    {
        case 2:
            return WriteToFileSwap2ByteOrder(itemsNumber, data);
        case 4:
            return WriteToFileSwap4ByteOrder(itemsNumber, data);
        case 8:
            return WriteToFileSwap8ByteOrder(itemsNumber, data);
        default:
            return WriteToFile(itemSize, itemsNumber, data);
    }
}

size_t CoreTools::CWriteFileManagerImpl::WriteToFileSwap2ByteOrder(size_t itemsNumber, const void* data)
{
    std::vector<uint16_t> target(itemsNumber);
    auto bytes = static_cast<const uint16_t*>(data);

    Endian::Swap2ByteOrderToTarget(boost::numeric_cast<int>(itemsNumber), bytes, target.data());

    return WriteToFile(sizeof(uint16_t), itemsNumber, target.data());
}

size_t CoreTools::CWriteFileManagerImpl::WriteToFileSwap4ByteOrder(size_t itemsNumber, const void* data)
{
    std::vector<uint32_t> target(itemsNumber);
    auto bytes = static_cast<const uint32_t*>(data);

    Endian::Swap4ByteOrderToTarget(boost::numeric_cast<int>(itemsNumber), bytes, target.data());

    return WriteToFile(sizeof(uint32_t), itemsNumber, target.data());
}

size_t CoreTools::CWriteFileManagerImpl::WriteToFileSwap8ByteOrder(size_t itemsNumber, const void* data)
{
    std::vector<uint64_t> target(itemsNumber);
    auto bytes = static_cast<const uint64_t*>(data);

    Endian::Swap8ByteOrderToTarget(boost::numeric_cast<int>(itemsNumber), bytes, target.data());

    return WriteToFile(sizeof(uint64_t), itemsNumber, target.data());
}

#endif  // SYSTEM_BIG_ENDIAN

size_t CoreTools::CWriteFileManagerImpl::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("CWriteFileManageImpl��ֹ����ReadFromFile��", itemSize, itemsNumber, data);

    return 0;
}

int CoreTools::CWriteFileManagerImpl::GetCharacter() noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("CWriteFileManageImpl��ֹ����GetCharacter��");

    return System::gCFileError;
}

bool CoreTools::CWriteFileManagerImpl::UnGetCharacter(int character) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("CWriteFileManageImpl��ֹ����UnGetCharacter��", character);

    return false;
}

std::string CoreTools::CWriteFileManagerImpl::GetString(int count) noexcept(gAssert < 4 || gCoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    FunctionProhibitedFromCalling("CWriteFileManageImpl��ֹ����GetString��", count);

    return std::string{};
}
