/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 13:51)

#ifndef CORE_TOOLS_LOG_MANAGER_O_STREAM_ASYNCHRONOUS_PARAMETER_H
#define CORE_TOOLS_LOG_MANAGER_O_STREAM_ASYNCHRONOUS_PARAMETER_H

#include "CoreTools/CoreToolsDll.h"

#include "AsynchronousParameterBase.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OStreamAsynchronousParameter final : public AsynchronousParameterBase
    {
    public:
        using ClassType = OStreamAsynchronousParameter;
        using ParentType = AsynchronousParameterBase;

    public:
        OStreamAsynchronousParameter(OStreamShared streamShared, std::string message, LogLevel logLevel) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Write() override;

    private:
        OStreamShared streamShared;
        std::string message;
        LogLevel logLevel;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_O_STREAM_ASYNCHRONOUS_PARAMETER_H
