///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:24)

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
