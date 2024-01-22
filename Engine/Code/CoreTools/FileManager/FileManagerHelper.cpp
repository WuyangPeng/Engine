/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:09)

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

CoreTools::FileBuffer CoreTools::FileManagerHelper::LoadFromFileUseEnvironment(const Environment& environment, const String& fileName, bool binaryFile)
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (binaryFile)
        return FileHandleHelper::LoadFromFileUseEnvironment(environment, fileName);
    else
        return CFileManagerHelper::LoadFromFileUseEnvironment(environment, fileName, binaryFile);

#else  // !SYSTEM_PLATFORM_WIN32

    return CFileManagerHelper::LoadFromFileUseEnvironment(environment, fileName, binaryFile);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool CoreTools::FileManagerHelper::IsFileExists(const std::string& fileName)
{
    const std::ifstream stream{ fileName };

    return stream.good();
}
