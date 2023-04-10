///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:39)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "UnitTestInterface.h"
#include "UnitTestStream.h"
#include "UnitTestSuiteFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"

// 使用组合模式封装UnitTest类和SuiteImpl类。
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

        NODISCARD int GetRandomSeed() const noexcept;
        NODISCARD uint32_t GetEngineRandomSeed() const;

    protected:
        NODISCARD int GetTestLoopCount() const noexcept;

    private:
        int testLoopCount;
        int randomSeed;
    };
}
#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_COMPOSITE_H
