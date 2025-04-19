/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:00)

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

        using EntitySharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static EntitySharedPtr Create(int value);

        explicit Entity(int value);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool EventFunction(const Telegram<>& telegram) override;

        NODISCARD int GetValue() const noexcept;

    private:
        int value;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_SUITE_PARAMETERS_H