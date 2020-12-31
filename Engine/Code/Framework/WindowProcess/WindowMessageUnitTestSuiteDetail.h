// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/22 17:19)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_DETAIL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_DETAIL_H 

#include "WindowMessageUnitTestSuite.h" 
 
template<typename TestType, typename... Types>
void Framework::WindowMessageUnitTestSuite
	::AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
{
	auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

	AddTest(suiteName, suite, testName, unitTest);
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_DETAIL_H
