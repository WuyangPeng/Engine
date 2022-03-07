///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/06 21:37)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_PARAMETER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_PARAMETER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/LogManager/LogMessage.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogAsynchronousParameter
    {
    public:
        using ClassType = LogAsynchronousParameter;
        using String = System::String;
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;
        using AppenderManagerWeakPtr = std::weak_ptr<AppenderManager>;

    public:
        LogAsynchronousParameter(const LogMessage& message, const AppenderManagerSharedPtr& appenderManager) noexcept;
        LogAsynchronousParameter(const String& fileName, const LogMessage& message, const AppenderManagerSharedPtr& appenderManager);

        CLASS_INVARIANT_DECLARE;

        void Write() const;

    private:
        String fileName;
        LogMessage message;
        AppenderManagerWeakPtr appenderManager;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_PARAMETER_H
