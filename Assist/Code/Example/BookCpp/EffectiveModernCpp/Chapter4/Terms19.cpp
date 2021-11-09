///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 21:10)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms19.h"

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Example0::MakeLogEntry(MAYBE_UNUSED Widget* pw) noexcept
{
}

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms19
            {
                namespace Example1
                {
                    std::vector<std::shared_ptr<Widget>> processedWidgets;
                }

                namespace Example2
                {
                    std::vector<std::shared_ptr<Widget>> processedWidgets;
                }
            }
        }
    }
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Example1::Widget::Process()
{
    // ...
    // ���������

    // ���������Widget��������������������ش�
    processedWidgets.emplace_back(this);
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Example2::Widget::Process()
{
    // ...
    // ͬǰ���������

    // ��ָ�浽��ǰ�����std::shared_ptr����processedWidgets
    processedWidgets.emplace_back(shared_from_this());
}