///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/01 22:40)

#ifndef EXTENDED_STL_PREFACE_SEVEN_SIGNS_OF_A_GOOD_CPP_LIBRARY_H
#define EXTENDED_STL_PREFACE_SEVEN_SIGNS_OF_A_GOOD_CPP_LIBRARY_H

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookStandardLibrary
{
    namespace ExtendedSTL
    {
        class EXTENDED_STL_DEFAULT_DECLARE SevenSignsOfAGoodCppLibrary final
        {
        public:
            using ClassType = SevenSignsOfAGoodCppLibrary;

        public:
            SevenSignsOfAGoodCppLibrary() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const;

            void CRemoveFile() const;
            void STLSoftFile() const noexcept;
        };
    }
}

#endif  // EXTENDED_STL_PREFACE_SEVEN_SIGNS_OF_A_GOOD_CPP_LIBRARY_H
