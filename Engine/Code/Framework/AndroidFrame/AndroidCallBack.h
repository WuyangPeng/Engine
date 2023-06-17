///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:51)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_H

#include "AndroidCallBackInterface.h"

#include <memory>

namespace Framework
{
    template <typename MiddleLayer>
    class AndroidCallBack : public AndroidCallBackInterface
    {
    public:
        using MiddleLayerType = MiddleLayer;
        using ClassType = AndroidCallBack<MiddleLayer>;
        using ParentType = AndroidCallBackInterface;

    public:
        explicit AndroidCallBack(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void RedrawNeededMessage(AndroidApp* androidApp) override;
        void ResizedMessage(AndroidApp* androidApp) override;
        void RectChanged(AndroidApp* androidApp) override;
        void InitMessage(AndroidApp* androidApp) override;
        void TermMessage(AndroidApp* androidApp) override;
        void Display(AndroidApp* androidApp, int64_t timeDelta) override;
        NODISCARD int KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
        NODISCARD int KeyUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
        NODISCARD int ActionDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
        NODISCARD int ActionUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
        NODISCARD int ActionMoveMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;

    private:
        using MiddleLayerTypeSharedPtr = std::shared_ptr<MiddleLayerType>;

    private:
        MiddleLayerTypeSharedPtr middleLayer;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_H
