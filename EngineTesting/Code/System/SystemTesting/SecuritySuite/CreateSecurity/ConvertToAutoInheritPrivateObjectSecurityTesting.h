/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:18)

#ifndef SYSTEM_SECURITY_SUITE_CONVERT_TO_AUTO_INHERIT_PRIVATE_OBJECT_SECURITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_CONVERT_TO_AUTO_INHERIT_PRIVATE_OBJECT_SECURITY_TESTING_H

#include "CreateSecurityTestingBase.h"

namespace System
{
    class ConvertToAutoInheritPrivateObjectSecurityTesting final : public CreateSecurityTestingBase
    {
    public:
        using ClassType = ConvertToAutoInheritPrivateObjectSecurityTesting;
        using ParentType = CreateSecurityTestingBase;

    public:
        explicit ConvertToAutoInheritPrivateObjectSecurityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ConvertToAutoInheritPrivateObjectSecurityTest();

        void DoConvertToAutoInheritPrivateObjectSecurityTest(WindowsHandle tokenHandle);
        void ConvertTest(const SecurityDescriptorPtr& descriptor);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_CONVERT_TO_AUTO_INHERIT_PRIVATE_OBJECT_SECURITY_TESTING_H