///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/10 15:36)

#ifndef SOUND_EFFECT_TESTING_TESTING_HELPER_H
#define SOUND_EFFECT_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace SoundEffect
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddMacroSuite();
        void AddConfigurationSuite();
        void AddInterfaceSuite();
        void AddCsynUtilSuite();
        void AddDirectSoundSuite();
        void AddOggSuite();
        void AddOpenALSuite();
        void AddVorbisSuite();
        void AddFreeAlutSuite();
    };
}

#endif  // SOUND_EFFECT_TESTING_TESTING_HELPER_H