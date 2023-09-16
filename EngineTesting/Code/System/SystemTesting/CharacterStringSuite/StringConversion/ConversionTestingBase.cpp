///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:19)

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
    ASSERT_TRUE_FAILURE_THROW(conversionMinLength <= length && length < bufferSize, "ת���ַ���ʧ�ܡ�");
}