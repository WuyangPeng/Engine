/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:24)

#ifndef SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_TESTING_BASE_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class AccessesGrantedTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = AccessesGrantedTestingBase;
        using ParentType = UnitTest;

    public:
        explicit AccessesGrantedTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using MaskContainer = std::map<FileHandleDesiredAccess, AccessGenericMask>;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_TESTING_BASE_H