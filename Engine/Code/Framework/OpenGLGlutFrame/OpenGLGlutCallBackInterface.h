///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 14:18)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Framework/FrameworkDll.h"
#include "Framework/WindowProcess/WindowProcessFwd.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutCallBackInterface
    {
    public:
        using ClassType = OpenGLGlutCallBackInterface;
        using TimerFunctionCallback = void (*)(int);

    public:
        explicit OpenGLGlutCallBackInterface(int64_t delta) noexcept;
        virtual ~OpenGLGlutCallBackInterface() noexcept = default;
        OpenGLGlutCallBackInterface(const OpenGLGlutCallBackInterface& rhs) noexcept = default;
        virtual OpenGLGlutCallBackInterface& operator=(const OpenGLGlutCallBackInterface& rhs) noexcept = default;
        OpenGLGlutCallBackInterface(OpenGLGlutCallBackInterface&& rhs) noexcept = default;
        virtual OpenGLGlutCallBackInterface& operator=(OpenGLGlutCallBackInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        int GetWindowID() const noexcept;
        void SetWindowID(int window);
        void SetMillisecond(int aMillisecond) noexcept;
        NODISCARD int64_t GetDelta() const noexcept;

        NODISCARD virtual bool PreCreate();
        NODISCARD virtual bool Initialize();
        virtual void PreIdle();
        virtual void Terminate();

        virtual bool RenderScene();
        virtual bool ChangeSize(int width, int height);
        virtual bool SpecialKeysDown(int key, int xCoordinate, int yCoordinate);
        virtual bool KeyboardDown(int key, int xCoordinate, int yCoordinate);
        virtual bool SpecialKeysUp(int key, int xCoordinate, int yCoordinate);
        virtual bool KeyboardUp(int key, int xCoordinate, int yCoordinate);
        virtual bool MotionFunction(int xCoordinate, int yCoordinate);
        virtual bool PassiveMotion(int xCoordinate, int yCoordinate);
        virtual bool MouseClick(int button, int state, int xCoordinate, int yCoordinate);
        virtual bool IdleFunction();
        virtual bool TimerFunction(TimerFunctionCallback callback);
        virtual bool ProcessMenu(int menuValue);
        virtual void DestroyWindow();

        NODISCARD virtual int GetMillisecond() const noexcept;
        NODISCARD virtual int GetTerminateKey() const noexcept;

    protected:
        NODISCARD static MouseButtonsTypes GetMouseButtonsTypes(int button) noexcept;
        NODISCARD static MouseStateTypes GetMouseStateTypes(int state) noexcept;

    private:
        int windowID{ 0 };
        int millisecond{ 0 };
        int64_t delta{ 0 };
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H
