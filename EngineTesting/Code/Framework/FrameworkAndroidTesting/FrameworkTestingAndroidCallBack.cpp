// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.4 (2019/09/10 20:10)

#include "FrameworkTestingAndroidCallBack.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using std::string;
#include SYSTEM_WARNING_DISABLE(26432)
Framework::FrameworkTestingAndroidCallBack::FrameworkTestingAndroidCallBack(int64_t delta)
    : ParentType{ delta, "¡¾¿ò¼Ü¿â¡¿µ¥Ôª²âÊÔÌ×¼þ" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::FrameworkTestingAndroidCallBack::~FrameworkTestingAndroidCallBack()
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, FrameworkTestingAndroidCallBack)

void Framework::FrameworkTestingAndroidCallBack::InitSuite()
{
    AddAndroidFrameSuite();
}

void Framework::FrameworkTestingAndroidCallBack::AddAndroidFrameSuite()
{
    auto androidFrameSuite = GenerateSuite("°²×¿¿ò¼Ü");

    //System::AndroidApp* app = GetAndroidApp();

    // 	ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidProcessManagerTesting,app);
    // 	ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidProcessTesting,app);
    // 	ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidCallBackInterfaceTesting,app);
    // 	ADD_TEST_USE_PARAMETER_1(androidFrameSuite, AndroidCallBackTesting,app);
    // 	ADD_TEST(androidFrameSuite, AndroidMessageLoopTesting);
    // 	ADD_TEST(androidFrameSuite, AndroidFrameBuildTesting);
    // 	ADD_TEST(androidFrameSuite, AndroidCallBackUnitTestSuiteTesting);

    AddSuite(androidFrameSuite);
}
