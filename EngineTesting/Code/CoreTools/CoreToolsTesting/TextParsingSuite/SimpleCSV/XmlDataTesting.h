///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/26 15:02)

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
        void DoRunUnitTest() override;
        void MainTest();

        void XmlDataTest();
        void ConstXmlDataTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_XML_DATA_TESTING_H
