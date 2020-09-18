//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.2 (2020/09/11 16:03)

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

    // NonConstMember������ǳ�����Ա���������ڵ���ʱ�������ࡣ
    // NonConstCopyMember������ǳ�����Ա���������ڵ���ʱ�����࣬�Բ���һ�������ĸ�����
    // CopyConstructor�����帴�ƹ��캯���͸�ֵ�������

    // ����빲����Դ������ֻ�Ǹ������ָ���Ա�����й����������Share��Ϊ��׺
    struct ShareClasses
    {
    public:
        using ClassType = ShareClasses;
        using NonConstMember = TrueType;
        using NonConstCopyMember = FalseType;
        using CopyConstructor = FalseType;
    };

    // ��û���޸�����ĳ�Ա������Ϊ��������ܣ�����ֻ�Ǹ������ָ���Ա��
    struct PerformanceUnsharedClasses
    {
    public:
        using ClassType = PerformanceUnsharedClasses;
        using NonConstMember = FalseType;
        using NonConstCopyMember = FalseType;
        using CopyConstructor = FalseType;
    };

    // �����޸�����ĳ�Ա���������ƻḴ��һ�ݶ����ĸ�����
    struct CopyUnsharedClasses
    {
    public:
        using ClassType = CopyUnsharedClasses;
        using NonConstMember = TrueType;
        using NonConstCopyMember = FalseType;
        using CopyConstructor = TrueType;
    };

    // �����޸�����ĳ�Ա������ֻ�е����÷ǳ�����Ա����ʱ����Ż�ȥ����һ�ݶ����ĸ�����
    // ���ڵ��������麯��������£���ֹʹ���ӳٸ��ơ�
    struct DelayCopyUnsharedClasses
    {
    public:
        using ClassType = DelayCopyUnsharedClasses;
        using NonConstMember = FalseType;
        using NonConstCopyMember = TrueType;
        using CopyConstructor = FalseType;
    };

    // ���ֹ����
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
