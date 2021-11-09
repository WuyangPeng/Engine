///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 21:10)

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

    // objPTr���ͱ���std::shared_ptr
    // ָ�浽����Ķ���
    // ����������ڻ����У��򷵻ؿ�ָ�룩
    auto objPtr = cache[id].lock();

    // ��������ڻ����У�������룬������֮
    if (!objPtr)
    {
        objPtr = LoadWidget(id);
        cache[id] = objPtr;
    }

    return objPtr;
}
