///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/05 12:25)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms3Derive.h"
#include "CoreTools/Contract/Noexcept.h"

bool BookExperience::EffectiveModernCpp::Chapter1::Terms3::F(MAYBE_UNUSED const Widget& w)
{
    static_assert(std::is_same_v<decltype(w), const Widget&>);

    CoreTools::DisableNoexcept();

    return true;
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms3::ActhenticateUser() noexcept
{
}

std::deque<std::string> BookExperience::EffectiveModernCpp::Chapter1::Terms3::MakeStringDeque()  // ��������
{
    return { "1", "2", "3", "4", "5", "6", "7", "8" };
}
