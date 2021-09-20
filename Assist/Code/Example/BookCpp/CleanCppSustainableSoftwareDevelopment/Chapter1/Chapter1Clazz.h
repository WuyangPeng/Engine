///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/29 18:18)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER1_CLAZZ_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER1_CLAZZ_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_DEFAULT_DECLARE Chapter1Clazz final
        {
        public:
            using ClassType = Chapter1Clazz;

        public:
            Chapter1Clazz() noexcept;
            virtual ~Chapter1Clazz() noexcept;
            void DoSomething() noexcept;

            CLASS_INVARIANT_DECLARE;

            Chapter1Clazz(const Chapter1Clazz& rhs) noexcept = default;
            Chapter1Clazz& operator=(const Chapter1Clazz& rhs) noexcept = default;
            Chapter1Clazz(Chapter1Clazz&& rhs) noexcept = default;
            Chapter1Clazz& operator=(Chapter1Clazz&& rhs) noexcept = default;

        private:
            int attribute;

            void Function() noexcept;
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER1_CLAZZ_H
