/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/17 20:11)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_TESTING_HELPER_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace ThreadingCoreRenderEngineAssist
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

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_TESTING_TESTING_HELPER_H