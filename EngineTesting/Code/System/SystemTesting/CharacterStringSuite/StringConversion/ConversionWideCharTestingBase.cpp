/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:38)

#include "ConversionWideCharTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConversionWideCharTestingBase::ConversionWideCharTestingBase(const OStreamShared& stream, int conversionMinLength, const std::wstring& wideCharConversionResult)
    : ParentType{ stream, conversionMinLength }, wideCharConversionResult{ wideCharConversionResult }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConversionWideCharTestingBase)

void System::ConversionWideCharTestingBase::ResultChecking(const WideCharType& wideChar, int wideCharActualLength, int wideCharLength)
{
    const std::wstring wideCharResult{ wideChar.data() };
    ASSERT_EQUAL(wideCharActualLength, boost::numeric_cast<int>(wideCharResult.size() + 1));

    ASSERT_EQUAL(wideCharResult, wideCharConversionResult);
    ASSERT_EQUAL(wideCharActualLength, wideCharLength);
}
