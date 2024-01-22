/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:03)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManagerImpl.h"
#include "CWriteFileManagerImpl.h"
#include "FileManagerFactory.h"
#include "ReadFileHandleImpl.h"
#include "WriteFileHandleImpl.h"
#include "System/FileManager/Flags/FileFlags.h"

CoreTools::FileManagerFactory::ReadFileManagerSharedPtr CoreTools::FileManagerFactory::CreateReadFileManager(const String& fileName)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return std::make_shared<ReadFileHandleImpl>(fileName);

#else  // !SYSTEM_PLATFORM_WIN32

    return std::make_shared<CReadFileManagerImpl>(fileName);

#endif  // SYSTEM_PLATFORM_WIN32
}

CoreTools::FileManagerFactory::WriteFileManagerSharedPtr CoreTools::FileManagerFactory::CreateWriteFileManager(const String& fileName, bool addition)
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (addition)
    {
        return std::make_shared<WriteFileHandleImpl>(fileName, System::FileHandleCreationDisposition::OpenExisting);
    }
    else
    {
        return std::make_shared<WriteFileHandleImpl>(fileName);
    }

#else  // !SYSTEM_PLATFORM_WIN32

    return std::make_shared<CWriteFileManagerImpl>(fileName, addition);

#endif  // SYSTEM_PLATFORM_WIN32
}
