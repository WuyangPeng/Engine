///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 15:28)

#ifndef CORE_TOOLS_MESSAGE_EVENT_SUITE_ENTITY_H
#define CORE_TOOLS_MESSAGE_EVENT_SUITE_ENTITY_H

#include "CoreTools/MessageEvent/EventEntityDetail.h"

namespace CoreTools
{
    class Entity final : public EventEntity<>
    {
    public:
        using ClassType = Entity;
        using ParentType = EventEntity<>;

    public:
        NODISCARD static std::shared_ptr<ClassType> Create(int value);

        explicit Entity(int value);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool EventFunction(const Telegram& telegram) override;

        NODISCARD int GetValue() const noexcept;

    private:
        int value;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_SUITE_PARAMETERS_H