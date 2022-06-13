///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/10 15:35)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

SoundEffect::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "音效库"s }
{
    InitSuite();

    SOUND_EFFECT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SoundEffect, TestingHelper)

// private
void SoundEffect::TestingHelper::InitSuite()
{
    AddMacroSuite();
    AddConfigurationSuite();
    AddInterfaceSuite();
    AddCsynUtilSuite();
    AddDirectSoundSuite();
    AddOggSuite();
    AddOpenALSuite();
    AddVorbisSuite();
    AddFreeAlutSuite();
}

void SoundEffect::TestingHelper::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("宏");

    AddSuite(macroSuite);
}

void SoundEffect::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("配置");

    AddSuite(configurationSuite);
}

void SoundEffect::TestingHelper::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("接口");

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
