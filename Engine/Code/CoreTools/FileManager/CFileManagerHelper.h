///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:34)

#ifndef CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELPER_H
#define CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELPER_H

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
        NODISCARD static const FileBuffer LoadFromFile(const String& fileName, bool binaryFile);

        NODISCARD static const FileBuffer LoadFromFileUseEnvironment(const String& fileName, bool binaryFile);

        // ���滺������һ���ļ��С�
        static void SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

        // ���ӻ�������һ���ļ��С�
        static void AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELPER_H