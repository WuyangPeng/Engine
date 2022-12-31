///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/11/30 22:02)

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
    std::wstring wideCharResult{ wideChar.data() };
    ASSERT_EQUAL(wideCharActualLength, boost::numeric_cast<int>(wideCharResult.size() + 1));

    ASSERT_EQUAL(wideCharResult, wideCharConversionResult);
    ASSERT_EQUAL(wideCharActualLength, wideCharLength);
}
