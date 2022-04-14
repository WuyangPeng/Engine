// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/09/02 10:57)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

SoundEffect::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "“Ù–ßø‚"s }
{
    InitSuite();

    SOUND_EFFECT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SoundEffect, TestingHelper)

// private
void SoundEffect::TestingHelper ::InitSuite()
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

void SoundEffect::TestingHelper ::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("∫Í");

    AddSuite(macroSuite);
}

void SoundEffect::TestingHelper ::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("≈‰÷√");

    AddSuite(configurationSuite);
}

void SoundEffect::TestingHelper ::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("Ω”ø⁄");

    AddSuite(interfaceSuite);
}

void SoundEffect::TestingHelper ::AddCsynUtilSuite()
{
    auto csynUtilSuite = GenerateSuite("CsynUtil");

    AddSuite(csynUtilSuite);
}

void SoundEffect::TestingHelper ::AddDirectSoundSuite()
{
    auto directSoundSuite = GenerateSuite("DirectSound");

    AddSuite(directSoundSuite);
}

void SoundEffect::TestingHelper ::AddOggSuite()
{
    auto oggSuite = GenerateSuite("Ogg");

    AddSuite(oggSuite);
}

void SoundEffect::TestingHelper ::AddOpenALSuite()
{
    auto openALSuite = GenerateSuite("OpenAL");

    AddSuite(openALSuite);
}

void SoundEffect::TestingHelper ::AddVorbisSuite()
{
    auto vorbisSuite = GenerateSuite("Vorbis");

    AddSuite(vorbisSuite);
}

void SoundEffect::TestingHelper ::AddFreeAlutSuite()
{
    auto freeAlutSuite = GenerateSuite("FreeAlut");

    AddSuite(freeAlutSuite);
}
