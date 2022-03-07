///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 16:21)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogFileNameImpl final
    {
    public:
        using ClassType = LogFileNameImpl;
        using String = System::String;

    public:
        explicit LogFileNameImpl(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFileName() const;

    private:
        String fileName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_IMPL_H
