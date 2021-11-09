///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/04 21:03)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_XML_FILE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_XML_FILE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class XmlFileTesting final : public UnitTest
    {
    public:
        using ClassType = XmlFileTesting;
        using ParentType = UnitTest;

    public:
        explicit XmlFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DefaultXmlFileTest();
        void ConstXmlFileTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_XML_FILE_TESTING_H
