///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:51)

#include "CoreTools/CoreToolsExport.h"

#include "Environment.h"
#include "FileHandleHelper.h"
#include "Detail/ReadFileHandleImpl.h"
#include "Detail/WriteFileHandleImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

using boost::numeric_cast;

// static
const CoreTools::FileBuffer CoreTools::FileHandleHelper::LoadFromFile(const String& fileName)
{
    ReadFileHandleImpl handle{ fileName };

    auto bufferSize = boost::numeric_cast<size_t>(handle.GetFileLength());
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

const CoreTools::FileBuffer CoreTools::FileHandleHelper::LoadFromFileUseEnvironment(const String& fileName)
{
    auto fullFileName = ENVIRONMENT_SINGLETON.GetPathReading(fileName);

    return LoadFromFile(fullFileName);
}
