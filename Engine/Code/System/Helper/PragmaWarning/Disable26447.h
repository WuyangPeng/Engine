///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/10 14:16)

// 该函数声明为noexcept，但调用可能引发异常的函数。

#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 26447)
#endif  // TCRE_USE_MSVC