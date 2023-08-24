///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 15:24)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MIDDLE_LAYER_INTERFACE_TESTING_BASE_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MIDDLE_LAYER_INTERFACE_TESTING_BASE_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/MiddleLayer/EngineMiddleLayerInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
    class MiddleLayerInterfaceTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = MiddleLayerInterfaceTestingBase;
        using ParentType = UnitTest;

    public:
        explicit MiddleLayerInterfaceTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using EnvironmentParameter = Rendering::EnvironmentParameter;
        using SetManagerFunction = void (EngineMiddleLayerInterface::*)(const MiddleLayerInterfaceSharedPtr&);

    protected:
        template <typename TestingType>
        void MiddleLayerMemberTest();

        template <typename TestingType>
        void MiddleLayerTest();

        template <typename TestingType>
        void KeyUpExceptionTest();

        template <typename TestingType>
        void KeyDownExceptionTest();

        template <typename TestingType>
        void SpecialKeyUpExceptionTest();

        template <typename TestingType>
        void SpecialKeyDownExceptionTest();

        template <typename TestingType>
        void PassiveMotionExceptionTest();

        template <typename TestingType>
        void MotionExceptionTest();

        template <typename TestingType>
        void MouseWheelExceptionTest();

        template <typename TestingType>
        void MouseClickExceptionTest();

        template <typename TestingType>
        void SetManagerExceptionTest(SetManagerFunction setManagerFunction);

        template <typename TestingType, typename GetManagerFunction = MiddleLayerInterfaceSharedPtr (TestingType::*)()>
        void GetManagerExceptionTest(GetManagerFunction getManagerFunction);

        template <typename TestingType, typename GetConstManagerFunction = ConstMiddleLayerInterfaceSharedPtr (TestingType::*)() const>
        void GetConstManagerExceptionTest(GetConstManagerFunction getManagerFunction);

    protected:
        NODISCARD MiddleLayerPlatform GetMiddleLayerPlatform() const noexcept;
        NODISCARD EnvironmentDirectory GetEnvironmentDirectory() const noexcept;
        NODISCARD WindowPoint GetWindowPoint() const noexcept;
        NODISCARD WindowSize GetWindowSize() const noexcept;

    private:
        MiddleLayerPlatform middleLayerPlatform;
        EnvironmentDirectory environmentDirectory;
        WindowPoint point;
        WindowSize size;
        VirtualKeysTypes virtualKeysTypes;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_MIDDLE_LAYER_INTERFACE_TESTING_BASE_H