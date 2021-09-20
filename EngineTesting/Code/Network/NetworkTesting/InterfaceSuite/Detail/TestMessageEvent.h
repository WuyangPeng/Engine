// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 11:31)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_MESSAGE_EVENT_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_MESSAGE_EVENT_H

#include "CoreTools/Threading/Mutex.h"
 
#include "Network/Interface/Server.h"
#include "Network/NetworkMessage/NetworkMessageEvent.h"

namespace Network
{
	class TestMessageEvent : public NetworkMessageEvent
	{
	public:
		using ClassType = TestMessageEvent;
		using ParentType = NetworkMessageEvent;

	public:
		TestMessageEvent();
		virtual ~TestMessageEvent();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		virtual void CallBackEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) override;

		uint64_t GetCallBackTime() const;

		void SetServerWeakPtr(const ServerSharedPtr& ptr);

	private:
		uint64_t m_CallBackTime;
		CoreTools::Mutex m_TestMessageEventCriticalSection;
		ServerWeakPtr m_ServerWeakPtr;
	};

	using TestMessageEventSharedPtr = std::shared_ptr<TestMessageEvent>;
	using ConstTestMessageEventSharedPtr = std::shared_ptr<const TestMessageEvent>;
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_TEST_MESSAGE_EVENT_H
