///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/10 21:10)

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
    // 处理对象本身

    // 将处理完的Widget加入链表，这种做法大错特错
    processedWidgets.emplace_back(this);
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Example2::Widget::Process()
{
    // ...
    // 同前处理对象本身

    // 将指涉到当前对象的std::shared_ptr加入processedWidgets
    processedWidgets.emplace_back(shared_from_this());
}