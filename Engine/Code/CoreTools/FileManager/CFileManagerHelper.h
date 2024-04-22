/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:52)

#ifndef CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELPER_H
#define CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "Environment.h"
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
        /// װ�������ļ���һ����������
        NODISCARD static FileBuffer LoadFromFile(const String& fileName, bool binaryFile);

        NODISCARD static FileBuffer LoadFromFileUseEnvironment(const Environment& environment, const String& fileName, bool binaryFile);

        /// ���滺������һ���ļ��С�
        static void SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

        /// ���ӻ�������һ���ļ��С�
        static void AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

        NODISCARD static std::string LoadFromFile(const std::string& fileName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELPER_H