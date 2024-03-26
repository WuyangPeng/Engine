/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:38)

#include "WideCharConversionTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WideCharConversionTestingBase::WideCharConversionTestingBase(const OStreamShared& stream, int conversionMinLength, std::string multiByteConversionResult)
    : ParentType{ stream, conversionMinLength }, multiByteConversionResult{ std::move(multiByteConversionResult) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WideCharConversionTestingBase)

void System::WideCharConversionTestingBase::ResultChecking(const MultiByteType& multiByte, int multiByteActualLength, int multiByteLength)
{
    const std::string multiByteResult{ multiByte.data() };
    ASSERT_EQUAL(multiByteActualLength, boost::numeric_cast<int>(multiByteResult.size() + 1));

    ASSERT_EQUAL(multiByteResult, multiByteConversionResult);
    ASSERT_EQUAL(multiByteActualLength, multiByteLength);
}
