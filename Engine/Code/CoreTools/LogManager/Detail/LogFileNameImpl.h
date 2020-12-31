//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 11:04)

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

        [[nodiscard]] String GetFileName() const;

    private:
        String m_FileName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_IMPL_H
