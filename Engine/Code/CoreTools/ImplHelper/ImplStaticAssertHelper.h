//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/11 16:03)

#ifndef CORE_TOOLS_IMPL_HELPER_IMPL_STATIC_ASSERT_HELPER_H
#define CORE_TOOLS_IMPL_HELPER_IMPL_STATIC_ASSERT_HELPER_H

namespace CoreTools
{
    struct TrueType
    {
    };

    struct FalseType
    {
    };

    // NonConstMember：定义非常量成员函数，且在调用时不复制类。
    // NonConstCopyMember：定义非常量成员函数，且在调用时复制类，以产生一个独立的副本。
    // CopyConstructor：定义复制构造函数和赋值运算符。

    // 类必须共享资源，复制只是复制类的指针成员。所有共享类必须以Share作为后缀
    struct ShareClasses
    {
    public:
        using ClassType = ShareClasses;
        using NonConstMember = TrueType;
        using NonConstCopyMember = FalseType;
        using CopyConstructor = FalseType;
    };

    // 类没有修改自身的成员函数，为了提高性能，复制只是复制类的指针成员。
    struct PerformanceUnsharedClasses
    {
    public:
        using ClassType = PerformanceUnsharedClasses;
        using NonConstMember = FalseType;
        using NonConstCopyMember = FalseType;
        using CopyConstructor = FalseType;
    };

    // 类有修改自身的成员函数，复制会复制一份独立的副本。
    struct CopyUnsharedClasses
    {
    public:
        using ClassType = CopyUnsharedClasses;
        using NonConstMember = TrueType;
        using NonConstCopyMember = FalseType;
        using CopyConstructor = TrueType;
    };

    // 类有修改自身的成员函数，只有当调用非常量成员函数时，类才会去复制一份独立的副本。
    // 对于导出类有虚函数的情况下，禁止使用延迟复制。
    struct DelayCopyUnsharedClasses
    {
    public:
        using ClassType = DelayCopyUnsharedClasses;
        using NonConstMember = FalseType;
        using NonConstCopyMember = TrueType;
        using CopyConstructor = FalseType;
    };

    // 类禁止复制
    struct NonCopyClasses
    {
    public:
        using ClassType = NonCopyClasses;
        using NonConstMember = TrueType;
        using NonConstCopyMember = FalseType;
        using CopyConstructor = FalseType;
    };
}

#endif  // CORE_TOOLS_IMPL_HELPER_IMPL_STATIC_ASSERT_HELPER_H
