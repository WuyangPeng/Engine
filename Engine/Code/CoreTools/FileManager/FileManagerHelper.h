// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 14:20)

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

		// ���滺������һ���ļ��С�
		static void SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

		// ���ӻ�������һ���ļ��С�
		static void AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_HELP_H
