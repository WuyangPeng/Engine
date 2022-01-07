///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/11/03 22:38)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms23.h"
#include "System/Helper/PragmaWarning.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms23::Example0::Annotation::Annotation(MAYBE_UNUSED std::string text) noexcept
{
}

#include STSTEM_WARNING_PUSH

#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 26478)
#endif  // TCRE_USE_MSVC

BookExperience::EffectiveModernCpp::Chapter5::Terms23::Example1::Annotation::Annotation(const std::string text)
    : value(std::move(text))  // 将text“移动入”value;
{
    // 这段代码实际的所作所为和乍看之下有所不同！
    // 最终调用的是复制构造函数
}
#include STSTEM_WARNING_POP

void BookExperience::EffectiveModernCpp::Chapter5::Terms23::Example0::Process(MAYBE_UNUSED const Widget& lvalArg) noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms23::Example0::Process(MAYBE_UNUSED Widget&& rvalArg) noexcept
{
}
