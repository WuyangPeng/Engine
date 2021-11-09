///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 21:11)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms20.h"
#include "Terms20Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms20::Terms20Example::Terms20Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter4::Terms20, Terms20Example)

void BookExperience::EffectiveModernCpp::Chapter4::Terms20::Terms20Example::WeakPtrExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // spw�������ɺ�ָ�浽Widget�����ü�����Ϊ1
    auto spw = std::make_shared<Widget>();

    // ...

    // wpw��spwָ�浽ͬһ��Widget��
    // ���ü�������Ϊ1
    std::weak_ptr<Widget> wpw(spw);

    // ���ü�����Ϊ0
    // Widget����������
    // wpw����
    spw = nullptr;

    // ��wpw����ָ�浽�κζ���
    if (wpw.expired())
    {
        // ...
    }

    // ��wpwʧЧ����spw1Ϊ�ա�
    std::shared_ptr<Widget> spw1 = wpw.lock();

    auto spw2 = wpw.lock();  // ͬ�ϣ���ʹ��auto

    // ��wpwʧЧ���׳�std::bad_weak_ptr�ͱ���쳣��
    std::shared_ptr<Widget> spw3(wpw);
}
