///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:45)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerImpl.h"
#include "System/FileManager/CFile.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

CoreTools::CFileManagerImpl::CFileManagerImpl(const String& fileName, const String& mode)
    : file{ nullptr }, fileName{ fileName }, mode{ mode }
{
    Open();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
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

// private
void CoreTools::CFileManagerImpl::Close() noexcept
{
    if (!System::CloseCFile(file))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("�ر��ļ�")
            << fileName
            << SYSTEM_TEXT("ʧ�ܣ�")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CFileManagerImpl::IsValid() const noexcept
{
    if (file != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

size_t CoreTools::CFileManagerImpl::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
    CORE_TOOLS_ASSERTION_0(0u < itemsNumber && data != nullptr, "׼��д���������Ч��");

    return System::ReadCFile(data, itemSize, itemsNumber, file);
}

size_t CoreTools::CFileManagerImpl::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ1��2��4��8\n");
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

    CoreTools::DisableNoexcept();

    return System::GetCharacter(file);
}

bool CoreTools::CFileManagerImpl::UnGetCharacter(int character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return System::UnGetCharacter(file, character);
}

bool CoreTools::CFileManagerImpl::PutCharacter(int character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return System::PutCharacter(file, character);
}

bool CoreTools::CFileManagerImpl::PutString(const string& str)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return System::PutString(file, str.c_str());
}

string CoreTools::CFileManagerImpl::GetString(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::GetString(file, count);
}

bool CoreTools::CFileManagerImpl::IsEOF() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::IsEOF(file);
}

bool CoreTools::CFileManagerImpl::Flush() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Flush(file);
}

bool CoreTools::CFileManagerImpl::Seek(long offset, FileSeek whence) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Seek(file, offset, whence);
}

CoreTools::CFileManagerImpl::PosType CoreTools::CFileManagerImpl::GetPosition()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto position = System::GetPosition(file);

    constexpr PosType errorPosition{ -1 };

    if (position != errorPosition)
    {
        return position;
    }
    else
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("��ȡ�ļ���%1%����λ��ʧ�ܣ�"s)) % fileName).str());
    }
}

bool CoreTools::CFileManagerImpl::SetPosition(PosType position) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::SetPosition(file, position);
}

long CoreTools::CFileManagerImpl::Tell() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Tell(file);
}

void CoreTools::CFileManagerImpl::Rewind() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Rewind(file);
}

bool CoreTools::CFileManagerImpl::Setvbuf(FileSetvBuf type, size_t size) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::SetvBuf(file, type, size);
}
