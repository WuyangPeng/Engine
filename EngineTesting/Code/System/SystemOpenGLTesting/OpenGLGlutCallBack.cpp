///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/06/28 18:38)

#include "OpenGLGlutCallBack.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using std::string;
using namespace std::literals;

System::OpenGLGlutCallBack::OpenGLGlutCallBack(int64_t delta)
    : ParentType{ delta, "【系统库】OpenGL单元测试套件"s }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutCallBack)

void System::OpenGLGlutCallBack::AddSuite()
{
    AddOpenGLSuite();
}

void System::OpenGLGlutCallBack::AddOpenGLSuite()
{
    auto openGLSuite = GenerateSuite("OpenGL");

    ADD_TEST(openGLSuite, OpenGLUtilityTesting);
    ADD_TEST(openGLSuite, OpenGLInitTesting);
    ADD_TEST(openGLSuite, OpenGLAPITesting);
    ADD_TEST(openGLSuite, OpenGLProgramTesting);
    ADD_TEST(openGLSuite, OpenGLShaderTesting);
    ADD_TEST(openGLSuite, OpenGLGlutTesting);

    DoAddSuite(openGLSuite);
}
