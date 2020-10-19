//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 11:47)

// ��־��Ϣǰ׺���ⲿ�ӿ�
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LogMessagePrefixImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogMessagePrefix final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(LogMessagePrefix);
        using String = System::String;

    public:
        LogMessagePrefix(AppenderPrint appenderFlags, LogLevel level, LogFilter filter);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] String GetPrefix() const;
        [[nodiscard]] int GetPrefixSize() const;

    private:
        IMPL_TYPE_DECLARE(LogMessagePrefix);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H
