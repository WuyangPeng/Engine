///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:10)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE QuerySharedStringsImpl final
        {
        public:
            using ClassType = QuerySharedStringsImpl;
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

        public:
            QuerySharedStringsImpl() noexcept = default;
            explicit QuerySharedStringsImpl(const SharedStringsSharedPtr& sharedStrings) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD SharedStringsSharedPtr GetSharedStrings() const;
            void SetSharedStrings(const SharedStringsSharedPtr& sharedStrings) noexcept;

        private:
            using SharedStringsWeakPtr = std::weak_ptr<SharedStrings>;

        private:
            SharedStringsWeakPtr m_SharedStrings;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_IMPL_H
