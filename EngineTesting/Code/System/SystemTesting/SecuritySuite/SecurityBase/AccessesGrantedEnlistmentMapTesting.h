/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:24)

#ifndef SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_ENLISTMENT_MAP_TESTING_H
#define SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_ENLISTMENT_MAP_TESTING_H

#include "AccessesGrantedTestingBase.h"

namespace System
{
    class AccessesGrantedEnlistmentMapTesting final : public AccessesGrantedTestingBase
    {
    public:
        using ClassType = AccessesGrantedEnlistmentMapTesting;
        using ParentType = AccessesGrantedTestingBase;

    public:
        explicit AccessesGrantedEnlistmentMapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void EnlistmentMapGenericMaskTest();

        void DoEnlistmentMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask);

    private:
        MaskContainer masks;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_ENLISTMENT_MAP_TESTING_H