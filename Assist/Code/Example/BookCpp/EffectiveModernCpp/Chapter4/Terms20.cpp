///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/10 21:10)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms20.h"

#include <unordered_map>

int BookExperience::EffectiveModernCpp::Chapter4::Terms20::WidgetID::GetValue() const noexcept
{
    return value;
}

bool BookExperience::EffectiveModernCpp::Chapter4::Terms20::operator==(const WidgetID& lhs, const WidgetID& rhs) noexcept
{
    return lhs.GetValue() == rhs.GetValue();
}

std::unique_ptr<const BookExperience::EffectiveModernCpp::Chapter4::Terms20::Widget> BookExperience::EffectiveModernCpp::Chapter4::Terms20::LoadWidget(MAYBE_UNUSED WidgetID id)
{
    return std::make_unique<BookExperience::EffectiveModernCpp::Chapter4::Terms20::Widget>();
}

std::shared_ptr<const BookExperience::EffectiveModernCpp::Chapter4::Terms20::Widget> BookExperience::EffectiveModernCpp::Chapter4::Terms20::FastLoadWidget(WidgetID id)
{
    static std::unordered_map<WidgetID,
                              std::weak_ptr<const Widget>>
        cache;

    // objPTr的型别是std::shared_ptr
    // 指涉到缓存的对象
    // （如果对象不在缓存中，则返回空指针）
    auto objPtr = cache[id].lock();

    // 如果对象不在缓存中，则加载入，并缓存之
    if (!objPtr)
    {
        objPtr = LoadWidget(id);
        cache[id] = objPtr;
    }

    return objPtr;
}
