// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 12:30)

#include "EventTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <thread>

using std::ostream;
using std::thread;

CoreTools::EventTesting
	::EventTesting(const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_ManualResetTrueEvent{ true,false }, m_ManualResetFlaseEvent{ false,true }, m_TestValue{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EventTesting)
void CoreTools::EventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EventTesting
	::MainTest()
{
	// ≤‚ ‘¡Ω¥Œ
	ASSERT_NOT_THROW_EXCEPTION_0(ManualResetTrueCreateThreadTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ManualResetTrueCreateThreadTest);

	ASSERT_NOT_THROW_EXCEPTION_0(ManualResetFalseCreateThreadTest);
}

void CoreTools::EventTesting
	::ManualResetTrueCreateThreadTest()
{
	thread thread1{ &EventTesting::Thread1,this };
	thread thread2{ &EventTesting::Thread2,this };
	thread thread3{ &EventTesting::Thread3,this };
	thread1.join();
	thread2.join();
	thread3.join();

	thread thread4{ &EventTesting::Thread4,this };
	thread4.join();
}

void CoreTools::EventTesting
	::Thread1()
{
	ASSERT_EQUAL(m_TestValue, 0);

	++m_TestValue;

	m_ManualResetTrueEvent.SetEvent();
}

void CoreTools::EventTesting
	::Thread2()
{
	m_ManualResetTrueEvent.Wait();

	ASSERT_TRUE(m_TestValue == 1 || m_TestValue == 3);

	++m_TestValue;

	m_ManualResetTrueEvent.SetEvent();
}

void CoreTools::EventTesting
	::Thread3()
{
	m_ManualResetTrueEvent.Wait();

	ASSERT_TRUE(m_TestValue == 1 || m_TestValue == 2);

	m_TestValue += 2;

	m_ManualResetTrueEvent.SetEvent();
}

void CoreTools::EventTesting
	::Thread4()
{
	ASSERT_EQUAL(m_TestValue, 4);

	m_TestValue = 0;

	m_ManualResetTrueEvent.ResetEvent();
}

void CoreTools::EventTesting
	::ManualResetFalseCreateThreadTest()
{
	thread thread1{ &EventTesting::Thread5,this };
	thread thread2{ &EventTesting::Thread6,this };
	thread thread3{ &EventTesting::Thread5,this };
	thread1.join();
	thread2.join();
	thread3.join();

	thread thread4{ &EventTesting::Thread7,this };
	thread4.join();
}

void CoreTools::EventTesting
	::Thread5()
{
	m_ManualResetFlaseEvent.Wait();

	m_ManualResetFlaseEvent.SetEvent();
}

void CoreTools::EventTesting
	::Thread6()
{
	m_ManualResetFlaseEvent.Wait();

	m_ManualResetFlaseEvent.SetEvent();
}

void CoreTools::EventTesting
	::Thread7()
{
	m_ManualResetFlaseEvent.ResetEvent();
}

