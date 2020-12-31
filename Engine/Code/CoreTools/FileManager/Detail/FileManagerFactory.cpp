//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 12:55)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManagerImpl.h"
#include "CWriteFileManagerImpl.h"
#include "FileManagerFactory.h"
#include "ReadFileHandleImpl.h"
#include "WriteFileHandleImpl.h"

using std::make_shared;

CoreTools::FileManagerFactory::ReadFileManageInterfacePtr CoreTools::FileManagerFactory::CreateReadFileManage(const String& fileName)
{
#ifdef SYSTEM_PLATFORM_WIN32
    return make_shared<ReadFileHandleImpl>(fileName);
#else  // !SYSTEM_PLATFORM_WIN32
    return make_shared<CReadFileManagerImpl>(fileName);
#endif  // SYSTEM_PLATFORM_WIN32
}

CoreTools::FileManagerFactory::WriteFileManageInterfacePtr CoreTools::FileManagerFactory::CreateWriteFileManage(const String& fileName)
{
#ifdef SYSTEM_PLATFORM_WIN32
    return make_shared<WriteFileHandleImpl>(fileName);
#else  // !SYSTEM_PLATFORM_WIN32
    return make_shared<CWriteFileManagerImpl>(fileName);
#endif  // SYSTEM_PLATFORM_WIN32
}
