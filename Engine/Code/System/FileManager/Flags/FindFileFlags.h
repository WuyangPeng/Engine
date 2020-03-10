// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:52)

#ifndef SYSTEM_FILE_MANAGE_FIND_FILE_FLAGS_H
#define SYSTEM_FILE_MANAGE_FIND_FILE_FLAGS_H

#include "System/Helper/Platform.h"  

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class FileNotifyFilter 
	{	
		ChangeFileName = FILE_NOTIFY_CHANGE_FILE_NAME, 
		ChangeDirName = FILE_NOTIFY_CHANGE_DIR_NAME,
		ChangeAttributes = FILE_NOTIFY_CHANGE_ATTRIBUTES,
		ChangeSize = FILE_NOTIFY_CHANGE_SIZE,
		ChangeLastWrite = FILE_NOTIFY_CHANGE_LAST_WRITE,
		ChangeLastAccess = FILE_NOTIFY_CHANGE_LAST_ACCESS,
		ChangeCreation = FILE_NOTIFY_CHANGE_CREATION,
		ChangeSecurity = FILE_NOTIFY_CHANGE_SECURITY,
	};	
	
	enum class FindFirstFileAdditional 
	{	
		Default = 0x00000000,
		CaseSensitive = FIND_FIRST_EX_CASE_SENSITIVE,
		LargeFetch = FIND_FIRST_EX_LARGE_FETCH,      
	};		
	
#else // !SYSTEM_PLATFORM_WIN32

	enum class FileNotifyFilter 
	{	
		ChangeFileName = 0x00000001, 
		ChangeDirName = 0x00000002,  
		ChangeAttributes = 0x00000004,
		ChangeSize = 0x00000008,   
		ChangeLastWrite = 0x00000010,   
		ChangeLastAccess = 0x00000020,   
		ChangeCreation = 0x00000040,
		ChangeSecurity = 0x00000100,  
	};	

	enum class FindFirstFileAdditional 
	{	
		Default = 0x00000000,
		CaseSensitive = 0x00000001,
		LargeFetch = 0x00000002,      
	};
		
#endif // SYSTEM_PLATFORM_WIN32	 
}

#endif // SYSTEM_FILE_MANAGE_FIND_FILE_FLAGS_H
