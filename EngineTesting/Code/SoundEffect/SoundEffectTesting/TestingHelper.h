// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/09/02 10:56)

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