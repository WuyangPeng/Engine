//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/14 13:45)

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

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "������Ч");

    Read(itemSize, 1, data);
}

void CoreTools::ReadFileHandleImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "������Ч");

    ReadFromFile(itemSize, itemsNumber, data);
}

void CoreTools::ReadFileHandleImpl::WriteToFile([[maybe_unused]] size_t itemSize, [[maybe_unused]] size_t itemsNumber, [[maybe_unused]] const void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_4(false, "ReadFileHandleImpl��ֹ����WriteToFile��");
}

void CoreTools::ReadFileHandleImpl::AppendToFile([[maybe_unused]] size_t itemSize, [[maybe_unused]] size_t itemsNumber, [[maybe_unused]] const void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_4(false, "ReadFileHandleImpl��ֹ����AppendToFile��");
}
