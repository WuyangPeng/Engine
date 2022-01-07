///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.6 (2021/11/24 21:05)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookLinux/Helper/BookLinuxClassInvariantMacro.h"

BookLinux::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "【书籍·操作系统·linux】单元测试套件" }
{
    InitSuite();

    BOOK_LINUX_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookLinux, TestingHelper)

void BookLinux::TestingHelper::InitSuite()
{
    AddBeginningLinuxProgrammingSuite();
    AddLinuxCommandLineAndShellScriptingBibleSuite();
    AddProfessionalLinuxKernelArchitectureSuite();
}

void BookLinux::TestingHelper::AddBeginningLinuxProgrammingSuite()
{
    auto beginningLinuxProgrammingSuite = GenerateSuite("Linux程序设计");

    ADD_TEST(beginningLinuxProgrammingSuite, BeginningLinuxProgramming::BeginningLinuxProgrammingPlaceholderTesting);

    AddSuite(beginningLinuxProgrammingSuite);
}

void BookLinux::TestingHelper::AddLinuxCommandLineAndShellScriptingBibleSuite()
{
    auto linuxCommandLineAndShellScriptingBibleSuite = GenerateSuite("Linux命令行与shell脚本编程大全");

    ADD_TEST(linuxCommandLineAndShellScriptingBibleSuite, LinuxCommandLineAndShellScriptingBible::LinuxCommandLineAndShellScriptingBiblePlaceholderTesting);

    AddSuite(linuxCommandLineAndShellScriptingBibleSuite);
}

void BookLinux::TestingHelper::AddProfessionalLinuxKernelArchitectureSuite()
{
    auto professionalLinuxKernelArchitectureSuite = GenerateSuite("深入Linux内核架构");

    ADD_TEST(professionalLinuxKernelArchitectureSuite, ProfessionalLinuxKernelArchitecture::ProfessionalLinuxKernelArchitecturePlaceholderTesting);

    AddSuite(professionalLinuxKernelArchitectureSuite);
}
