///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 14:06)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_H

#include "OpenGLGlutCallBackInterface.h"
#include "CoreTools/Time/CustomTime.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
    template <typename MiddleLayer>
    class OpenGLGlutCallBack : public OpenGLGlutCallBackInterface
    {
    public:
        using MiddleLayerType = MiddleLayer;
        using ClassType = OpenGLGlutCallBack<MiddleLayerType>;
        using ParentType = OpenGLGlutCallBackInterface;
        using CustomTime = CoreTools::CustomTime;

    public:
        explicit OpenGLGlutCallBack(int64_t delta);

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
        using MiddleLayerTypeSharedPtr = std::shared_ptr<MiddleLayerType>;

    private:
        void SetGLUTModifiers(int aButton, int state) noexcept;

    private:
        MiddleLayerTypeSharedPtr middleLayer;
        CustomTime lastTime;
        VirtualKeysTypes glutModifiers;
        MouseButtonsTypes button;
        int64_t accumulative;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_H
