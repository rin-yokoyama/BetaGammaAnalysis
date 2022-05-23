/**
 * @file APV8104Decoder.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief Decoder for the APV8104/8508 list mode data
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __APV8104_DECODER_H__
#define __APV8104_DECODER_H__

#include <vector>
#include <algorithm>
#include "APVSingleData.h"
#include "APVDecoderBase.h"
#include <map>

class APV8104Decoder : public APVDecoderBase<APVSingleData>
{
public:
	/**
	 * @brief Construct a new APV8104Decoder object
	 *
	 */
	APV8104Decoder() : APVDecoderBase<APVSingleData>(kEventDataSize), tdc_bin2ns_(1) {}
	/**
	 * @brief Destroy the APV8104Decoder object
	 *
	 */
	virtual ~APV8104Decoder() {}
	/**
	 * @brief Decode one event of data
	 *
	 * @param buff pointer to the buffer at the start of the event data
	 * @return APVSingleData* pointer to the data object
	 */
	APVSingleData *DecodeAnEvent(char *buff) override;

	/**
	 * @brief Select APV Module type. 8104 is selected by default
	 *
	 * @param name  "APV8508" or "APV8104"
	 */
	void SetAPVModuleType(std::string name);

private:
	static const int kEventDataSize = 10; // data size of one event in bytes
	const double kTDCBin2nsAPV8508 = 2;
	const double kTDCBin2nsAPV8104 = 1;
	std::map<const std::string, const double> bin2ns_map_ = {
		{"APV8508", kTDCBin2nsAPV8508},
		{"APV8104", kTDCBin2nsAPV8104}};
	static const int kTDCFPBins = 256;
	double tdc_bin2ns_;
};

#endif /// __APV8104_DECODER_H__