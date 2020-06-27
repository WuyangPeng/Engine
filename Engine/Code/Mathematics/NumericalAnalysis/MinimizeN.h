// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_H

#include "Mathematics/MathematicsDll.h"

#include "Minimize1.h"
#include "MinimizeNData.h"
#include "MinimizeNGetMinimum.h"

#include <vector>

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class MinimizeN
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = MinimizeN<Real, UserDataType>;
		using MinimizeNData = MinimizeNData<Real>;
		using RealVector = std::vector<Real>;

		// ����С���ĺ������ͣ�result = f(t,userData)������t��dԪ�飨d�ĳߴ��ڹ��캯������
		// userData���ɹ��캯����SetUserData(*)��ָ���ṩ��
		// ��ʹ������ͨ����ľ�̬������װ��һ���Ǿ�̬��Ա����������������£��û�������һ��ָ��������ָ�롣
		// ��Ȼ���û����ݿ����Ǹ��ӵģ�����Ҫ��ȷ���������������������Ҫ��������Ϣ��
		using Function = Real(*)(const RealVector&, const UserDataType*);

	public:
		// �ѿ����˻����ṩ��GetMinimum(*)��������Сֵ�洢��t0[0..d-1] �����ֵ�洢��t1[0..d-1]������d�ǡ��ߴ硱��
		// ������ͨ�����ŵ�ǰ�����ߵ����λ��������ÿ��������������ʹ�� Minimize1<Real>����
		// ����ǡ��������ķ����趨��������Powell's Direction Set Method����
		// ������maxLevel���͡�maxBracket��������Minimize1<Real>��
		// �Ķ�������ĵ�����ͷ�ļ��������˽���Щ��ζ��ʲô��
		// ���롰maxIterations���Ƿ����趨���ĵ�����Ŀ��
		MinimizeN(int dimensions, Function function, int maxLevel, int maxBracket, int maxIterations, const UserDataType* userData);

		CLASS_INVARIANT_DECLARE;

		// ���ҵѿ����˻�������Сֵ�洢��t0[0..d-1] �����ֵ�洢��t1[0..d-1]������d�ǡ��ߴ硱��
		// ����Ĳ²�����ttInitial[0..d-1]�д洢����Сֵ��λ����tMin[0..d-1] ����С��ֵ��fMin��
		const MinimizeNData GetMinimum(const RealVector& begin, const RealVector& end, const RealVector& initial) const;

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

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_H
