///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 13:38)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManagerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;
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

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "������Ч");

    Read(itemSize, 1, data);
}

void CoreTools::CReadFileManagerImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "������Ч");

    const auto readNumber = ReadFromFile(itemSize, itemsNumber, data);

    if (readNumber != itemsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ļ����ݴ���"s));
    }

#ifdef SYSTEM_BIG_ENDIAN
    if (1 < itemSize)
    {
        Endian::SwapByteOrder(itemSize, itemsNumber, data);
    }
#endif  // SYSTEM_BIG_ENDIAN
}

size_t CoreTools::CReadFileManagerImpl::WriteToFile(MAYBE_UNUSED size_t itemSize, MAYBE_UNUSED size_t itemsNumber, MAYBE_UNUSED const void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_4(false, "CReadFileManageImpl��ֹ����WriteToFile��");

    return 0;
}

bool CoreTools::CReadFileManagerImpl::PutCharacter(MAYBE_UNUSED int character) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_4(false, "CReadFileManageImpl��ֹ����PutCharacter��");

    return false;
}

bool CoreTools::CReadFileManagerImpl::PutString(MAYBE_UNUSED const string& str) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_4(false, "CReadFileManageImpl��ֹ����PutString��");

    return false;
}
