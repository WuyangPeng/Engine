// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:23)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
	class BoostSockTesting : public SingletonTesting
	{
	public:
            using ClassType = BoostSockTesting;
            using ParentType = SingletonTesting;

        public:
            explicit BoostSockTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;

	protected:
		void BoostServerThread();
		void DoBoostServerThread();

		void AddOffset() noexcept;
		void ClearOffset() noexcept;
		int GetOffset() const noexcept;
		int GetIncrease() const noexcept;
		int GetMessageID() const noexcept;
		int GetRealOffset() const noexcept;
		int GetRealPort() const noexcept;

	private:
		int m_Increase;
		int m_MessageID;
		int m_Offset;
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_TESTING_H