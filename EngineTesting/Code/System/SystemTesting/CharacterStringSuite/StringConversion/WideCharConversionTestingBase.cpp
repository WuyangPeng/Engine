///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/11/30 22:02)

#include "WideCharConversionTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WideCharConversionTestingBase::WideCharConversionTestingBase(const OStreamShared& stream, int conversionMinLength, const std::string& multiByteConversionResult)
    : ParentType{ stream, conversionMinLength }, multiByteConversionResult{ multiByteConversionResult }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WideCharConversionTestingBase)

void System::WideCharConversionTestingBase::ResultChecking(const MultiByteType& multiByte, int multiByteActualLength, int multiByteLength)
{
    std::string multiByteResult{ multiByte.data() };
    ASSERT_EQUAL(multiByteActualLength, boost::numeric_cast<int>(multiByteResult.size() + 1));

    ASSERT_EQUAL(multiByteResult, multiByteConversionResult);
    ASSERT_EQUAL(multiByteActualLength, multiByteLength);
}
