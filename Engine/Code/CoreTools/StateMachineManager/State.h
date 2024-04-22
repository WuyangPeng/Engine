/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:19)

#ifndef CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_H
#define CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/MessageEvent/EventEntity.h"

#include <memory>

namespace CoreTools
{
    template <typename EntityType>
    class State : public std::enable_shared_from_this<State<EntityType>>
    {
    public:
        using ClassType = State<EntityType>;

        using EntityTypeSharedPtr = std::shared_ptr<EntityType>;
        using EntityEventType = typename EntityType::EntityEventType;
        using Telegram = Telegram<EntityEventType>;
        using EntityTypeWeakPtr = std::weak_ptr<EntityType>;
        using StateSharedPtr = std::shared_ptr<ClassType>;
        using ConstStateSharedPtr = std::shared_ptr<const ClassType>;
        using MessageResult = std::pair<StateSharedPtr, bool>;

    public:
        State() noexcept;
        virtual ~State() noexcept = default;

        State(const State& rhs) noexcept = default;
        State& operator=(const State& rhs) noexcept = default;
        State(State&& rhs) noexcept = default;
        State& operator=(State&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void Enter(EntityTypeSharedPtr aEntity);

        NODISCARD virtual StateSharedPtr Execute(int64_t timeInterval) = 0;

        virtual void Exit() = 0;

        NODISCARD virtual MessageResult OnMessage(const Telegram& telegram) = 0;

        template <typename StateType, typename ResultType = StateType, typename... Args>
        NODISCARD static std::shared_ptr<ResultType> MakeState(Args&&... args);

        NODISCARD EntityTypeSharedPtr GetOwner();

        NODISCARD bool IsExactly(const Rtti& rtti) const noexcept;

        CORE_TOOLS_RTTI_DECLARE;

    protected:
        NODISCARD StateSharedPtr GetPossiblePreviousState();

    private:
        virtual void DoEnter() = 0;

    private:
        EntityTypeWeakPtr entity;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_H