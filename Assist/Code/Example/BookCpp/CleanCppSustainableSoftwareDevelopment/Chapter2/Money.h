///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_MONEY_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_MONEY_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/Helper/PragmaWarning/Operators.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_DEFAULT_DECLARE Money final : private boost::totally_ordered<Money>
        {
        public:
            using ClassType = Money;

        public:
            explicit Money(double value) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetValue() const noexcept;

        private:
            double value;
        };

        NODISCARD bool operator<(const Money& lhs, const Money& rhs) noexcept;
        NODISCARD bool operator==(const Money& lhs, const Money& rhs) noexcept;
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_MONEY_H
