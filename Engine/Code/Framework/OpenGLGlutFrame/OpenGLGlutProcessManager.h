///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 15:02)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_H

#include "Framework/FrameworkDll.h"

#include "System/OpenGL/Using/GlutUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperBase.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameFwd.h"

FRAMEWORK_EXPORT_UNIQUE_PTR(OpenGLGlutProcessManager);
FRAMEWORK_NON_COPY_EXPORT_IMPL(OpenGLGlutProcessManagerImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutProcessManager : public CoreTools::Singleton<OpenGLGlutProcessManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(OpenGLGlutProcessManager);
        using ParentType = Singleton<OpenGLGlutProcessManager>;

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
        using MainFunctionHelperBaseSharedPtr = std::shared_ptr<MainFunctionHelperBase>;
        using OpenGLGlutCallBackInterfaceSharedPtr = std::shared_ptr<OpenGLGlutCallBackInterface>;

    private:
        enum class OpenGLGlutProcessManagerCreate
        {
            Init,
        };

    public:
        static void Create();
        static void Destroy() noexcept;

        explicit OpenGLGlutProcessManager(OpenGLGlutProcessManagerCreate openGLGlutProcessManagerCreate);

        CLASS_INVARIANT_DECLARE;

        SINGLETON_GET_PTR_DECLARE(OpenGLGlutProcessManager);

    public:
        NODISCARD static RenderSceneCallback GetRenderSceneCallback() noexcept;
        NODISCARD static ChangeSizeCallback GetChangeSizeCallback() noexcept;
        NODISCARD static TimerFunctionCallback GetTimerFunctionCallback() noexcept;
        NODISCARD static SpecialKeysDownCallback GetSpecialKeysDownCallback() noexcept;
        NODISCARD static KeyboardDownCallback GetKeyboardDownCallback() noexcept;
        NODISCARD static SpecialKeysUpCallback GetSpecialKeysUpCallback() noexcept;
        NODISCARD static KeyboardUpCallback GetKeyboardUpCallback() noexcept;
        NODISCARD static MouseFunctionCallback GetMouseFunctionCallback() noexcept;
        NODISCARD static MotionFunctionCallback GetMotionFunctionCallback() noexcept;
        NODISCARD static PassiveMotionFunctionCallback GetPassiveMotionCallback() noexcept;
        NODISCARD static IdleFunctionCallback GetIdleFunctionCallback() noexcept;
        NODISCARD static ProcessMenuCallback GetProcessMenuCallback() noexcept;
        NODISCARD static TerminateCallback GetTerminateCallback() noexcept;

        NODISCARD OpenGLGlutCallBackInterfaceSharedPtr GetOpenGLGlutCallBackInterface() const;
        void SetOpenGLGlutCallBack(const OpenGLGlutCallBackInterfaceSharedPtr& openGLGlutCallBack);
        void ClearOpenGLGlutCallBack();

        void SetWindowId(int window);
        NODISCARD int GetWindowId() const;
        void SetMillisecond(int millisecond);
        NODISCARD int GetMillisecond() const;

        void SetMainFunctionHelper(const MainFunctionHelperBaseSharedPtr& mainFunctionHelper);
        void ClearMainFunctionHelper();
        NODISCARD MainFunctionHelperBaseSharedPtr GetMainFunctionHelper();

        bool PreCreate();
        bool Initialize();
        void PreIdle();
        void Terminate();

    private:
        using OpenGLGlutProcessManagerUniquePtr = std::unique_ptr<OpenGLGlutProcessManager>;

    private:
        static OpenGLGlutProcessManagerUniquePtr openGLGlutProcessManager;
        PackageType impl;
    };
}

#define OPENGL_GLUT_PROCESS_MANAGER_SINGLETON Framework::OpenGLGlutProcessManager::GetSingleton()

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_H
