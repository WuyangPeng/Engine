// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 15:23)

#include "CoreTools/CoreToolsExport.h"

#include "FileManagerFactory.h"
#include "ReadFileHandleImpl.h"
#include "WriteFileHandleImpl.h"
#include "CReadFileManagerImpl.h"
#include "CWriteFileManagerImpl.h"

using std::make_shared;

CoreTools::FileManagerFactory::ReadFileManageInterfacePtr CoreTools::FileManagerFactory
	::CreateReadFileManage(const String& fileName)
{
#ifdef SYSTEM_PLATFORM_WIN32
	return make_shared<ReadFileHandleImpl>(fileName);
#else // !SYSTEM_PLATFORM_WIN32
	return make_shared<CReadFileManagerImpl>(fileName);
#endif // SYSTEM_PLATFORM_WIN32	
}

CoreTools::FileManagerFactory::WriteFileManageInterfacePtr CoreTools::FileManagerFactory
	::CreateWriteFileManage(const String& fileName)
{
#ifdef SYSTEM_PLATFORM_WIN32
	return make_shared<WriteFileHandleImpl>(fileName);
#else // !SYSTEM_PLATFORM_WIN32
	return make_shared<CWriteFileManagerImpl>(fileName);
#endif // SYSTEM_PLATFORM_WIN32	
}
