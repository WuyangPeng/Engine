// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 14:20)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_HELP_H
#define CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_HELP_H

#include "CoreTools/CoreToolsDll.h"

#include "FileBuffer.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE FileHandleHelper
	{
	public:
		using ClassType = FileHandleHelper;
		using String = System::String;

	public:
		// 装载整个文件到一个缓冲区。
		static const FileBuffer LoadFromFile(const String& fileName);

		static const FileBuffer LoadFromFileUseEnvironment(const String& fileName);

		// 保存缓冲区到一个文件中。
		static void SaveIntoFile(const String& fileName, int bufferSize, const char* buffer);

		// 附加缓冲区到一个文件中。
		static void AppendToFile(const String& fileName, int bufferSize, const char* buffer);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_HELP_H
