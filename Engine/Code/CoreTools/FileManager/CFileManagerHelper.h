///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 10:02)

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
        // 装载整个文件到一个缓冲区。
        NODISCARD static FileBuffer LoadFromFile(const String& fileName, bool binaryFile);

        NODISCARD static FileBuffer LoadFromFileUseEnvironment(const String& fileName, bool binaryFile);

        // 保存缓冲区到一个文件中。
        static void SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

        // 附加缓冲区到一个文件中。
        static void AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer);

        NODISCARD static std::string LoadFromFile(const std::string& fileName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_HELPER_H