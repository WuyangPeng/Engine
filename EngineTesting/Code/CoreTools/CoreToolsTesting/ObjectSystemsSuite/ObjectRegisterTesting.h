/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/24 15:12)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H

#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ObjectRegisterTesting final : public UnitTest
    {
    public:
        using ClassType = ObjectRegisterTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectRegisterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ObjectAssociated = ObjectAssociated<Object>;
        using WeakObjectAssociated = WeakObjectAssociated<Object>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void UniqueIdExceptionTest();
        void RegisterRootSucceedTest();
        void RegisterObjectSucceedTest();
        void RegisterWeakObjectSucceedTest();
        void RegisterObjectContainerSucceedTest();
        void RegisterObjectArraySucceedTest();

        void RegisterRootSucceedResultTest(const ObjectRegister& objectRegister);
        void RegisterObjectSucceedResultTest(const ObjectRegister& objectRegister);
        void RegisterWeakObjectSucceedResultTest(const ObjectRegister& objectRegister);
        void RegisterObjectContainerSucceedResultTest(const ObjectRegister& objectRegister);
        void RegisterObjectArraySucceedResultTest(const ObjectRegister& objectRegister);

    private:
        BoolObjectSharedPtr boolObject;
        EnumObjectSharedPtr enumObject;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H