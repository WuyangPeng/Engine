//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 13:25)

// ʹ�����ģʽ��װUnitTest���SuiteImpl�ࡣ
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "UnitTestInterface.h"
#include "UnitTestStream.h"
#include "UnitTestSuiteFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestComposite : public UnitTestStream, public UnitTestInterface
    {
    public:
        using ClassType = UnitTestComposite;
        using ParentType = UnitTestStream;
        using InterfaceType = UnitTestInterface;
        using ClassShareType = NonCopyClasses;
        using UnitTestCompositeSharedPtr = std::shared_ptr<UnitTestComposite>;

    public:
        explicit UnitTestComposite(const OStreamShared& streamShared) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        virtual void ClearUnitTestCollection();
        virtual void AddUnitTest(const UnitTestCompositeSharedPtr& unitTest);

        void SetTestLoopCount(int TestLoopCount) noexcept;
        void SetRandomSeed(int randomSeed) noexcept;

        [[nodiscard]] int GetEngineeringOffsetValue() const noexcept;
        [[nodiscard]] int GetRandomSeed() const noexcept;
        [[nodiscard]] uint32_t GetEngineRandomSeed() const;

    protected:
        [[nodiscard]] int GetTestLoopCount() const noexcept;

    private:
        int m_TestLoopCount;
        int m_RandomSeed;
    };
}
#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H
