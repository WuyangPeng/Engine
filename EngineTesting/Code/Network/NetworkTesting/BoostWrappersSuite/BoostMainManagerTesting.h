// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/13 16:22)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_BASE_MAIN_MANAGER_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_BASE_MAIN_MANAGER_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h" 

namespace Network
{
	class BoostMainManagerTesting : public SingletonTesting
	{
	public:
            using ClassType = BoostMainManagerTesting;
            using ParentType = SingletonTesting;

        public:
            explicit BoostMainManagerTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void SingletonTest();
		void IncrementTest();
		void DecrementToZeroTest();

		// ���Ը�������
		void Increment();
		void DecrementToZero(IOContextType& ioContext);

		virtual void DoRunUnitTest() override;

	private:
		int m_Count;
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_BASE_MAIN_MANAGER_TESTING_H