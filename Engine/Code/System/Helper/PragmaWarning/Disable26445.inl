/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/03 14:36)

/// 警告：请勿将 gsl::span 或 std::string_view 分配给引用。它们的构造成本低廉，并且不是基础数据的所有者。

#if defined(TCRE_USE_MSVC)

    #pragma warning(disable : 26445)

#endif  // TCRE_USE_MSVC
