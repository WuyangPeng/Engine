//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 15:30)

#ifndef CORE_TOOLS_MESSAGE_EVENT_PARAMETERS_INTERFACE_H
#define CORE_TOOLS_MESSAGE_EVENT_PARAMETERS_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "System/Helper/PragmaWarning.h"
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

        ParametersInterface() noexcept = default;
        virtual ~ParametersInterface() noexcept = default;
        ParametersInterface(const ParametersInterface& rhs) noexcept = default;
        ParametersInterface& operator=(const ParametersInterface& rhs) noexcept = default;
        ParametersInterface(ParametersInterface&& rhs) noexcept = default;
        ParametersInterface& operator=(ParametersInterface&& rhs) noexcept = default;

#include STSTEM_WARNING_POP

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual const BaseSharedPtr Clone() const;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(ParametersInterface);
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_H
