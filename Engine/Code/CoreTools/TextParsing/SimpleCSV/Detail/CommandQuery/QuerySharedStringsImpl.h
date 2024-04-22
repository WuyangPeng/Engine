/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 17:58)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>

namespace CoreTools::SimpleCSV
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
        void SetSharedStrings(const SharedStringsSharedPtr& aSharedStrings) noexcept;

    private:
        using SharedStringsWeakPtr = std::weak_ptr<SharedStrings>;

    private:
        SharedStringsWeakPtr sharedStrings;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_IMPL_H
