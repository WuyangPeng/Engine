// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/17 11:14)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

Script::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "Ω≈±æ"s }
{
    InitSuite();

    SCRIPT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Script, TestingHelper)

void Script::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddConfigurationSuite();
    AddInterfaceSuite();
    AddJavaSuite();
    AddLuaSuite();
    AddPerlSuite();
    AddPythonSuite();
    AddTCREScriptSuite();
}

void Script::TestingHelper ::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("∞Ô÷˙");

    AddSuite(helperSuite);
}

void Script::TestingHelper ::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("≈‰÷√");

    AddSuite(configurationSuite);
}

void Script::TestingHelper ::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("Ω”ø⁄");

    AddSuite(interfaceSuite);
}

void Script::TestingHelper ::AddJavaSuite()
{
    auto javaSuite = GenerateSuite("Java");

    AddSuite(javaSuite);
}

void Script::TestingHelper ::AddLuaSuite()
{
    auto luaSuite = GenerateSuite("lua");

    AddSuite(luaSuite);
}

void Script::TestingHelper ::AddPerlSuite()
{
    auto perlSuite = GenerateSuite("perl");

    AddSuite(perlSuite);
}

void Script::TestingHelper ::AddPythonSuite()
{
    auto pythonSuite = GenerateSuite("python"); 

    AddSuite(pythonSuite);
}

void Script::TestingHelper ::AddTCREScriptSuite()
{
    auto tcreScriptSuite = GenerateSuite("tcreScript");  

    AddSuite(tcreScriptSuite);
}
