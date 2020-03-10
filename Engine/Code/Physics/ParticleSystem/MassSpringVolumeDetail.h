// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 18:10)

#ifndef PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_VOLUME_DETAIL_H
#define PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_VOLUME_DETAIL_H

#include "MassSpringVolume.h"

namespace Physics
{

	template <typename Real, typename TVector>
	MassSpringVolume<Real, TVector>::MassSpringVolume(int numSlices, int numRows,int numCols, Real step)
		:ParticleSystemManager<Real, TVector>(numSlices*numRows*numCols, step)
	{
		mNumSlices = numSlices;
		mNumRows = numRows;
		mNumCols = numCols;
		mSliceQuantity = mNumRows * mNumCols;
		mNumSlicesM1 = mNumSlices - 1;
		mNumRowsM1 = mNumRows - 1;
		mNumColsM1 = mNumCols - 1;

		mPositionGrid = NEW1<TVector**>(mNumSlices);
		mVelocityGrid = NEW1<TVector**>(mNumSlices);
		for (int slice = 0; slice < mNumSlices; ++slice)
		{
			mPositionGrid[slice] = NEW1<TVector*>(mNumRows);
			mVelocityGrid[slice] = NEW1<TVector*>(mNumRows);
			for (int row = 0; row < mNumRows; ++row)
			{
				int i = mNumCols * (row + mNumRows * slice);
				mPositionGrid[slice][row] = &mPositions[i];
				mVelocityGrid[slice][row] = &mVelocities[i];
			}
		}

		mConstantsS = NEW3<Real>(mNumCols, mNumRows, mNumSlicesM1);
		mLengthsS = NEW3<Real>(mNumCols, mNumRows, mNumSlicesM1);
		mConstantsR = NEW3<Real>(mNumCols, mNumRowsM1, mNumSlices);
		mLengthsR = NEW3<Real>(mNumCols, mNumRowsM1, mNumSlices);
		mConstantsC = NEW3<Real>(mNumColsM1, mNumRows, mNumSlices);
		mLengthsC = NEW3<Real>(mNumColsM1, mNumRows, mNumSlices);
	}

	template <typename Real, typename TVector>
	MassSpringVolume<Real, TVector>::~MassSpringVolume()
	{
		for (int slice = 0; slice < mNumSlices; ++slice)
		{
			DELETE1(mPositionGrid[slice]);
			DELETE1(mVelocityGrid[slice]);
		}
		DELETE1(mPositionGrid);
		DELETE1(mVelocityGrid);

		DELETE3(mConstantsS);
		DELETE3(mLengthsS);
		DELETE3(mConstantsR);
		DELETE3(mLengthsR);
		DELETE3(mConstantsC);
		DELETE3(mLengthsC);
	}

	template <typename Real, typename TVector>
	int MassSpringVolume<Real, TVector>::GetNumSlices() const
	{
		return mNumSlices;
	}

	template <typename Real, typename TVector>
	int MassSpringVolume<Real, TVector>::GetNumRows() const
	{
		return mNumRows;
	}

	template <typename Real, typename TVector>
	int MassSpringVolume<Real, TVector>::GetNumCols() const
	{
		return mNumCols;
	}

	template <typename Real, typename TVector>
	void MassSpringVolume<Real, TVector>::SetMass(int slice, int row, int col,
		Real mass)
	{
		int i = GetIndex(slice, row, col);
		ParticleSystemManager<Real, TVector>::SetMass(i, mass);
	}

	template <typename Real, typename TVector>
	Real MassSpringVolume<Real, TVector>::GetMass(int slice, int row, int col) const
	{
		int i = GetIndex(slice, row, col);
		return ParticleSystemManager<Real, TVector>::GetMass(i);
	}

	template <typename Real, typename TVector>
	TVector*** MassSpringVolume<Real, TVector>::Positions3D() const
	{
		return mPositionGrid;
	}

	template <typename Real, typename TVector>
	TVector& MassSpringVolume<Real, TVector>::Position(int slice, int row,int col)
	{
		int i = GetIndex(slice, row, col);
		return ParticleSystemManager<Real, TVector>::Position(i);
	}

	template <typename Real, typename TVector>
	TVector*** MassSpringVolume<Real, TVector>::Velocities3D() const
	{
		return mVelocityGrid;
	}

	template <typename Real, typename TVector>
	TVector& MassSpringVolume<Real, TVector>::Velocity(int slice, int row,int col)
	{
		int i = GetIndex(slice, row, col);
		return ParticleSystemManager<Real, TVector>::Velocity(i);
	}

	template <typename Real, typename TVector>
	Real& MassSpringVolume<Real, TVector>::ConstantS(int slice, int row, int col)
	{
		return mConstantsS[slice][row][col];
	}

