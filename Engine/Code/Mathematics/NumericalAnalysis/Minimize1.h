///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/15 11:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_H

#include "Mathematics/MathematicsDll.h"

#include "Minimize1DataDetail.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class Minimize1 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Minimize1<Real, UserDataType>;

        // ��С���ĺ������ͣ�result = f(t,userData)��
        // userData��ͨ�����캯����SetUserData(*)���õ�ָ�롣
        // ��ʹ������ͨ��һ����ľ�̬������װ����һ���Ǿ�̬��Ա������
        // ����������£��û�������һ��ָ�������
        // ��Ȼ��������Ҫ����ȷ����function��ӵ�����м������������Ϣ��
        // �û����ݿ����Ǹ��ӵġ�
        using Function = Real (*)(Real, const UserDataType*);
        using Minimize1Data = Minimize1Data<Real>;
        using Math = Math<Real>;

    public:
        // ����[t0,t1]�ṩ��GetMinimum(Real,Real,Real)
        // ��ͨ�������������д���
        // ��ÿ��������[a,b]��ֵf0 = f(a)��f1 = f((a+b)/2)��
        // ��f2 = f(b)�ļ�顣
        // ���{f0,f1,f2}�ǵ����ģ�Ȼ��[a,b]��ϸ�ֺʹ���
        // �ݹ����������ͨ��'maxLevel'�޶���
        // ���{f0,f1,f2}���ǵ����ģ�������������������
        // ���ȣ����f1 = min{f0,f1,f2}����{f0,f1,f2}����ʾΪ
        // �����ŵ���Сֵ����
        // GetBracketedMinimum(*)�������Զ�λ������Сֵ��
        // �÷���ʹ�ö��ֵ�һ����ʽ����Ϊ�������߲�ֵ��
        // ���ȷֲ����������Ŀ�ǡ�maxBracket'��
        // ��Σ����Ϊf1 = max{f0,f1,f2}��
        // ��{f0,f1,f2}Ϊ�������ֵ��
        // ��С���������ݹ���֮ǰ��[a,(a+b)/2] �� [(a+b)/2,b]�ϡ�
        Minimize1(Function function, int maxLevel, int maxBracket, const UserDataType* userData) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetUserData(const UserDataType* newUserData) noexcept;
        NODISCARD const UserDataType* GetUserData() const noexcept;

        // ����'function'����С������[t0,t1]ʹ��
        // ��tInitial��Ϊ��ʼ�²���'function'ֵ��
        // ��С��λ��Ϊ'tMin'����С��ֵ��'fMin'��
        // ���صĵ�һ����ΪtMin�͵ڶ�����ΪfMin
        NODISCARD Minimize1Data GetMinimum(Real begin, Real end, Real initial) const;

    private:
        // ���ǵ��õĿ�ʼ������ص�[t0,tInitial]��[tInitial,t1]��
        void CompareMinimum(Real begin, Real beginFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const;

    private:
        // ���ǵ��õݹ�������[a,(a+b)/2] �� [(a+b)/2,b]��
        void CompareMinimum(Real begin, Real beginFunction, Real middle, Real middleFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const;

        // ���ǵ��õ�{f0,f1,f2}��������Сֵʱ��
        void CompareBracketedMinimum(Real begin,
                                     Real beginFunction,
                                     Real middle,
                                     Real middleFunction,
                                     Real end,
                                     Real endFunction,
                                     int level,
                                     Minimize1Data& minimize1Data) const;

    private:
        Function function;
        int maxLevel;
        int maxBracket;
        const UserDataType* userData;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_H
