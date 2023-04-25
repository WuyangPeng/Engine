///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 10:49)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_H

#include "State.h"
#include "CoreTools/CoreToolsTesting/StateMachineSuite/Flags/States.h"
#include "CoreTools/StateMachineManager/StateMachineDetail.h"
#include "CoreTools/StateMachineManager/StateMachineRow.h"

#include <boost/mpl/vector.hpp>

namespace CoreTools
{
    class Player final : public StateMachine<Player, States>
    {
    public:
        using ClassType = Player;
        using ParentType = StateMachine<Player, States>;

    public:
        Player() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void StartPlayback(const Play& eventType) noexcept;
        void OpenDrawer(const OpenClose& eventType) noexcept;
        void CloseDrawer(const OpenClose& eventType) noexcept;
        void StoreCdInfo(const CdDetected& eventType) noexcept;
        void StopPlayback(const Stop& eventType) noexcept;
        void PausePlayback(const Pause& eventType) noexcept;
        void StopAndOpen(const OpenClose& eventType) noexcept;
        void ResumePlayback(const Play& eventType) noexcept;

        struct TransitionTable : boost::mpl::vector11<StateMachineRow<Player, States, States::Stopped, Play, States::Playing, &Player::StartPlayback>,
                                                      StateMachineRow<Player, States, States::Stopped, OpenClose, States::Open, &Player::OpenDrawer>,
                                                      StateMachineRow<Player, States, States::Open, OpenClose, States::Empty, &Player::CloseDrawer>,
                                                      StateMachineRow<Player, States, States::Empty, OpenClose, States::Open, &Player::OpenDrawer>,
                                                      StateMachineRow<Player, States, States::Empty, CdDetected, States::Stopped, &Player::StoreCdInfo>,
                                                      StateMachineRow<Player, States, States::Playing, Stop, States::Stopped, &Player::StopPlayback>,
                                                      StateMachineRow<Player, States, States::Playing, Pause, States::Paused, &Player::PausePlayback>,
                                                      StateMachineRow<Player, States, States::Playing, OpenClose, States::Open, &Player::StopAndOpen>,
                                                      StateMachineRow<Player, States, States::Paused, Play, States::Playing, &Player::ResumePlayback>,
                                                      StateMachineRow<Player, States, States::Paused, Stop, States::Stopped, &Player::StopPlayback>,
                                                      StateMachineRow<Player, States, States::Paused, OpenClose, States::Open, &Player::StopAndOpen>>
        {
        };

        template <typename EventType>
        NODISCARD StateType NoTransition(StateType state, const EventType& eventType) noexcept;

    private:
        static constexpr States initialState = States::Empty;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_H