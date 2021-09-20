///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/28 9:37)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "PrefaceDeclaration.h"
#include "PrefaceExample.h"
#include "PrefaceWidget.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Preface::PrefaceExample::PrefaceExample() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Preface, PrefaceExample)

void BookExperience::EffectiveModernCpp::Preface::PrefaceExample::ProcessValsTest() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    ProcessVals();
    ProcessVals(1);
}

void BookExperience::EffectiveModernCpp::Preface::PrefaceExample::SomeFuncTest() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    PrefaceDeclaration();
}

void BookExperience::EffectiveModernCpp::Preface::PrefaceExample::MatrixTest() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Matrix lhs{};
    Matrix rhs{};

    const auto result = lhs + rhs;
}

bool BookExperience::EffectiveModernCpp::Preface::PrefaceExample::DeclarationTest() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    return WidgetDeclaration();
}
