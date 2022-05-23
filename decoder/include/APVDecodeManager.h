/**
 * @file APVDecodeManager.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief Manage running the apv decoder
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __APV_DECODE_MANAGER_H__
#define __APV_DECODE_MANAGER_H__

#include <fstream>
#include <string>
#include <thread>
#include <TTree.h>
#include <TFile.h>
#include "APV8104Decoder.h"
#include "APVMultiData.h"
#include "ProgressPrinter.h"

class APVDecodeManager
{
public:
	/**
	 * @brief Construct a new APVDecodeManager object
	 *
	 * @param ifname input binary file name
	 * @param ofname output root file name
	 */
	APVDecodeManager(std::string ifname, std::string ofname) : fin_(ifname, std::ios::in | std::ios::binary), rootfile_(ofname.c_str(), "RECREATE"), block_size_(10)
	{
	}
	/**
	 * @brief Destroy the APVDecodeManager object
	 *
	 */
	virtual ~APVDecodeManager();

	/**
	 * @brief Initialize this manager before the main loop
	 *
	 * @param module_type
	 */
	void Init(std::string module_type);
	/**
	 * @brief Set the Block Size object in bytes
	 *
	 * @param size
	 */
	void SetBlockSize(ULong64_t size) { block_size_ = size; }

	/**
	 * @brief Main analysis loop
	 *
	 */
	void Loop();

private:
	const static unsigned int kPrintFreq; /// Print frequency of the progress
	const static unsigned int kNWorkers;  /// Number of workers
	TFile rootfile_;
	std::ifstream fin_;
	ULong64_t block_size_;
	char *buffer_ = nullptr; /// A pointer to the data buffer
	APVDecoderBase<APVSingleData> *decoder_ = nullptr;
	std::vector<APV8104Decoder> decoders_;
	bool loop_ready_ = false; /// A flag to show if the main loop is ready
	TTree *output_tree_ = nullptr;
	APVMultiData block_data_;				  /// Output data container for output_tree_
	ProgressPrinter *prog_printer_ = nullptr; /// A pointer to the ProgressPrinter object
};

#endif ///__APV__DECODE_MANAGER_H__