/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:03)

#include "CoreTools/CoreToolsExport.h"

#include "FileHandleImpl.h"
#include "System/FileManager/File.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::FileHandleImpl::FileHandleImpl(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation)
    : fileName{ fileName }, file{ System::CreateSystemFile(fileName, access, shareMode, creation) }
{
    if (!System::IsFileHandleValid(file))
    {
        THROW_EXCEPTION((Error::Format{ SYSTEM_TEXT("���ļ���%1%��ʧ�ܣ�"s) } % fileName).str())
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::FileHandleImpl::~FileHandleImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    if (!System::CloseSystemFile(file))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("�ر��ļ�"), fileName, SYSTEM_TEXT("ʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::FileHandleImpl::IsValid() const noexcept
{
    if (System::IsFileHandleValid(file))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

uint64_t CoreTools::FileHandleImpl::GetFileLength() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (uint64_t size{}; System::GetFileLength(file, size))
    {
        return size;
    }
    else
    {
        THROW_WINDOWS_EXCEPTION
    }
}

void CoreTools::FileHandleImpl::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "׼��д���������Ч��");

    System::WindowsDWord in{ 0 };

    if (const auto readNumber = boost::numeric_cast<System::WindowsDWord>(itemSize * itemsNumber);
        !System::ReadSystemFile(file, data, readNumber, &in) || in != readNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ļ����ݴ���"s))
    }
}

void CoreTools::FileHandleImpl::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "׼����ȡ��������Ч��");

    System::WindowsDWord out{ 0 };

    if (const auto writeNumber = boost::numeric_cast<System::WindowsDWord>(itemSize * itemsNumber);
        !System::WriteSystemFile(file, data, writeNumber, &out) || out != writeNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����д���ļ�����"s))
    }
}

void CoreTools::FileHandleImpl::AppendToFile(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "׼����ȡ��������Ч��");

    System::WindowsDWord out{ 0 };

    if (const auto writeNumber = boost::numeric_cast<System::WindowsDWord>(itemSize * itemsNumber);
        !System::AppendSystemFile(file, data, writeNumber, &out) || out != writeNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����д���ļ�����"s))
    }
}
