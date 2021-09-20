// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王测试版本：0.7.0.1 (2020/05/18 10:47)

#ifndef THE_LAST_OVERLORD_TESTING_TESTING_HELPER_H
#define THE_LAST_OVERLORD_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace TheLastOverlord
{
	class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = CMainFunctionTestingHelper;

	public:
		TestingHelper(int argc, char** argv);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void InitSuite();

		void AddVersionSuite();
		void AddEngineSuite();
	};
}

#endif // THE_LAST_OVERLORD_TESTING_TESTING_HELPER_H