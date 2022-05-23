/**
 * @file APVSingleData.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief Data container for a single hit data from APV modules
 * @version 0.1
 * @date 2022-04-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __APVSINGLEDATA_H__
#define __APVSINGLEDATA_H__
#include "TObject.h"

class APVSingleData : public TObject
{
public:
	/**
	 * @brief Default constructor of an APVSingleData object
	 *
	 */
	APVSingleData() {}

	/**
	 * @brief Construct a new APVSingleData object
	 *
	 * @param run_number
	 * @param event_id
	 * @param timing
	 * @param charge
	 */

	APVSingleData(Int_t run_number, const ULong64_t &event_id, Int_t channel, const Double_t &timing, const Double_t &charge) : fRunNumber(run_number), fEventId(event_id), fID(channel), fTiming(timing), fCharge(charge) {}
	/**
	 * @brief Copy constructor of an APVSingleData object
	 *
	 * @param obj
	 */

	APVSingleData(const APVSingleData &obj) : TObject(obj)
	{
		fRunNumber = obj.GetRunNumber();
		fEventId = obj.GetEventId();
		fID = obj.GetID();
		fTiming = obj.GetTiming();
		fCharge = obj.GetCharge();
	}
	/**
	 * @brief Destroy the APVSingleData object
	 *
	 */
	virtual ~APVSingleData() {}

	/**
	 * @brief Set the Data of this APVSignleData object
	 *
	 * @param run_number
	 * @param event_id
	 * @param channel
	 * @param timing
	 * @param charge
	 */
	void SetData(Int_t run_number, const ULong64_t &event_id, Int_t channel, const Double_t &timing, const Double_t &charge)
	{
		fRunNumber = run_number;
		fEventId = event_id;
		fID = channel;
		fTiming = timing;
		fCharge = charge;
	}

	/**
	 * @brief Get the Run Number
	 *
	 * @return Int_t
	 */
	Int_t GetRunNumber() const { return fRunNumber; }
	/**
	 * @brief Get the Event Id
	 *
	 * @return ULong64_t
	 */
	ULong64_t GetEventId() const { return fEventId; }
	/**
	 * @brief Get the Channel object
	 *
	 * @return Int_t
	 */
	Int_t GetID() const { return fID; }
	/**
	 * @brief Get the Timing
	 *
	 * @return Double_t
	 */
	Double_t GetTiming() const { return fTiming; }
	/**
	 * @brief Get the Charge
	 *
	 * @return Double_t
	 */
	Double_t GetCharge() const { return fCharge; }

	void SetID(Int_t id) { fID = id; }
private:
	Int_t fRunNumber;
	ULong64_t fEventId;
	ULong64_t fTimestamp;
	UInt_t fADS;
	Int_t fID;
	Double_t fTiming;
	Double_t fCharge;

	ClassDef(APVSingleData, 1)
};

#endif // __APVSingleDATA_H__