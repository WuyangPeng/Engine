///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 13:52)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_IMPL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameFwd.h"

#include <memory>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE OpenGLGlutProcessManagerImpl
    {
    public:
        using ClassType = OpenGLGlutProcessManagerImpl;

        using MainFunctionHelperBaseSharedPtr = std::shared_ptr<MainFunctionHelperBase>;
        using OpenGLGlutCallBackInterfaceSharedPtr = std::shared_ptr<OpenGLGlutCallBackInterface>;

    public:
        OpenGLGlutProcessManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD static OpenGLGlutCallBackInterfaceSharedPtr GetOpenGLGlutCallBack() noexcept;

        static void SetOpenGLGlutCallBack(const OpenGLGlutCallBackInterfaceSharedPtr& aOpenGLGlutCallBack) noexcept;
        static void ClearOpenGLGlutCallBack() noexcept;
        static void SetWindowId(int window);
        NODISCARD static int GetWindowId();
        static void SetMainFunctionHelper(const MainFunctionHelperBaseSharedPtr& mainFunctionHelperBase) noexcept;
        static void ClearMainFunctionHelper() noexcept;
        NODISCARD static MainFunctionHelperBaseSharedPtr GetMainFunctionHelper();
        static void SetMillisecond(int millisecond);
        NODISCARD static int GetMillisecond();

        NODISCARD static bool PreCreate();
        NODISCARD static bool Initialize();
        static void PreIdle();
        static void Terminate();

        static void RenderScene();
        static void ChangeSize(int width, int height);
        static void TimerFunction(int timer);
        static void SpecialKeysDown(int key, int xCoordinate, int yCoordinate);
        static void KeyboardDown(unsigned char key, int xCoordinate, int yCoordinate);
        static void SpecialKeysUp(int key, int xCoordinate, int yCoordinate);
        static void KeyboardUp(unsigned char key, int xCoordinate, int yCoordinate);
        static void MouseFunction(int button, int state, int xCoordinate, int yCoordinate);
        static void MotionFunction(int xCoordinate, int yCoordinate);
        static void PassiveMotion(int xCoordinate, int yCoordinate);
        static void IdleFunction();
        static void ProcessMenu(int menuValue);
        static void TerminateFunction();

    private:
        using MainFunctionHelperBaseWeakPtr = std::weak_ptr<MainFunctionHelperBase>;

    private:
        static void DoTerminateFunction();

    private:
        static OpenGLGlutCallBackInterfaceSharedPtr openGLGlutCallBack;
        static MainFunctionHelperBaseWeakPtr mainFunctionHelper;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_MANAGE_IMPL_H
