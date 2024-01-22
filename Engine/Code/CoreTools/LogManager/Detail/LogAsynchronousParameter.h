/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:36)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_PARAMETER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_PARAMETER_H

#include "CoreTools/CoreToolsDll.h"

#include "AsynchronousParameterBase.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/LogManager/LogMessage.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogAsynchronousParameter final : public AsynchronousParameterBase
    {
    public:
        using ClassType = LogAsynchronousParameter;
        using ParentType = AsynchronousParameterBase;

        using String = System::String;
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;

    public:
        LogAsynchronousParameter(LogMessage message, AppenderManagerSharedPtr appenderManager) noexcept;
        LogAsynchronousParameter(String fileName, LogMessage message, AppenderManagerSharedPtr appenderManager) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Write() override;

    private:
        String fileName;
        LogMessage message;
        AppenderManagerSharedPtr appenderManager;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_PARAMETER_H
