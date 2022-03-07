///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/09 1:41)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManagerImpl.h"
#include "CWriteFileManagerImpl.h"
#include "FileManagerFactory.h"
#include "ReadFileHandleImpl.h"
#include "WriteFileHandleImpl.h"
#include "System/FileManager/Flags/FileFlags.h"

using std::make_shared;

CoreTools::FileManagerFactory::ReadFileManagerSharedPtr CoreTools::FileManagerFactory::CreateReadFileManager(const String& fileName)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return make_shared<ReadFileHandleImpl>(fileName);

#else  // !SYSTEM_PLATFORM_WIN32

    return make_shared<CReadFileManagerImpl>(fileName);

#endif  // SYSTEM_PLATFORM_WIN32
}

CoreTools::FileManagerFactory::WriteFileManagerSharedPtr CoreTools::FileManagerFactory::CreateWriteFileManager(const String& fileName, bool addition)
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (addition)
    {
        return make_shared<WriteFileHandleImpl>(fileName, System::FileHandleCreationDisposition::OpenExisting);
    }
    else
    {
        return make_shared<WriteFileHandleImpl>(fileName);
    }

#else  // !SYSTEM_PLATFORM_WIN32

    return make_shared<CWriteFileManagerImpl>(fileName, addition);

#endif  // SYSTEM_PLATFORM_WIN32
}
