///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:41)

#ifndef BOOK_STANDARD_LIBRARY_STANDARD_CPP_IO_STREAMS_AND_LOCALES_PREFACE_TESTING_H
#define BOOK_STANDARD_LIBRARY_STANDARD_CPP_IO_STREAMS_AND_LOCALES_PREFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookStandardLibrary
{
    namespace StandardCppIOStreamsAndLocales
    {
        class StandardCppIOStreamsAndLocalesPrefaceTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = StandardCppIOStreamsAndLocalesPrefaceTesting;
            using ParentType = UnitTest;

        public:
            explicit StandardCppIOStreamsAndLocalesPrefaceTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();
        };
    }
}

#endif  // BOOK_STANDARD_LIBRARY_STANDARD_CPP_IO_STREAMS_AND_LOCALES_PREFACE_TESTING_H