///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/10 14:07)

// 不符合函数CloseHandle、SetWaitableTimer或GetProcAddress的规范。

#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 6387)
#endif  // TCRE_USE_MSVC
