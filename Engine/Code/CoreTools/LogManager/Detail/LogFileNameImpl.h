///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 15:24)

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
        explicit LogFileNameImpl(String fileName) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFileName() const;

    private:
        String fileName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_IMPL_H
