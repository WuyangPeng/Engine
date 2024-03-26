/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:38)

#include "ConversionTestingBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConversionTestingBase::ConversionTestingBase(const OStreamShared& stream, int conversionMinLength)
    : ParentType{ stream }, conversionMinLength{ conversionMinLength }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConversionTestingBase)

void System::ConversionTestingBase::LengthChecking(int length)
{
    ASSERT_TRUE_FAILURE_THROW(conversionMinLength <= length && length < defaultBufferSize, "转换字符串失败。");
}