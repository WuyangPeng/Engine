///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/22 20:49)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms21.h"
#include "Terms21Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::Terms21Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter4::Terms21, Terms21Example)

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::MakeExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26414)

    auto upw1(std::make_unique<Widget>());  // ʹ��makeϵ�к���

    std::unique_ptr<Widget> upw2(new Widget);  // ��ʹ��makeϵ�к���

    auto spw1(std::make_shared<Widget>());  // ʹ��makeϵ�к���

    std::shared_ptr<Widget> spw2(new Widget);  // ��ʹ��makeϵ�к���

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ProcessWidget0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    // Ǳ�ڵ��ڴ�й©
    ProcessWidget(std::shared_ptr<Widget>(new Widget), ComputePriority());

#include STSTEM_WARNING_POP

    // ���ᷢ��Ǳ�ڵ��ڴ�й©����
    ProcessWidget(std::make_shared<Widget>(), ComputePriority());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26414)

    std::shared_ptr<Widget> spw1(new Widget);

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto spw2 = std::make_shared<Widget>();

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::DeleterExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto widgetDeleter = [](Widget* pw) noexcept {
    // ...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    std::unique_ptr<Widget, decltype(widgetDeleter)> upw(new Widget, widgetDeleter);

    std::shared_ptr<Widget> spw(new Widget, widgetDeleter);

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::Vector0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto upv = std::make_unique<std::vector<int>>(10, 20);

    auto spv = std::make_shared<std::vector<int>>(10, 20);

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::Vector1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // ����std::initializer_list�ͱ����
    auto initList = { 10, 20 };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    // ����std::initializer_list�ͱ�Ĺ��캯������std::vector
    auto spv = std::make_shared<std::vector<int>>(initList);

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ReallyBigType0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    // ͨ��std::make_shared�����Ĵ�Ķ���
    auto pBigObj = std::make_shared<ReallyBigType>();

#include STSTEM_WARNING_POP

    // ...
    // ����ָ�浽�����Ķ��std::shared_ptr��std::weak_ptr
    // ��ʹ����Щ����ָ������������ö���

    // ...
    // ���һ��ָ�浽�ö����std::shared_ptr�ڴ�������
    // ��ָ�浽�ö��������std::weak_ptr��Ȼ����

    // ...
    // �ڴ˽׶Σ�ǰ���������ռ�õ��ڴ��Դ��ڷ���δ����״̬

    // ...
    // ���һ��ָ�浽�����std::weak_ptr�ڴ˱�����
    // ���ƿ�Ͷ�����ռ�õ�ͬһ�ڴ���ڴ˵õ��ͷš�
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ReallyBigType1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26414)

    // ͨ��new���ʽ�����Ĵ�Ķ���
    std::shared_ptr<ReallyBigType> pBigObj(new ReallyBigType);

#include STSTEM_WARNING_POP

    // ...

    // ͬǰ������ָ�浽������
    // ���std::shared_ptr��std::weak_ptr��
    // ��ʹ����Щ����ָ���������ö���

    // ...

    // ���һ��ָ�浽�ö����std::shared_ptr�ڴ˱�������
    // ��ָ�浽�ö��������std::weak_ptr��Ȼ����
    // ǰ���������ռ�õ��ڴ���Щ�����ա�

    // ...

    // �ڴ˽׶Σ������ƿ���ռ�õ��ڴ��Դ��ڷ���δ����״̬

    // ...
    // ���һ��ָ�浽�����std::weak_ptr�ڴ˱�����
    // ���ƿ���ռ�õ��ڴ���ڴ˵õ��ͷš�
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ProcessWidget1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    // ͬǰ��Ǳ�ڵ���Դй©��
    ProcessWidget(std::shared_ptr<Widget>(new Widget, CusDel), ComputePriority());  // ʵ���Ǹ���ֵ

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ProcessWidget2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    std::shared_ptr<Widget> spw(new Widget, CusDel);

#include STSTEM_WARNING_POP

    // ��ȷ�����������Ż�
    ProcessWidget(spw, ComputePriority());  // ʵ���Ǹ���ֵ
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::Terms21Example::ProcessWidget3Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    std::shared_ptr<Widget> spw(new Widget, CusDel);

#include STSTEM_WARNING_POP

    ProcessWidget(std::move(spw), ComputePriority());  // ����Ч�ʣ����쳣��ȫ
}
