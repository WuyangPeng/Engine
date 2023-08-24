///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 13:59)

#ifndef FRAMEWORK_OPEN_GL_GLUT_FRAME_OPEN_GL_GLUT_CALL_BACK_H
#define FRAMEWORK_OPEN_GL_GLUT_FRAME_OPEN_GL_GLUT_CALL_BACK_H

#include "Framework/FrameworkDll.h"

#include "OpenGLGlutCallBackInterface.h"
#include "CoreTools/Time/CustomTime.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
    template <typename MiddleLayer>
    class OpenGLGlutCallBack : public OpenGLGlutCallBackInterface
    {
    public:
        using ClassType = OpenGLGlutCallBack<MiddleLayer>;
        using ParentType = OpenGLGlutCallBackInterface;

        using CustomTime = CoreTools::CustomTime;

    public:
        OpenGLGlutCallBack(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool RenderScene() override;
        NODISCARD bool ChangeSize(int width, int height) override;
        NODISCARD bool SpecialKeysDown(int key, int xCoordinate, int yCoordinate) override;
        NODISCARD bool KeyboardDown(int key, int xCoordinate, int yCoordinate) override;
        NODISCARD bool SpecialKeysUp(int key, int xCoordinate, int yCoordinate) override;
        NODISCARD bool KeyboardUp(int key, int xCoordinate, int yCoordinate) override;
        NODISCARD bool MotionFunction(int xCoordinate, int yCoordinate) override;
        NODISCARD bool PassiveMotion(int xCoordinate, int yCoordinate) override;
        NODISCARD bool MouseClick(int button, int state, int xCoordinate, int yCoordinate) override;
        NODISCARD bool IdleFunction() override;
        NODISCARD bool TimerFunction(TimerFunctionCallback callback) override;
        NODISCARD bool ProcessMenu(int menuValue) override;
        void DestroyWindow() override;

    private:
        using MiddleLayerTypeUniquePtr = std::unique_ptr<MiddleLayer>;

    private:
        void SetGlutModifiers(int aButton, int state) noexcept;

    private:
        MiddleLayerTypeUniquePtr middleLayer;
        CustomTime lastTime;
        VirtualKeysTypes glutModifiers;
        MouseButtonsTypes button;
        int64_t accumulative;
    };
}

#endif  // FRAMEWORK_OPEN_GL_GLUT_FRAME_OPEN_GL_GLUT_CALL_BACK_H
