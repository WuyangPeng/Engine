///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/28 9:37)

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
    // wid是Widget型别的某个对象
    Widget wid;

    // 在这个对SomeFunc的调用中，
    // w是wid经由复制构造函数创建的副本。
    SomeFunc(wid);

    // 在这个对SomeFunc的调用中，
    // w是wid经由移动构造函数创建的副本。
    SomeFunc(std::move(wid));
}
