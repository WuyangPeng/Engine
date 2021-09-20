///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/28 9:37)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "PrefaceWidget.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Preface::Matrix BookExperience::EffectiveModernCpp::Preface::operator+(MAYBE_UNUSED const Matrix& lhs, MAYBE_UNUSED const Matrix& rhs) noexcept
{
    return Matrix{};
}

void BookExperience::EffectiveModernCpp::Preface::SomeFunc(MAYBE_UNUSED Widget w) noexcept
{
}

void BookExperience::EffectiveModernCpp::Preface::PrefaceDeclaration() noexcept
{
    // wid��Widget�ͱ��ĳ������
    Widget wid;

    // �������SomeFunc�ĵ����У�
    // w��wid���ɸ��ƹ��캯�������ĸ�����
    SomeFunc(wid);

    // �������SomeFunc�ĵ����У�
    // w��wid�����ƶ����캯�������ĸ�����
    SomeFunc(std::move(wid));
}
