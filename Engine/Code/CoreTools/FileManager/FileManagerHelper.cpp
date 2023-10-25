///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/22 14:11)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerHelper.h"
#include "FileHandleHelper.h"
#include "FileManagerHelper.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <fstream>

CoreTools::FileBuffer CoreTools::FileManagerHelper::LoadFromFile(const String& fileName, bool binaryFile)
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

CoreTools::FileBuffer CoreTools::FileManagerHelper::LoadFromFileUseEnvironment(const String& fileName, bool binaryFile)
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

bool CoreTools::FileManagerHelper::IsFileExists(const std::string& fileName)
{
    const std::ifstream stream{ fileName };

    return stream.good();
}
