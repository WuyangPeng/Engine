///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 2:10)

#include "CryptographyForDevelopersPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CryptographyForDevelopers/Helper/CryptographyForDevelopersClassInvariantMacro.h"

BookAlgorithm::CryptographyForDevelopers::CryptographyForDevelopersPlaceholderTesting::CryptographyForDevelopersPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CRYPTOGRAPHY_FOR_DEVELOPERS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::CryptographyForDevelopers, CryptographyForDevelopersPlaceholderTesting)

void BookAlgorithm::CryptographyForDevelopers::CryptographyForDevelopersPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::CryptographyForDevelopers::CryptographyForDevelopersPlaceholderTesting::MainTest() noexcept
{
}
