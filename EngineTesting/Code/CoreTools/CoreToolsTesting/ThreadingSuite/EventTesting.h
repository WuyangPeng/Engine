// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 11:51)

#ifndef CORE_TOOLS_THREADING_SUITE_EVENT_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_EVENT_TESTING_H

#include "CoreTools/Threading/Event.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class EventTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EventTesting); 

	private:
		void MainTest();
        void ManualResetTrueCreateThreadTest();
        void ManualResetFalseCreateThreadTest();
        
        void Thread1();
        void Thread2();
        void Thread3();
        void Thread4();
        
        void Thread5();
        void Thread6();
        void Thread7();

		void DoRunUnitTest() override;

	private:
		Event m_ManualResetTrueEvent;
        Event m_ManualResetFlaseEvent;
        int m_TestValue;
	};
}

#endif // CORE_TOOLS_THREADING_SUITE_EVENT_TESTING_H