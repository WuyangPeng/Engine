///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/18 11:30)

#ifndef CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_SUBCLASS_H
#define CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_SUBCLASS_H

#include "CoreTools/MessageEvent/EventInterface.h"

namespace CoreTools
{
    class EventSubclass final : public EventInterface
    {
    public:
        using ClassType = EventSubclass;
        using ParentType = EventInterface;

    public:
        explicit EventSubclass(int value) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool EventFunction(const CallbackParameters& callbackParameters) override;

        NODISCARD int GetValue() const noexcept;
        void SetValue(int aValue) noexcept;

    private:
        int value;
    };

    using EventSubclassSharedPtr = std::shared_ptr<EventSubclass>;
    using ConsEventSubclassSharedPtr = std::shared_ptr<const EventSubclass>;
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_SUBCLASS_H