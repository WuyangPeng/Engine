/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/01 10:50)

#include "CoreTools/CoreToolsExport.h"

#include "Environment.h"
#include "FileHandleHelper.h"
#include "Detail/ReadFileHandleImpl.h"
#include "Detail/WriteFileHandleImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

CoreTools::FileBuffer CoreTools::FileHandleHelper::LoadFromFile(const String& fileName)
{
    ReadFileHandleImpl handle{ fileName };

    const auto bufferSize = boost::numeric_cast<int>(handle.GetFileLength());
    FileBuffer buffer{ bufferSize };

    if (bufferSize == 0)
    {
        return buffer;
    }

    handle.ReadFromFile(sizeof(char), buffer.GetSize(), buffer.GetBufferBegin());

    return buffer;
}

void CoreTools::FileHandleHelper::SaveIntoFile(const String& fileName, int bufferSize, const char* buffer)
{
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

    WriteFileHandleImpl handle{ fileName };

    handle.WriteToFile(sizeof(char), bufferSize, buffer);
}

void CoreTools::FileHandleHelper::AppendToFile(const String& fileName, int bufferSize, const char* buffer)
{
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

    WriteFileHandleImpl handle{ fileName, System::FileHandleCreationDisposition::OpenAlways };

    handle.AppendToFile(sizeof(char), bufferSize, buffer);
}

CoreTools::FileBuffer CoreTools::FileHandleHelper::LoadFromFileUseEnvironment(const Environment& environment, const String& fileName)
{
    const auto fullFileName = environment.GetPathReading(fileName);

    return LoadFromFile(fullFileName);
}
