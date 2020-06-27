// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_H

#include "Mathematics/MathematicsDll.h"

#include "Minimize1DataDetail.h"

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class Minimize1
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
		using Function = Real(*)(Real, const UserDataType*);
		using Minimize1Data = Minimize1Data<Real>;

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
		Minimize1(Function function, int maxLevel, int maxBracket, const UserDataType* userData);
		~Minimize1();

		CLASS_INVARIANT_DECLARE;

		void SetUserData(const UserDataType* userData);
		const UserDataType* GetUserData() const;

		// ����'function'����С������[t0,t1]ʹ��
		// ��tInitial��Ϊ��ʼ�²���'function'ֵ��
		// ��С��λ��Ϊ'tMin'����С��ֵ��'fMin'��
		// ���صĵ�һ����ΪtMin�͵ڶ�����ΪfMin
		const Minimize1Data GetMinimum(Real begin, Real end, Real initial) const;

	private:
		// ���ǵ��õĿ�ʼ������ص�[t0,tInitial]��[tInitial,t1]��
		void CompareMinimum(Real begin, Real beginFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const;

	private:
		// ���ǵ��õݹ�������[a,(a+b)/2] �� [(a+b)/2,b]��
		void CompareMinimum(Real begin, Real beginFunction, Real middle, Real middleFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const;

		// ���ǵ��õ�{f0,f1,f2}��������Сֵʱ��
		void CompareBracketedMinimum(Real begin, Real beginFunction, Real middle, Real middleFunction,
									 Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const;

	private:
		Function m_Function;
		int m_MaxLevel;
		int m_MaxBracket;
		const UserDataType* m_UserData;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_H
