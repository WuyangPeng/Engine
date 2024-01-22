/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:53)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_H

#include "Framework/FrameworkDll.h"

#include "OpenGLGlutCallBackInterface.h"
#include "System/OpenGL/Using/GlutUsing.h"

#include <type_traits>

namespace Framework
{
    template <typename OpenGLGlutCallBack>
    class OpenGLGlutProcess
    {
    public:
        static_assert(std::is_base_of_v<OpenGLGlutCallBackInterface, OpenGLGlutCallBack>);

    public:
        using ClassType = OpenGLGlutProcess<OpenGLGlutCallBack>;

        using RenderSceneCallback = System::RenderSceneCallback;
        using ChangeSizeCallback = System::ChangeSizeCallback;
        using TimerFunctionCallback = System::TimerFunctionCallback;
        using SpecialKeysDownCallback = System::SpecialKeysDownCallback;
        using KeyboardDownCallback = System::KeyboardDownCallback;
        using SpecialKeysUpCallback = System::SpecialKeysUpCallback;
        using KeyboardUpCallback = System::KeyboardUpCallback;
        using MouseFunctionCallback = System::MouseFunctionCallback;
        using MotionFunctionCallback = System::MotionFunctionCallback;
        using PassiveMotionFunctionCallback = System::PassiveMotionFunctionCallback;
        using IdleFunctionCallback = System::IdleFunctionCallback;
        using ProcessMenuCallback = System::ProcessMenuCallback;
        using TerminateCallback = System::TerminateCallback;

    public:
        explicit OpenGLGlutProcess(int64_t delta);
        virtual ~OpenGLGlutProcess() noexcept = default;
        OpenGLGlutProcess(const OpenGLGlutProcess& rhs) noexcept = default;
        OpenGLGlutProcess& operator=(const OpenGLGlutProcess& rhs) noexcept = default;
        OpenGLGlutProcess(OpenGLGlutProcess&& rhs) noexcept = default;
        OpenGLGlutProcess& operator=(OpenGLGlutProcess&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD RenderSceneCallback GetRenderSceneCallback() const noexcept;
        NODISCARD ChangeSizeCallback GetChangeSizeCallback() const noexcept;
        NODISCARD TimerFunctionCallback GetTimerFunctionCallback() const noexcept;
        NODISCARD SpecialKeysDownCallback GetSpecialKeysDownCallback() const noexcept;
        NODISCARD KeyboardDownCallback GetKeyboardDownCallback() const noexcept;
        NODISCARD SpecialKeysUpCallback GetSpecialKeysUpCallback() const noexcept;
        NODISCARD KeyboardUpCallback GetKeyboardUpCallback() const noexcept;
        NODISCARD MouseFunctionCallback GetMouseFunctionCallback() const noexcept;
        NODISCARD MotionFunctionCallback GetMotionFunctionCallback() const noexcept;
        NODISCARD PassiveMotionFunctionCallback GetPassiveMotionCallback() const noexcept;
        NODISCARD IdleFunctionCallback GetIdleFunctionCallback() const noexcept;
        NODISCARD ProcessMenuCallback GetProcessMenuCallback() const noexcept;
        NODISCARD TerminateCallback GetTerminateCallback() const noexcept;

        void SetWindowId(int window);
        void SetMillisecond(int millisecond);
        NODISCARD int GetMillisecond() const;
        NODISCARD int GetWindowId() const;

        NODISCARD virtual bool PreCreate();
        NODISCARD virtual bool Initialize();
        virtual void PreIdle();
        virtual void Terminate();
    };

    using OpenGLGlutProcessInterface = OpenGLGlutProcess<OpenGLGlutCallBackInterface>;
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_H
