//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:23)

#ifndef CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELP_H
#define CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELP_H

#include "CoreTools/CoreToolsDll.h"

#include "FileBuffer.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CFileManagerHelper final
    {
    public:
        using ClassType = CFileManagerHelper;
        using String = System::String;

    public:
        // װ�������ļ���һ����������
        [[nodiscard]] static const FileBuffer LoadFromFile(const String& fileName, bool binaryFile);

        [[nodiscard]] static const FileBuffer LoadFromFileUseEnvironment(const String& fileName, bool binaryFile);

        // ���滺������һ���ļ��С�
        static void SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

        // ���ӻ�������һ���ļ��С�
        static void AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELP_H