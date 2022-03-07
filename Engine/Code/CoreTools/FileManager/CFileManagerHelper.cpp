///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:44)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerHelper.h"
#include "Environment.h"
#include "Detail/CFileManagerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

// static
const CoreTools::FileBuffer CoreTools::CFileManagerHelper::LoadFromFile(const String& fileName, bool binaryFile)
{
    const auto mode = binaryFile ? SYSTEM_TEXT("rb"s) : SYSTEM_TEXT("rt"s);

    CFileManagerImpl manager{ fileName, mode };

    const auto bufferSize = boost::numeric_cast<size_t>(manager.GetFileLength());
    FileBuffer buffer{ bufferSize };

    const auto result = manager.ReadFromFile(sizeof(char), buffer.GetSize(), buffer.GetBufferBegin());
    if (result != bufferSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ���ļ���С��һ�£�"s));
    }

    return buffer;
}

// static
void CoreTools::CFileManagerHelper::SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer)
{
    // ���뻺����������ڡ���֤�û���������ָ�����ֽ����ǲ����ܵġ�
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

    const auto mode = binaryFile ? SYSTEM_TEXT("wb"s) : SYSTEM_TEXT("wt"s);

    CFileManagerImpl manager{ fileName, mode };

    const auto result = manager.WriteToFile(sizeof(char), bufferSize, buffer);

    if (result != boost::numeric_cast<size_t>(bufferSize))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("д����ļ���С��һ�£�"s));
    }
}

// static
void CoreTools::CFileManagerHelper::AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer)
{
    // ���뻺����������ڡ���֤�û���������ָ�����ֽ����ǲ����ܵġ�
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

    const auto mode = binaryFile ? SYSTEM_TEXT("ab"s) : SYSTEM_TEXT("at"s);

    CFileManagerImpl manager{ fileName, mode };

    const auto result = manager.WriteToFile(sizeof(char), bufferSize, buffer);

    if (result != boost::numeric_cast<size_t>(bufferSize))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("д����ļ���С��һ�£�"s));
    }
}

const CoreTools::FileBuffer CoreTools::CFileManagerHelper::LoadFromFileUseEnvironment(const String& fileName, bool binaryFile)
{
    auto fullFileName = ENVIRONMENT_SINGLETON.GetPathReading(fileName);

    return LoadFromFile(fullFileName, binaryFile);
}
