// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 13:02)

#include "SemaphoreTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <thread>

using std::ostream;
using std::thread;

CoreTools::SemaphoreTesting
	::SemaphoreTesting(const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_Semaphore1{ 1,5 }, m_Semaphore2{ 0,6 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
} 

 CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SemaphoreTesting)
void CoreTools::SemaphoreTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}


void CoreTools::SemaphoreTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CreateFourThread);
}

void CoreTools::SemaphoreTesting
	::CreateFourThread()
{
	thread thread1{ &SemaphoreTesting::ReadThread,this };
	thread thread2{ &SemaphoreTesting::ReadThread,this };
	thread thread3{ &SemaphoreTesting::ReadThread,this };
	thread thread4{ &SemaphoreTesting::WirteThread,this };
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
}

void CoreTools::SemaphoreTesting
	::ReadThread()
{
	m_Semaphore2.Wait();

	ASSERT_EQUAL(m_Semaphore1.GetCurrentCount(), 0);
	ASSERT_EQUAL(m_Semaphore1.GetMaximumCount(), 5);
	ASSERT_RANGE(m_Semaphore2.GetCurrentCount(), 0, 2);
	ASSERT_EQUAL(m_Semaphore2.GetMaximumCount(), 6);
}

void CoreTools::SemaphoreTesting
	::WirteThread()
{
	ASSERT_EQUAL(m_Semaphore1.GetCurrentCount(), 1);
	ASSERT_EQUAL(m_Semaphore1.GetMaximumCount(), 5);
	ASSERT_EQUAL(m_Semaphore2.GetCurrentCount(), 0);
	ASSERT_EQUAL(m_Semaphore2.GetMaximumCount(), 6);

	m_Semaphore1.Wait();

	ASSERT_EQUAL(m_Semaphore1.GetCurrentCount(), 0);
	ASSERT_EQUAL(m_Semaphore1.GetMaximumCount(), 5);
	ASSERT_EQUAL(m_Semaphore2.GetCurrentCount(), 0);
	ASSERT_EQUAL(m_Semaphore2.GetMaximumCount(), 6);

	m_Semaphore2.Release(3);
}

