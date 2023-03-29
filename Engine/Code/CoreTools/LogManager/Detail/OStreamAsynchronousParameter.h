///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 17:34)

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
