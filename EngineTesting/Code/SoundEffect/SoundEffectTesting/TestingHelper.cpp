// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/09/02 10:57)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(SoundEffect, TestingHelper, "“Ù–ßø‚")

// private
void SoundEffect::TestingHelper ::AddSuites()
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

void SoundEffect::TestingHelper
	::AddMacroSuite()
{
	ADD_TEST_BEGIN(macroSuite, "∫Í");

	ADD_TEST_END(macroSuite);
}

void SoundEffect::TestingHelper
	::AddConfigurationSuite()
{
	ADD_TEST_BEGIN(configurationSuite, "≈‰÷√");

	ADD_TEST_END(configurationSuite);
}

void SoundEffect::TestingHelper
	::AddInterfaceSuite()
{
	ADD_TEST_BEGIN(interfaceSuite, "Ω”ø⁄");

	ADD_TEST_END(interfaceSuite);
}

void SoundEffect::TestingHelper
	::AddCsynUtilSuite()
{
	ADD_TEST_BEGIN(csynUtilSuite, "CsynUtil");

	ADD_TEST_END(csynUtilSuite);
}

void SoundEffect::TestingHelper
	::AddDirectSoundSuite()
{
	ADD_TEST_BEGIN(directSoundSuite, "DirectSound");

	ADD_TEST_END(directSoundSuite);
}

void SoundEffect::TestingHelper
	::AddOggSuite()
{
	ADD_TEST_BEGIN(oggSuite, "Ogg");

	ADD_TEST_END(oggSuite);
}

void SoundEffect::TestingHelper
	::AddOpenALSuite()
{
	ADD_TEST_BEGIN(openALSuite, "OpenAL");

	ADD_TEST_END(openALSuite);
}

void SoundEffect::TestingHelper
	::AddVorbisSuite()
{
	ADD_TEST_BEGIN(vorbisSuite, "Vorbis");

	ADD_TEST_END(vorbisSuite);
}

void SoundEffect::TestingHelper
	::AddFreeAlutSuite()
{
	ADD_TEST_BEGIN(freeAlutSuite, "FreeAlut");

	ADD_TEST_END(freeAlutSuite);
}

