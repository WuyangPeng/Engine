/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 23:27)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerImpl.h"
#include "CheckItemSize.h"
#include "System/FileManager/CFile.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::CFileManagerImpl::CFileManagerImpl(const String& fileName, const String& mode)
    : file{ nullptr }, fileName{ fileName }, mode{ mode }
{
    Open();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::CFileManagerImpl::Open()
{
    if (!System::OpenCFile(file, StringConversion::StandardConversionCFileString(fileName), StringConversion::StandardConversionCFileString(mode)))
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("���ļ���%1%��ʧ�ܣ�"s)) % fileName).str());
    }
}

CoreTools::CFileManagerImpl::~CFileManagerImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    Close();
}

void CoreTools::CFileManagerImpl::Close() const noexcept
{
    if (!System::CloseCFile(file))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("�ر��ļ�"), fileName, SYSTEM_TEXT("ʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CFileManagerImpl::IsValid() const noexcept
{
    return file != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

size_t CoreTools::CFileManagerImpl::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(0u < itemsNumber && data != nullptr, "׼��д���������Ч��");

    return System::ReadCFile(data, itemSize, itemsNumber, file);
}

size_t CoreTools::CFileManagerImpl::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(0u < itemsNumber && data != nullptr, "׼����ȡ��������Ч��");

    return System::WriteCFile(data, itemSize, itemsNumber, file);
}

CoreTools::CFileManagerImpl::OffType CoreTools::CFileManagerImpl::GetFileLength() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    OffType length{ 0 };
    if (!System::GetFileLength(fileName, &length))
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("�ļ���%1%�������ڣ�"s)) % fileName).str());
    }

    return length;
}

int CoreTools::CFileManagerImpl::GetCharacter()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    DisableNoexcept();

    return System::GetCharacter(file);
}

bool CoreTools::CFileManagerImpl::UnGetCharacter(int character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    DisableNoexcept();

    return System::UnGetCharacter(file, character);
}

bool CoreTools::CFileManagerImpl::PutCharacter(int character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    DisableNoexcept();

    return System::PutCharacter(file, character);
}

bool CoreTools::CFileManagerImpl::PutString(const std::string& str)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    DisableNoexcept();

    return System::PutString(file, str.c_str());
}

std::string CoreTools::CFileManagerImpl::GetString(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::GetString(file, count);
}

bool CoreTools::CFileManagerImpl::IsEof() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::IsEof(file);
}

bool CoreTools::CFileManagerImpl::Flush() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Flush(file);
}

bool CoreTools::CFileManagerImpl::Seek(long offset, FileSeek whence) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Seek(file, offset, whence);
}

CoreTools::CFileManagerImpl::PosType CoreTools::CFileManagerImpl::GetPosition() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    constexpr PosType errorPosition{ -1 };

    if (const auto position = System::GetPosition(file);

#if !defined(TCRE_USE_GCC)

        position != errorPosition)

#else  // defined(TCRE_USE_GCC)

        memcmp(&position, &errorPosition, sizeof(PosType)) != 0)

#endif  // !defined(TCRE_USE_GCC)

    {
        return position;
    }
    else
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("��ȡ�ļ���%1%����λ��ʧ�ܣ�"s)) % fileName).str())
    }
}

bool CoreTools::CFileManagerImpl::SetPosition(PosType position) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::SetPosition(file, position);
}

long CoreTools::CFileManagerImpl::Tell() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Tell(file);
}

bool CoreTools::CFileManagerImpl::SetVBuffer(FileSetVBuffer type, size_t size) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::SetVBuffer(file, type, size);
}
