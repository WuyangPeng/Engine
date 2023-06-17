///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 19:30)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

SoundEffect::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��Ч��"s }
{
    InitSuite();

    SOUND_EFFECT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SoundEffect, TestingHelper)

// private
void SoundEffect::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddConfigurationSuite();
    AddInterfaceSuite();
    AddCsynUtilSuite();
    AddDirectSoundSuite();
    AddOggSuite();
    AddOpenALSuite();
    AddVorbisSuite();
    AddFreeAlutSuite();
}

void SoundEffect::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("��");

    AddSuite(helperSuite);
}

void SoundEffect::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("����");

    AddSuite(configurationSuite);
}

void SoundEffect::TestingHelper::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("�ӿ�");

    AddSuite(interfaceSuite);
}

void SoundEffect::TestingHelper::AddCsynUtilSuite()
{
    auto csynUtilSuite = GenerateSuite("CsynUtil");

    AddSuite(csynUtilSuite);
}

void SoundEffect::TestingHelper::AddDirectSoundSuite()
{
    auto directSoundSuite = GenerateSuite("DirectSound");

    AddSuite(directSoundSuite);
}

void SoundEffect::TestingHelper::AddOggSuite()
{
    auto oggSuite = GenerateSuite("Ogg");

    AddSuite(oggSuite);
}

void SoundEffect::TestingHelper::AddOpenALSuite()
{
    auto openALSuite = GenerateSuite("OpenAL");

    AddSuite(openALSuite);
}

void SoundEffect::TestingHelper::AddVorbisSuite()
{
    auto vorbisSuite = GenerateSuite("Vorbis");

    AddSuite(vorbisSuite);
}

void SoundEffect::TestingHelper::AddFreeAlutSuite()
{
    auto freeAlutSuite = GenerateSuite("FreeAlut");

    AddSuite(freeAlutSuite);
}
