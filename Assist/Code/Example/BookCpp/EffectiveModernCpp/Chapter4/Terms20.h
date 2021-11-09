///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 21:09)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM20_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM20_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms20
            {
                class Widget
                {
                };

                class WidgetID
                {
                public:
                    int GetValue() const noexcept;

                private:
                    int value;
                };

                bool operator==(const WidgetID& lhs, const WidgetID& rhs) noexcept;

                std::unique_ptr<const Widget> LoadWidget(MAYBE_UNUSED WidgetID id);
                std::shared_ptr<const Widget> FastLoadWidget(WidgetID id);
            }
        }
    }
}

namespace std
{
    template <>
    struct hash<BookExperience::EffectiveModernCpp::Chapter4::Terms20::WidgetID>
    {
        std::size_t operator()(const BookExperience::EffectiveModernCpp::Chapter4::Terms20::WidgetID& value) const noexcept
        {
            return std::hash<int>{}(value.GetValue());
        }
    };
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM20_H
