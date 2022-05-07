///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/05 18:37)
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