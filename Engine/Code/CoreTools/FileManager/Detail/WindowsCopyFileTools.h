///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:38)

#ifndef CORE_TOOLS_FILE_MANAGER_WINDOWS_COPY_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_WINDOWS_COPY_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "CopyFileToolsImpl.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WindowsCopyFileTools final : public CopyFileToolsImpl
    {
    public:
        using ClassType = WindowsCopyFileTools;
        using ParentType = CopyFileToolsImpl;

    public:
        WindowsCopyFileTools(const String& inFileName, const String& outFileName);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        String inFileName;
        String outFileName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WINDOWS_COPY_FILE_TOOLS_H
