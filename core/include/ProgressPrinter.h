/**
 * @file ProgressPrinter.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief	A base class for printing progress of data processing
 * @version 0.1
 * @date 2022-05-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __PROGRESS_PRINTER_H__
#define __PROGRESS_PRINTER_H__

#include <string>
#include "RemainTime.h"

class ProgressPrinter : public RemainTime
{
public:
	ProgressPrinter(const double &first, const double &last, const unsigned long long &freq) : RemainTime(last-first)
	{
		first_ = first;
		print_frequency_ = freq;
	}
	virtual ~ProgressPrinter(){};

	virtual void PrintProgress(const unsigned long long &prog);

protected:
	const static std::string kMsgPrefix;
	unsigned long long print_frequency_;
	double first_;
};

#endif /// __PROGRESS_PRINTER_H__