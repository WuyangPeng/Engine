// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 14:20)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_HELP_H
#define CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_HELP_H

#include "CoreTools/CoreToolsDll.h"

#include "FileBuffer.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE FileManagerHelper
	{
	public:
		using ClassType = FileManagerHelper;
		using String = System::String;

	public:
		static const FileBuffer LoadFromFile(const String& fileName, bool binaryFile);

		static const FileBuffer LoadFromFileUseEnvironment(const String& fileName, bool binaryFile);

		// 保存缓冲区到一个文件中。
		static void SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

		// 附加缓冲区到一个文件中。
		static void AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_HELP_H
