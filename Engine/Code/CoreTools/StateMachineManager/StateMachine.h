// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 17:26)

#ifndef CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_H
#define CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_H 

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template<typename Derived, typename State = uint32_t>
	class StateMachine
	{
	public:
		using StateType = State;
		using ClassType = StateMachine<Derived, StateType>;

	public:
		StateMachine();
		virtual ~StateMachine() = 0;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	public:
		template <typename EventType>
		StateType CallNoTransition(StateType state, const EventType& eventType);

		template<typename EventType>
		StateType ProcessEvent(const EventType& eventType);

		template <typename EventType>
		StateType NoTransition(StateType state, const EventType& eventType);

		StateType GetStateType() const;

	protected:
		void SetStateType(StateType stateType);

	private:
		StateType m_State;
	};
}

// ʹ��StateMachiner�ķ�ʽ��

// ��һ�����������е��ࣺ
// struct Play { };
// struct OpenClose {};
// struct CdDetected { CdDetected(char const*, std::vector<std::clock_t> const&) { } };
// struct Pause { };
// struct Stop { };
// ��Щ�����ʹ�÷�Ĭ�Ϲ��캯�����졣

// �ڶ���������״̬ö�ٻ�ʹ�����ͣ�
// enum class States {
// Empty, Open, Stopped, Playing, Paused };

// ��������������̳���StateMachine
// class Player : public StateMachine<Player,States>
// ��Player��Ҫ�������º�����
// static const StatesFlags sm_InitialState = States::Empty;
// һ���ڲ��ࣺ
// struct TransitionTable : boost::mpl::vector11<
//                 Derived  States  Start            Event      Next             Action
// StateMachineRow <Player, States, States::Stopped, Play,      States::Playing, &Player::StartPlayback>,
// StateMachineRow <Player, States, States::Stopped, OpenClose, States::Open,    &Player::OpenDrawer>,
// StateMachineRow <Player, States, States::Open,    OpenClose, States::Empty,   &Player::CloseDrawer>,	 
// StateMachineRow <Player, States, States::Empty,   OpenClose, States::Open,    &Player::OpenDrawer>,
// StateMachineRow <Player, States, States::Empty,   CdDetected,States::Stopped, &Player::StoreCdInfo>,	 
// StateMachineRow <Player, States, States::Playing, Stop,      States::Stopped, &Player::StopPlayback>,
// StateMachineRow <Player, States, States::Playing, Pause,     States::Paused,  &Player::PausePlayback>,
// StateMachineRow <Player, States, States::Playing, OpenClose, States::Open,    &Player::StopAndOpen>,	 
// StateMachineRow <Player, States, States::Paused,  Play,      States::Playing, &Player::ResumePlayback>,
// StateMachineRow <Player, States, States::Paused,  Stop,      States::Stopped, &Player::StopPlayback>,
// StateMachineRow <Player, States, States::Paused,  OpenClose, States::Open,    &Player::StopAndOpen>
// > {};

// ʹ�ã�
// Player player;                
// player.ProcessEvent(OpenClose());
// player.ProcessEvent(OpenClose());
// player.ProcessEvent(CdDetected("louie, louie", std::vector<std::clock_t>()));
// player.ProcessEvent(Play());
// player.ProcessEvent(Pause());
// player.ProcessEvent(Play());
// player.ProcessEvent(Stop());

#endif //  CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_H

