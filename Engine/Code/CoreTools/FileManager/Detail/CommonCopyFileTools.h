//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 17:01)

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
        ReadFileManager m_InFile;
        WriteFileManager m_OutFile;
        BufferType m_Buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_COMMON_COPY_FILE_TOOLS_H
