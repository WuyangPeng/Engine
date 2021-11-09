///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:51)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_HELPER_H
#define CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "FileBuffer.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FileManagerHelper final
    {
    public:
        using ClassType = FileManagerHelper;
        using String = System::String;

    public:
        NODISCARD static const FileBuffer LoadFromFile(const String& fileName, bool binaryFile);

        NODISCARD static const FileBuffer LoadFromFileUseEnvironment(const String& fileName, bool binaryFile);

        // ���滺������һ���ļ��С�
        static void SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

        // ���ӻ�������һ���ļ��С�
        static void AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

        NODISCARD static bool IsFileExists(const std::string& fileName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_HELPER_H
