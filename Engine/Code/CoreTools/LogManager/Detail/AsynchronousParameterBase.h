///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 17:14)

#ifndef CORE_TOOLS_LOG_MANAGER_ASYNCHRONOUS_PARAMETER_BASE_H
#define CORE_TOOLS_LOG_MANAGER_ASYNCHRONOUS_PARAMETER_BASE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AsynchronousParameterBase
    {
    public:
        using ClassType = AsynchronousParameterBase;

    public:
        AsynchronousParameterBase() noexcept = default;
        virtual ~AsynchronousParameterBase() noexcept = default;
        AsynchronousParameterBase(const AsynchronousParameterBase& rhs) noexcept = default;
        AsynchronousParameterBase& operator=(const AsynchronousParameterBase& rhs) noexcept = default;
        AsynchronousParameterBase(AsynchronousParameterBase&& rhs) noexcept = default;
        AsynchronousParameterBase& operator=(AsynchronousParameterBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Write() = 0;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_ASYNCHRONOUS_PARAMETER_BASE_H