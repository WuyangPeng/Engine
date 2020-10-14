//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 10:05)

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
    : m_File{ nullptr }, m_FileName{ fileName }, m_Mode{ mode }
{
    Open();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::CFileManagerImpl::Open()
{
    if (!System::OpenCFile(m_File, StringConversion::StandardConversionCFileString(m_FileName), StringConversion::StandardConversionCFileString(m_Mode)))
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("打开文件“%1%”失败！"s)) % m_FileName).str());
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
    if (!System::CloseCFile(m_File))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("关闭文件")
            << m_FileName
            << SYSTEM_TEXT("失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CFileManagerImpl::IsValid() const noexcept
{
    if (m_File != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

size_t CoreTools::CFileManagerImpl::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(0u < itemsNumber && data != nullptr, "准备写入的数据无效！");

    return System::ReadCFile(data, itemSize, itemsNumber, m_File);
}

size_t CoreTools::CFileManagerImpl::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(0u < itemsNumber && data != nullptr, "准备读取的数据无效！");

    return System::WriteCFile(data, itemSize, itemsNumber, m_File);
}

CoreTools::CFileManagerImpl::OffType CoreTools::CFileManagerImpl::GetFileLength() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    OffType length{ 0 };
    if (!System::GetFileLength(m_FileName, &length))
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("文件“%1%”不存在！"s)) % m_FileName).str());
    }

    return length;
}

int CoreTools::CFileManagerImpl::GetCharacter()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return System::GetCharacter(m_File);
}

bool CoreTools::CFileManagerImpl::UnGetCharacter(int character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return System::UnGetCharacter(m_File, character);
}

bool CoreTools::CFileManagerImpl::PutCharacter(int character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return System::PutCharacter(m_File, character);
}

bool CoreTools::CFileManagerImpl::PutString(const string& str)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return System::PutString(m_File, str.c_str());
}

string CoreTools::CFileManagerImpl::GetString(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::GetString(m_File, count);
}

bool CoreTools::CFileManagerImpl::IsEOF() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::IsEOF(m_File);
}

bool CoreTools::CFileManagerImpl::Flush() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Flush(m_File);
}

bool CoreTools::CFileManagerImpl::Seek(long offset, FileSeek whence) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Seek(m_File, offset, whence);
}

CoreTools::CFileManagerImpl::PosType CoreTools::CFileManagerImpl::GetPosition()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto position = System::GetPosition(m_File);

    constexpr PosType errorPosition{ -1 };

    if (position != errorPosition)
    {
        return position;
    }
    else
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("获取文件“%1%”的位置失败！"s)) % m_FileName).str());
    }
}

bool CoreTools::CFileManagerImpl::SetPosition(PosType position) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::SetPosition(m_File, position);
}

long CoreTools::CFileManagerImpl::Tell() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Tell(m_File);
}

void CoreTools::CFileManagerImpl::Rewind() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::Rewind(m_File);
}

bool CoreTools::CFileManagerImpl::Setvbuf(FileSetvBuf type, size_t size) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return System::SetvBuf(m_File, type, size);
}
