///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/23 16:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H

#include "Mathematics/MathematicsDll.h"

#include "BrentsMethodRoot.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class BrentsMethod final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BrentsMethod<Real, UserDataType>;
        using Math = Math<Real>;
        using BrentsMethodRoot = BrentsMethodRoot<Real>;

        // һ������F(x)������һ������Ĳ�����
        // ���㴫���û���������ݸ���Ҫ�����ĺ�����
        using Function = Real (*)(Real, const UserDataType*);

    public:
        // ����Brent�ķ������ڼ���һ�������ĸ��ļ��[x0,x1]����f(x0) * f(x1) < 0�ķ�����
        // ʹ������β�ֵ���Բ���һ�����Ƹ���
        // �����Ҫ�Ļ����ں����ʵʩ�������ڲ壨�������
        // ���⣬������ǰ�����У����������ڲ�Ĺ����ǲ��㹻����ʱ���÷��������˵����ַ���

        //  function:
        //  ���������������ġ�����ָ�����ǿա�

        //  maxIterations:
        //  ���ڶ�λһ��������������������Ӧ�������ġ�
        //  negativeFTolerance, positiveFTolerance:
        //  ������x������ʱ�ĺ���ֵf(x)����
        //  negativeFTolerance <= f(x) <= positiveFTolerance��
        //  ֵ�������㣺negativeFTolerance <= 0, positiveFTolerance >= 0��
        //  stepXTolerance:
        //  Brent�ķ�����Ҫ����Ĳ���֮ǰ���ڲ�xֵ������Ϊ��һ�����Ƹ���
        //  ��Щ���Խ��бȽϵ����������Ĳ��죬
        //  ��Ҫ�������û�ָ����x����ϴ�����ȷ�����ȣ���
        //  �˲�����ƫ�
        //  convXTolerance:
        //  ������������ʱ����ֹ��ǰ�ӵ���[xsub0,xsub1]���㹻С�ģ�
        //  Ҳ����˵��|xsub1 - xsub0| <= tolerance���˲�����ƫ�
        //  userData:
        //  �˲��������㴫������Ҫ�����ĺ���ר�ŵ����ݡ�
        //  ͨ������£���function����һ����ľ�̬�������Ի��C���ĺ���ָ�룩
        //  �͡�userData����'this'���������ݵ�һ���Ӽ��ġ�this��ָ�룩��

        BrentsMethod(Function function, int maxIterations, Real negativeFTolerance, Real positiveFTolerance,
                     Real stepXTolerance, Real convXTolerance, const UserDataType* userData) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetFunction(Function function);
        [[nodiscard]] Function GetFunction() const noexcept;
        void SetMaxIterations(int maxIterations) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] int GetMaxIterations() const noexcept;
        void SetNegativeFTolerance(Real negativeFTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real GetNegativeFTolerance() const noexcept;
        void SetPositiveFTolerance(Real positiveFTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real GetPositiveFTolerance() const noexcept;
        void SetStepXTolerance(Real stepXTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real GetStepXTolerance() const noexcept;
        void SetConvXTolerance(Real convXTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real GetConvXTolerance() const noexcept;
        void SetUserData(const UserDataType* userData) noexcept;
        [[nodiscard]] const UserDataType* GetUserData() const noexcept;

        [[nodiscard]] Real GetFunctionValue(Real value) const;

        // �����صĸ��н�ʱ��x�Ǹ���y�Ǹ��ĺ���ֵ��
        [[nodiscard]] const BrentsMethodRoot GetRoot(Real begin, Real end);

    private:
        Function m_Function;
        int m_MaxIterations;
        Real m_NegativeFTolerance;
        Real m_PositiveFTolerance;
        Real m_StepXTolerance;
        Real m_ConvXTolerance;
        const UserDataType* m_UserData;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H
