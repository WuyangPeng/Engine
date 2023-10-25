///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:45)

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
