///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:47)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerHelper.h"
#include "FileHandleHelper.h"
#include "FileManagerHelper.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <fstream>

using std::ifstream;
using std::string;

// static
const CoreTools::FileBuffer CoreTools::FileManagerHelper::LoadFromFile(const String& fileName, bool binaryFile)
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (binaryFile)
        return FileHandleHelper::LoadFromFile(fileName);
    else
        return CFileManagerHelper::LoadFromFile(fileName, binaryFile);

#else  // !SYSTEM_PLATFORM_WIN32

    return CFileManagerHelper::LoadFromFile(fileName, binaryFile);

#endif  // SYSTEM_PLATFORM_WIN32
}

// static
void CoreTools::FileManagerHelper::SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer)
{
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

#ifdef SYSTEM_PLATFORM_WIN32

    if (binaryFile)
        return FileHandleHelper::SaveIntoFile(fileName, bufferSize, buffer);
    else
        return CFileManagerHelper::SaveIntoFile(fileName, binaryFile, bufferSize, buffer);

#else  // !SYSTEM_PLATFORM_WIN32

    return CFileManagerHelper::SaveIntoFile(fileName, binaryFile, bufferSize, buffer);

#endif  // SYSTEM_PLATFORM_WIN32
}

// static
void CoreTools::FileManagerHelper::AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer)
{
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

#ifdef SYSTEM_PLATFORM_WIN32

    if (binaryFile)
        return FileHandleHelper::AppendToFile(fileName, bufferSize, buffer);
    else
        return CFileManagerHelper::AppendToFile(fileName, binaryFile, bufferSize, buffer);

#else  // !SYSTEM_PLATFORM_WIN32

    return CFileManagerHelper::AppendToFile(fileName, binaryFile, bufferSize, buffer);

#endif  // SYSTEM_PLATFORM_WIN32
}

const CoreTools::FileBuffer CoreTools::FileManagerHelper::LoadFromFileUseEnvironment(const String& fileName, bool binaryFile)
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (binaryFile)
        return FileHandleHelper::LoadFromFileUseEnvironment(fileName);
    else
        return CFileManagerHelper::LoadFromFileUseEnvironment(fileName, binaryFile);

#else  // !SYSTEM_PLATFORM_WIN32

    return CFileManagerHelper::LoadFromFileUseEnvironment(fileName, binaryFile);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool CoreTools::FileManagerHelper::IsFileExists(const string& fileName)
{
    ifstream fstream{ fileName };

    return fstream.good();
}
