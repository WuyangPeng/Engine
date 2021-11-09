///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/09/30 20:38)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms8.h"

#include <iostream>

using std::cout;

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::F(int)
{
    cout << "F(int)被调用\n";
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::F(void*)
{
    cout << "F(void*)被调用\n";
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms8::F(bool)
{
    cout << "F(bool)被调用\n";
}

int* BookExperience::EffectiveModernCpp::Chapter3::Terms8::FindRecord() noexcept
{
    return nullptr;
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms8::F1(MAYBE_UNUSED std::shared_ptr<Widget> spw) noexcept
{
    return 0;
}

double BookExperience::EffectiveModernCpp::Chapter3::Terms8::F2(MAYBE_UNUSED std::unique_ptr<Widget> upw) noexcept
{
    return 0.0;
}

bool BookExperience::EffectiveModernCpp::Chapter3::Terms8::F3(MAYBE_UNUSED Widget* pw) noexcept
{
    return true;
}
