/**
 * @file EuricaMergerData.hpp
 * @author Rin Yokoyama (yokoyama@cns.s.u-tokyo.ac.jp)
 * @brief
 * @version 0.1
 * @date 2023-01-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __EURICA_MERGER_DATA_HPP__
#define __EURICA_MERGER_DATA_HPP__

#include "OutputTreeData.hpp"
#include "Data_bigrips.h"
#include "Data_wasabi.h"
#include "Data_eurica.h"

namespace eurica
{
    // typedef OutputTreeData<eurica::Data_wasabi, eurica::Data_eurica> WasabiData;
    // typedef OutputTreeData<WasabiData, eurica::Data_bigrips> BigRIPSData;
    // typedef OutputTreeData<BigRIPSData, BigRIPSData> MergedData;
    using WasabiData = OutputTreeData<eurica::Data_wasabi, eurica::Data_eurica>;
    using MergedData = OutputTreeData<WasabiData, eurica::Data_bigrips>;
    using BetaMergedData = OutputTreeData<MergedData, MergedData>;
}

#endif //__EURICA_MERGER_DATA_HPP__