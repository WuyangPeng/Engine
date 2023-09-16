///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:18)

#include "CompareStringUseLocaleTestingBase.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompareStringUseLocaleTestingBase::CompareStringUseLocaleTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      compares{ Compares::NormIgnoreCase,
                Compares::NormIgnoreNonSpace,
                Compares::NormIgnoreSymbols,
                Compares::LinguisticIgnoreCase,
                Compares::LinguisticIgnoreDiacritic,
                Compares::NormIgnoreKanaType,
                Compares::NormIgnoreWidth,
                Compares::NormLinguisticCasing,
                Compares::SortStringSort,
                Compares::SortDigitsAsNumbers }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CompareStringUseLocaleTestingBase)

size_t System::CompareStringUseLocaleTestingBase::GetComparesSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return compares.size();
}

void System::CompareStringUseLocaleTestingBase::RandomShuffleCompares(std::default_random_engine& randomEngine)
{
    SYSTEM_CLASS_IS_VALID_1;

    std::ranges::shuffle(compares, randomEngine);
}

System::Compares System::CompareStringUseLocaleTestingBase::GetCompares(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return compares.at(index % compares.size());
}
