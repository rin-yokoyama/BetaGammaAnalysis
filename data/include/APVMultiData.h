/**
 * @file APVMultiData.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief Data container object for multiple APVSingleData
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __APV_MULTI_DATA_H__
#define __APV_MULTI_DATA_H__

#include <vector>
#include <TObject.h>
#include "APVSingleData.h"

class APVMultiData : public TObject
{
public:
	/**
	 * @brief Construct a new APVMultiData object
	 *
	 */
	APVMultiData() {}
	/**
	 * @brief Construct a copy of the APVMultiData object
	 *
	 * @param obj
	 */
	APVMultiData(const APVMultiData &obj) : TObject(obj)
	{
		data_vec_ = obj.data_vec_;
	}
	/**
	 * @brief Destroy the APVMultiData object
	 *
	 */
	virtual ~APVMultiData() {}

	void SetData(std::vector<APVSingleData *> data) { data_vec_ = data; }
	std::vector<APVSingleData*> &GetData() { return data_vec_;}

private:
	std::vector<APVSingleData *> data_vec_;
	ClassDef(APVMultiData, 1)
};

#endif /// __APV_MULTI_DATA_H__
