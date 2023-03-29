///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:41)

#include "CoreTools/CoreToolsExport.h"

#include "Environment.h"
#include "FileHandleHelper.h"
#include "Detail/ReadFileHandleImpl.h"
#include "Detail/WriteFileHandleImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

// static
CoreTools::FileBuffer CoreTools::FileHandleHelper::LoadFromFile(const String& fileName)
{
    ReadFileHandleImpl handle{ fileName };

    const auto bufferSize = boost::numeric_cast<size_t>(handle.GetFileLength());
    FileBuffer buffer{ bufferSize };

    handle.ReadFromFile(sizeof(char), buffer.GetSize(), buffer.GetBufferBegin());

    return buffer;
}

// static
void CoreTools::FileHandleHelper::SaveIntoFile(const String& fileName, int bufferSize, const char* buffer)
{
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

    WriteFileHandleImpl handle{ fileName };

    handle.WriteToFile(sizeof(char), bufferSize, buffer);
}

// static
void CoreTools::FileHandleHelper::AppendToFile(const String& fileName, int bufferSize, const char* buffer)
{
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

    WriteFileHandleImpl handle{ fileName, System::FileHandleCreationDisposition::OpenAlways };

    handle.AppendToFile(sizeof(char), bufferSize, buffer);
}

CoreTools::FileBuffer CoreTools::FileHandleHelper::LoadFromFileUseEnvironment(const String& fileName)
{
    const auto fullFileName = ENVIRONMENT_SINGLETON.GetPathReading(fileName);

    return LoadFromFile(fullFileName);
}
