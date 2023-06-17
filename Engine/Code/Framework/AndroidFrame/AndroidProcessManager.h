///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:51)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_H

#include "Framework/FrameworkDll.h"

#include "AndroidFrameFwd.h"
#include "System/Android/Fwd/AndroidFlagsFwd.h"
#include "System/Android/Using/AndroidInputUsing.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

FRAMEWORK_EXPORT_UNIQUE_PTR(AndroidProcessManager);
FRAMEWORK_NON_COPY_EXPORT_IMPL(AndroidProcessManagerImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE AndroidProcessManager : public CoreTools::Singleton<AndroidProcessManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(AndroidProcessManager);
        using ParentType = Singleton<AndroidProcessManager>;
        SINGLETON_GET_PTR_DECLARE(AndroidProcessManager);

    public:
        using AndroidCallBackInterfaceSharedPtr = std::shared_ptr<AndroidCallBackInterface>;
        using AndroidApp = System::AndroidApp;
        using AndroidInputEvent = System::AndroidInputEvent;
        using AppCmd = void (*)(AndroidApp* app, int cmd);
        using InputEvent = int (*)(AndroidApp* app, AndroidInputEvent* event);
        using Display = void (*)(AndroidApp* state, int64_t timeDelta);

    private:
        enum class AndroidProcessManagerCreate
        {
            Init,
        };

    public:
        static void Create();
        static void Destroy() noexcept;

        explicit AndroidProcessManager(AndroidProcessManagerCreate androidProcessManagerCreate);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD static AppCmd GetAppCmd() noexcept;
        NODISCARD static InputEvent GetInputEvent() noexcept;
        NODISCARD static Display GetDisplay() noexcept;

        NODISCARD AndroidCallBackInterfaceSharedPtr GetAndroidCallBackInterface() const;

        void SetAndroidCallBack(const AndroidCallBackInterfaceSharedPtr& androidCallBack);
        void ClearAndroidCallBack();

        NODISCARD bool PreCreate();
        NODISCARD bool Initialize();
        void PreIdle();
        void Terminate();

    private:
        void DestroyImpl();

    private:
        static std::unique_ptr<AndroidProcessManager> androidProcessManager;
        PackageType impl;
    };
}

#define ANDROID_PROCESS_MANAGE_SINGLETON Framework::AndroidProcessManager::GetSingleton()

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_PROCESS_MANAGE_H
