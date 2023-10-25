///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 13:46)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H

#include "CoreTools/CoreToolsDll.h"

#include "UnitTestInterface.h"
#include "UnitTestStream.h"

// ʹ�����ģʽ��װUnitTest���SuiteImpl�ࡣ
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestComposite : public UnitTestStream, public UnitTestInterface
    {
    public:
        using ClassType = UnitTestComposite;
        using ParentType = UnitTestStream;
        using InterfaceType = UnitTestInterface;

        using UnitTestCompositeSharedPtr = std::shared_ptr<UnitTestComposite>;

    public:
        explicit UnitTestComposite(const OStreamShared& streamShared) noexcept;

        ~UnitTestComposite() = default;
        UnitTestComposite(const UnitTestComposite& rhs) = delete;
        UnitTestComposite& operator=(const UnitTestComposite& rhs) = delete;
        UnitTestComposite(UnitTestComposite&& rhs) noexcept;
        UnitTestComposite& operator=(UnitTestComposite&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        virtual void ClearUnitTestCollection();
        virtual void AddUnitTest(const UnitTestCompositeSharedPtr& unitTest);

        void SetTestLoopCount(int aTestLoopCount) noexcept;
        void SetRandomSeed(int aRandomSeed) noexcept;

        NODISCARD uint32_t GetEngineRandomSeed() const;

    protected:
        NODISCARD int GetTestLoopCount() const noexcept;

    private:
        int testLoopCount;
        int randomSeed;
    };
}
#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H
