//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:28)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_HELP_H
#define CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_HELP_H

#include "CoreTools/CoreToolsDll.h"

#include "FileBuffer.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FileHandleHelper final
    {
    public:
        using ClassType = FileHandleHelper;
        using String = System::String;

    public:
        // װ�������ļ���һ����������
        [[nodiscard]] static const FileBuffer LoadFromFile(const String& fileName);

        [[nodiscard]] static const FileBuffer LoadFromFileUseEnvironment(const String& fileName);

        // ���滺������һ���ļ��С�
        static void SaveIntoFile(const String& fileName, int bufferSize, const char* buffer);

        // ���ӻ�������һ���ļ��С�
        static void AppendToFile(const String& fileName, int bufferSize, const char* buffer);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_HELP_H
