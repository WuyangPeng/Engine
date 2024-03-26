/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:38)

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
