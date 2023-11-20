///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/13 19:16)

#ifndef ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_H
#define ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <filesystem>

namespace AssistTools
{
    class GenerateTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = GenerateTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        GenerateTesting(const OStreamShared& stream, String output);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void ResultTest(const String& directory);

        NODISCARD String GetOutput() const;

    private:
        void RegularFileTest(const String& fileName);

    private:
        String output;
    };
}

#endif  // ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_H