	template <typename Real, typename TVector>
	Real& MassSpringVolume<Real, TVector>::LengthS(int slice, int row, int col)
	{
		return mLengthsS[slice][row][col];
	}

	template <typename Real, typename TVector>
	Real& MassSpringVolume<Real, TVector>::ConstantR(int slice, int row, int col)
	{
		return mConstantsR[slice][row][col];
	}

	template <typename Real, typename TVector>
	Real& MassSpringVolume<Real, TVector>::LengthR(int slice, int row, int col)
	{
		return mLengthsR[slice][row][col];
	}

	template <typename Real, typename TVector>
	Real& MassSpringVolume<Real, TVector>::ConstantC(int slice, int row, int col)
	{
		return mConstantsC[slice][row][col];
	}

	template <typename Real, typename TVector>
	Real& MassSpringVolume<Real, TVector>::LengthC(int slice, int row, int col)
	{
		return mLengthsC[slice][row][col];
	}

	template <typename Real, typename TVector>
	TVector MassSpringVolume<Real, TVector>::Acceleration(int i, Real time,const TVector* positions, const TVector* velocities)
	{
		// Compute spring forces on position X[i].  The positions are not
		// necessarily mPositions since the RK4 solver in ParticleSystem
		// evaluates the acceleration function at intermediate positions.  The
		// face, edge, and corner points of the volume of masses must be handled
		// separately since each has fewer than eight spring attached to it.

		TVector acceleration = ExternalAcceleration(i, time, positions,velocities);

		TVector diff, force;
		Real ratio;

		int slice, row, col, prev, next;
		GetCoordinates(i, slice, row, col);

		if (slice > 0)
		{
			prev = i - mSliceQuantity;  // index to previous slice-neighbor
			diff = positions[prev] - positions[i];
			ratio = LengthS(slice - 1, row, col) / TVector::ToolsType::VectorMagnitude(diff);
			force = ConstantS(slice - 1, row, col)*((Real)1 - ratio)*diff;
			acceleration += mInvMasses[i] * force;
		}

		if (slice < mNumSlicesM1)
		{
			next = i + mSliceQuantity;  // index to next slice-neighbor
			diff = positions[next] - positions[i];
			ratio = LengthS(slice, row, col) / TVector::ToolsType::VectorMagnitude(diff);
			force = ConstantS(slice, row, col)*((Real)1 - ratio)*diff;
			acceleration += mInvMasses[i] * force;
		}

		if (row > 0)
		{
			prev = i - mNumCols;  // index to previous row-neighbor
			diff = positions[prev] - positions[i];
			ratio = LengthR(slice, row - 1, col) / TVector::ToolsType::VectorMagnitude(diff);
			force = ConstantR(slice, row - 1, col)*((Real)1 - ratio)*diff;
			acceleration += mInvMasses[i] * force;
		}

		if (row < mNumRowsM1)
		{
			next = i + mNumCols;  // index to next row-neighbor
			diff = positions[next] - positions[i];
			ratio = LengthR(slice, row, col) / TVector::ToolsType::VectorMagnitude(diff);
			force = ConstantR(slice, row, col)*((Real)1 - ratio)*diff;
			acceleration += mInvMasses[i] * force;
		}

		if (col > 0)
		{
			prev = i - 1;  // index to previous col-neighbor
			diff = positions[prev] - positions[i];
			ratio = LengthC(slice, row, col - 1) / TVector::ToolsType::VectorMagnitude(diff);
			force = ConstantC(slice, row, col - 1)*((Real)1 - ratio)*diff;
			acceleration += mInvMasses[i] * force;
		}

		if (col < mNumColsM1)
		{
			next = i + 1;  // index to next col-neighbor
			diff = positions[next] - positions[i];
			ratio = LengthC(slice, row, col) / TVector::ToolsType::VectorMagnitude(diff);
			force = ConstantC(slice, row, col)*((Real)1 - ratio)*diff;
			acceleration += mInvMasses[i] * force;
		}

		return acceleration;
	}

	template <typename Real, typename TVector>
	TVector MassSpringVolume<Real, TVector>::ExternalAcceleration(int, Real,const TVector*, const TVector*)
	{
		return TVector::sm_Zero;
	}

	template <typename Real, typename TVector>
	int MassSpringVolume<Real, TVector>::GetIndex(int slice, int row, int col) const
	{
		return col + mNumCols * (row + mNumRows * slice);
	}

	template <typename Real, typename TVector>
	void MassSpringVolume<Real, TVector>::GetCoordinates(int i, int& slice,int& row, int& col) const
	{
		col = i % mNumCols;
		i = (i - col) / mNumCols;
		row = i % mNumRows;
		slice = i / mNumRows;
	}



}

#endif // PHYSICS_PARTICLE_SYSTEM_MASS_SPRING_VOLUME_DETAIL_H