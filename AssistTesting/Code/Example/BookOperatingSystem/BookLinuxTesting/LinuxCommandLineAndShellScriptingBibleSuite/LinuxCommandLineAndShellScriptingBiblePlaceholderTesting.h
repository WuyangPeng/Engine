///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.6 (2021/11/24 21:13)

#ifndef BOOK_LINUX_LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_PLACEHOLDER_TESTING_H
#define BOOK_LINUX_LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookLinux
{
    namespace LinuxCommandLineAndShellScriptingBible
    {
        class LinuxCommandLineAndShellScriptingBiblePlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = LinuxCommandLineAndShellScriptingBiblePlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit LinuxCommandLineAndShellScriptingBiblePlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_LINUX_LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_PLACEHOLDER_TESTING_H