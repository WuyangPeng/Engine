///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/27 22:02)

#include "Example/BookCpp/STLTutorialAndReferenceGuide/STLTutorialAndReferenceGuideExport.h"

#include "Preface.h"
#include "Example/BookCpp/STLTutorialAndReferenceGuide/Helper/STLTutorialAndReferenceGuideClassInvariantMacro.h"

#include <vector>

using std::pair;
using std::vector;

BookStandardLibrary::STLTutorialAndReferenceGuide::Preface::Preface() noexcept
{
    STL_TUTORIAL_AND_REFERENCE_GUIDE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookStandardLibrary::STLTutorialAndReferenceGuide, Preface)

void BookStandardLibrary::STLTutorialAndReferenceGuide::Preface::Main() const
{
    STL_TUTORIAL_AND_REFERENCE_GUIDE_CLASS_IS_VALID_CONST_9;

    std::vector<pair<int, int>> myVector{ { 0, 1 }, { 2, 3 }, { 4, 5 } };

    auto iter = myVector.begin();

    iter->second = 5;

    constexpr auto i = 0;
    pair<int, int> tmp = myVector.at(i);
    tmp.second = 5;
    myVector.at(i) = tmp;
}
