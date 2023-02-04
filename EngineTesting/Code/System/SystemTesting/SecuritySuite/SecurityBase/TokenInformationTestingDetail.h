///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 16:58)

#ifndef SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_DETAIL_H
#define SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_DETAIL_H

#include "TokenInformationTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

template <System::TokenInformationClass TokenInformation, typename SecurityToken>
void System::TokenInformationTesting::DoTokenInformationTest()
{
    const auto tokenHandle = OpenProcessToken();

    GetTokenInformationTest<TokenInformation, SecurityToken>(tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, tokenHandle);
}

template <System::TokenInformationClass TokenInformation, typename SecurityToken>
void System::TokenInformationTesting::GetTokenInformationTest(WindowsHandle tokenHandle)
{
    const auto bufferLength = GetBufferLength(tokenHandle, TokenInformation);

    ASSERT_NOT_THROW_EXCEPTION_3(LengthTest, bufferLength, tokenHandle, TokenInformation);
}

#endif  // SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_DETAIL_H