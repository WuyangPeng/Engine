/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 09:49)

#ifndef CORE_TOOLS_MESSAGE_EVENT_EVENT_INTERFACE_H
#define CORE_TOOLS_MESSAGE_EVENT_EVENT_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::EventInterface>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::EventInterface>;

namespace CoreTools
{
    // ���ֻ��Ҫһ���ص�����������̳�EventFunction��
    // �����Ҫ����ص������������ض���using CallbackMemberFunction = bool (ClassType::*)(const CallbackParameters& callbackParameters);
    // �ٶ���������EventFunction�ĺ�����
    class CORE_TOOLS_DEFAULT_DECLARE EventInterface : public std::enable_shared_from_this<EventInterface>
    {
    public:
        using ClassType = EventInterface;

        using CallbackMemberFunction = bool (ClassType::*)(const CallbackParameters& callbackParameters);

    public:
        EventInterface() noexcept = default;
        virtual ~EventInterface() noexcept = default;
        EventInterface(const EventInterface& rhs) noexcept = default;
        EventInterface& operator=(const EventInterface& rhs) noexcept = default;
        EventInterface(EventInterface&& rhs) noexcept = default;
        EventInterface& operator=(EventInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual bool EventFunction(const CallbackParameters& callbackParameters) = 0;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(EventInterface);
    CORE_TOOLS_WEAK_PTR_DECLARE(EventInterface);
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_EVENT_INTERFACE_H
