///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ���԰汾��0.8.0.11 (2022/07/19 15:41)

#ifndef THREADING_CORE_RENDER_ENGINE_GAME_TESTING_TESTING_HELPER_H
#define THREADING_CORE_RENDER_ENGINE_GAME_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace ThreadingCoreRenderEngineGame
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

#endif  // THREADING_CORE_RENDER_ENGINE_GAME_TESTING_TESTING_HELPER_H