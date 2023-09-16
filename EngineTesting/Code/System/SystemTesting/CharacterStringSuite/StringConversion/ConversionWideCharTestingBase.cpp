///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:19)

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
