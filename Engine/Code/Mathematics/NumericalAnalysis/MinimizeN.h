///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/26 14:28)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_H

#include "Mathematics/MathematicsDll.h"

#include "Minimize1.h"
#include "MinimizeNData.h"
#include "MinimizeNGetMinimum.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class MinimizeN final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = MinimizeN<Real, UserDataType>;
        using MinimizeNData = MinimizeNData<Real>;
        using Container = std::vector<Real>;
        using Math = Math<Real>;

        // ����С���ĺ������ͣ�result = f(t,userData)������t��dԪ�飨d�ĳߴ��ڹ��캯������
        // userData���ɹ��캯����SetUserData(*)��ָ���ṩ��
        // ��ʹ������ͨ����ľ�̬������װ��һ���Ǿ�̬��Ա����������������£��û�������һ��ָ��������ָ�롣
        // ��Ȼ���û����ݿ����Ǹ��ӵģ�����Ҫ��ȷ���������������������Ҫ��������Ϣ��
        using Function = Real (*)(const Container&, const UserDataType*);

    public:
        // �ѿ����˻����ṩ��GetMinimum(*)��������Сֵ�洢��t0[0..d-1] �����ֵ�洢��t1[0..d-1]������d�ǡ��ߴ硱��
        // ������ͨ�����ŵ�ǰ�����ߵ����λ��������ÿ��������������ʹ�� Minimize1<Real>����
        // ����ǡ��������ķ����趨��������Powell's Direction Set Method����
        // ������maxLevel���͡�maxBracket��������Minimize1<Real>��
        // �Ķ�������ĵ�����ͷ�ļ��������˽���Щ��ζ��ʲô��
        // ���롰maxIterations���Ƿ����趨���ĵ�����Ŀ��
        MinimizeN(int dimensions, Function function, int maxLevel, int maxBracket, int maxIterations, const UserDataType* userData) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ���ҵѿ����˻�������Сֵ�洢��t0[0..d-1] �����ֵ�洢��t1[0..d-1]������d�ǡ��ߴ硱��
        // ����Ĳ²�����ttInitial[0..d-1]�д洢����Сֵ��λ����tMin[0..d-1] ����С��ֵ��fMin��
        [[nodiscard]] const MinimizeNData GetMinimum(const Container& begin, const Container& end, const Container& initial) const;

    private:
        using MinimizeNGetMinimum = MinimizeNGetMinimum<Real, UserDataType>;

    private:
        int m_Dimensions;
        Function m_Function;
        int m_MaxLevel;
        int m_MaxBracket;
        int m_MaxIterations;
        const UserDataType* m_UserData;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_H
