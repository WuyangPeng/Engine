///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 14:40)

#ifndef CORE_TOOLS_FILE_MANAGER_COMMON_COPY_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_COMMON_COPY_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "CopyFileToolsImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"

#include <string>
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
