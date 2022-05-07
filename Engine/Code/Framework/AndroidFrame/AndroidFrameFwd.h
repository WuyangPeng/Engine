///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 18:37)
#ifndef FRAMEWORK_ANDROID_FRAME_FWD_H
#define FRAMEWORK_ANDROID_FRAME_FWD_H

namespace Framework
{
    class AndroidProcessManager;

    template <typename AndroidCallBack>
    class AndroidProcess;

    class AndroidCallBackInterface;

    template <typename MiddleLayer>
    class AndroidCallBack;

    class AndroidCallBackUnitTestSuite;
    class AndroidMessageLoop;

    template <typename AndroidProcess>
    class AndroidFrameBuild;
}

#endif  // FRAMEWORK_ANDROID_FRAME_FWD_H