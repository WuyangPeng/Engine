///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/11/03 22:38)

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
    : value(std::move(text))  // ��text���ƶ��롱value;
{
    // ��δ���ʵ�ʵ�������Ϊ��է��֮��������ͬ��
    // ���յ��õ��Ǹ��ƹ��캯��
}
#include STSTEM_WARNING_POP

void BookExperience::EffectiveModernCpp::Chapter5::Terms23::Example0::Process(MAYBE_UNUSED const Widget& lvalArg) noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms23::Example0::Process(MAYBE_UNUSED Widget&& rvalArg) noexcept
{
}
