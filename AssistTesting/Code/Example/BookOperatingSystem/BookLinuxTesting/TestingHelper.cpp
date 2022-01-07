///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.6 (2021/11/24 21:05)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookLinux/Helper/BookLinuxClassInvariantMacro.h"

BookLinux::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���鼮������ϵͳ��linux����Ԫ�����׼�" }
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
    auto beginningLinuxProgrammingSuite = GenerateSuite("Linux�������");

    ADD_TEST(beginningLinuxProgrammingSuite, BeginningLinuxProgramming::BeginningLinuxProgrammingPlaceholderTesting);

    AddSuite(beginningLinuxProgrammingSuite);
}

void BookLinux::TestingHelper::AddLinuxCommandLineAndShellScriptingBibleSuite()
{
    auto linuxCommandLineAndShellScriptingBibleSuite = GenerateSuite("Linux��������shell�ű���̴�ȫ");

    ADD_TEST(linuxCommandLineAndShellScriptingBibleSuite, LinuxCommandLineAndShellScriptingBible::LinuxCommandLineAndShellScriptingBiblePlaceholderTesting);

    AddSuite(linuxCommandLineAndShellScriptingBibleSuite);
}

void BookLinux::TestingHelper::AddProfessionalLinuxKernelArchitectureSuite()
{
    auto professionalLinuxKernelArchitectureSuite = GenerateSuite("����Linux�ں˼ܹ�");

    ADD_TEST(professionalLinuxKernelArchitectureSuite, ProfessionalLinuxKernelArchitecture::ProfessionalLinuxKernelArchitecturePlaceholderTesting);

    AddSuite(professionalLinuxKernelArchitectureSuite);
}
