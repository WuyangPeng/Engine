/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:22)

#ifndef CORE_TOOLS_MESSAGE_EVENT_PARAMETERS_INTERFACE_H
#define CORE_TOOLS_MESSAGE_EVENT_PARAMETERS_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::ParametersInterface>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::ParametersInterface>;

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ParametersInterface : public std::enable_shared_from_this<ParametersInterface>
    {
    public:
        using ClassType = ParametersInterface;

        using BaseSharedPtr = std::shared_ptr<ClassType>;

    public:
        ParametersInterface() noexcept = default;
        virtual ~ParametersInterface() noexcept = default;
        ParametersInterface(const ParametersInterface& rhs) noexcept = default;
        ParametersInterface& operator=(const ParametersInterface& rhs) noexcept = default;
        ParametersInterface(ParametersInterface&& rhs) noexcept = default;
        ParametersInterface& operator=(ParametersInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual BaseSharedPtr Clone() const;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(ParametersInterface);
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_H
