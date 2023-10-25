///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/22 11:31)

#ifndef CORE_TOOLS_FILE_MANAGER_COMMON_COPY_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_COMMON_COPY_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "CopyFileToolsImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"

#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CommonCopyFileTools final : public CopyFileToolsImpl
    {
    public:
        using ClassType = CommonCopyFileTools;
        using ParentType = CopyFileToolsImpl;

    public:
        CommonCopyFileTools(const String& inFileName, const String& outFileName);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using BufferType = std::vector<char>;

    private:
        ReadFileManager inFile;
        WriteFileManager outFile;
        BufferType buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_COMMON_COPY_FILE_TOOLS_H
