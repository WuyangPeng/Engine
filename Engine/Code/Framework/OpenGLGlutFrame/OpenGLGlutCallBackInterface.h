/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:54)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
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
        OpenGLGlutCallBackInterface& operator=(const OpenGLGlutCallBackInterface& rhs) noexcept = default;
        OpenGLGlutCallBackInterface(OpenGLGlutCallBackInterface&& rhs) noexcept = default;
        OpenGLGlutCallBackInterface& operator=(OpenGLGlutCallBackInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD int GetWindowId() const noexcept;
        void SetWindowId(int aWindowId);
        void SetMillisecond(int aMillisecond) noexcept;
        NODISCARD int64_t GetDelta() const noexcept;

        NODISCARD virtual bool PreCreate();
        NODISCARD virtual bool Initialize();
        virtual void PreIdle();
        virtual void Terminate();

        NODISCARD virtual bool RenderScene();
        NODISCARD virtual bool ChangeSize(int width, int height);
        NODISCARD virtual bool SpecialKeysDown(int key, int xCoordinate, int yCoordinate);
        NODISCARD virtual bool KeyboardDown(int key, int xCoordinate, int yCoordinate);
        NODISCARD virtual bool SpecialKeysUp(int key, int xCoordinate, int yCoordinate);
        NODISCARD virtual bool KeyboardUp(int key, int xCoordinate, int yCoordinate);
        NODISCARD virtual bool MotionFunction(int xCoordinate, int yCoordinate);
        NODISCARD virtual bool PassiveMotion(int xCoordinate, int yCoordinate);
        NODISCARD virtual bool MouseClick(int button, int state, int xCoordinate, int yCoordinate);
        NODISCARD virtual bool IdleFunction();
        NODISCARD virtual bool TimerFunction(TimerFunctionCallback callback);
        NODISCARD virtual bool ProcessMenu(int menuValue);
        virtual void DestroyWindow();

        NODISCARD virtual int GetMillisecond() const noexcept;
        NODISCARD virtual int GetTerminateKey() const noexcept;

    protected:
        NODISCARD static MouseButtonsTypes GetMouseButtonsTypes(int button) noexcept;
        NODISCARD static MouseStateTypes GetMouseStateTypes(int state) noexcept;

    private:
        int windowId;
        int millisecond;
        int64_t delta;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_INTERFACE_H
