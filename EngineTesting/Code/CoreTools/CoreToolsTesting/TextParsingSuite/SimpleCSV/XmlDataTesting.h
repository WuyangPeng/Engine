///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/01 22:42)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_XML_DATA_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_XML_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class XmlDataTesting final : public UnitTest
    {
    public:
        using ClassType = XmlDataTesting;
        using ParentType = UnitTest;

    public:
        explicit XmlDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void XmlDataTest();
        void ConstXmlDataTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_XML_DATA_TESTING_H
