///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:09)

// _alloca通过引发堆栈溢出异常来指示失败。应考虑改用 _malloca。

#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 6255)
#endif  // TCRE_USE_MSVC
