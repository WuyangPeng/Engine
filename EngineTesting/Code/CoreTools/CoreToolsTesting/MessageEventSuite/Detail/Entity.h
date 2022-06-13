///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:59)

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
        NODISCARD static std::shared_ptr<ClassType> Create(int value);

        explicit Entity(int value);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        bool EventFunction(const Telegram& telegram) override;

        NODISCARD int GetValue() const noexcept;

    private:
        int value;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_SUITE_PARAMETERS_H