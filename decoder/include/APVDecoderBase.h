/**
 * @file APVDecoderBase.h
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief The base class for decoding APV8XXX list mode data
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __APV_DECODER_BASE_H__
#define __APV_DECODER_BASE_H__
#include <vector>

template <class T>
class APVDecoderBase
{
public:
	/**
	 * @brief Construct a new APVDecoderBase object
	 *
	 * @param size Data size of one event in bytes
	 */
	APVDecoderBase(int size) : event_size_(size), event_id_(0), run_number_(0) {}
	/**
	 * @brief Destroy the APVDecoderBase object
	 *
	 */
	virtual ~APVDecoderBase() {}

	/**
	 * @brief Decode a block of data and return a vector
	 * of event data
	 *
	 * @param buff a pointer to the data buffer
	 * @param size size of the buffer to read in bytes
	 * @return const std::vector<T *>&
	 */
	virtual std::vector<T> &Decode(char *buff, int size);
	/**
	 * @brief Decode and sort a block of data
	 *
	 * @param buff a pointer to the data buffer
	 * @param size   size of the buffer to read in bytes
	 * @return std::vector<T *>&
	 */
	virtual std::vector<T> &SortedDecode(char *buff, int size);

	/**
	 * @brief Set the Runnumber object
	 *
	 * @param number
	 */
	void SetRunnumber(int number) { run_number_ = number; }

	const std::vector<T> &GetDataVec() const { return data_vec_; }

protected:
	virtual T *DecodeAnEvent(char *buff) = 0;
	int run_number_;
	ULong64_t event_id_;

private:
	const int event_size_;	  // Data size of one event in bytes
	std::vector<T> data_vec_; // Vector of event data
};

template <class T>
std::vector<T> &APVDecoderBase<T>::Decode(char *buff, int size)
{
	const unsigned long long n_event = size / event_size_;
	data_vec_.clear();
	for (unsigned long long i = 0; i < n_event; ++i)
	{
		data_vec_.emplace_back(*DecodeAnEvent(&buff[i * event_size_]));
	}
	return data_vec_;
}

template <class T>
std::vector<T> &APVDecoderBase<T>::SortedDecode(char *buff, int size)
{
	Decode(buff, size);
	std::sort(data_vec_.begin(), data_vec_.end(), [](const T &x, const T &y)
			  { return x.GetTiming() < y.GetTiming(); });
	return data_vec_;
}

#endif