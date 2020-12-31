//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:39)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerHelper.h"
#include "FileHandleHelper.h"
#include "FileManagerHelper.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

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
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "传入的指针为空！");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "传入的缓冲区大小小于或等于零！");

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
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "传入的指针为空！");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "传入的缓冲区大小小于或等于零！");

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
