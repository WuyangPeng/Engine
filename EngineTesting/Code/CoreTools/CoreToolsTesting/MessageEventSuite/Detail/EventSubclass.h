///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 16:00)

#ifndef CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_SUBCLASS_H
#define CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_SUBCLASS_H

#include "CoreTools/MessageEvent/EventInterface.h"

namespace CoreTools
{
    class EventSubclass : public EventInterface
    {
    public:
        using ClassType = EventSubclass;
        using ParentType = EventInterface;

    public:
        explicit EventSubclass(int value) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool EventFunction(const CallbackParameters& callbackParameters) override;

        NODISCARD int GetValue() const noexcept;
        void SetValue(int aValue) noexcept;

    private:
        int value;
    };

    using EventSubclassSharedPtr = std::shared_ptr<EventSubclass>;
    using ConsEventSubclassSharedPtr = std::shared_ptr<const EventSubclass>;
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_SUBCLASS_H