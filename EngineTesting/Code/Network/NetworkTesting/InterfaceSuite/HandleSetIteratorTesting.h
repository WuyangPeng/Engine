// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 11:32)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_ITERATOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_ITERATOR_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class HandleSetIteratorTesting : public SingletonTesting
	{
	public:
            using ClassType = HandleSetIteratorTesting;
            using ParentType = SingletonTesting;

        public:
            explicit HandleSetIteratorTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void ACETest();
		void BoostTest();
		void NetworkTest();
		void NullTest();

		void ACEConstructionTest();
		void BoostConstructionTest();
		void NetworkConstructionTest();
		void NullConstructionTest();

		void ACEOperatorTest();
		void BoostOperatorExceptionTest();
		void NetworkOperatorExceptionTest();
		void NullOperatorExceptionTest();

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_ITERATOR_TESTING_H