// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.3 (2020/03/06 18:58)

#ifndef CORE_TOOLS_MESSAGE_EVENT_SUITE_ENTITY_H
#define CORE_TOOLS_MESSAGE_EVENT_SUITE_ENTITY_H

#include "CoreTools/MessageEvent/EventEntityDetail.h"

namespace CoreTools
{
    class Entity : public EventEntity<>
    {
    public:
        using ClassType = Entity;
        using ParentType = EventEntity<>;

    public:
        Entity();
        Entity(int value);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool EventFunction(const Telegram& telegram) override;

        int GetValue() const noexcept;

    private:
        int m_Value;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_SUITE_PARAMETERS_H